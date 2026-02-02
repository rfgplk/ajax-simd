#pragma once

//  Copyright (c) 2024- David Lucius Severus
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
// set default lib usage

#ifdef __AJAX_MICRON
#include <micron/__special/initializer_list>
#include <micron/concepts.hpp>
#include <micron/type_traits.hpp>
#include <micron/types.hpp>
#else
#include "types_mc.hpp"
#include <concepts>
#include <initializer_list>
#include <type_traits>
#endif

namespace stdlib
{
#ifdef __AJAX_MICRON
using namespace micron;
#else
using namespace std;
#endif
};
