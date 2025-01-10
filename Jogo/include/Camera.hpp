#pragma once

#include "../stdafx/stdafx.hpp"

namespace Gerenciador {
	class Camera {
		private:
			sf::View camera;
			sf::Vector2f tamJanela;
		public:
			Camera(sf::Vector2f tamJanela);
			~Camera();
			void setTamJanela(const sf::Vector2f& tamJanela);
			sf::Vector2f getTamJanela() const;
			void atualizar(const sf::Vector2f& pos, const sf::Vector2f tamJanela);
			sf::View getCamera() const;
	};
}