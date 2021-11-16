# 1 "main.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 387 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "main.cpp" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 443 "/usr/include/features.h" 3 4
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 444 "/usr/include/features.h" 2 3 4
# 465 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 452 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 453 "/usr/include/sys/cdefs.h" 2 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 454 "/usr/include/sys/cdefs.h" 2 3 4
# 466 "/usr/include/features.h" 2 3 4
# 489 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 3 4
# 1 "/usr/include/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/gnu/stubs.h" 2 3 4
# 490 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/bits/libc-header-start.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4

extern "C" {




# 1 "/usr/lib/clang/9.0.1/include/stddef.h" 1 3 4
# 46 "/usr/lib/clang/9.0.1/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/lib/clang/9.0.1/include/stdarg.h" 1 3 4
# 14 "/usr/lib/clang/9.0.1/include/stdarg.h" 3 4
typedef __builtin_va_list va_list;
# 32 "/usr/lib/clang/9.0.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 37 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/bits/types.h" 1 3 4
# 27 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 142 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/time64.h" 1 3 4
# 143 "/usr/include/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 39 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/__fpos_t.h" 1 3 4




# 1 "/usr/include/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 6 "/usr/include/bits/types/__fpos_t.h" 2 3 4




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 40 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/__fpos64_t.h" 1 3 4
# 10 "/usr/include/bits/types/__fpos64_t.h" 3 4
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 41 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 42 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/FILE.h" 1 3 4



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 43 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types/struct_FILE.h" 1 3 4
# 35 "/usr/include/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 44 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/bits/types/cookie_io_functions_t.h" 1 3 4
# 27 "/usr/include/bits/types/cookie_io_functions_t.h" 3 4
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
# 47 "/usr/include/stdio.h" 2 3 4





typedef __gnuc_va_list va_list;
# 63 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;






typedef __off64_t off64_t;






typedef __ssize_t ssize_t;






typedef __fpos_t fpos_t;




typedef __fpos64_t fpos64_t;
# 133 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 134 "/usr/include/stdio.h" 2 3 4



extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) throw ();

extern int rename (const char *__old, const char *__new) throw ();



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) throw ();
# 164 "/usr/include/stdio.h" 3 4
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
        const char *__new, unsigned int __flags) throw ();







extern FILE *tmpfile (void) ;
# 183 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile64 (void) ;



extern char *tmpnam (char *__s) throw () ;




extern char *tmpnam_r (char *__s) throw () ;
# 204 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     throw () __attribute__ ((__malloc__)) ;







extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);
# 227 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 237 "/usr/include/stdio.h" 3 4
extern int fcloseall (void);
# 246 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 270 "/usr/include/stdio.h" 3 4
extern FILE *fopen64 (const char *__restrict __filename,
        const char *__restrict __modes) ;
extern FILE *freopen64 (const char *__restrict __filename,
   const char *__restrict __modes,
   FILE *__restrict __stream) ;




extern FILE *fdopen (int __fd, const char *__modes) throw () ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) throw () ;




extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  throw () ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) throw () ;





extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) throw ();



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) throw ();




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) throw ();


extern void setlinebuf (FILE *__stream) throw ();







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) throw ();





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) throw ();



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3))) ;




extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) throw ();






extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;


extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;

extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) throw () __asm__ ("" "__isoc99_sscanf");
# 432 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__scanf__, 2, 0)));




extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) throw () __asm__ ("" "__isoc99_vsscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 485 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);






extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 510 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);
# 521 "/usr/include/stdio.h" 3 4
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);
# 537 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
          ;
# 587 "/usr/include/stdio.h" 3 4
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream) ;
# 603 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;







extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
# 662 "/usr/include/stdio.h" 3 4
extern int fputs_unlocked (const char *__restrict __s,
      FILE *__restrict __stream);
# 673 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);







extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);
# 707 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 731 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 750 "/usr/include/stdio.h" 3 4
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);



extern void clearerr (FILE *__stream) throw ();

extern int feof (FILE *__stream) throw () ;

extern int ferror (FILE *__stream) throw () ;



extern void clearerr_unlocked (FILE *__stream) throw ();
extern int feof_unlocked (FILE *__stream) throw () ;
extern int ferror_unlocked (FILE *__stream) throw () ;







extern void perror (const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];


extern int _sys_nerr;
extern const char *const _sys_errlist[];
# 782 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) throw () ;




