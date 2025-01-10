#include "../include/ListaEntidade.hpp"

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
		for (int i = 0; i < objListaEntidade.getTamanho(); i++) {
			objListaEntidade[i]->desenhar();
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
		for (int i = 0; i < tam; i++) {
			aux = objListaEntidade.operator[](i);
			if (aux != nullptr) {
				if ((aux->getID() == IDs::IDs::jogador)){
					aux = static_cast<Entidade::Personagem::Jogador::Jogador*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if ((aux->getID() == IDs::IDs::inimigo)) {
					aux = static_cast<Entidade::Personagem::Inimigo::Inimigo*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
				if ((aux->getID() == IDs::IDs::plataforma)) {
					aux = static_cast<Entidade::Obstaculos::Plataforma*>(aux);
					aux->salvar(jsonAux);
					jsonReturn.push_back(jsonAux);
				}
			}
		}
		return jsonReturn;
	}

	void ListaEntidade::carregar(nlohmann::json& j, Entidade::Personagem::Jogador::Jogador* pJog) {
		Entidade::Entidade* aux = nullptr;
		cout << "Carregando" << endl;
		
		nlohmann::json::iterator it = j.begin();
		cout << "begin" << endl;
		for (auto& it : j) {
			IDs::IDs ID = it["ID"];
			cout << (int)ID << endl;
		}

		/*for (it) {
			cout << j[i]["ID"] << endl;
			if (j[i]["ID"] == IDs::IDs::jogador) {
				sf::Vector2f pos(j[i]["posicao"]["x"], j[i]["posicao"]["y"]);
				cout << pos.x << " " << pos.y << " Jogador" << endl;
				pJog->setPos(pos);
			}
			else if (j[i]["ID"] == IDs::IDs::inimigo) {
				if (pJog == nullptr) {
					std::cout << "Jogador nao encontrado" << std::endl;
					exit(1);
				}
				sf::Vector2f pos(j[i]["posicao"]["x"], j[i]["posicao"]["y"]);
				aux = new Entidade::Personagem::Inimigo::Inimigo(pos, pJog);
			}
			else if (j[i]["ID"] == IDs::IDs::plataforma) {
				sf::Vector2f pos(j[i]["posicao"]["x"], j[i]["posicao"]["y"]);
				sf::Vector2f tam(j[i]["tamanho"]["x"], j[i]["tamanho"]["y"]);
				aux = new Entidade::Obstaculos::Plataforma(pos, tam, IDs::IDs::plataforma);
			}
			else {
				std::cout << "ID desconhecido no JSON" << std::endl;
				continue;
			}

			if (aux != nullptr) {
				inserirEnt(aux);
			}
		}*/
	}
}