//@	{
//@	    "dependencies_extra":[],
//@	    "targets":[
//@	        {
//@	            "dependencies":[],
//@	            "name":"filein.o",
//@	            "type":"object"
//@	        }
//@	    ]
//@	}
#include "filein.h"
#include "errormessage.h"
#include "strerror.h"
#include "variant.h"

#define _FILE_OFFSET_BITS 64

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

using namespace Glinde;

FileIn::FileIn(const char* filename):m_name(filename)
	{
	static_assert(sizeof(m_handle)>=sizeof(int),"Handle is too small");
	m_handle=open(filename,O_RDONLY,S_IRUSR|S_IWUSR);
	if(m_handle==-1)
		{
		char errbuff[256];
		strerror(errno,errbuff,256);
		throw ErrorMessage("It was not possible to open the file #0;. #1;"
			,{filename,errbuff});
		}
	}

FileIn::~FileIn()
	{
	fsync(static_cast<int>(m_handle));
	close(static_cast<int>(m_handle));
	}

size_t FileIn::read(void* buffer,size_t count)
	{
	auto pos=reinterpret_cast<uint8_t*>(buffer);
	size_t n_read=0;
	while(n_read!=count)
		{
		auto n=::read(static_cast<int>(m_handle),pos,count-n_read);
		if(n==0)
			{return n_read;}
		if(n==-1)
			{throw ErrorMessage("I/O error",{});}
		pos+=n;
		n_read+=n;
		}
	return n_read;
	}

