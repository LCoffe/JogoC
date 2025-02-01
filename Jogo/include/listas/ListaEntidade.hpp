#pragma once

#include <vector>
#include "../json.hpp"
#include "Lista.hpp"
#include "../entes/Entidade.hpp"
#include "../entes/personagens/Personagem.hpp"
#include "../entes/obstaculos/Plataforma.hpp"
#include "../entes/personagens/jogador/Jogador.hpp"
#include "../entes/personagens/Inimigos/Inimigo.hpp"
#include "../entes/personagens/Inimigos/GuerreiraAthena.hpp"
#include "../entes/personagens/Inimigos/Gorgona.hpp"
#include "../entes/obstaculos/Caixa.hpp"

using namespace std;

namespace Lista {
	class ListaEntidade {
		private:
			Lista<Entidade::Entidade> objListaEntidade;
			const IDs::IDs ID;
		public:
			ListaEntidade();
			~ListaEntidade();
			void inserirEnt(Entidade::Entidade* ent);
			void removerEnt(int pos);
			const int getTamanho() const { return objListaEntidade.getTamanho(); }
			Entidade::Entidade* operator[](int i) { return objListaEntidade[i]; }
			Entidade::Entidade* getEntidade(const IDs::IDs ID);
			void limparLista();
			void desenharEntidades();
			nlohmann::json save();
			void carregar(nlohmann::json& j, Entidade::Personagem::Jogador::Jogador *pJog);
			void executar();
	};
}