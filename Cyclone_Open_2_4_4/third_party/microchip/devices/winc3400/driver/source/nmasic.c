/**
 *
 * \file
 *
 * \brief This module contains WINC3400 ASIC specific internal APIs.
 *
 * Copyright (c) 2017-2019 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include "common/include/nm_common.h"
#include "driver/source/nmbus.h"
#include "bsp/include/nm_bsp.h"
#include "driver/source/nmasic.h"
#include "driver/include/m2m_types.h"

#define NMI_GLB_RESET_0             (NMI_PERIPH_REG_BASE + 0x400)
#define NMI_INTR_REG_BASE           (NMI_PERIPH_REG_BASE + 0xa00)
#define NMI_PIN_MUX_0               (NMI_PERIPH_REG_BASE + 0x408)
#define NMI_INTR_ENABLE             (NMI_INTR_REG_BASE)
#define GET_UINT32(X,Y)             (X[0+Y] + ((uint32)X[1+Y]<<8) + ((uint32)X[2+Y]<<16) +((uint32)X[3+Y]<<24))

/*SPI and I2C only*/
#define CORT_HOST_COMM              (0x14)
#define HOST_CORT_COMM              (0x0e)
#define WAKE_CLK_REG                (0x1)
#define CLOCKS_EN_REG               (0x13)

#define TIMEOUT                     (2000)
#define WAKEUP_TRIALS               (4)

sint8 chip_apply_conf(uint32 u32Conf)
{
    sint8 ret = M2M_SUCCESS;
    uint32 val32 = u32Conf;

#ifdef __ENABLE_PMU__
    val32 |= rHAVE_USE_PMU_BIT;
#endif
#ifdef __ENABLE_SLEEP_CLK_SRC_RTC__
    val32 |= rHAVE_SLEEP_CLK_SRC_RTC_BIT;
#elif defined __ENABLE_SLEEP_CLK_SRC_XO__
    val32 |= rHAVE_SLEEP_CLK_SRC_XO_BIT;
#endif
#ifdef __ENABLE_EXT_PA_INV_TX_RX__
    val32 |= rHAVE_EXT_PA_INV_TX_RX;
#endif
#ifdef __ENABLE_LEGACY_RF_SETTINGS__
    val32 |= rHAVE_LEGACY_RF_SETTINGS;
#endif
#ifdef __DISABLE_FIRMWARE_LOGS__
    val32 |= rHAVE_LOGS_DISABLED_BIT;
#endif
    do {
        nm_write_reg(rNMI_GP_REG_1, val32);
        if(val32 != 0) {
            uint32 reg = 0;
            ret = nm_read_reg_with_ret(rNMI_GP_REG_1, &reg);
            if(ret == M2M_SUCCESS) {
                if(reg == val32)
                    break;
            }
        } else {
            break;
        }
    } while(1);

    return M2M_SUCCESS;
}

void chip_idle(void)
{
    uint32 reg =0;
    nm_read_reg_with_ret(WAKE_CLK_REG, &reg);
    if(reg&NBIT1)
    {
        reg &=~NBIT1;
        nm_write_reg(WAKE_CLK_REG, reg);
    }
}

void enable_rf_blocks(void)
{
    nm_write_reg(0x6, 0xdb);
    nm_write_reg(0x7, 0x6);
    nm_bsp_sleep(10);
    nm_write_reg(0x1480, 0);
    nm_write_reg(0x1484, 0);
    nm_bsp_sleep(10);

    nm_write_reg(0x6, 0x0);
    nm_write_reg(0x7, 0x0);
}

