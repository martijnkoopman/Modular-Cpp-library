#if defined(FOO_SHARED)
#  ifdef __linux__
#    if defined(FOO_LIBRARY)
#      define FOO_EXPORT __attribute__((visibility("default")))
#    else
#      define FOO_EXPORT
#    endif
#  endif
#  ifdef _WIN32
#    if defined(FOO_LIBRARY)
#      define FOO_EXPORT __declspec(dllexport)
#    else
#      define FOO_EXPORT __declspec(dllimport)
#    endif
#  endif
#else
#  define FOO_EXPORT
#endif
