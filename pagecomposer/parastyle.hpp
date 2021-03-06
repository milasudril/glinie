//@	{"targets":[{"name":"parastyle.hpp","type":"include"}]}

#ifndef PAGECOMPOSER_PARASTYLE_HPP
#define PAGECOMPOSER_PARASTYLE_HPP

#include "color.hpp"
#include "textsizemode.hpp"
#include <string>

namespace PageComposer
	{
	class ParaStyle
		{
		public:
			enum class Alignment:int{LEFT,RIGHT,CENTER};
			enum class SizeDimension:int{WIDTH,HEIGHT};

			ParaStyle() noexcept:m_size(256.0)
				,m_size_dimension(SizeDimension::WIDTH)
				,m_size_mode(TextSizeMode::ABSOLUTE)
				,m_color{1,1,1,0.75}
				,m_alignment(Alignment::LEFT)
				{}

			ParaStyle& alignment(Alignment align) noexcept
				{
				m_alignment=align;
				return *this;
				}

			Alignment alignment() const noexcept
				{return m_alignment;}

			ParaStyle& size(float size_new) noexcept
				{
				m_size=size_new;
				return *this;
				}

			float size() const noexcept
				{return m_size;}

			ParaStyle& sizeDimension(SizeDimension dim) noexcept
				{
				m_size_dimension=dim;
				return *this;
				}

			SizeDimension sizeDimension() const noexcept
				{return m_size_dimension;}

			ParaStyle& color(Color c) noexcept
				{
				m_color=c;
				return *this;
				}

			Color color() const noexcept
				{return m_color;}



			ParaStyle& textSizeMode(TextSizeMode s) noexcept
				{
				m_size_mode=s;
				return *this;
				}

			TextSizeMode textSizeMode() const noexcept
				{return m_size_mode;}

		private:
			float m_size;
			SizeDimension m_size_dimension;
			TextSizeMode m_size_mode;
			Color m_color;
			Alignment m_alignment;
		};
	}

#endif