sint8 enable_interrupts(void)
{
    uint32 reg = 0;
    sint8 ret = M2M_SUCCESS;
    /**
    interrupt pin mux select
    **/
    ret = nm_read_reg_with_ret(NMI_PIN_MUX_0, &reg);
    if(M2M_SUCCESS != ret) {
        return M2M_ERR_BUS_FAIL;
    }
    reg |= ((uint32) 1 << 8);
    ret = nm_write_reg(NMI_PIN_MUX_0, reg);
    if(M2M_SUCCESS != ret) {
        return M2M_ERR_BUS_FAIL;
    }
    /**
    interrupt enable
    **/
    ret = nm_read_reg_with_ret(NMI_INTR_ENABLE, &reg);
    if(M2M_SUCCESS != ret) {
        return M2M_ERR_BUS_FAIL;
    }
    reg |= ((uint32) 1 << 16);
    ret = nm_write_reg(NMI_INTR_ENABLE, reg);
    if(M2M_SUCCESS != ret) {
        return M2M_ERR_BUS_FAIL;
    }
    return M2M_SUCCESS;
}

sint8 cpu_start(void) {
    uint32 reg = 0;
    sint8 ret;

    /**
    reset regs
    */
    ret = nm_write_reg(BOOTROM_REG, 0);
    ret += nm_write_reg(NMI_STATE_REG, 0);
    ret += nm_write_reg(NMI_REV_REG, 0);

    /**
    Go...
    **/
    ret += nm_read_reg_with_ret(0x1118, &reg);
    if(M2M_SUCCESS != ret) {
        ret = M2M_ERR_BUS_FAIL;
        M2M_ERR("[nmi start]: fail read reg 0x1118 ...\r\n");
    }
    reg |= NBIT0;
    ret += nm_write_reg(0x1118, reg);
    ret = nm_write_reg(0x150014, 0x1); //DTODO WHY IS THIS HERE??
    ret += nm_read_reg_with_ret(NMI_GLB_RESET_0, &reg);
    if((reg & (1ul << 10)) == (1ul << 10)) {
        reg &= ~(1ul << 10);
        ret += nm_write_reg(NMI_GLB_RESET_0, reg);
    }

    reg |= (1ul << 10);
    ret += nm_write_reg(NMI_GLB_RESET_0, reg);
    nm_bsp_sleep(1); /* Removing this can cause a bus error. */
    return ret;
}

uint32 nmi_get_chipid(void)
{
    static uint32 chipid = 0;

    if(chipid == 0) {
        uint32 rfrevid;

        if((nm_read_reg_with_ret(0x1000, &chipid)) != M2M_SUCCESS) {
            chipid = 0;
            return 0;
        }
        if((nm_read_reg_with_ret(0x13f4, &rfrevid)) != M2M_SUCCESS) {
            chipid = 0;
            return 0;
        }

        if(chipid == 0x1002a0)  {
            if(rfrevid == 0x1) { /* 1002A0 */
            } else /* if (rfrevid == 0x2) */ { /* 1002A1 */
                chipid = 0x1002a1;
            }
        } else if(chipid == 0x1002b0) {
            if(rfrevid == 3) { /* 1002B0 */
            } else if(rfrevid == 4) { /* 1002B1 */
                chipid = 0x1002b1;
            } else /* if(rfrevid == 5) */ { /* 1002B2 */
                chipid = 0x1002b2;
            }
        } else if(chipid == 0x1000f0) {
            /* For 3400, the WiFi chip ID register reads 0x1000f0.
             * Therefore using BT chip ID register here which should read 0x3000D0
             */
#define rBT_CHIP_ID_REG  (0x3b0000)
            if((nm_read_reg_with_ret(rBT_CHIP_ID_REG, &chipid)) != M2M_SUCCESS) {
                chipid = 0;
                return 0;
            }
            if(chipid == 0x3000d0) {
                if(rfrevid == 6) {
                    chipid = 0x3000d1;
                }
                else if(rfrevid == 2) {
                    chipid = 0x3000d2;
                }
            }
        }
//#define PROBE_FLASH
#ifdef PROBE_FLASH
        if(chipid) {
            UWORD32 flashid;

            flashid = probe_spi_flash();
            if((chipid & 0xf00000) == 0x300000) {
                if(flashid == 0x1440ef) {
                    chipid &= ~(0x0f0000);
                    chipid |= 0x040000;
                }
            } else {
                if(flashid == 0x1230ef) {
                    chipid &= ~(0x0f0000);
                    chipid |= 0x050000;
                }
                if(flashid == 0xc21320c2) {
                    chipid &= ~(0x0f0000);
                    chipid |= 0x050000;
                }
            }
        }
#else
        /*M2M is by default have SPI flash*/
        if((chipid & 0xf00000) == 0x300000) {
            chipid &= ~(0x0f0000);
            chipid |= 0x040000;
        } else {
            chipid &= ~(0x0f0000);
            chipid |= 0x050000;
        }
#endif /* PROBE_FLASH */
    }
    return chipid;
}

