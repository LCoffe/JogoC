#ifndef ANIMACAO_HPP
#define ANIMACAO_HPP

#include "../gerenciadores/GerenciadorGrafico.hpp"
#include <SFML/Graphics.hpp>

namespace ElementosGraficos {

	class Animacao {
	protected:
		sf::RectangleShape corpo;

		static Gerenciador::GerenciadorGrafico* pGG;

	public:
		Animacao();

		virtual ~Animacao();

		virtual void desenhar();

	};


}

#endif