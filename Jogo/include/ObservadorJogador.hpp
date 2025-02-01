#pragma once

#include "../include/Observador.hpp"
#include "../entes/personagens/jogador/Jogador.hpp"

namespace Observado {
	namespace Observador {
		class ObservadorJogador : public Observador {
		private:
			Entidade::Personagem::Jogador::Jogador* pJogador;
			Gerenciador::GerenciadorGrafico* pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();
			float tempoAtaque;
		public:
			ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJog);
			~ObservadorJogador();

			void attTeclaPressionada(sf::Keyboard::Key tecla);
			void attTeclaUnica(sf::Keyboard::Key tecla);
		};
	}
}