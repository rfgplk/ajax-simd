<img align="left" style="width:300px" src="https://github.com/user-attachments/assets/7ef7560e-3363-412e-bd38-d77d7fa921b1" alt="ajax_logo" width="300"/> 

<div align="left">

### **ajax** 🐘

#### zero-overhead (and common sense) C++ data-parallel types library
ajax is a C++23 header-only SIMD abstraction library that provides thin, zero-overhead wrappers around x86 SIMD intrinsics; allowing developers to write expressive, type-safe, and performance-critical data-parallel code.

</div>

[![License](https://img.shields.io/badge/License-Boost_1.0-lightblue.svg)](https://www.boost.org/LICENSE_1_0.txt)
[![C++23](https://img.shields.io/badge/C++-23-blue.svg)](https://en.cppreference.com/w/cpp/23)


------

<br/>

<br/>

API
----
```cpp
// all main public facing functions are found within src/simd.hpp
// where T is the bit width, and F primitive/lane width 
v128<T, F> // 128-bit SSE vectors
v256<T, F> // 256-bit AVX/AVX2 vectors
v512<T, F> // 512-bit AVX-512 vectors
// aliases
using v8 = v128<i128, __v8>;
using v16 = v128<i128, __v16>;
using v32 = v128<i128, __v32>;
using v64 = v128<i128, __v64>;
using vfloat = v128<f128, __vf>;
using vdouble = v128<d128, __vd>;

// 256bit
using w8 = v256<i256, __v8>;
using w16 = v256<i256, __v16>;
using w32 = v256<i256, __v32>;
using w64 = v256<i256, __v64>;
using wfloat = v256<f256, __vf>;
using wdouble = v256<d256, __vd>;
// 512bit
using z8 = v512<i512, __v8>;
using z16 = v512<i512, __v16>;
using z32 = v512<i512, __v32>;
using z64 = v512<i512, __v64>;
using zfloat = v512<f512, __vf>;
using zdouble = v512<d512, __vd>;

// Also supports Eigen-like naming convention
using packet16c = v128<i128, __v8>;
using packet8s = v128<i128, __v16>;
using packet4i = v128<i128, __v32>;
using packet2l = v128<i128, __v64>;
using packet4f = v128<f128, __vf>;
using packet2d = v128<d128, __vd>;

// common usage is designed to be exactly like std::array/std::vector (or other similar serial containers), with minimal differences
ajax::w32 arr = {};
arr += 5;
arr -= 20;
arr = { 5, 10, 15, 20, 25, 30, 35, 40 };
if(arr[0] == 5) // true
arr = (int)5;
arr = (char)5;
```



Features
--------
 - written for x86_64
 - C++23, header-only, zero-overhead design
 - strongly typed SIMD abstractions
 - supports 128-bit, 256-bit, and 512-bit vector widths
 - direct mapping to native x86 intrinsics
 - compile-time dispatch via concepts and constraints
 - no runtime cost, no dynamic allocation, enabling constant folding and compile time evaluation
 - minimal abstraction over intrinsic registers


Motivation
----------

<p align="justify"> 

*ajax* was developed to provide a minimal, no-nonsense SIMD layer that preserves the full power of native intrinsics while improving readability, correctness, and composability. The lack of common-sense, easily usable SIMD libraries that strike a practical balance between abstraction and control was glaring; existing solutions either expose raw intrinsics with little structure or introduce layers of indirection that impact performance while offering little value in terms of development speed.

In particular, the introduction of *std::simd* to experimental C++ was found to be overly cumbersome and, in many cases, illogical. Its design diverges significantly from natural container-like semantics, introducing complexity that makes low-level data-parallel programming harder rather than simpler. Instead of feeling like a straightforward extension of fundamental types, it often requires adapting algorithms to fit the abstraction.

<p align="justify"> 

## License
Licensed under the Boost Software License.
