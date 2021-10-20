#include <assert.hpp>

#include <stdio.h>
#include <stdlib.h>

OSL_BEGIN_NAMESPACE

void assert_failed(const char *file, u32 line, const char* message)
{
    fprintf(stderr, "%s:%u: assertion failed:\n\t%s\n\t", file, line, message);
    exit(1);
}

OSL_END_NAMESPACE
