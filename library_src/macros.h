#ifndef LINEAR_ALGEBRA_MACROS__H
#define LINEAR_ALGEBRA_MACROS__H

#include "config.h"


#if BUILDING_LINEAR_ALGEBRA_LIBRARY && HAVE_VISIBILITY
  #define LINEAR_ALGEBRA_EXPORTED_SYMBOL __attribute__((__visibility__("default")))
#elif defined _MSC_VER
  #define LINEAR_ALGEBRA_EXPORTED_SYMBOL __declspec(dllexport)
#elif defined _MSC_VER
  #define LINEAR_ALGEBRA_EXPORTED_SYMBOL __declspec(dllimport)
#else
  #define LINEAR_ALGEBRA_EXPORTED_SYMBOL
#endif


#define LINEAR_ALGEBRA_CONSTRUCTOR __attribute__((constructor)) 
#define LINEAR_ALGEBRA_DESTRUCTOR  __attribute__((destructor))  


#endif /* LINEAR_ALGEBRA_MACROS__H */


