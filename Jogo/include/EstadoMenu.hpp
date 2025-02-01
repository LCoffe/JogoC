#pragma once

#include "../include/Estado.hpp"
#include "../menus/Menu.hpp"
#include "../fases/Fase.hpp"

namespace Estado {
	class EstadoMenu : public Estado {
		private:
			Menu::Menu* menu;

			void criarMenu();
		public:
			EstadoMenu(const IDs::IDs ID);
			~EstadoMenu();
			void mudarAtivoObs(const bool ativo);
			void executar();
			void setFase(Fase::Fase* fase);
			Fase::Fase* getFase();
			Menu::Menu* getMenu() { return menu; }
	};
}