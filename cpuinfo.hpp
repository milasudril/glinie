//@	{"targets":[{"name":"cpuinfo.hpp","type":"include"}]}
#ifndef GLINDE_CPUINFO_HPP
#define GLINDE_CPUINFO_HPP

/** \file cpuinfo.hpp \brief Routines for getting properties of the CPU
 */

#include <cstdint>

namespace Glinde
	{
	/**\brief Routines for getting properties of the CPU
	*/
	namespace CPUInfo
		{
		static constexpr uint16_t word_test=0x00ff;

		/**\brief Returns the endianness of the CPU.
		 *
		 * This function tests the endianness of the CPU
		 *
		 * \return A non-zero value when the CPU is big endian, and zero
		 * otherwise.
		 *
		*/
		inline bool constexpr bigEndianIs()
			{
			return ( *(reinterpret_cast<const uint8_t*>(&word_test))==0x0);
			}
		}
	}

#endif
