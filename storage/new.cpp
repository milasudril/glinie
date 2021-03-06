/*
Glinde
Copyright (C) 2017  Torbjörn Rathsman

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/
//@	{"targets":[{"name":"new.o","type":"object"}]}

#include "memoryalloc.hpp"

using namespace Glinde;

void* operator new(size_t n_bytes)
	{return memoryAllocate(n_bytes);}

void operator delete(void* buffer)
	{memoryFree(buffer);}

void* operator new[](size_t n_bytes)
	{return memoryAllocate(n_bytes);}

void operator delete[](void* buffer)
	{memoryFree(buffer);}

void operator delete(void* buffer,size_t n)
	{memoryFree(buffer);}

void operator delete[](void* buffer,size_t n)
	{memoryFree(buffer);}
