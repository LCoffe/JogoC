#pragma once

#include "Menu.hpp"
#include "../fases/Fase.hpp"
#include "../elementosGraficos/Texto.hpp"

namespace Menu {
	class MenuSalvarColocacao : public Menu {
		private:
			Fase::Fase* pFase;
			Texto* nome;

			void criarBotoes();
			void criarTitulo();
			void criarFundo();
		public:
			MenuSalvarColocacao();
			~MenuSalvarColocacao();
			void setFase(Fase::Fase* pFase) { this->pFase = pFase; }
			Fase::Fase* getFase() { return pFase; }
			void executar();
	};
}