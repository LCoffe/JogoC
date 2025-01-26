#include "../../include/elementosGraficos/animacoes/Animacao.hpp"

namespace ElementosGraficos {

	Gerenciador::GerenciadorGrafico* Animacao::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

	Animacao::Animacao() : corpo() {}

	Animacao::~Animacao(){}

	void Animacao::desenhar() {
		corpo.setScale(1.0f, 1.0f);
		pGG->desenharElemento(corpo);

	}

}