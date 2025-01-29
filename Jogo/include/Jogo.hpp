#pragma once

#include "../stdafx/stdafx.hpp"
#include "../Fase01.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "GerenciadorEstado.hpp"
#include "Parallax.hpp"

class Jogo {
private:
	static Gerenciador::GerenciadorGrafico* pGG;
	static Gerenciador::GerenciadorEventos* pGE;
	static Gerenciador::GerenciadorEstado* pGEst;
	sf::Event evento;

	Parallax parallax;

public:
	Jogo();
	~Jogo();
	void executar();
	bool carregarRecursos();
};

