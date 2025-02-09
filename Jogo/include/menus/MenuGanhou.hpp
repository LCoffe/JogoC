#pragma once

#include "Menu.hpp"
#include "../fases/Fase.hpp"
#include "../elementosGraficos/Texto.hpp"

namespace Menu {
	class MenuGanhou : public Menu {
	private:
		Texto* pontuacao;
		Fase::Fase* pFase;

		void criarBotoes();
		void criarTitulo();
		void criarFundo();
	public:
		MenuGanhou();
		~MenuGanhou();
		void setFase(Fase::Fase* pFase) { this->pFase = pFase; }
		Fase::Fase* getFase() { return pFase; }
		void criarTextoPontuacao();
		void executar();
	};
}