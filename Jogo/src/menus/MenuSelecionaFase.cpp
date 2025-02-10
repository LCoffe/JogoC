#include "../../include/menus/MenuSelecionaFase.hpp"

namespace Menu {
	MenuSelecionaFase::MenuSelecionaFase() : Menu(IDs::IDs::menuSelecionaFase) {
		criarTitulo();
		criarFundo();
		criarBotoes();
	}
	MenuSelecionaFase::~MenuSelecionaFase() {
	}
	void MenuSelecionaFase::criarTitulo() {
		titulo = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 3.5f), "Selecione a fase");
		titulo->setTamFonte(50);
		titulo->setCorTexto(218, 165, 32);
		titulo->setCorBordaTexto(0, 0, 0);
	}
	void MenuSelecionaFase::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
	}
	void MenuSelecionaFase::criarBotoes() {
		incluiBotao(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoPonteJog1, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 450.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoPonteJog2, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoCasteloJog1, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoCasteloJog2, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoVoltar, sf::Vector2f(120.0f, 70.0f));
	}
	void MenuSelecionaFase::executar() {
		for (auto& it : botoes) {
			if (it->getSelecionado() && (IDs::IDs::botaoPonteJog1 == it->getID() || IDs::IDs::botaoPonteJog2 == it->getID())) {
				fundo->setTexture(pGG->incluirTextura(FUNDO_F1_PATH));
			}
			else if (it->getSelecionado() && (IDs::IDs::botaoCasteloJog1 == it->getID() || IDs::IDs::botaoCasteloJog2 == it->getID())) {
				fundo->setTexture(pGG->incluirTextura(FUNDO_F2_PATH));
			}
		}
		desenhar();
	}
}