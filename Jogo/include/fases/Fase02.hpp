#pragma once

#include "../../include/fases/Fase.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"

constexpr const char* const CAMINHO_TEX_FUNDO2 = "assets/fundos/fundo02.png";

namespace Fase {

	class Fase02:public Fase
	{
	private:
		sf::Texture tileset;
		sf::VertexArray tilemap;

		void criarMapa(bool doisJogadores);
		void iniciaFundo();

	public:
		Fase02();
		~Fase02();
		void iniciaFase(bool doisJogadores);
		void carregaFase();
		void carregaTrocaFase();
		void carregar();

	};


}

