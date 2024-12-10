#include "../include/Texto.h"

#define TEXT_SIZE 24

namespace ElementosGraficos {

	Gerenciador::GerenciadorGrafico* Texto::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

	Texto::Texto(const sf::Vector2f pos, std::string info, const char* path):info(info) {

		texto.setString(info);
		texto.setFont(*pGG->carregarFonte(path));
		texto.setCharacterSize(TEXT_SIZE);
		setAlinhamentoTexto(TextAligment::left);
		texto.setPosition(sf::Vector2f(pos.x, pos.y));
		texto.setFillColor(sf::Color::White);

	}

	Texto::~Texto() {};

	void Texto::setInfoTexto(std::string info) {

		this->info = info;
		texto.setString(this->info);

	}

	void Texto::setPosicao(sf::Vector2f pos) {
		texto.setPosition(sf::Vector2f(pos.x, pos.y));
	}


}