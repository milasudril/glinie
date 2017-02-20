//@	{
//@	 "targets":[{"name":"layerstack.hpp","type":"include"}]
//@	,"dependencies_extra":[{"ref":"layerstack.o","rel":"implementation"}]
//@	}

#ifndef PAGECOMPOSER_LAYERSTACK_HPP
#define PAGECOMPOSER_LAYERSTACK_HPP

#include "layer.hpp"
#include <vector>
#include <cstddef>

namespace PageComposer
	{
	class RenderContext;

	class LayerStack
		{
		public:
			LayerStack(RenderContext& rc) noexcept:r_rc(rc)
				{}

			void render() const noexcept;

			LayerStack& push(Layer&& l)
				{
				l.object().layerStack(*this,m_layers.size());
				m_layers.push_back(std::move(l));
				return *this;
				}


			size_t size() const noexcept
				{return m_layers.size();}

			void layersSwap(size_t a,size_t b) noexcept
				{std::swap(m_layers[a],m_layers[b]);}

			Layer& operator[](size_t k) noexcept
				{return m_layers[k];}

			const Layer& operator[](size_t k) const noexcept
				{return m_layers[k];}

		private:
			RenderContext& r_rc;
			std::vector<Layer> m_layers;
		};
	}

#endif
