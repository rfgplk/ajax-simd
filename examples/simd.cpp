#include "../src/simd.hpp"

#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
int
main()
{
  std::cout << "Has instruction set enabled: " << std::endl
            << "AVX-128: " << ajax::__has_avx128(ajax::__get_runtime_features()) << std::endl
            << "AVX-256: " << ajax::__has_avx256(ajax::__get_runtime_features()) << std::endl
            << "sse: " << ajax::__has_sse(ajax::__get_runtime_features()) << std::endl;

  ajax::v128<ajax::i128, ajax::__v32> v(2, 5, 7, 11);
  ajax::v128<ajax::i128, ajax::__v32> u(8, 12, 24, 45);
  // access elements
  // for(auto& n : v) <- this doesn't exist because the underlying type cannot really be "iterated" and would break
  // compat.
  //  std::cout << n << std::endl;
  std::cout << "Values of set (v): ";
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;
  // set elements
  std::cout << "Setting elements: " << std::endl;
  v = { 8, 12, 24, 45 };
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;
  v.to_zero();     // zero out entire array
  std::cout << "Zeroing out: " << std::endl;
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;
  std::cout << "Is all zeroes: " << v.all_zeroes() << std::endl;
  v.to_ones();     // set all bits to one
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;
  std::cout << "Is all ones: " << v.all_ones() << std::endl;

  std::cout << "Resetting set to { 5, 10, 25, 50 } and adding 10 to each value: " << std::endl;
  v = { 5, 10, 25, 50 };
  v += 10;     // arithmetic, add 10 to each elements
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;

  std::cout << "Subtracting 1 from each value:" << std::endl;
  v -= 1;
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;
  v -= { 5, 10, 15, 20 };     // subtract another set
  std::cout << "Subtracting another set of { 5, 10, 15, 20 }: " << std::endl;
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;
  v *= 3;
  std::cout << "After multiplication: " << std::endl;
  for ( size_t i = 0; i < v.size(); i++ ) {
    if ( static_cast<size_t>(i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  }
  std::cout << std::endl;

  // shorthand
  ajax::w32 arr32 = {};
  for ( size_t i = 0; i < 30; ++i )
    arr32 += (3 * i);
  i32 arr[8] = {};
  arr32.get(arr);     // load to primitive type
  std::cout << "C++ POD array is: " << std::endl;
  for ( size_t i = 0; i < 8; i++ )
    std::cout << arr32[i] << ", ";
  std::cout << std::endl;
  return 0;
}
#pragma GCC diagnostic pop
