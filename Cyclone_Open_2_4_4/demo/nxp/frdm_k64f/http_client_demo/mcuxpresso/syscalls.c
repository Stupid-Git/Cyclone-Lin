#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#undef errno
extern int errno;
extern int _end;

extern caddr_t __HeapBase;
extern caddr_t __HeapLimit;

extern caddr_t _sbrk(int incr);
extern int link(char *old, char *new);
extern int _close(int file);
extern int _fstat(int file, struct stat *st);
extern int _isatty(int file);
extern int _lseek(int file, int ptr, int dir);
extern void _exit(int status);
extern void _kill(int pid, int sig);
extern int _getpid(void);

int _write(int file, char *ptr, int len)
{
   int i;

   if(file == 1)
   {
      for(i = 0; i < len; i++)
      fputc(ptr[i], stdout);
   }
   else if(file == 2)
   {
      for(i = 0; i < len; i++)
      fputc(ptr[i], stderr);
   }

   return len;
}

int _read(int file, char *ptr, int len)
{
   return 0;
}

extern caddr_t _sbrk(int incr)
{
   static caddr_t heap_end = NULL;
   caddr_t prev_heap_end;

   if(heap_end == NULL)
      heap_end = (caddr_t) &__HeapBase;

   prev_heap_end = heap_end;

   if((heap_end + incr) > (caddr_t) &__HeapLimit)
   {
      errno = ENOMEM;
      return (caddr_t) -1;
   }

   heap_end += incr;

   return prev_heap_end;
}

extern int link(char *old, char *new)
{
   return -1;
}

extern int _close(int file)
{
   return -1;
}

extern int _fstat(int file, struct stat *st)
{
   st->st_mode = S_IFCHR;
   return 0;
}

extern int _isatty(int file)
{
   return 1;
}

extern int _lseek(int file, int ptr, int dir)
{
   return 0;
}

extern void _exit(int status)
{
   while(1);
}

extern void _kill(int pid, int sig)
{
   return;
}

extern int _getpid(void)
{
   return -1;
}
