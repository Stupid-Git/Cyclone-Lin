/**
  ******************************************************************************
  * @file    stm324xg_eval_lcd.h
  * @author  MCD Application Team
  * @brief   This file contains the common defines and functions prototypes for
  *          the stm324xg_eval_lcd.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM324XG_EVAL_LCD_H
#define __STM324XG_EVAL_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm324xg_eval.h" 
#include "../components/ili9325/ili9325.h"
#include "../utilities/fonts/fonts.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM324xG_EVAL
  * @{
  */
    
/** @addtogroup STM324xG_EVAL_LCD
  * @{
  */ 

/** @defgroup STM324xG_EVAL_LCD_Exported_Types STM324xG EVAL LCD Exported Types
  * @{
  */
typedef struct 
{ 
  uint32_t TextColor;
  uint32_t BackColor;
  sFONT    *pFont; 
}LCD_DrawPropTypeDef;
/**
  * @}
  */ 

/** @defgroup STM324xG_EVAL_LCD_Exported_Constants STM324xG EVAL LCD Exported Constants
  * @{
  */
/** 
  * @brief  LCD status structure definition  
  */     
#define LCD_OK         0x00
#define LCD_ERROR      0x01
#define LCD_TIMEOUT    0x02
    
typedef struct 
{
  int16_t X;
  int16_t Y;
}Point, * pPoint; 

/** 
  * @brief  Line mode structures definition
  */ 
typedef enum
{
  CENTER_MODE          = 0x01,    /* Center mode */
  RIGHT_MODE           = 0x02,    /* Right mode  */
  LEFT_MODE            = 0x03     /* Left mode   */
}Line_ModeTypdef;

/** 
  * @brief  LCD color  
  */ 
#define LCD_COLOR_BLUE          0x001F
#define LCD_COLOR_GREEN         0x07E0
#define LCD_COLOR_RED           0xF800
#define LCD_COLOR_CYAN          0x07FF
#define LCD_COLOR_MAGENTA       0xF81F
#define LCD_COLOR_YELLOW        0xFFE0
#define LCD_COLOR_LIGHTBLUE     0x841F
#define LCD_COLOR_LIGHTGREEN    0x87F0
#define LCD_COLOR_LIGHTRED      0xFC10
#define LCD_COLOR_LIGHTCYAN     0x87FF
#define LCD_COLOR_LIGHTMAGENTA  0xFC1F
#define LCD_COLOR_LIGHTYELLOW   0xFFF0
#define LCD_COLOR_DARKBLUE      0x0010
#define LCD_COLOR_DARKGREEN     0x0400
#define LCD_COLOR_DARKRED       0x8000
#define LCD_COLOR_DARKCYAN      0x0410
#define LCD_COLOR_DARKMAGENTA   0x8010
#define LCD_COLOR_DARKYELLOW    0x8400
#define LCD_COLOR_WHITE         0xFFFF
#define LCD_COLOR_LIGHTGRAY     0xD69A
#define LCD_COLOR_GRAY          0x8410
#define LCD_COLOR_DARKGRAY      0x4208
#define LCD_COLOR_BLACK         0x0000
#define LCD_COLOR_BROWN         0xA145
#define LCD_COLOR_ORANGE        0xFD20

/** 
  * @brief LCD default font 
  */ 
#define LCD_DEFAULT_FONT         Font24

/**
  * @}
  */

/** @defgroup STM324xG_EVAL_LCD_Exported_Functions STM324xG EVAL LCD Exported Functions
  * @{
  */   
uint8_t  BSP_LCD_Init(void);
uint32_t BSP_LCD_GetXSize(void);
uint32_t BSP_LCD_GetYSize(void);
 
uint16_t BSP_LCD_GetTextColor(void);
uint16_t BSP_LCD_GetBackColor(void);
void     BSP_LCD_SetTextColor(__IO uint16_t Color);
void     BSP_LCD_SetBackColor(__IO uint16_t Color);
void     BSP_LCD_SetFont(sFONT *fonts);
sFONT    *BSP_LCD_GetFont(void);

void     BSP_LCD_Clear(uint16_t Color);
void     BSP_LCD_ClearStringLine(uint16_t Line);
void     BSP_LCD_DisplayStringAtLine(uint16_t Line, uint8_t *ptr);
void     BSP_LCD_DisplayStringAt(uint16_t Xpos, uint16_t Ypos, uint8_t *Text, Line_ModeTypdef Mode);
void     BSP_LCD_DisplayChar(uint16_t Xpos, uint16_t Ypos, uint8_t Ascii);

uint16_t BSP_LCD_ReadPixel(uint16_t Xpos, uint16_t Ypos);
void     BSP_LCD_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGB_Code);
void     BSP_LCD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     BSP_LCD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     BSP_LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void     BSP_LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     BSP_LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
void     BSP_LCD_DrawPolygon(pPoint Points, uint16_t PointCount);
void     BSP_LCD_DrawEllipse(int Xpos, int Ypos, int XRadius, int YRadius);
void     BSP_LCD_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);
void     BSP_LCD_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pbmp);
void     BSP_LCD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     BSP_LCD_FillCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
void     BSP_LCD_FillPolygon(pPoint Points, uint16_t PointCount);
void     BSP_LCD_FillEllipse(int Xpos, int Ypos, int XRadius, int YRadius);

void     BSP_LCD_DisplayOff(void);
void     BSP_LCD_DisplayOn(void);
 
/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

#ifdef __cplusplus
}
#endif

#endif /* __STM324XG_EVAL_LCD_H */
