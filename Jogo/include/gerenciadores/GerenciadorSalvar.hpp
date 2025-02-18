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
#define CAMINHO_SAVE_TROCAFASE "./Save/saveTrocaFase.json"

namespace Fase {
	class Ponte;
	class Castelo;
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
			void salvarTrocaFase(Entidade::Personagem::Jogador::Jogador* pJog, Entidade::Personagem::Jogador::Jogador* pJogDois);
			nlohmann::json salvarObstaculo(Lista::ListaEntidade& LO);
			void salvarColocacao(string nome, int pontuacao);
			nlohmann::json carregarPersonagem();
			nlohmann::json carregarObstaculo();
			nlohmann::json carregarFase();
			nlohmann::json carregarColocacao();
			nlohmann::json carregaTrocaFase();
			void limparColocacao();

			void salvarJogo(Lista::ListaEntidade LP, Lista::ListaEntidade LO, IDs::IDs IDFase, bool doisJogadores);
			void carregarJogo(Fase::Ponte &Ponte);
			void carregarJogo(Fase::Castelo &Castelo);
			//void carregarJogo(Lista::ListaEntidade &LP, Lista::ListaEntidade &LO);
	};
}