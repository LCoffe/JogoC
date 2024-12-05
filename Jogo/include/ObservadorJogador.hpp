#pragma once

#include "../include/Observador.hpp"
#include "../include/Jogador.hpp"

namespace Observado {
	namespace Observador {
		class ObservadorJogador : public Observador {
		private:
			Entidade::Personagem::Jogador::Jogador* pJogador;
		public:
			ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJog);
			~ObservadorJogador();

			void upTeclaPressionada(sf::Keyboard::Key tecla);
			void upTeclaUnica(sf::Keyboard::Key tecla);
		};
	}
}