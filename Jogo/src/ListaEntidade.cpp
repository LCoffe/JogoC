#include "../include/ListaEntidade.hpp"

namespace Lista {
	ListaEntidade::ListaEntidade() : objListaEntidade(), ID() {}

	ListaEntidade::~ListaEntidade() { limparLista(); }

	void ListaEntidade::inserirEnt(Entidade::Entidade* ent) { objListaEntidade.inserir(ent); }

	void ListaEntidade::removerEnt(Entidade::Entidade* ent) { objListaEntidade.remover(ent); }

	std::vector<Entidade::Entidade*> ListaEntidade::getEntidades(IDs::IDs ID) {
		std::vector<Entidade::Entidade*> entidades;
		for (int i = 0; i < objListaEntidade.getTamanho(); i++) {
			if (objListaEntidade[i]->getID() == ID) {
				entidades.push_back(objListaEntidade[i]);
			}
		}
		return entidades;
	}

	void ListaEntidade::limparLista() { objListaEntidade.limpar(); }

	void ListaEntidade::desenharEntidades() {
		for (int i = 0; i < objListaEntidade.getTamanho(); i++) {
			objListaEntidade[i]->desenhar();
		}
	}

	void ListaEntidade::executar() {
		int tam = objListaEntidade.getTamanho();
		Entidade::Entidade* aux = nullptr;
		for (int i = 0; i < tam; i++) {
			aux = objListaEntidade[i];
			if (aux != nullptr) {
				aux->atualizar();
			}
		}
	}
}