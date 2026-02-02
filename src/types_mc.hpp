//  Copyright (c) 2024- David Lucius Severus
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
#pragma once

#define __WORDSIZE 64     // only for 64bit

#define __S16_TYPE short int
#define __U16_TYPE unsigned short int
#define __S32_TYPE int
#define __U32_TYPE unsigned int
#define __SLONGWORD_TYPE long int
#define __ULONGWORD_TYPE unsigned long int
#if __WORDSIZE == 32
#define __SQUAD_TYPE int64_t
#define __UQUAD_TYPE uint64_t
#define __SWORD_TYPE int
#define __UWORD_TYPE unsigned int
#define __SLONG32_TYPE long int
#define __ULONG32_TYPE unsigned long int
#define __S64_TYPE int64_t
#define __U64_TYPE uint64_t
#elif __WORDSIZE == 64
#define __SQUAD_TYPE long int
#define __UQUAD_TYPE unsigned long int
#define __SWORD_TYPE long int
#define __UWORD_TYPE unsigned long int
#define __SLONG32_TYPE int
#define __ULONG32_TYPE unsigned int
#define __S64_TYPE long int
#define __U64_TYPE unsigned long int
#else
#error
#endif
#if defined __x86_64__ && defined __ILP32__
#define __SYSCALL_SLONG_TYPE __SQUAD_TYPE
#define __SYSCALL_ULONG_TYPE __UQUAD_TYPE
#else
#define __SYSCALL_SLONG_TYPE __SLONGWORD_TYPE
#define __SYSCALL_ULONG_TYPE __ULONGWORD_TYPE
#endif

#define __DEV_T_TYPE __UQUAD_TYPE
#define __UID_T_TYPE __U32_TYPE
#define __GID_T_TYPE __U32_TYPE
#define __INO_T_TYPE __SYSCALL_ULONG_TYPE
#define __INO64_T_TYPE __UQUAD_TYPE
#define __MODE_T_TYPE __U32_TYPE
#ifdef __x86_64__
#define __NLINK_T_TYPE __SYSCALL_ULONG_TYPE
#define __FSWORD_T_TYPE __SYSCALL_SLONG_TYPE
#else
#define __NLINK_T_TYPE __UWORD_TYPE
#define __FSWORD_T_TYPE __SWORD_TYPE
#endif
#define __OFF_T_TYPE __SYSCALL_SLONG_TYPE
#define __OFF64_T_TYPE __SQUAD_TYPE
#define __PID_T_TYPE __S32_TYPE
#define __RLIM_T_TYPE __SYSCALL_ULONG_TYPE
#define __RLIM64_T_TYPE __UQUAD_TYPE
#define __BLKCNT_T_TYPE __SYSCALL_SLONG_TYPE
#define __BLKCNT64_T_TYPE __SQUAD_TYPE
#define __FSBLKCNT_T_TYPE __SYSCALL_ULONG_TYPE
#define __FSBLKCNT64_T_TYPE __UQUAD_TYPE
#define __FSFILCNT_T_TYPE __SYSCALL_ULONG_TYPE
#define __FSFILCNT64_T_TYPE __UQUAD_TYPE
#define __ID_T_TYPE __U32_TYPE
#define __CLOCK_T_TYPE __SYSCALL_SLONG_TYPE
#define __TIME_T_TYPE __SYSCALL_SLONG_TYPE
#define __USECONDS_T_TYPE __U32_TYPE
#define __SUSECONDS_T_TYPE __SYSCALL_SLONG_TYPE
#define __SUSECONDS64_T_TYPE __SQUAD_TYPE
#define __DADDR_T_TYPE __S32_TYPE
#define __KEY_T_TYPE __S32_TYPE
#define __CLOCKID_T_TYPE __S32_TYPE
#define __TIMER_T_TYPE void *
#define __BLKSIZE_T_TYPE __SYSCALL_SLONG_TYPE
// #define __FSID_T_TYPE		struct { int __val[2]; }
#define __SSIZE_T_TYPE __SWORD_TYPE
#define __CPU_MASK_TYPE __SYSCALL_ULONG_TYPE

using __dev_t = __DEV_T_TYPE;     /* Type of device numbers.  */
using __uid_t = __UID_T_TYPE;     /* Type of user identifications.  */
using __gid_t = __GID_T_TYPE;     /* Type of group identifications.  */
using __ino_t = __INO_T_TYPE;     /* Type of file serial numbers.  */
using __ino64_t = __INO64_T_TYPE; /* Type of file serial numbers (LFS).*/
using __mode_t = __MODE_T_TYPE;   /* Type of file attribute bitmasks.  */
using __nlink_t = __NLINK_T_TYPE; /* Type of file link counts.  */
using __off_t = __OFF_T_TYPE;     /* Type of file sizes and offsets.  */
using __off64_t = __OFF64_T_TYPE; /* Type of file sizes and offsets (LFS).  */
using __pid_t = __PID_T_TYPE;     /* Type of process identifications.  */
// using  __fsid_t __FSID_T_TYPE;	/* Type of file system IDs.  */
using __clock_t = __CLOCK_T_TYPE; /* Type of CPU usage counts.  */
using __clockid_t = __CLOCKID_T_TYPE;
using __rlim_t = __RLIM_T_TYPE;           /* Type for resource measurement.  */
using __rlim64_t = __RLIM64_T_TYPE;       /* Type for resource measurement (LFS).  */
using __id_t = __ID_T_TYPE;               /* General type for IDs.  */
using __time_t = __TIME_T_TYPE;           /* Seconds since the Epoch.  */
using __timer_t = __TIMER_T_TYPE;         /* Seconds since the Epoch.  */
using __useconds_t = __USECONDS_T_TYPE;   /* Count of microseconds.  */
using __suseconds_t = __SUSECONDS_T_TYPE; /* Signed count of microseconds.  */
using __suseconds64_t = __SUSECONDS64_T_TYPE;

