#pragma once

#include "Menu.hpp"
#include "../fases/Fase.hpp"
#include "../elementosGraficos/Texto.hpp"

namespace Menu {
	class MenuMorreu : public Menu {
	private:
		Fase::Fase* pFase;
		Texto* pontuacao;

		void criarBotoes();
		void criarTitulo();
		void criarFundo();
	public:
		MenuMorreu();
		~MenuMorreu();
		void criarTextoPontuacao();
		void setFase(Fase::Fase* pFase) { this->pFase = pFase; }
		Fase::Fase* getFase() { return pFase; }
		void executar();
	};
}