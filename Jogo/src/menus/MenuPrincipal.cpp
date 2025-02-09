#include "../../include/menus/MenuPrincipal.hpp"


namespace Menu {
	MenuPrincipal::MenuPrincipal() : Menu(IDs::IDs::menuPrincipal), tituloImg(nullptr) {
		criarFundo();
		criarTitulo();
		criarBotoes();
	}
	MenuPrincipal::~MenuPrincipal() {
	}
	void MenuPrincipal::criarTitulo() {
		/*titulo = new Texto(sf::Vector2f(100.0f, 50.0f), "");
		if (titulo == nullptr) {
			throw std::invalid_argument("Titulo invalido");
		}*/
		tituloImg = new sf::RectangleShape(sf::Vector2f(400.0f, 200.0f));
		if (tituloImg == nullptr) {
			throw std::invalid_argument("Titulo invalido");
		}
		tituloImg->setTexture(pGG->incluirTextura(TITULO_PATH));
		tituloImg->setPosition(sf::Vector2f(50.0f, 0.0f));
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
		incluiBotao(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSelecionaFase, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 550.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoColocacao, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 600.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoCarregar, sf::Vector2f(120.0f, 70.0f));
		incluiBotao(sf::Vector2f(100.0f, 650.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoSair, sf::Vector2f(120.0f, 70.0f));
		inicializaIt();
	}
	void MenuPrincipal::executar() {
		desenhar();
		pGG->desenharElemento(*tituloImg);
	}
}
