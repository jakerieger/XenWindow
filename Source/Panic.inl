#include <cstdio>
#include <cstdlib>
#include <cstdarg>

[[noreturn]] inline void Panic(
  const char* file, const int line, const char* func, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char msg[512];
    snprintf(msg, 512, fmt, args);
    msg[511] = {'\0'};
    fprintf(stderr,
            "%s:%d\nPanic:\n  In: %s\n  Message: %s\n",
            file,
            line,
            func,
            msg);
    std::abort();
}
