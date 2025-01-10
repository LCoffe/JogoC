#pragma once

#include "../include/Observador.hpp"
#include "../include/Fase.hpp"
#include "../include/GerenciadorEstado.hpp"

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
		};
	}
}
