#pragma once

#include <vector>
#include "Lista.hpp"
#include "Entidade.hpp"


using namespace std;

namespace Lista {
	class ListaEntidade {
		private:
			Lista<Entidade::Entidade> objListaEntidade;
			IDs::IDs ID;
		public:
			ListaEntidade();
			~ListaEntidade();
			void inserirEnt(Entidade::Entidade* ent);
			void removerEnt(Entidade::Entidade* ent);
			const int getTamanho() const { return objListaEntidade.getTamanho(); }
			Entidade::Entidade* operator[](int i) { return objListaEntidade[i]; }
			std::vector<Entidade::Entidade*> getEntidades(IDs::IDs ID);
			void limparLista();
			void drawEntidades();
			void executar();
	};
}