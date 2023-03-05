// --------------- Assert --------------- //
#ifdef NDEBUG

#include "Log.h"

#define CC_ASSERT(condition, message)           		\
do                                                      \
{                                                       \
	if(!(condition)) CC_FATAL(message);    				\
}                                                       \
while(0)
#else

#include <cassert>

#define CC_ASSERT(condition, message) assert(condition && message)
#endif

// --------------- Smart Pointers --------------- //

template <typename T>
using Id = std::unique_ptr<T>;

template <typename T, typename ... Args>
auto MakeId(Args&& ... args) -> decltype(auto)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using Ref = std::shared_ptr<T>;

template <typename T, typename ... Args>
auto MakeRef(Args&& ... args) -> decltype(auto)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}
