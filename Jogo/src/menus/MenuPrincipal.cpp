#include "../../include/menus/MenuPrincipal.hpp"


namespace Menu {
	MenuPrincipal::MenuPrincipal() : Menu(IDs::IDs::menuPrincipal) {
		criarFundo();
		criarTitulo();
		criarBotoes();
	}
	MenuPrincipal::~MenuPrincipal() {
	}
	void MenuPrincipal::criarTitulo() {
		titulo = new Texto(sf::Vector2f(100.0f, 50.0f), "Jogo");
		if (titulo == nullptr) {
			throw std::invalid_argument("Titulo invalido");
		}
		titulo->setTamFonte(50);
	}
	void MenuPrincipal::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
		if (fundo == nullptr) {
			throw std::invalid_argument("Fundo invalido");
		}
		fundo->setTexture(pGG->incluirTextura(FUNDO_PATH));
	}
	void MenuPrincipal::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoJogar1Jog, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoJogar2Jog, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoColocacao, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoCarregar, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(120.0f, 70.0f));
		inicializaIt();
	}
	void MenuPrincipal::executar() {
		desenhar();
	}
}
