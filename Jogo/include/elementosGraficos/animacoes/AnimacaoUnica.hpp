#pragma once

#include "../gerenciadores/GerenciadorGrafico.hpp"
#include <SFML/Graphics.hpp>

namespace ElementosGraficos {

	class AnimacaoUnica
	{
	private:
		const unsigned int imageCount;
		unsigned int imagemAtual;
		sf::Texture* texture;
		float tempoTotal;
		sf::IntRect tamRect;
		const float switchTime;

	public:
		AnimacaoUnica(const char* path, const unsigned int imageCount, const float switchTime);

		~AnimacaoUnica();

		void atualizar(const float dt, bool olhandoEsquerda);

		void resetar();

		sf::IntRect getTam() const;

		sf::Texture* getTextura()const;
	};


}


