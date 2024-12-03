#pragma once

#include "../include/Observer.hpp"
#include "../include/Jogador.hpp"

namespace Subject {
	namespace Observer {
		class ObserverJogador : public Observer {
		private:
			Entidade::Personagem::Jogador::Jogador* pJogador;
		public:
			ObserverJogador(Entidade::Personagem::Jogador::Jogador* pJog);
			~ObserverJogador();

			void upKeyPressed(sf::Keyboard::Key tecla);
			void upKeyReleased(sf::Keyboard::Key tecla);
		};
	}
}