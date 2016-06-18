#ifdef __WAND__
target[name[stringformat.h] type[include]]
dependency[stringformat.o]
#endif

#ifndef GLINDE_STRINGFORMAT_H
#define GLINDE_STRINGFORMAT_H

#include "variant.h"
#include "range.h"
#include <initializer_list>
#include <cstddef>

namespace Glinde
	{

	void format(const Range<char>& buffer,const char* format_string
		,const Range<const Variant>& args);

	inline void format(const Range<char>& buffer,const char* format_string
		,const std::initializer_list<Variant>& args)
		{format(buffer,format_string,Range<const Variant>(args.begin(),args.size()));}

	}

#endif