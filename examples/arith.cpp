#include "../src/simd.hpp"

#include <iostream>

int
main()
{

  ajax::w64 v(1, 2, 3, 4);
  v += 10;
  unsigned long long arr[4] = { 0xff, 0xff, 0xff, 0xff };
  ajax::w64 w;
  w.uload(&arr);
  v += w;
  for ( int i = 0; i < v.size(); ++i )
    if ( (i + 1) != v.size() )
      std::cout << v[i] << ", ";
    else
      std::cout << v[i];
  std::cout << std::endl;
};
