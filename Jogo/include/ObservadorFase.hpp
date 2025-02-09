#pragma once

#include "../include/Observador.hpp"
#include "../fases/Fase.hpp"
#include "../gerenciadores/GerenciadorEstado.hpp"

using namespace Entidade::Personagem::Jogador;


namespace Observado {
	namespace Observador {
		class ObservadorFase : public Observador {
		private:
			Fase::Fase* pFase;
		public:
			ObservadorFase(Fase::Fase* pFase);
			~ObservadorFase();
			void attTeclaPressionada(sf::Keyboard::Key tecla);
			void attTeclaUnica(sf::Keyboard::Key tecla);
			void jogadorMorreu();
			void finalizaFase(Jogador* pJog, Jogador* pJog2, bool temInimigoVivo);
			bool verificaInimigoVivo(Lista::ListaEntidade& LP);
		};
	}
}
