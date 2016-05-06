#ifdef __WAND__
target[name[memoryalloc.o] type[object] dependency[jemalloc;external]]
#endif

#define NDEBUG

#include "memoryalloc.h"
#include "errormessage.h"
#include "debug.h"
#include <jemalloc/jemalloc.h>

using namespace Glinie;

void* Glinie::memoryAllocate(size_t N)
	{
	void* ret=mallocx(N,MALLOCX_ALIGN(64));
	if(ret==nullptr)
		{
		throw ErrorMessage("It was not possible to allocate %zu bytes of memory"
			,N);
		}
	GLINIE_DEBUG_PRINT("Allocated %zu bytes at %p",N,ret);
	return ret;
	}

void Glinie::memoryFree(void* buffer)
	{
	if(buffer!=nullptr)
		{
		GLINIE_DEBUG_PRINT("DeAllocating %p",buffer);
		dallocx(buffer,MALLOCX_ALIGN(64));
		}
	}

void* Glinie::memoryRealloc(void* buffer,size_t N)
	{
	if(buffer==nullptr)
		{return memoryAllocate(N);}
	void* ret=rallocx(buffer,N,MALLOCX_ALIGN(64));
	if(ret==nullptr)
		{
		throw ErrorMessage("It was not possible to resize the block at %p to %zu bytes"
			,buffer,N);
		}
	return ret;
	}