using __daddr_t = __DADDR_T_TYPE; /* The type of a disk address.  */
using __key_t = __KEY_T_TYPE;     /* Type of an IPC key.  */

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

typedef long int intptr_t;
typedef unsigned long int uintptr_t;
using ptr_t = uintptr_t;
using addr_t = uintptr_t;

// portable cstdint for gcc, pp macros

using int8_t = __INT8_TYPE__;
using int16_t = __INT16_TYPE__;
using int32_t = __INT32_TYPE__;
using int64_t = __INT64_TYPE__;

using intptr_t = __INTPTR_TYPE__;
using uint8_t = __UINT8_TYPE__;
using uint16_t = __UINT16_TYPE__;
using uint32_t = __UINT32_TYPE__;
using uint64_t = __UINT64_TYPE__;
using fint8_t = __UINT_FAST8_TYPE__;
using fint16_t = __UINT_FAST16_TYPE__;
using fint32_t = __UINT_FAST32_TYPE__;
using fint64_t = __UINT_FAST64_TYPE__;

using int_least8_t = int8_t;
using uint_least8_t = uint8_t;
using int_least16_t = int16_t;
using uint_least16_t = uint16_t;
using int_least32_t = int32_t;
using uint_least32_t = uint32_t;
using int_least64_t = int64_t;
using uint_least64_t = uint64_t;

using intmax_t = __INTMAX_TYPE__;
using uintmax_t = __UINTMAX_TYPE__;
using max_t = __INTMAX_TYPE__;
using umax_t = __UINTMAX_TYPE__;
using ssize_t = max_t;
using size_t = umax_t;
using word = umax_t;

// time block
using clock_t = __clock_t;
using clockid_t = __clockid_t;
using timer_t = __timer_t;
using suseconds_t = __suseconds_t;

using time_t = __time_t;
using time64_t = time_t;
using slong_t = __SYSCALL_SLONG_TYPE;
using ulong_t = __SYSCALL_ULONG_TYPE;
using quad_t = int64_t;
using uquad_t = uint64_t;

using kernel_long_t = long;
using kernel_ulong_t = unsigned long;
using kernel_ino_t = kernel_ulong_t;
using kernel_mode_t = unsigned int;
using kernel_pid_t = int;
using kernel_ipc_pid_t = int;
using kernel_uid32_t = unsigned int;
using kernel_gid32_t = unsigned int;
using kernel_uid_t = unsigned int;
using kernel_gid_t = unsigned int;
using kernel_old_uid_t = unsigned int;
using kernel_old_gid_t = unsigned int;
using kernel_suseconds_t = kernel_long_t;
using kernel_daddr_t = int;
using kernel_old_dev_t = unsigned int;

using kernel_size_t = kernel_ulong_t;
using kernel_ssize_t = kernel_long_t;
using kernel_ptrdiff_t = kernel_long_t;

typedef kernel_long_t kernel_off_t;
typedef long long kernel_loff_t;
typedef kernel_long_t kernel_old_time_t;
typedef kernel_long_t kernel_time_t;
typedef long long kernel_time64_t;
typedef kernel_long_t kernel_clock_t;
typedef int kernel_timer_t;
typedef int kernel_clockid_t;
typedef char *kernel_caddr_t;
typedef unsigned short kernel_uid16_t;
typedef unsigned short kernel_gid16_t;

// using complex = _Complex;
// using imaginary = _Imaginary;

using c8 = char8_t;
using c16 = char16_t;
using c32 = char32_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using p8 = fint8_t;
using p16 = fint16_t;
using p32 = fint32_t;
using p64 = fint64_t;

using byte = uint8_t;
using p64 = uintptr_t;

typedef umax_t __attribute__((__may_alias__)) word;
constexpr u32 byte_width = 8;

using pnt_t = byte;
// using time_t = uint64_t;
// TODO: implement time.h

#if defined(__GNUC__) && !defined(__clang__) && defined(__cplusplus) && __cplusplus >= 202300L
using f16 = _Float16;
using f32 = _Float32;
using f64 = _Float64;
using f128 = _Float128;
#elif (defined(__clang__))
using f16 = float;
using f32 = float;
using f64 = double;
typedef long double f128;
#endif
typedef long double flong;
using ff = float;
using df = double;

using nullptr_t = decltype(nullptr);

