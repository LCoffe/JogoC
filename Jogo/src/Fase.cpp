#include "../include/Fase.hpp"


namespace Fase {
	Entidade::Personagem::Jogador::Jogador* Fase::pJogador = nullptr;

	Fase::Fase(IDs::IDs ID_Fase) : Ente(ID_Fase) {
		pListaPersona = new Lista::ListaEntidade();
	}

	Fase::~Fase() {
		if (pListaPersona != nullptr && pJogador != nullptr) {
			delete pListaPersona;
			pJogador = nullptr;
		}
		else {
			delete pListaPersona;
		}
		pListaPersona = nullptr;
	}
	
	void Fase::criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID) {
		Entidade::Entidade* personagem = nullptr;
		Entidade::Personagem::Inimigo::Inimigo* pInimigo = nullptr;
		switch (ID) {
			case IDs::IDs::jogador:
				pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
				if (pJogador == nullptr) {
					std::cout << "Erro ao criar jogador" << std::endl;
				}
				personagem = static_cast<Entidade::Entidade*>(pJogador);
				break;
			case IDs::IDs::inimigo:
				if (pJogador == nullptr) {
					std::cout << "Erro ao criar inimigo, jogador nao foi criado" << std::endl;
					break;
				}
				pInimigo = new Entidade::Personagem::Inimigo::Inimigo(pos, this->pJogador);
				if (pInimigo == nullptr) {
					std::cout << "Erro ao criar inimigo" << std::endl;
					break;
				}
				personagem = static_cast<Entidade::Entidade*>(pInimigo);
				break;
			default:
				break;
		}
		if (personagem != nullptr) {
			pListaPersona->inserirEnt(personagem);

		}
	}

	void Fase::draw() {
		pListaPersona->drawEntidades();
	}

	void Fase::executar() {
		pJogador = getJogador();
		if (pJogador) {
			pListaPersona->executar();
		}
	}
}