extern int fileno_unlocked (FILE *__stream) throw () ;
# 800 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) throw ();





extern char *cuserid (char *__s);




struct obstack;


extern int obstack_printf (struct obstack *__restrict __obstack,
      const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       const char *__restrict __format,
       __gnuc_va_list __args)
     throw () __attribute__ ((__format__ (__printf__, 2, 0)));







extern void flockfile (FILE *__stream) throw ();



extern int ftrylockfile (FILE *__stream) throw () ;


extern void funlockfile (FILE *__stream) throw ();
# 858 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 873 "/usr/include/stdio.h" 3 4
}
# 2 "main.cpp" 2
# 1 "/usr/lib/clang/9.0.1/include/stdalign.h" 1 3
# 3 "main.cpp" 2
# 1 "/usr/lib/clang/9.0.1/include/stdint.h" 1 3
# 52 "/usr/lib/clang/9.0.1/include/stdint.h" 3
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdint.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 29 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 30 "/usr/include/stdint.h" 2 3 4




# 1 "/usr/include/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 35 "/usr/include/stdint.h" 2 3 4


# 1 "/usr/include/bits/stdint-uintn.h" 1 3 4
# 24 "/usr/include/bits/stdint-uintn.h" 3 4
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
# 38 "/usr/include/stdint.h" 2 3 4





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 71 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 87 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 101 "/usr/include/stdint.h" 3 4
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
# 53 "/usr/lib/clang/9.0.1/include/stdint.h" 2 3
# 4 "main.cpp" 2

struct Foo {
    char c;
    int n;
};


#pragma pack(1)
struct Bar {
    char c;
    int n;
};


#pragma pop
#pragma pack(8)
struct BarAlignedTo8Bytes {
    char c;
    int n;
};


#pragma pop

struct Baz {
    char c;
    int n;
};

struct Qux {
    char c;
    alignas(128) int n;
    alignas(32) float data[4];
};



struct sse_t
{
  alignas(16) float sse_data[4];
};

#pragma pack(16)
struct sse_t_pragma_pack_16
{
  float sse_data[4];
  short s;
  char c;
};

#pragma pack(32)
struct sse_t_pragma_pack_32
{
  float sse_data[4];
};

#pragma pack(4)


struct data {
  char x;
  alignas(128) char cacheline[128];

};


struct PackedStruct {
    char text[21];
    float decimal;
}__attribute__((__packed__));

struct test
{
    unsigned char field1 __attribute__((__packed__));
    unsigned short field2 __attribute__((__packed__));
    unsigned long field3 __attribute__((__packed__));
} var1, var2;

struct test2
{
    unsigned char field1 __attribute__((__packed__));
    unsigned short field2 __attribute__((__packed__));
    unsigned long field3;



};




struct fooWith4ByteAlignment {
    int a;
    char b;
    float c;
    double d;

    bool e;
};


struct alignas(8) fooWith8ByteAlignment {
    int a;
    char b;
    float c;
    double d;

    bool e;
};

struct fooWith8ByteAlignmentAndPadding
{
    int a;
    char b;
    char _pad0[3];
    float c;
    char _pad1[4];
    double d;
    bool e;
    char _pad2[7];
};

#pragma pack(1)
struct TestPragmaPack1
{
   char AA;
   int BB;
   char CC;
};

#pragma pop
#pragma pack(4)
struct TestPragmaPack4
{
   char AA;
   int BB;
   char CC;
};

#pragma pop
#pragma pack(8)
struct alignas(8) TestPragmaPack8
{
   char AA;
   int BB;
   char CC;
};

#pragma pop
struct alignas(8) TestAlignas8
{
   char AA;
   int BB;
   char CC;
};

#pragma pack(8)
struct alignas(8) TestPragmaPack8AlignAs8
{
   char AA;
   int BB;
   char CC;
};

#pragma pop

