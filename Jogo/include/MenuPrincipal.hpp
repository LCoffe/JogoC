#pragma once

#include "../include/Menu.hpp"

constexpr const char* FUNDO_PATH = "..\\Jogo\\assets\\gamemenu.png";

namespace Menu {
	class MenuPrincipal : public Menu {
		private:
			void criarTitulo();
			void criarFundo();
			void criarBotoes();
		public:
			MenuPrincipal();
			~MenuPrincipal();
			void executar();
	};
}