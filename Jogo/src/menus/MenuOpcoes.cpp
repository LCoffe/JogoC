#include "../../include/menus/MenuOpcoes.hpp"

constexpr const char* const CAMINHO_FUNDO_FASE1 = "assets/fundos/fundo1.png";

namespace Menu {
	MenuOpcoes::MenuOpcoes() : Menu(IDs::IDs::menuOpcoes), pFase(nullptr) {
		criarTitulo();
		criarBotoes();
		criarFundo();
	}

	void MenuOpcoes::criarTitulo() {
		titulo = new Texto(sf::Vector2f(100.0f, 50.0f), "Opcoes");
		if (titulo == nullptr) {
			throw std::invalid_argument("Titulo invalido");
		}
		titulo->setTamFonte(50);
	}

	void MenuOpcoes::criarFundo() {
	}

	void MenuOpcoes::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSalvar, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoVoltar, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoMenuPrincipal, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(120.0f, 70.0f));
		inicializaIt();
	}

	void MenuOpcoes::criaFundoParallax() {
		fundoParallax = new Fundo::Parallax();
		if (pFase->getID() == IDs::IDs::fase01) {
			fundoParallax->carregarTextura(CAMINHO_FUNDO_FASE1);
		}
		if (fundoParallax == nullptr) {
			//throw std::invalid_argument("Fundo invalido");
			exit(1);
		}
	}

	MenuOpcoes::~MenuOpcoes() {
		pFase = nullptr;
	}



	void MenuOpcoes::executar() {
		desenhar();
	}
}