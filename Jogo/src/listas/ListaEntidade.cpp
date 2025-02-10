#include "../../include/listas/ListaEntidade.hpp"

namespace Lista {
	ListaEntidade::ListaEntidade() : objListaEntidade(), ID() {}

	ListaEntidade::~ListaEntidade() {}

	void ListaEntidade::inserirEnt(Entidade::Entidade* ent) { objListaEntidade.inserir(ent); }

	void ListaEntidade::removerEnt(int pos) { objListaEntidade.removerElemento(pos); }

	Entidade::Entidade* ListaEntidade::getEntidade(IDs::IDs ID) {
		std::vector<Entidade::Entidade*> entidades;
		for (int i = 0; i < objListaEntidade.getTamanho(); i++) {
			if (objListaEntidade[i]->getID() == ID) {
				return objListaEntidade[i];
			}
		}
		return nullptr;
	}

	void ListaEntidade::limparLista() { objListaEntidade.limpar(); }

	void ListaEntidade::desenharEntidades() {
		Entidade::Entidade* aux = nullptr;
		for (Lista<Entidade::Entidade>::Iterator it = objListaEntidade.begin(); it != objListaEntidade.end(); ++it) {
			aux = *it;
			if (aux != nullptr) {
				aux->desenhar();
			}
		}
	}

    void ListaEntidade::executar() {
		int tam = objListaEntidade.getTamanho();
		Entidade::Entidade* aux = nullptr;
		for (int i = tam - 1; i >= 0; i--) {
			aux = objListaEntidade.operator[](i);
			if (aux != nullptr) {
				if (aux->getRemover()) {
					removerEnt(i);
					aux = nullptr;
				}
				else {
					aux->atualizar();
				}
			}
		}
    }

	nlohmann::json ListaEntidade::save() {
		int tam = objListaEntidade.getTamanho();
		Entidade::Entidade* aux = nullptr;
		nlohmann::json jsonAux;
		nlohmann::json jsonReturn;
		for (Lista<Entidade::Entidade>::Iterator it = objListaEntidade.begin(); it != objListaEntidade.end(); ++it) {
			aux = *it;
			if (aux != nullptr) {
				if ((aux->getID() == IDs::IDs::jogador)){
					aux = static_cast<Entidade::Personagem::Jogador::Jogador*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if ((aux->getID() == IDs::IDs::guerreiraAthena)) {
					aux = static_cast<Entidade::Personagem::Inimigo::GuerreiraAthena*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if (aux->getID() == IDs::IDs::gorgona) {
					aux = static_cast<Entidade::Personagem::Inimigo::Gorgona*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if (aux->getID() == IDs::IDs::minotauro) {
					aux = static_cast<Entidade::Personagem::Inimigo::Minotauro*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if ((aux->getID() == IDs::IDs::caixa)) {
					aux = static_cast<Entidade::Obstaculos::Caixa*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if (aux->getID() == IDs::IDs::espinho) {
					aux = static_cast<Entidade::Obstaculos::Espinho*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if (aux->getID() == IDs::IDs::portao) {
					aux = static_cast<Entidade::Obstaculos::Portao*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if (aux->getID() == IDs::IDs::maocondenados) {
					aux = static_cast<Entidade::Obstaculos::MaoCondenados*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
			}
		}
		return jsonReturn;
	}
}