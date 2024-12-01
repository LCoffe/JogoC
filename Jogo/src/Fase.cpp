#include "../include/Fase.hpp"


namespace Fase {
	Entidade::Personagem::Jogador::Jogador* Fase::pJogador = nullptr;

	Fase::Fase(IDs::IDs ID_Fase) : Ente(ID_Fase) {
		pListaPersona = new Lista::ListaEntidade();
		pListaObstaculo = new Lista::ListaEntidade();

		pGC = new Gerenciador::GerenciadorColisoes(pListaPersona, pListaObstaculo);
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

		if (pListaObstaculo != nullptr) {
			delete pListaObstaculo;
		}
		pListaObstaculo = nullptr;

		if (pGC != nullptr) {
			delete pGC;
		}
		pGC = nullptr;
	}
	
	void Fase::criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID) {
		Entidade::Entidade* personagem = nullptr;
		Entidade::Personagem::Inimigo::Inimigo* pInimigo = nullptr;
		switch (ID) {
			case IDs::IDs::jogador:
				pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
				if (pJogador == nullptr) {
					cout << "Erro ao criar jogador" << endl;
				}
				personagem = static_cast<Entidade::Entidade*>(pJogador);
				break;
			case IDs::IDs::inimigo:
				if (pJogador == nullptr) {
					cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
					break;
				}
				pInimigo = new Entidade::Personagem::Inimigo::Inimigo(pos, this->pJogador);
				if (pInimigo == nullptr) {
					cout << "Erro ao criar inimigo" << endl;
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

	void Fase::criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, IDs::IDs ID) {
		Entidade::Entidade* entidade = nullptr;
		if (ID == IDs::IDs::plataforma) {
			Entidade::Obstaculos::Plataforma* plataforma = nullptr;
			plataforma = new Entidade::Obstaculos::Plataforma(pos, tam, ID);
			if (plataforma == nullptr) {
				cout << "Erro ao criar plataforma" << endl;
			}
			entidade = static_cast<Entidade::Entidade*>(plataforma);
		}

		if (entidade != nullptr) {
			pListaObstaculo->inserirEnt(entidade);
		}
	}

	void Fase::draw() {
		pListaPersona->drawEntidades();
		pListaObstaculo->drawEntidades();
	}

	void Fase::executar() {
		pJogador = getJogador();
		if (pJogador) {
			pListaPersona->executar();
			pListaObstaculo->executar();
			pGC->executar();
			draw();
		}
	}
}