uint32 nmi_get_rfrevid(void)
{
    uint32 rfrevid;
    if((nm_read_reg_with_ret(0x13f4, &rfrevid)) != M2M_SUCCESS) {
        rfrevid = 0;
    }
    return rfrevid;
}

void restore_pmu_settings_after_global_reset(void)
{
    /*
     * Must restore PMU register value after
     * global reset if PMU toggle is done at
     * least once since the last hard reset.
     */
    if(REV(nmi_get_chipid()) >= REV_2B0) {
        nm_write_reg(0x1e48, 0xb78469ce);
    }
}

void nmi_update_pll(void)
{
    uint32 pll;

    pll = nm_read_reg(0x1428);
    pll &= ~0x1ul;
    nm_write_reg(0x1428, pll);
    pll |= 0x1ul;
    nm_write_reg(0x1428, pll);

}
void nmi_set_sys_clk_src_to_xo(void)
{
    uint32 val32;

    /* Switch system clock source to XO. This will take effect after nmi_update_pll(). */
    val32 = nm_read_reg(0x141c);
    val32 |= (1 << 2);
    nm_write_reg(0x141c, val32);

    /* Do PLL update */
    nmi_update_pll();
}

sint8 chip_sleep(void)
{
    uint32 reg;
    sint8 ret = M2M_SUCCESS;

    while(1)
    {
        ret = nm_read_reg_with_ret(CORT_HOST_COMM, &reg);
        if(ret != M2M_SUCCESS) goto ERR1;
        if((reg & NBIT0) == 0) break;
    }

    /* Clear bit 1 */
    ret = nm_read_reg_with_ret(WAKE_CLK_REG, &reg);
    if(ret != M2M_SUCCESS)goto ERR1;
    if(reg & NBIT1)
    {
        reg &=~NBIT1;
        ret = nm_write_reg(WAKE_CLK_REG, reg);
        if(ret != M2M_SUCCESS)goto ERR1;
    }

    ret = nm_read_reg_with_ret(HOST_CORT_COMM, &reg);
    if(ret != M2M_SUCCESS)goto ERR1;
    if(reg & NBIT0)
    {
        reg &= ~NBIT0;
        ret = nm_write_reg(HOST_CORT_COMM, reg);
        if(ret != M2M_SUCCESS)goto ERR1;
    }

ERR1:
    return ret;
}

