#include "../../include/menus/MenuMorreu.hpp"

namespace Menu {
	MenuMorreu::MenuMorreu() : Menu(IDs::IDs::menuMorreu) {
		criarTitulo();
		criarFundo();
		criarBotoes();
	}
	MenuMorreu::~MenuMorreu() {
		delete titulo;
		titulo = nullptr;
	}
	void MenuMorreu::criarTitulo() {
		titulo = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 3.5f), "Voce Morreu");
		titulo->setTamFonte(50);
	}
	void MenuMorreu::criarTextoPontuacao() {
		if (pFase != nullptr) {
			pontuacao = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 2.5f), "Pontuacao: " + std::to_string(pFase->getPontuacao()));
			pontuacao->setTamFonte(50);
		}
	}
	void MenuMorreu::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
		fundo->setTexture(pGG->incluirTextura("..\\Jogo\\assets\\gamemenu.png"));
	}
	void MenuMorreu::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSalvarColocacao, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoMenuPrincipal, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(120.0f, 70.0f));
	}
	void MenuMorreu::executar() {
		desenhar();
		pontuacao->desenhar();
	}
}