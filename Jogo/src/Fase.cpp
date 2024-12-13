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
		if (ID == IDs::IDs::jogador) {
			pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
			if (pJogador == nullptr) {
				cout << "Erro ao criar jogador" << endl;
			}
			personagem = static_cast<Entidade::Entidade*>(pJogador);
		}
		if (ID == IDs::IDs::inimigo) {
			if (pJogador == nullptr) {
				cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
			}
			Entidade::Personagem::Inimigo::Inimigo* pInimigo = new Entidade::Personagem::Inimigo::Inimigo(pos, this->pJogador);
			if (pInimigo == nullptr) {
				cout << "Erro ao criar inimigo" << endl;
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
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

	void Fase::criaLimite() {
		Entidade::Entidade* entidade = nullptr;
		Entidade::Obstaculos::Plataforma* limite = nullptr;
		//Limite da Esquerda
		limite = new Entidade::Obstaculos::Plataforma(sf::Vector2f(0.1f, 768.0f), sf::Vector2f(1366.0f, 110.0f), IDs::IDs::plataforma);
		limite->getCorpo().setFillColor(sf::Color::Transparent);
		if (limite != nullptr) {
			entidade = static_cast<Entidade::Entidade*>(limite);
		}

		if (entidade != nullptr) {
			pListaObstaculo->inserirEnt(entidade);
		}
		limite = nullptr;
		entidade = nullptr;
		//Limite da Direita
		limite = new Entidade::Obstaculos::Plataforma(sf::Vector2f(1366.0f, 768.0f), sf::Vector2f(1366.0f, 110.0f), IDs::IDs::plataforma);
		limite->getCorpo().setFillColor(sf::Color::Transparent);
		if (limite != nullptr) {
			entidade = static_cast<Entidade::Entidade*>(limite);
		}

		if (entidade != nullptr) {
			pListaObstaculo->inserirEnt(entidade);
		}
	}

	void Fase::gerenciarColisoes() {
		pGC->executar();
	}

	void Fase::desenhar() {
		pListaPersona->desenharEntidades();
		pListaObstaculo->desenharEntidades();
	}
}