sint8 chip_wake(void)
{
    sint8 ret = M2M_SUCCESS;
    uint32 reg = 0, clk_status_reg = 0, trials = 0;

    nm_read_reg_with_ret(CLOCKS_EN_REG, &clk_status_reg);

    ret = nm_read_reg_with_ret(HOST_CORT_COMM, &reg);
    if(ret != M2M_SUCCESS)goto _WAKE_EXIT;

    if(!(reg & NBIT0))
    {
        /*USE bit 0 to indicate host wakeup*/
        ret = nm_write_reg(HOST_CORT_COMM, reg|NBIT0);
        if(ret != M2M_SUCCESS)goto _WAKE_EXIT;
    }

    ret = nm_read_reg_with_ret(WAKE_CLK_REG, &reg);
    if(ret != M2M_SUCCESS) goto _WAKE_EXIT;

    /* Set bit 1 */
    if(!(reg & NBIT1))
    {
        ret = nm_write_reg(WAKE_CLK_REG, reg | NBIT1);
        if(ret != M2M_SUCCESS) goto _WAKE_EXIT;
    }

    do
    {
        ret = nm_read_reg_with_ret(CLOCKS_EN_REG, &clk_status_reg);
        if(ret != M2M_SUCCESS) {
            M2M_ERR("Bus error (5).%d %lx\r\n", ret, clk_status_reg);
            goto _WAKE_EXIT;
        }
        if(clk_status_reg & NBIT2) {
            break;
        }
        nm_bsp_sleep(2);
        trials++;
        if(trials > WAKEUP_TRIALS)
        {
            M2M_ERR("Failed to wakeup the chip\r\n");
            ret = M2M_ERR_TIME_OUT;
            goto _WAKE_EXIT;
        }
    } while(1);
    /* Workaround sometimes spi fail to read clock regs after reading/writing clockless registers */
    //nm_bus_reset();
_WAKE_EXIT:
    return ret;
}

sint8 chip_reset_and_cpu_halt(void)
{
    sint8 ret = M2M_SUCCESS;
    uint32 reg = 0;

    ret = chip_wake();
    if(ret != M2M_SUCCESS) {
        return ret;
    }
    chip_reset();
    ret = nm_read_reg_with_ret(0x1118, &reg);
    if(M2M_SUCCESS != ret) {
        ret = M2M_ERR_BUS_FAIL;
        M2M_ERR("[nmi start]: fail read reg 0x1118 ...\r\n");
    }
    reg |= (1 << 0);
    ret = nm_write_reg(0x1118, reg);
    ret += nm_read_reg_with_ret(NMI_GLB_RESET_0, &reg);
    if((reg & (1ul << 10)) == (1ul << 10)) {
        reg &= ~(1ul << 10);
        ret += nm_write_reg(NMI_GLB_RESET_0, reg);
        ret += nm_read_reg_with_ret(NMI_GLB_RESET_0, &reg);
    }
    nm_write_reg(BOOTROM_REG, 0);
    nm_write_reg(NMI_STATE_REG, 0);
    nm_write_reg(NMI_REV_REG, 0);
    nm_write_reg(NMI_PIN_MUX_0, 0x11111000);
    return ret;
}
sint8 chip_reset(void)
{
    sint8 ret = M2M_SUCCESS;

    ret += nm_write_reg(NMI_GLB_RESET_0, 0);
    nm_bsp_sleep(50);
#ifndef CONF_WINC_USE_UART
    restore_pmu_settings_after_global_reset();
#endif
    return ret;
}

sint8 wait_for_bootrom(uint8 arg)
{
    sint8 ret = M2M_SUCCESS;
    uint32 reg = 0, cnt = 0;
    uint32 u32GpReg1 = 0;

    reg = 0;
    while(1) {
        reg = nm_read_reg(0x1014);  /* wait for efuse loading done */
        if(reg & 0x80000000) {
            break;
        }
        nm_bsp_sleep(1); /* Removing this can cause a bus error. */
    }
    reg = nm_read_reg(M2M_WAIT_FOR_HOST_REG);
    reg &= 0x1;

    /* check if waiting for the host will be skipped or not */
    if(reg == 0)
    {
        while(reg != M2M_FINISH_BOOT_ROM)
        {
            nm_bsp_sleep(1);
            reg = nm_read_reg(BOOTROM_REG);

            if(++cnt > TIMEOUT)
            {
                M2M_DBG("failed to load firmware from flash.\r\n");
                ret = M2M_ERR_INIT;
                goto ERR2;
            }
        }
    }

    if(M2M_WIFI_MODE_CONFIG == arg) {
        nm_write_reg(NMI_REV_REG, M2M_ATE_FW_START_VALUE);
    } else if(M2M_WIFI_MODE_ETHERNET == arg) {
        u32GpReg1 = rHAVE_ETHERNET_MODE_BIT;
    } else {
        /*bypass this step*/
    }

    if(REV(nmi_get_chipid()) == REV_3A0)
    {
        chip_apply_conf(u32GpReg1 | rHAVE_USE_PMU_BIT);
    }
    else
    {
        chip_apply_conf(u32GpReg1);
    }

    nm_write_reg(BOOTROM_REG, M2M_START_FIRMWARE);

#ifdef __ROM_TEST__
    rom_test();
#endif /* __ROM_TEST__ */

ERR2:
    return ret;
}

