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
//@	{
//@	 "dependencies_extra":[{"ref":"errormessage.o","rel":"implementation"}]
//@	,"targets":[{"name":"errormessage.hpp","type":"include"}]
//@	}
#ifndef GLINDE_ERRORMESSAGE_HPP
#define GLINDE_ERRORMESSAGE_HPP

/**\file errormessage.hpp \brief Defines an error message.
 */

#include "storage/arrayfixed.hpp"
#include <initializer_list>

namespace Glinde
	{
	class Variant;

	/**\brief Class representing a formated error message.
	 *
	 * The exception handling within Glinde is based on throwing ErrorMessage
	 * objects. An ErrorMessage contains a formated string describing the
	 * exception in a user-friendly way. Typically, the message is formated at
	 * the point where the exception is thrown. The message can then be catched
	 * and displayed to the user.
	 *
	 */
	class ErrorMessage
		{
		public:
			ErrorMessage() noexcept
				{}

			/**\brief Initializes an ErrorMessage.
			 *
			 * This constructor initializes the ErrorMessage. The format string
			 * follows the syntax of format.
			 *
			 * \note If the message does not fit within the internal buffer, it
			 * is truncated, but always zero terminated. However, this should
			 * not be a problem, since it is not useful with to long messages
			 * anyways.
			 *
			*/
			explicit ErrorMessage(const char* format_string
				,const std::initializer_list<Variant>& args) noexcept;


			/**\brief Retrievs a pointer to the error message.
			 *
			 * This function returns a pointer to the error message.
			*/
			const char* messageGet() const noexcept
				{return m_buffer.begin();}


		private:
			ArrayFixed<char,1024> m_buffer;
		};
	}

#endif
