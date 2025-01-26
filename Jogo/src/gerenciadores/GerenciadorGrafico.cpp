#include "../../include/gerenciadores/GerenciadorGrafico.hpp"

namespace Gerenciador{
	GerenciadorGrafico* GerenciadorGrafico::pGG = nullptr;
	float GerenciadorGrafico::tempo = 0.0f;

	GerenciadorGrafico::GerenciadorGrafico():
		janela(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jogo")), relogio(), 
		camera(new Camera(sf::Vector2f(TELA_X,TELA_Y)))
	{
		if (janela == nullptr) {
			std::cerr << "Erro ao criar a janela" << std::endl;
			exit(1);
		}
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
		view.setCenter(TELA_X / 2.0f, TELA_Y / 2.0f);
		janela->setView(view);

		camera->atualizar(pos, tamJanela);
		janela->setView(getCamera());
	}

	const sf::View GerenciadorGrafico::getCamera() const {
		return camera->getCamera();
	}

	bool GerenciadorGrafico::carregarTexturaFundo(const std::string& caminho) {
		if (!texturaFundo.loadFromFile(caminho)) {
			std::cerr << "Erro: Não foi possível carregar a textura do fundo: " << caminho << std::endl;
			return false;
		}
		texturaFundo.setRepeated(true);
		spriteFundo.setTexture(texturaFundo);
		spriteFundo.setTextureRect(sf::IntRect(0, 0, TELA_X * 2, TELA_Y));
		spriteFundo.setScale(
			static_cast<float>(TELA_X) / texturaFundo.getSize().x,
			static_cast<float>(TELA_Y) / texturaFundo.getSize().y
		);
		spriteFundo.setPosition(0, 0);

		if (!shaderParallax.loadFromMemory(
			"uniform float offset;"
			"void main() {"
			"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
			"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
			"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;"
			"    gl_FrontColor = gl_Color;"
			"}", sf::Shader::Vertex)) {
			std::cerr << "Erro ao carregar o shader de paralax!" << std::endl;
			return false;
		}

		offsetParallax = 0.f;
		return true;
	}

	void GerenciadorGrafico::atualizarParallax() {
		offsetParallax += relogio.getElapsedTime().asSeconds();  // Ajuste a velocidade conforme necessário
		shaderParallax.setUniform("offset", offsetParallax);
		relogio.restart();
	}

	void GerenciadorGrafico::desenharFundo() {
		janela->draw(spriteFundo, &shaderParallax);
	}

}