sint8 wait_for_firmware_start(uint8 arg)
{
    sint8 ret = M2M_SUCCESS;
    uint32 reg = 0, cnt = 0;
    volatile uint32 regAddress = NMI_STATE_REG;
    volatile uint32 checkValue = M2M_FINISH_INIT_STATE;

    if(M2M_WIFI_MODE_CONFIG == arg) {
        regAddress = NMI_REV_REG;
        checkValue = M2M_ATE_FW_START_VALUE;//M2M_ATE_FW_IS_UP_VALUE;
    } else {
        /*bypass this step*/
    }

    while(checkValue != reg)
    {
        nm_bsp_sleep(2); /* Removing this can cause a bus error. */
        M2M_DBG("%x %x %x\r\n", (unsigned int)nm_read_reg(0x108c), (unsigned int)nm_read_reg(0x108c), (unsigned int)nm_read_reg(0x14A0));
        if(nm_read_reg_with_ret(regAddress, &reg) != M2M_SUCCESS)
        {
            // ensure reg != checkValue
            reg = !checkValue;
        }
        if(++cnt > TIMEOUT)
        {
            M2M_DBG("Time out for wait firmware Run\r\n");
            ret = M2M_ERR_INIT;
            goto ERR;
        }
    }
    if(M2M_FINISH_INIT_STATE == checkValue)
    {
        nm_write_reg(NMI_STATE_REG, 0);
    }
ERR:
    return ret;
}

sint8 chip_deinit(void)
{
    uint32 reg = 0;
    sint8 ret;
    uint8 timeout = 10;

    /**
    stop the firmware, need a re-download
    **/
    ret = nm_read_reg_with_ret(NMI_GLB_RESET_0, &reg);
    if(ret != M2M_SUCCESS) {
        M2M_ERR("failed to de-initialize\r\n");
    }
    reg &= ~(1 << 10);
    ret = nm_write_reg(NMI_GLB_RESET_0, reg);

    if(ret != M2M_SUCCESS) {
        M2M_ERR("Error while writing reg\r\n");
        return ret;
    }

    do {
        ret = nm_read_reg_with_ret(NMI_GLB_RESET_0, &reg);
        if(ret != M2M_SUCCESS) {
            M2M_ERR("Error while reading reg\r\n");
            return ret;
        }
        /*Workaround to ensure that the chip is actually reset*/
        if((reg & (1 << 10))) {
            M2M_DBG("Bit 10 not reset retry %d\r\n", timeout);
            reg &= ~(1 << 10);
            ret = nm_write_reg(NMI_GLB_RESET_0, reg);
            timeout--;
        } else {
            break;
        }
    } while(timeout);

    return ret;
}

#ifdef CONF_PERIPH

