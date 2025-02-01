#pragma once

#include "../include/Observador.hpp"
#include "../fases/Fase.hpp"
#include "../gerenciadores/GerenciadorEstado.hpp"

namespace Observado{
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
		};
	}
}