int main() {
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Foo));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Foo));

    printf("pragma pack(1) - alignment to single bytes\n");
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Bar));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Bar));

    printf("pragma pack(8) - alignment to 8 bytes\n");
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct BarAlignedTo8Bytes));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct BarAlignedTo8Bytes));

    printf("pragma pack(4) - restored packing - alignas() alignment to single bytes\n");
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Baz));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Baz));

    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Qux));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Qux));

    printf("alignof(data) =\t%zu\n", alignof(struct data));
    printf("sizeof(data) = %zu (1 byte + 127 bytes padding + 128-byte array)\n",
           sizeof(struct data));

    printf("\n");
    printf("alignment of sse_t is %zu\n", alignof(struct sse_t));
    printf("size of sse_t is %zu\n", sizeof(struct sse_t));

    printf("\n");
    printf("alignment of sse_t_pragma_pack_16 is %zu\n", alignof(sse_t_pragma_pack_16));
    printf("size of sse_t_pragma_pack_16 is %zu\n", sizeof(struct sse_t_pragma_pack_16));

    printf("\n");
    printf("alignment of sse_t_pragma_pack_32 is %zu\n", alignof(sse_t_pragma_pack_32));
    printf("size of sse_t_pragma_pack_32 is %zu\n", sizeof(struct sse_t_pragma_pack_32));

    printf("\n");
    alignas(2048) struct data d;
    printf("alignment of instance 'd' is %zu\n", alignof(d));
    printf("size of instance 'd' is %zu\n\n", sizeof(d));

    printf("__attribute__((__packed__)) automatically aligns the entire struct to single bytes, i.e. with one byte granularity\n");
    printf("alignof(struct {char text[21]; float decimal;}) =\t%zu\n", alignof(struct PackedStruct));
    printf("sizeof(struct {char text[21]; float decimal;}) =\t%zu\n\n", sizeof(struct PackedStruct));

    printf("__attribute__((__packed__)) automatically aligns the specific members of the struct to single bytes, i.e. with one byte granularity\n");
    printf("alignof(struct {char(packed), short(packed), long}) =\t%zu\n", alignof(struct test));
    printf("sizeof(struct {char(packed), short(packed), long}) =\t%zu\n\n", sizeof(struct test));

    printf( "__attribute__((__packed__)) is ineffective when at least one of the members wasn't marked for packing"
            "even when the rest of them was marked for packing\n");
    printf("alignof(struct {char(packed), short(packed), long}) =\t%zu\n", alignof(struct test2));
    printf("sizeof(struct {char(packed), short(packed), long}) =\t%zu\n\n", sizeof(struct test2));

    printf("alignment of fooWith4ByteAlignment: struct{int, char, float, double, bool} is %zu\n", alignof(fooWith4ByteAlignment));
    printf("size of fooWith4ByteAlignment: struct{int, char, float, double, bool} is %zu\n\n", sizeof(fooWith4ByteAlignment));

    printf("alignment of fooWith8ByteAlignment: struct{int, char, float, double, bool} is %zu\n", alignof(fooWith8ByteAlignment));
    printf("size of fooWith8ByteAlignment: struct{int, char, float, double, bool} is %zu\n\n", sizeof(fooWith8ByteAlignment));

    printf("alignment of fooWith8ByteAlignmentAndPadding: struct{int, char, float, double, bool} is %zu\n", alignof(fooWith8ByteAlignmentAndPadding));
    printf("size of fooWith8ByteAlignmentAndPadding: struct{int, char, float, double, bool} is %zu\n\n", sizeof(fooWith8ByteAlignmentAndPadding));

    alignas(8) int a;




    printf("sizeof(int) aligned to 8 bytes with alignas(8):\t\t%zu\n", sizeof(a));
    printf("alignof(int) aligned to 8 bytes with alignas(8):\t%zu\n", alignof(a));
    printf("address of 'a':\t%p\n", &a);
    printf("sizeof(&a):\t%zu\n", sizeof(&a));
    uint64_t addressOfA_AsNumber = reinterpret_cast<uint64_t>(&a);
    printf("address of 'a':\t%zu\n\n", addressOfA_AsNumber);

    alignas(256) long b[4];
    printf("%p\n\n", &b);

    alignas(16) int aa[4];
    alignas(4096) int bb[4];
    printf("&aa[0]:\t%p\t<- address is aligned to 16 (16^1) byte boundary, therefore the first digit is 0 - divisible by 16\n", aa);
    printf("&bb[0]:\t%p\t<- address is aligned to 256 (16^3) byte boundary, therefore the first three digits are 0 - divisible by 4096\n\n", bb);

    printf("#pragma pack(1)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack1));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack1));

    printf("#pragma pack(4)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack4));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack4));

    printf("#pragma pack(8)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack8));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack8));

    printf("struct alignas(8)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestAlignas8));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestAlignas8));

    printf("#pragma pack(8) + struct alignas(8)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack8AlignAs8));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack8AlignAs8));

    return 0;
}
