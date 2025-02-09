#pragma once

#include "../../include/menus/Menu.hpp"

constexpr const char* const FUNDO_F1_PATH = "..\\Jogo\\assets\\fundos\\fundo1.png";
constexpr const char* const FUNDO_F2_PATH = "..\\Jogo\\assets\\fundos\\fundo02.png";

namespace Menu {
	class MenuSelecionaFase : public Menu {
	private:
		void criarTitulo();
		void criarFundo();
		void criarBotoes();
	public:
		MenuSelecionaFase();
		~MenuSelecionaFase();
		void executar();
	};
}