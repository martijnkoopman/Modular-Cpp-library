#if defined(FOO_SHARED)
#  if defined(__linux__) || defined(__APPLE__)
#    if defined(FOO_LIBRARY)
#      define FOO_EXPORT __attribute__((visibility("default")))
#    else
#      define FOO_EXPORT
#    endif
#  endif
#  if defined(_WIN32)
#    if defined(FOO_LIBRARY)
#      define FOO_EXPORT __declspec(dllexport)
#    else
#      define FOO_EXPORT __declspec(dllimport)
#    endif
#  endif
#else
#  define FOO_EXPORT
#endif
