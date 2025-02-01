#include "../../include/elementosGraficos/animacoes/AnimacaoUnica.hpp"

namespace ElementosGraficos{



	AnimacaoUnica::AnimacaoUnica(const char* path, const unsigned int imageCount, const float switchTime) :
		imageCount(imageCount),
		imagemAtual(0),
		texture(Gerenciador::GerenciadorGrafico::getGerGrafico()->incluirTextura(path)),
		tempoTotal(0.0f),
		tamRect(),
		switchTime(switchTime) {

		if (!texture) {
			std::cerr << "Erro ao carregar textura: " << path << std::endl;
			exit(1);
		}
		tamRect.width = texture->getSize().x / float(imageCount);
		tamRect.height = texture->getSize().y;

		if (texture == nullptr) {
			std::cout << "ERRO ao carregar textura em AnimacaoUnica::AnimacaoUnica()." << std::endl;
			exit(1);
			}


		}

	AnimacaoUnica::~AnimacaoUnica(){}

	void AnimacaoUnica::atualizar(const float dt, bool olhandoEsquerda) {
		/* Baseado em --> https://www.youtube.com/watch?v=Aa8bXSq5LDE&t=196s */
		tempoTotal += dt;

		if (tempoTotal >= switchTime) {
			tempoTotal -= switchTime;
			imagemAtual++;

			if (imagemAtual >= imageCount) {
				imagemAtual = 0;
			}

		}

		if (olhandoEsquerda) {
			tamRect.left = (imagemAtual + 1) * abs(tamRect.width);
			tamRect.width = -abs(tamRect.width);

		}
		else {
			tamRect.left = imagemAtual * tamRect.width;
			tamRect.width = abs(tamRect.width);
		}

	}

	void AnimacaoUnica::resetar() {
		imagemAtual = 0;
		tempoTotal = 0;
	}

	sf::IntRect AnimacaoUnica::getTam() const {
		return tamRect;
	}

	sf::Texture* AnimacaoUnica::getTextura() const {
		return texture;
	}

}
