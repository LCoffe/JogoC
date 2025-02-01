#pragma once


#include "../../stdafx/stdafx.hpp"
#include "../../include/listas/ListaEntidade.hpp"
#include "../../include/entes/personagens/Personagem.hpp"
#include "../../include/entes/personagens/jogador/Jogador.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"
#include "../../include/entes/obstaculos/Obstaculo.hpp"
#include <fstream>
#include "../../include/gerenciadores/GerenciadorEstado.hpp"
#include "../../include/json.hpp"

#define CAMINHO_SAVE_PERSONA "./Save/savePersona.json"
#define CAMINHO_SAVE_OBST "./Save/saveObst.json"
#define CAMINHO_SAVE_FASE "./Save/saveFase.json"
#define CAMINHO_SAVE_COLOCACAO "./Save/saveColocacao.json"

namespace Fase {
	class Fase01;
}

namespace Gerenciador {
	class GerenciadorSalvar {
		private:
			static GerenciadorEstado* pGEst;

			std::ofstream abreArqSave(const char* caminho);
			void fechaArqSave(std::ofstream& jsonOut);
			std::ifstream abreArqLoad(const char* caminho);
			void fechaArqLoad(std::ifstream& jsonIn);
		public:
			GerenciadorSalvar();
			~GerenciadorSalvar();

			nlohmann::json salvarPersonagem(Lista::ListaEntidade& LP);
			nlohmann::json salvarObstaculo(Lista::ListaEntidade& LO);
			void salvarColocacao(string nome, int pontuacao);
			nlohmann::json carregarPersonagem(Fase::Fase01 &Fase);
			nlohmann::json carregarObstaculo(Fase::Fase01 &Fase);
			nlohmann::json carregarFase();
			nlohmann::json carregarColocacao();
			void limparColocacao();

			void salvarJogo(Lista::ListaEntidade LP, Lista::ListaEntidade LO, IDs::IDs IDFase, bool doisJogadores);
			void carregarJogo(Fase::Fase01 &Fase);
			//void carregarJogo(Lista::ListaEntidade &LP, Lista::ListaEntidade &LO);
	};
}