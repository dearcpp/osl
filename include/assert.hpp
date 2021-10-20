#ifndef _OSL_ASSERT_HPP_
#define _OSL_ASSERT_HPP_

# include <int_types.hpp>

OSL_BEGIN_NAMESPACE

void assert_failed(const char *file, u32 line, const char* message);

OSL_END_NAMESPACE

#endif
