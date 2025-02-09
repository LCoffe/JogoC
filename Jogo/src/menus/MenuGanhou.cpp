#include "../../include/menus/MenuGanhou.hpp"

namespace Menu {
	MenuGanhou::MenuGanhou() : Menu(IDs::IDs::menuGanhou) {
		criarTitulo();
		criarFundo();
		criarBotoes();
	}
	MenuGanhou::~MenuGanhou() {
		delete titulo;
		titulo = nullptr;
	}
	void MenuGanhou::criarTitulo() {
		titulo = new Texto(sf::Vector2f(pGG->getTamJanela().x / 3.1f, pGG->getTamJanela().y / 3.5f), "Voce Consquitou Athena");
		titulo->setTamFonte(50);
		titulo->setCorTexto(218, 165, 32);
		titulo->setCorBordaTexto(0, 0, 0);
	}
	void MenuGanhou::criarTextoPontuacao() {
		if (pFase != nullptr) {
			pontuacao = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 2.5f), "Pontuacao: " + std::to_string(pFase->getPontuacao()));
			pontuacao->setTamFonte(50);
			pontuacao->setCorTexto(218, 165, 32);
			pontuacao->setCorBordaTexto(0, 0, 0);
		}
	}
	void MenuGanhou::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
		fundo->setTexture(pGG->incluirTextura("..\\Jogo\\assets\\gamemenu.png"));
	}
	void MenuGanhou::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSalvarColocacao, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoMenuPrincipal, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(120.0f, 70.0f));
	}

	void MenuGanhou::executar() {
		desenhar();
		pontuacao->desenhar();
	}
}