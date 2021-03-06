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
//@	 "targets":[{"name":"game.hpp","type":"include"}]
//@	,"dependencies_extra":[{"ref":"game.o","rel":"implementation"}]
//@	}

#ifndef GLINDE_GAME_HPP
#define GLINDE_GAME_HPP

#include "../harvester/directory.hpp"

namespace Glinde
	{
	class MessageQueue;

	class Game
		{
		public:
			explicit Game(MessageQueue& msgqueue,const char* filename);
			~Game();

		private:
			MessageQueue* r_msgqueue;
			Harvester::Directory m_dirtemp;
		};
	}

#endif
