#include "./pch.hpp"
#include "./base.hpp"

namespace dvo{

#ifdef NDEBUG
#else
  unsigned int debug::objCount = 0;
  unsigned int debug::objTotal = 0;
#endif


}

