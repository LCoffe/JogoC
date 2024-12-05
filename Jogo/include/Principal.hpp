#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Fase01.hpp"
#include "../include/GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"


class Principal {
private:
	static Gerenciador::GerenciadorGrafico* pGG;
	static Gerenciador::GerenciadorEventos* pGE;
	Fase::Fase01 fase;
	sf::Event evento;
	
public:
	Principal();
	~Principal();
	void executar();
};

