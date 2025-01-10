#include "../include/MenuOpcoes.hpp"

namespace Menu {
	MenuOpcoes::MenuOpcoes() : Menu(IDs::IDs::menuOpcoes), pFase(nullptr) {
		criarTitulo();
		criarFundo();
		criarBotoes();
	}

	void MenuOpcoes::criarTitulo() {
		titulo = new Texto(sf::Vector2f(100.0f, 50.0f), "Opcoes");
		if (titulo == nullptr) {
			throw std::invalid_argument("Titulo invalido");
		}
		titulo->setTamFonte(50);
	}

	void MenuOpcoes::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
		if (fundo == nullptr) {
			throw std::invalid_argument("Fundo invalido");
		}
		fundo->setTexture(pGG->incluirTextura("../Jogo/assets/gamemenu.png"));
	}

	void MenuOpcoes::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSalvar, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSalvarColocacao, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoVoltar, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoMenuPrincipal, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(120.0f, 70.0f));
		inicializaIt();
	}

	MenuOpcoes::~MenuOpcoes() {
		pFase = nullptr;
	}



	void MenuOpcoes::executar() {
		desenhar();
	}
}