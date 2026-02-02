//  Copyright (c) 2024- David Lucius Severus
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
#pragma once

#include "namespace.hpp"

#include "intrin.hpp"

namespace ajax
{

using __vf = float;
using __vd = double;
using __v8 = i8;
using __v16 = i16;
using __v32 = i32;
using __v64 = i64;

using b64 = __m64;
using f128 = __m128;
using d128 = __m128d;
using i128 = __m128i;
using f256 = __m256;
using d256 = __m256d;
using i256 = __m256i;
using f512 = __m512;
using d512 = __m512d;
using i512 = __m512i;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
template <typename T>
concept is_simd_type
    = stdlib::same_as<T, b64> or stdlib::same_as<T, f128> or stdlib::same_as<T, d128> or stdlib::same_as<T, i128>
      or stdlib::same_as<T, f256> or stdlib::same_as<T, d256> or stdlib::same_as<T, i256> or stdlib::same_as<T, f512>
      or stdlib::same_as<T, d512> or stdlib::same_as<T, i512>;
template <typename T>
concept is_simd_128_type = stdlib::same_as<T, f128> or stdlib::same_as<T, d128> or stdlib::same_as<T, i128>;
template <typename T>
concept is_simd_256_type = stdlib::same_as<T, f256> or stdlib::same_as<T, d256> or stdlib::same_as<T, i256>;
template <typename T>
concept is_simd_512_type = stdlib::same_as<T, f512> or stdlib::same_as<T, d512> or stdlib::same_as<T, i512>;
template <typename T>
concept is_int_flag_type
    = stdlib::same_as<T, __v8> or stdlib::same_as<T, __v16> or stdlib::same_as<T, __v32> or stdlib::same_as<T, __v64>;

template <typename T>
concept is_flag_type = stdlib::same_as<T, __vd> or stdlib::same_as<T, __vf> or stdlib::same_as<T, __v8>
                       or stdlib::same_as<T, __v16> or stdlib::same_as<T, __v32> or stdlib::same_as<T, __v64>;

#pragma GCC diagnostic pop
};
