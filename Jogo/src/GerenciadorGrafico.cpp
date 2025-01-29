#include "../include/GerenciadorGrafico.hpp"

namespace Gerenciador {
	GerenciadorGrafico* GerenciadorGrafico::pGG = nullptr;
	float GerenciadorGrafico::tempo = 0.0f;

	GerenciadorGrafico::GerenciadorGrafico() :
		janela(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jogo")), relogio(),
		camera(new Camera(sf::Vector2f(TELA_X, TELA_Y))), offsetParallax(0.0f)
	{
		if (janela == nullptr) {
			//std::cerr << "Erro ao criar a janela" << std::endl;
			exit(1);
		}
		sf::Image icone;
		if (!icone.loadFromFile(CAMINHO_ICONE)) {
			//std::cerr << "Erro ao carregar o icone" << std::endl;
			exit(1);
		}
		janela->setIcon(icone.getSize().x, icone.getSize().y, icone.getPixelsPtr());
		janela->setFramerateLimit(60);


	}

	GerenciadorGrafico::~GerenciadorGrafico() {}

	GerenciadorGrafico* GerenciadorGrafico::getGerGrafico() {
		//Garante que eu tenha apenas uma instancia do gerenciador grafico.
		if (pGG == nullptr) {
			pGG = new GerenciadorGrafico();
		}
		return pGG;
	}

	sf::Texture* GerenciadorGrafico::incluirTextura(const string& path) {
		sf::Texture* textura = new sf::Texture();
		if (!textura->loadFromFile(path)) {
			std::cerr << "Erro: Não foi possível carregar a textura em " << path << std::endl;
			delete textura;  // Libera memória para evitar vazamento
			return nullptr;
		}
		return textura;
	}

	void GerenciadorGrafico::setJanela(sf::RenderWindow* janela) {
		this->janela = janela;
	}

	const sf::Vector2f GerenciadorGrafico::getTamJanela() const {
		return static_cast<sf::Vector2f>(janela->getSize());
	}

	void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo) {
		janela->draw(corpo);
	}

	void GerenciadorGrafico::desenharTexto(sf::Text* texto)
	{
		if (texto) {
			janela->draw(*texto);
		}
	}

	void GerenciadorGrafico::mostrarElementos() {
		janela->display();
	}

	void GerenciadorGrafico::limpar() {
		janela->clear();
	}

	const bool GerenciadorGrafico::estaAberto() {
		return janela->isOpen();
	}

	void GerenciadorGrafico::fechar() {
		if (estaAberto()) {
			janela->close();
		}
	}

	void GerenciadorGrafico::resetarRelogio() {
		tempo = relogio.getElapsedTime().asSeconds();
		relogio.restart();
	}

	sf::Font* GerenciadorGrafico::carregarFonte(const char* path) {
		sf::Font* fonte = new sf::Font();
		if (!fonte->loadFromFile(path)) {
			std::cerr << "Erro: Não foi possível carregar a fonte em " << path << std::endl;
			delete fonte;  // Libera memória para evitar vazamento
			return nullptr;
		}
		return fonte;
	}

	void GerenciadorGrafico::atualizarCamera(const sf::Vector2f& pos, const sf::Vector2f tamJanela) {
		sf::View view = janela->getView();
		view.setSize(TELA_X, TELA_Y);
		view.setCenter(pos.x + TELA_X / 2.0f, TELA_Y / 2.0f);
		janela->setView(view);

		janela->setView(getCamera());
		camera->atualizar(pos, tamJanela);
	}

	const sf::View GerenciadorGrafico::getCamera() const {
		return camera->getCamera();
	}

	

}