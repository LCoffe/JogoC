#pragma once

#include "Menu.hpp"

constexpr const char* FUNDO_PATH = "..\\Jogo\\assets\\gamemenu.png";
constexpr const char* TITULO_PATH = "..\\Jogo\\assets\\icone\\tituloJogo.png";

namespace Menu {
	class MenuPrincipal : public Menu {
		private:
			sf::RectangleShape* tituloImg;

			void criarTitulo();
			void criarFundo();
			void criarBotoes();
		public:
			MenuPrincipal();
			~MenuPrincipal();
			void executar();
	};
}