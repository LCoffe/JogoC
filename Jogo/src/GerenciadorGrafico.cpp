#include "../include/GerenciadorGrafico.hpp"

namespace Gerenciador{
	GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;
	float GerenciadorGrafico::tempo = 0.0f;

	GerenciadorGrafico::GerenciadorGrafico():
		window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jogo")), relogio()
	{
		if (window == nullptr) {
			std::cerr << "Erro ao criar a janela" << std::endl;
			exit(1);
		}
	}

	GerenciadorGrafico::~GerenciadorGrafico() {}

	GerenciadorGrafico* GerenciadorGrafico::getGerGrafico() {
		//Garante que eu tenha apenas uma instancia do gerenciador grafico.
		if (pGrafico == nullptr) {
			pGrafico = new GerenciadorGrafico();
		}
		return pGrafico;
	}

	sf::Texture* GerenciadorGrafico::includeTexture(const string& path) {
		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile(path)) {
			std::cerr << "Erro ao carregar textura" << std::endl;
			exit(1);
		}
		return text;
	}

	void GerenciadorGrafico::setWindow(sf::RenderWindow* window) {
		this->window = window;
	}

	const sf::Vector2f GerenciadorGrafico::getTamWindow() const {
		return static_cast<sf::Vector2f>(window->getSize());
	}

	void GerenciadorGrafico::drawElemento(sf::RectangleShape corpo) {
		window->draw(corpo);
	}

	void GerenciadorGrafico::mostrarElementos() {
		window->display();
	}

	void GerenciadorGrafico::limpar() {
		window->clear();
	}

	const bool GerenciadorGrafico::estaAberto() {
		return window->isOpen();
	}

	void GerenciadorGrafico::fechar() {
		if (estaAberto()) {
			window->close();
		}
	}

	void GerenciadorGrafico::resetarRelogio() {
		tempo = relogio.getElapsedTime().asSeconds();
		relogio.restart();
	}

}