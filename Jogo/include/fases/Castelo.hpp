#pragma once

#include "../../include/fases/Fase.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"

constexpr const char* const CAMINHO_TEX_FUNDO2 = "assets/fundos/fundo02.png";

namespace Fase {

	class Castelo :public Fase
	{
	private:
		sf::Texture tileset;
		sf::VertexArray tilemap;

		void criarMapa(bool doisJogadores);
		void iniciaFundo();

	public:
		Castelo();
		~Castelo();
		void iniciaFase(bool doisJogadores);
		void carregaFase();
		void carregaTrocaFase();
		void carregar();

	};


}

