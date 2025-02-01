#pragma once

#include "Menu.hpp"
#include "../fases/Fase.hpp"

namespace Menu {
	class MenuOpcoes : public Menu {
		private:
			Fase::Fase* pFase;

			void criarTitulo();
			void criarFundo();
			void criarBotoes();
		public:
			MenuOpcoes();
			~MenuOpcoes();
			void setFase(Fase::Fase* pFase) { this->pFase = pFase; }
			Fase::Fase* getFase() { return pFase; }
			void criaFundoParallax();
			void executar();
	};
}