sint8 set_gpio_dir(uint8 gpio, uint8 dir)
{
    uint32 val32;
    sint8 ret;

    ret = nm_read_reg_with_ret(0x20108, &val32);
    if(ret != M2M_SUCCESS) goto _EXIT;

    if(dir) {
        val32 |= (1ul << gpio);
    } else {
        val32 &= ~(1ul << gpio);
    }

    ret = nm_write_reg(0x20108, val32);

_EXIT:
    return ret;
}
sint8 set_gpio_val(uint8 gpio, uint8 val)
{
    uint32 val32;
    sint8 ret;

    ret = nm_read_reg_with_ret(0x20100, &val32);
    if(ret != M2M_SUCCESS) goto _EXIT;

    if(val) {
        val32 |= (1ul << gpio);
    } else {
        val32 &= ~(1ul << gpio);
    }

    ret = nm_write_reg(0x20100, val32);

_EXIT:
    return ret;
}

sint8 get_gpio_val(uint8 gpio, uint8* val)
{
    uint32 val32;
    sint8 ret;

    ret = nm_read_reg_with_ret(0x20104, &val32);
    if(ret != M2M_SUCCESS) goto _EXIT;

    *val = (uint8)((val32 >> gpio) & 0x01);

_EXIT:
    return ret;
}

sint8 pullup_ctrl(uint32 pinmask, uint8 enable)
{
    sint8 s8Ret;
    uint32 val32;
    s8Ret = nm_read_reg_with_ret(0x142c, &val32);
    if(s8Ret != M2M_SUCCESS) {
        M2M_ERR("[pullup_ctrl]: failed to read\r\n");
        goto _EXIT;
    }
    if(enable) {
        val32 &= ~pinmask;
    } else {
        val32 |= pinmask;
    }
    s8Ret = nm_write_reg(0x142c, val32);
    if(s8Ret  != M2M_SUCCESS) {
        M2M_ERR("[pullup_ctrl]: failed to write\r\n");
        goto _EXIT;
    }
_EXIT:
    return s8Ret;
}
#endif /* CONF_PERIPH */

sint8 nmi_get_otp_mac_address(uint8 *pu8MacAddr,  uint8 *pu8IsValid)
{
    sint8 ret;
    uint32  u32RegValue;
    uint8   mac[6];
    tstrGpRegs strgp = {0};

    ret = nm_read_reg_with_ret(rNMI_GP_REG_0, &u32RegValue);
    if(ret != M2M_SUCCESS) goto _EXIT_ERR;

    ret = nm_read_block(u32RegValue|0x30000, (uint8*)&strgp, sizeof(tstrGpRegs));
    if(ret != M2M_SUCCESS) goto _EXIT_ERR;
    u32RegValue = strgp.u32Mac_efuse_mib;

    if(!EFUSED_MAC(u32RegValue)) {
        M2M_DBG("Default MAC\r\n");
        m2m_memset(pu8MacAddr, 0, 6);
        goto _EXIT_ERR;
    }

    M2M_DBG("OTP MAC\r\n");
    u32RegValue >>=16;
    ret = nm_read_block(u32RegValue|0x30000, mac, 6);
    m2m_memcpy(pu8MacAddr, mac, 6);
    if(pu8IsValid) *pu8IsValid = 1;
    return ret;

_EXIT_ERR:
    if(pu8IsValid) *pu8IsValid = 0;
    return ret;
}

sint8 nmi_get_mac_address(uint8 *pu8MacAddr)
{
    sint8 ret;
    uint32  u32RegValue;
    uint8   mac[6];
    tstrGpRegs strgp = {0};

    ret = nm_read_reg_with_ret(rNMI_GP_REG_0, &u32RegValue);
    if(ret != M2M_SUCCESS) goto _EXIT_ERR;

    ret = nm_read_block(u32RegValue|0x30000, (uint8*)&strgp, sizeof(tstrGpRegs));
    if(ret != M2M_SUCCESS) goto _EXIT_ERR;
    u32RegValue = strgp.u32Mac_efuse_mib;

    u32RegValue &=0x0000ffff;
    ret = nm_read_block(u32RegValue|0x30000, mac, 6);
    m2m_memcpy(pu8MacAddr, mac, 6);

_EXIT_ERR:
    return ret;
}
