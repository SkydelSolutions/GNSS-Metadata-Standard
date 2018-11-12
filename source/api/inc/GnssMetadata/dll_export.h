#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #ifdef api_EXPORTS
    #ifdef __GNUC__
      #define API_DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define API_DLL_PUBLIC __declspec(dllexport)
    #endif
  #else
    #ifdef __GNUC__
      #define API_DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define API_DLL_PUBLIC __declspec(dllimport)
    #endif
  #endif
  #define API_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define API_DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define API_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define API_DLL_PUBLIC
    #define API_DLL_LOCAL
  #endif
#endif