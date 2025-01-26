#pragma once

#include "../stdafx/stdafx.hpp"
#include "../fases/Fase01.hpp"
#include "../gerenciadores/GerenciadorEventos.hpp"
#include "../entes/personagens/jogador/Jogador.hpp"
#include "../entes/personagens/Inimigos/Inimigo.hpp"
#include "../gerenciadores/GerenciadorEstado.hpp"


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
	bool carregarRecursos();
};

