#pragma once
#include "Animacao.hpp"

namespace ElementosGraficos {

	class AnimacaoEstatica : public Animacao
	{
	private:
		sf::Texture* textura;

	public:
		AnimacaoEstatica();

		virtual ~AnimacaoEstatica();

		void inicializar(const char* path, sf::Vector2f pos, sf::Vector2f tam);

		void atualizar(sf::Vector2f pos);
	};


}


