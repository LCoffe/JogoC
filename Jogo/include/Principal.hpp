#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Fase01.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"


class Principal {
private:
	static Gerenciador::GerenciadorGrafico* pGG;
	Fase::Fase01 fase;
	sf::Event event;
	
public:
	Principal();
	~Principal();
	void executar();
};
