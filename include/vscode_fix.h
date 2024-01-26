
#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__(attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

int iprintf(const char *, ...)
    _ATTRIBUTE((__format__(__printf__, 1, 2)));
