#include "../../include/elementosGraficos/animacoes/AnimacaoEstatica.hpp"
#include "../../include/gerenciadores/GerenciadorGrafico.hpp"

constexpr auto PLATAFORMA_PATH = "..\\Jogo\\assets\\plataformas\\pedra.png";

namespace ElementosGraficos {

	AnimacaoEstatica::AnimacaoEstatica():textura(nullptr){}

	AnimacaoEstatica::~AnimacaoEstatica(){}

    void AnimacaoEstatica::inicializar(const char* path, sf::Vector2f pos, sf::Vector2f tam) {
       // std::cout << "Tentando carregar textura: " << path << std::endl;

        textura = pGG->incluirTextura(path);

        if (textura == nullptr) {
            std::cerr << "Erro ao carregar textura: " << path << std::endl;
            exit(1);
        }

        textura->setRepeated(true);

        corpo.setFillColor(sf::Color::Blue);
        corpo.setSize(tam);
        corpo.setPosition(pos);
        corpo.setOrigin(tam.x / 2, tam.y / 2);
        corpo.setTexture(textura);
        corpo.setTextureRect(sf::IntRect(0, 0, static_cast<int>(corpo.getSize().x), static_cast<int>(corpo.getSize().y)));

        //std::cout << "Textura carregada com sucesso! Dimensões: "
          //  << textura->getSize().x << "x" << textura->getSize().y << std::endl;
    }


	void AnimacaoEstatica::atualizar(sf::Vector2f pos) {
		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
	}

}