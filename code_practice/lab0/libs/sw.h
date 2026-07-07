#ifndef __LIBS_SW_H__
#define __LIBS_SW_H__

#ifndef __ASSEMBLER__

#ifdef __GNUC__

#define do_div(n, base)                                          \
    ({                                                           \
        unsigned long __n = (unsigned long)(n);                  \
        unsigned __base = (unsigned)(base);                      \
        unsigned long __quot = 0;                                \
        while (__n >= __base) {                                  \
            __n -= __base;                                       \
            __quot++;                                            \
        }                                                        \
        (n) = (unsigned long)__quot;                             \
        (unsigned)__n;                                           \
    })

#endif /* __GNUC__ */
#endif /* !__ASSEMBLER__ */
#endif /* !__LIBS_SW_H__ */
