#pragma once

#include <vector>
#include "../include/json.hpp"
#include "Lista.hpp"
#include "Entidade.hpp"
#include "Personagem.hpp"
#include "Plataforma.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "../include/GuerreiraAthena.hpp"
#include "../include/Gorgona.hpp"

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