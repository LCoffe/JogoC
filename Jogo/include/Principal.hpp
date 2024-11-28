#pragma once

#include "../stdafx/stdafx.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"

class Principal {
private:
	sf::RenderWindow window;
	sf::Event event;
	Jogador jogador;
	Inimigo inimigo;
public:
	Principal();
	~Principal();
	void executar();
};

