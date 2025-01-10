#include "../include/MenuSalvarColocacao.hpp"

namespace Menu {
	MenuSalvarColocacao::MenuSalvarColocacao() : Menu(IDs::IDs::menuSalvarColocao){
		criarTitulo();
		criarFundo();
		criarBotoes();
	}
	MenuSalvarColocacao::~MenuSalvarColocacao() {
		pFase = nullptr;
	}
	void MenuSalvarColocacao::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSalvar, sf::Vector2f(400.0f, 100.0f));
		incluiBotao(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoVoltar, sf::Vector2f(400.0f, 100.0f));
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(400.0f, 100.0f));
	}
	void MenuSalvarColocacao::criarTitulo() {
		titulo = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 3.5f), "Digite seu nome");
		titulo->setTamFonte(50);
	}

	void MenuSalvarColocacao::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
		fundo->setTexture(pGG->incluirTextura("..\\Jogo\\assets\\gamemenu.png"));
	}

	void MenuSalvarColocacao::executar() {
		desenhar();
	}
}