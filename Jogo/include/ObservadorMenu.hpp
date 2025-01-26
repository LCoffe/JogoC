#pragma once

#include "../include/Observador.hpp"
#include "../menus/Menu.hpp"
#include "../fases/Fase.hpp"
#include "../gerenciadores/GerenciadorEstado.hpp"

namespace Observado {
	namespace Observador {
		class ObservadorMenu: public Observador {
			private:
				static Gerenciador::GerenciadorGrafico* pGG;
				Gerenciador::GerenciadorSalvar* pGS;
				Menu::Menu* pMenu;
			public:
				ObservadorMenu(Menu::Menu* Menu);
				~ObservadorMenu();

				void attTeclaPressionada(sf::Keyboard::Key tecla);
				void attTeclaUnica(sf::Keyboard::Key tecla);
		};
	}
}