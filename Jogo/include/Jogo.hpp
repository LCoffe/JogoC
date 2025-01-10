#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Fase01.hpp"
#include "../include/GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "GerenciadorEstado.hpp"


class Jogo {
private:
	static Gerenciador::GerenciadorGrafico* pGG;
	static Gerenciador::GerenciadorEventos* pGE;
	static Gerenciador::GerenciadorEstado* pGEst;
	sf::Event evento;
	
public:
	Jogo();
	~Jogo();
	void executar();
};

