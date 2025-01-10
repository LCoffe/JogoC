#include "../include/EstadoMenu.hpp"
#include "../include/MenuPrincipal.hpp"
#include "../include/MenuOpcoes.hpp"
#include "../include/MenuSalvarColocacao.hpp"
#include "../include/MenuColocacao.hpp"

namespace Estado {
	EstadoMenu::EstadoMenu(const IDs::IDs ID) : Estado(ID), menu(nullptr) {
		criarMenu();
	}
	EstadoMenu::~EstadoMenu() {
		if (menu) {
			delete menu;
			menu = nullptr;
		}
	}

	void EstadoMenu::setFase(Fase::Fase* fase) {
		if (ID == IDs::IDs::estadoMenuOpcoes) {
			Menu::MenuOpcoes* menuOpcoes = static_cast<Menu::MenuOpcoes*>(menu);
			if (menuOpcoes != nullptr) {
				menuOpcoes->setFase(fase);
			}
		}
		else if (ID == IDs::IDs::estadoSalvarColocacao) {
			Menu::MenuSalvarColocacao* menuSalvarColocacao = static_cast<Menu::MenuSalvarColocacao*>(menu);
			if (menuSalvarColocacao != nullptr) {
				menuSalvarColocacao->setFase(fase);
			}
		}

	}

	Fase::Fase* EstadoMenu::getFase() {
		if (ID == IDs::IDs::estadoMenuOpcoes) {
			Menu::MenuOpcoes* menuOpcoes = static_cast<Menu::MenuOpcoes*>(menu);
			if (menuOpcoes != nullptr) {
				return menuOpcoes->getFase();
			}
		}
		return nullptr;
	}

	void EstadoMenu::mudarAtivoObs(const bool ativo) {
		if (ativo) {
			menu->setAtivoObs(true);
		}
		else {
			menu->setAtivoObs(false);
		}
	}

	void EstadoMenu::criarMenu() {
		if (ID == IDs::IDs::estadoMenuPrincipal) {
			Menu::MenuPrincipal* menuPrincipal = new Menu::MenuPrincipal();
			if (menuPrincipal == nullptr) {
				throw std::invalid_argument("Menu invalido");
			}
			menu = static_cast<Menu::Menu*>(menuPrincipal);
		}
		else if (ID == IDs::IDs::estadoMenuOpcoes) {
			Menu::MenuOpcoes* menuOpcoes = new Menu::MenuOpcoes();
			if (menuOpcoes == nullptr) {
				throw std::invalid_argument("Menu invalido");
			}
			menu = static_cast<Menu::Menu*>(menuOpcoes);
		}
		else if (ID == IDs::IDs::estadoSalvarColocacao) {
			Menu::MenuSalvarColocacao* menuSalvarColocacao = new Menu::MenuSalvarColocacao();
			if (menuSalvarColocacao == nullptr) {
				throw std::invalid_argument("Menu invalido");
			}
			menu = static_cast<Menu::Menu*>(menuSalvarColocacao);
		}
		else if (ID == IDs::IDs::estadoMenuColocacao) {
			Menu::MenuColocacao* menuColocacao = new Menu::MenuColocacao();
			if (menuColocacao == nullptr) {
				throw std::invalid_argument("Menu invalido");
			}
			menu = static_cast<Menu::Menu*>(menuColocacao);
		}
		else {
			throw std::invalid_argument("ID invalido");
		}
	}

	void EstadoMenu::executar() {
		menu->executar();
	}
}