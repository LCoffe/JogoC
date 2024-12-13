#pragma once

#include "GerenciadorGrafico.hpp"

#include <Math.h>
#include<SFML/Graphics.hpp>
#include<string>

#define FONT_PATH "./assets/fontes/Greek-Freak.ttf"

namespace ElementosGraficos {

	enum TextAligment {
		left,
		center,
		right

	};

	class Texto
	{
	private:
		std::string info;

		sf::Text texto;

		static Gerenciador::GerenciadorGrafico* pGG;

	public:
		Texto(const sf::Vector2f pos, std::string info = "",const char* path = FONT_PATH);

		~Texto();

		void setInfoTexto(std::string info);

		void setPosicao(sf::Vector2f pos);

		void setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B);

		void setTamFonte(const unsigned int tam);

		void setAlinhamentoTexto(TextAligment opcao);

		sf::Vector2f getTam();

		std::string getInfo() const;

		sf::Vector2f getPos() const;

		void desenhar();


	};


}


