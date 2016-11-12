
#include <errno.h>
#undef errno
extern int errno;

#include <sys/stat.h>
#include <sys/times.h>
char *__env[1] = {0};
char **environ = __env;
extern caddr_t _get_stack_pointer(void);
void _exit( int status )
{
    (void)status;

    while(1)
    {
        
    }
}

int close( int file )
{
    return -1;
}
int execve( char *name, char **argv, char **env )
{
    errno = ENOMEM;
    return -1;
}

int fork( void )
{
    errno = EAGAIN;
    return -1;
}
int fstat( int file, struct stat *st )
{
    st->st_mode = S_IFCHR;
    return 0;
}


/* Process-ID; this is sometimes used to generate strings unlikely to conflict
   with other processes. Minimal implementation, for a system without
   processes: */
int getpid( void )
{
    return 1;
}


/* Query whether output stream is a terminal. For consistency with the other
   minimal implementations, which only support output to stdout, this minimal
   implementation is suggested: */
int isatty(int file)
{
    return 1;
}


/* Send a signal. Minimal implementation: */
int kill( int pid, int sig )
{
    errno = EINVAL;
    return -1;
}


/* Establish a new name for an existing file. Minimal implementation: */
int link( char *old, char *new )
{
    errno = EMLINK;
    return -1;
}


/* Set position in a file. Minimal implementation: */
int lseek(int file, int ptr, int dir)
{
    return 0;
}


/* Open a file. Minimal implementation: */
int open( const char *name, int flags, int mode )
{
    return -1;
}


/* Read from a file. Minimal implementation: */
int read( int file, char *ptr, int len )
{
    return 0;
}


/* Increase program data space. As malloc and related functions depend on this,
   it is useful to have a working implementation. The following suffices for a
   standalone system; it exploits the symbol _end automatically defined by the
   GNU linker. */
caddr_t _sbrk( int incr )
{
    extern char _end;
    static char* heap_end;
    char* prev_heap_end;

    if( heap_end == 0 )
        heap_end = &_end;

     prev_heap_end = heap_end;

     if( ( heap_end + incr) > _get_stack_pointer() )
     {
        while(1)
        {
            /* TRAP HERE! */
        }
     }

     heap_end += incr;
     return (caddr_t)prev_heap_end;
}


/* Status of a file (by name). Minimal implementation: */
int stat( const char *file, struct stat *st )
{
    st->st_mode = S_IFCHR;
    return 0;
}


/* Timing information for current process. Minimal implementation: */
clock_t times( struct tms *buf )
{
    return -1;
}


/* Remove a file's directory entry. Minimal implementation: */
int unlink( char *name )
{
    errno = ENOENT;
    return -1;
}

int wait( int *status )
{
    errno = ECHILD;
    return -1;
}


void outbyte( char b )
{
    (void)b;
}
int write( int file, char *ptr, int len )
{
    int todo;

    for( todo = 0; todo < len; todo++ )
      outbyte(*ptr++);

    return len;
}
