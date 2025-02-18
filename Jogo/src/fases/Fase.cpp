#include "../../include/fases/Fase.hpp"
#include "../../include/ObservadorFase.hpp"
#include "../../include/elementosGraficos/Texto.hpp"

namespace Fase {
	Entidade::Personagem::Jogador::Jogador* Fase::pJogador = nullptr;
	Entidade::Personagem::Jogador::Jogador* Fase::pJogadorDois = nullptr;

	Fase::Fase(IDs::IDs ID_Fase) : Ente(ID_Fase), pGS(new Gerenciador::GerenciadorSalvar()), pObsFase(new Observado::Observador::ObservadorFase(this)), doisJogadores(false), pontuacao(0), fundo(nullptr), mapa(nullptr), temInimigoVivo(true) {
		pListaPersona = new Lista::ListaEntidade();
		pListaObstaculo = new Lista::ListaEntidade();

		pGC = new Gerenciador::GerenciadorColisoes(pListaPersona, pListaObstaculo);
	}

	Fase::~Fase() {
		if (pListaPersona != nullptr && pJogador != nullptr) {
			delete pListaPersona;
			pJogador = nullptr;
			if (pJogadorDois != nullptr) {
				pJogadorDois = nullptr;
			}
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

		if (pGS != nullptr) {
			delete pGS;
		}

		if (fundo != nullptr) {
			delete fundo;
		}

		if (pObsFase != nullptr) {
			delete pObsFase;
		}

		if (mapa != nullptr) {
			delete mapa;
		}
	}

	void Fase::criaPersonagem1Jog(const sf::Vector2f pos, const IDs::IDs ID) {
		Entidade::Entidade* personagem = nullptr;
		Entidade::Entidade* pArma = nullptr;
		Entidade::Entidade* pArma2 = nullptr;
		if (ID == IDs::IDs::jogador) {
			pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
			if (pJogador == nullptr) {
				exit(1);
			}
			pJogador->setJogadorUm(true);
			pJogador->inicializarBarraVida();
			Entidade::Item::Projetil* aux = new Entidade::Item::Projetil(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f));
			Entidade::Item::Arma* armaJog2 = static_cast<Entidade::Item::Arma*>(aux);
			Entidade::Item::Arma* armaJog1 = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
			pJogador->operator+=(armaJog1);
			pJogador->operator+=(armaJog2);
			personagem = static_cast<Entidade::Entidade*>(pJogador);
			pArma = static_cast<Entidade::Entidade*>(armaJog1);
			pArma2 = static_cast<Entidade::Entidade*>(armaJog2);
		}
		else if (ID == IDs::IDs::guerreiraAthena) {
			if (pJogador == nullptr) {
				exit(1);
			}
			Entidade::Personagem::Inimigo::GuerreiraAthena* pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, this->pJogador);
			Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo);
			pArma = static_cast<Entidade::Entidade*>(armaInim);

			if (pInimigo == nullptr) {
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		else if (ID == IDs::IDs::gorgona) {
			if (pJogador == nullptr) {
				exit(1);
			}
			Entidade::Personagem::Inimigo::Gorgona* pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, this->pJogador);
			Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona);
			pArma = static_cast<Entidade::Entidade*>(armaInim);

			if (pInimigo == nullptr) {
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		else if (ID == IDs::IDs::minotauro) {
			if (pJogador == nullptr) {
				exit(1);
			}
			Entidade::Personagem::Inimigo::Minotauro* pInimigo = new Entidade::Personagem::Inimigo::Minotauro(pos, this->pJogador);
			Entidade::Item::Projetil* armaInim = new Entidade::Item::Projetil(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(30.0f, 30.0f));
			pArma = static_cast<Entidade::Entidade*>(armaInim);
			if (pInimigo == nullptr) {
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		if (personagem != nullptr) {
			pListaPersona->inserirEnt(personagem);
			if (pArma != nullptr) {
				pListaPersona->inserirEnt(pArma);
			}
			if (pArma2 != nullptr) {
				pListaPersona->inserirEnt(pArma2);
			}
		}
	}

	void Fase::criaPersonagem2Jog(const sf::Vector2f pos, const IDs::IDs ID, bool jogadorUm) {
		Entidade::Entidade* personagem = nullptr;
		Entidade::Entidade* pArma = nullptr;
		if (ID == IDs::IDs::jogador) {
			if (jogadorUm) {
				pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
				if (pJogador == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				pJogador->setJogadorUm(true);
				pJogador->inicializarBarraVida();
				Entidade::Item::Arma* armaJog = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
				pJogador->operator+=(armaJog);
				personagem = static_cast<Entidade::Entidade*>(pJogador);
				pArma = static_cast<Entidade::Entidade*>(armaJog);
			}
			else {
				doisJogadores = true;
				pJogadorDois = new Entidade::Personagem::Jogador::Jogador(pos);
				pJogadorDois->inicializarBarraVida();
				if (pJogadorDois == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				Entidade::Item::Projetil* aux = new Entidade::Item::Projetil(static_cast<Entidade::Personagem::Personagem*>(pJogadorDois), sf::Vector2f(10.0f, 10.0f));
				Entidade::Item::Arma* armaJog = static_cast<Entidade::Item::Arma*>(aux);
				pJogadorDois->operator+=(armaJog);
				personagem = static_cast<Entidade::Entidade*>(pJogadorDois);
				pArma = static_cast<Entidade::Entidade*>(armaJog);
			}
		}
		else if (ID == IDs::IDs::guerreiraAthena) {
			if (pJogador == nullptr || pJogadorDois == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::GuerreiraAthena* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, this->pJogador, this->pJogadorDois);
			Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo);
			pArma = static_cast<Entidade::Entidade*>(armaInim);

			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		else if (ID == IDs::IDs::gorgona) {
			if (pJogador == nullptr || pJogadorDois == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Gorgona* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, this->pJogador, this->pJogadorDois);
			Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona);
			pArma = static_cast<Entidade::Entidade*>(armaInim);

			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		else if (ID == IDs::IDs::minotauro) {
			if (pJogador == nullptr || pJogadorDois == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Minotauro* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::Minotauro(pos, this->pJogador, this->pJogadorDois);
			Entidade::Item::Projetil* armaInim = new Entidade::Item::Projetil(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(30.0f, 30.0f));
			pArma = static_cast<Entidade::Entidade*>(armaInim);
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		if (personagem != nullptr) {
			pListaPersona->inserirEnt(personagem);
			if (pArma != nullptr) {
				pListaPersona->inserirEnt(pArma);
			}
		}
	}

	void Fase::carregaPersonagem1Jog(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, int armaAtual, sf::Vector2f posArma, const IDs::IDs IDArma, sf::Vector2f velArma, bool colidiu, bool direcaoArma, bool ativo, bool atacando, bool petrifica, bool levandoDano
		, float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao, bool colisaoChao) { //Usado para carregar os personagens
		Entidade::Entidade* personagem = nullptr;
		Entidade::Entidade* arma = nullptr;
		Entidade::Entidade* armaDois = nullptr;
		if (ID == IDs::IDs::jogador) {
			pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
			if (pJogador == nullptr) {
				//cout << "Erro ao criar jogador" << endl;
				exit(1);
			}
			Entidade::Item::Arma* pArma = nullptr;
			Entidade::Item::Arma* pArmaDois = nullptr;
			if (IDArma == IDs::IDs::projetil) {
				pArmaDois = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
				pArmaDois->setPos(sf::Vector2f(-500.0f, -500.0f));
				pArma = carregaArma(pJogador, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::projetil, colidiu, direcaoArma, velArma, false, ativo);
				pJogador->operator+=(pArmaDois);
				pJogador->operator+=(pArma);
			}
			else {
				pArmaDois = new Entidade::Item::Projetil(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f));
				pArmaDois->setPos(sf::Vector2f(-500.0f, -500.0f));
				pArma = carregaArma(pJogador, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador, false, false, sf::Vector2f(0.0f, 0.0f), false, false);
				pJogador->operator+=(pArma);
				pJogador->operator+=(pArmaDois);
			}
			if (pArma == nullptr || pArmaDois == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pJogador == nullptr) {
				//cout << "Erro ao criar jogador" << endl;
				exit(1);
			}
			try {
				pJogador->setTam(tam);
				pJogador->setVelocidade(vel);
				pJogador->setDirecao(direcao);
				pJogador->setJogadorUm(jogadorUm);
				pJogador->setVida(vida);
				pJogador->setTempoAtaque(tempoAtaque);
				pJogador->atacar(atacando);
				pJogador->setPetrificado(petrifica);
				pJogador->setLevandoDano(levandoDano);
				pJogador->setTempoDano(tempoDano);
				pJogador->setMorrendo(morrendo);
				pJogador->setTempoMorte(tempoMorrendo);
				pJogador->addPontuacao(pontuacao);
				pJogador->setColisaoChao(colisaoChao);
				pJogador->inicializarBarraVida();
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}
			pJogador->setAtivoObs(true);
			personagem = static_cast<Entidade::Entidade*>(pJogador);
			arma = static_cast<Entidade::Entidade*>(pArma);
			armaDois = static_cast<Entidade::Entidade*>(pArmaDois);
		}
		else if (ID == IDs::IDs::guerreiraAthena) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::GuerreiraAthena* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, pJogador);
			Entidade::Item::Arma* pArma = carregaArma(pInimigo, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo, false, false, sf::Vector2f(0.0f, 0.0f), false, false);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			try {
				pInimigo->setTam(tam);
				pInimigo->setVelocidade(vel);
				pInimigo->setDirecao(direcao);
				pInimigo->setVida(vida);
				pInimigo->setTempoAtaque(tempoAtaque);
				pInimigo->atacar(atacando);
				pInimigo->setLevandoDano(levandoDano);
				pInimigo->setTempoDano(tempoDano);
				pInimigo->setMorrendo(morrendo);
				pInimigo->setTempoMorte(tempoMorrendo);
				pInimigo->setColisaoChao(colisaoChao);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}

			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		else if (ID == IDs::IDs::gorgona) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Gorgona* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, pJogador);
			Entidade::Item::Arma* pArma = carregaArma(pInimigo, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona, false, false, sf::Vector2f(0.0f, 0.0f), petrifica, false);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			try {
				pInimigo->setTam(tam);
				pInimigo->setVelocidade(vel);
				pInimigo->setDirecao(direcao);
				pInimigo->setVida(vida);
				pInimigo->setTempoAtaque(tempoAtaque);
				pInimigo->atacar(atacando);
				pInimigo->setAtaquePetrificante(petrifica);
				pInimigo->setLevandoDano(levandoDano);
				pInimigo->setTempoDano(tempoDano);
				pInimigo->setMorrendo(morrendo);
				pInimigo->setTempoMorte(tempoMorrendo);
				pInimigo->setColisaoChao(colisaoChao);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}

			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		else if (ID == IDs::IDs::minotauro) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Minotauro* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::Minotauro(pos, pJogador);
			Entidade::Item::Arma* pArma = carregaArma(pInimigo, posArma, sf::Vector2f(30.0f, 30.0f), IDs::IDs::projetil, colidiu, direcaoArma, velArma, false, ativo);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			try {
				pInimigo->setTam(tam);
				pInimigo->setVelocidade(vel);
				pInimigo->setDirecao(direcao);
				pInimigo->setVida(vida);
				pInimigo->setTempoAtaque(tempoAtaque);
				pInimigo->atacar(atacando);
				pInimigo->setLevandoDano(levandoDano);
				pInimigo->setTempoDano(tempoDano);
				pInimigo->setMorrendo(morrendo);
				pInimigo->setTempoMorte(tempoMorrendo);
				pInimigo->setColisaoChao(colisaoChao);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		if (personagem != nullptr) {
			pListaPersona->inserirEnt(personagem);
			if (arma != nullptr) {
				pListaPersona->inserirEnt(arma);
			}
			if (armaDois != nullptr) {
				pListaPersona->inserirEnt(armaDois);
			}
		}
	}

	void Fase::carregaPersonagem2Jog(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, sf::Vector2f posArma, sf::Vector2f velArma, bool colidiu, bool direcaoArma, bool ativo, bool atacando, bool petrifica, bool levandoDano,
		float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao, bool colisaoChao) { //Usado para carregar os personagens
		Entidade::Entidade* personagem = nullptr;
		Entidade::Entidade* arma = nullptr;
		if (ID == IDs::IDs::jogador) {
			if (jogadorUm) {
				pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
				Entidade::Item::Arma* pArma = carregaArma(pJogador, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador, false, false, sf::Vector2f(0.0f, 0.0f), false, false);
				if (pArma == nullptr) {
					//cout << "Erro ao criar arma" << endl;
					exit(1);
				}
				if (pJogador == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				try {
					pJogador->setTam(tam);
					pJogador->setVelocidade(vel);
					pJogador->setDirecao(direcao);
					pJogador->setJogadorUm(jogadorUm);
					pJogador->setVida(vida);
					pJogador->setTempoAtaque(tempoAtaque);
					pJogador->atacar(atacando);
					pJogador->setPetrificado(petrifica);
					pJogador->setLevandoDano(levandoDano);
					pJogador->setTempoDano(tempoDano);
					pJogador->setMorrendo(morrendo);
					pJogador->setTempoMorte(tempoMorrendo);
					pJogador->addPontuacao(pontuacao);
					pJogador->setColisaoChao(colisaoChao);
					pJogador->inicializarBarraVida();
					pJogador->setAtivoObs(true);
				}
				catch (const std::exception& e) {
					cout << e.what() << endl;
				}
				personagem = static_cast<Entidade::Entidade*>(pJogador);
				arma = static_cast<Entidade::Entidade*>(pArma);
			}
			else {
				doisJogadores = true;
				pJogadorDois = new Entidade::Personagem::Jogador::Jogador(pos);
				Entidade::Item::Arma* pArma = carregaArma(pJogadorDois, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::projetil, colidiu, direcaoArma, velArma, false, ativo);
				if (pArma == nullptr) {
					//cout << "Erro ao criar arma" << endl;
					exit(1);
				}
				if (pJogadorDois == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				try {
					pJogadorDois->setTam(tam);
					pJogadorDois->setVelocidade(vel);
					pJogadorDois->setDirecao(direcao);
					pJogadorDois->setJogadorUm(jogadorUm);
					pJogadorDois->setVida(vida);
					pJogadorDois->setTempoAtaque(tempoAtaque);
					pJogadorDois->atacar(atacando);
					pJogadorDois->setPetrificado(petrifica);
					pJogadorDois->setLevandoDano(levandoDano);
					pJogadorDois->setTempoDano(tempoDano);
					pJogadorDois->setMorrendo(morrendo);
					pJogadorDois->setTempoMorte(tempoMorrendo);
					pJogadorDois->addPontuacao(pontuacao);
					pJogadorDois->setColisaoChao(colisaoChao);
					pJogadorDois->inicializarBarraVida();
					pJogadorDois->setAtivoObs(true);
				}
				catch (const std::exception& e) {
					cout << e.what() << endl;
				}
				personagem = static_cast<Entidade::Entidade*>(pJogadorDois);
				arma = static_cast<Entidade::Entidade*>(pArma);
			}
		}
		else if (ID == IDs::IDs::guerreiraAthena) {
			if (pJogador == nullptr || pJogadorDois == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::GuerreiraAthena* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, pJogador, pJogadorDois);
			Entidade::Item::Arma* pArma = carregaArma(pInimigo, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo, false, false, sf::Vector2f(0.0f, 0.0f), false, false);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			try {
				pInimigo->setTam(tam);
				pInimigo->setVelocidade(vel);
				pInimigo->setDirecao(direcao);
				pInimigo->setVida(vida);
				pInimigo->setTempoAtaque(tempoAtaque);
				pInimigo->atacar(atacando);
				pInimigo->setLevandoDano(levandoDano);
				pInimigo->setTempoDano(tempoDano);
				pInimigo->setMorrendo(morrendo);
				pInimigo->setTempoMorte(tempoMorrendo);
				pInimigo->setColisaoChao(colisaoChao);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		else if (ID == IDs::IDs::gorgona) {
			if (pJogador == nullptr || pJogadorDois == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Gorgona* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, pJogador, pJogadorDois);
			Entidade::Item::Arma* pArma = carregaArma(pInimigo, posArma, sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona, false, false, sf::Vector2f(0.0f, 0.0f), petrifica, false);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			try {
				pInimigo->setTam(tam);
				pInimigo->setVelocidade(vel);
				pInimigo->setDirecao(direcao);
				pInimigo->setVida(vida);
				pInimigo->setTempoAtaque(tempoAtaque);
				pInimigo->atacar(atacando);
				pInimigo->setAtaquePetrificante(petrifica);
				pInimigo->setLevandoDano(levandoDano);
				pInimigo->setTempoDano(tempoDano);
				pInimigo->setMorrendo(morrendo);
				pInimigo->setTempoMorte(tempoMorrendo);
				pInimigo->setColisaoChao(colisaoChao);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		else if (ID == IDs::IDs::minotauro) {
			if (pJogador == nullptr || pJogadorDois == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Minotauro* pInimigo = nullptr;
			pInimigo = new Entidade::Personagem::Inimigo::Minotauro(pos, pJogador, pJogadorDois);
			Entidade::Item::Arma* pArma = carregaArma(pInimigo, posArma, sf::Vector2f(30.0f, 30.0f), IDs::IDs::projetil, colidiu, direcaoArma, velArma, false, ativo);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			try {
				pInimigo->setTam(tam);
				pInimigo->setVelocidade(vel);
				pInimigo->setDirecao(direcao);
				pInimigo->setVida(vida);
				pInimigo->setTempoAtaque(tempoAtaque);
				pInimigo->atacar(atacando);
				pInimigo->setLevandoDano(levandoDano);
				pInimigo->setTempoDano(tempoDano);
				pInimigo->setMorrendo(morrendo);
				pInimigo->setTempoMorte(tempoMorrendo);
				pInimigo->setColisaoChao(colisaoChao);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		if (personagem != nullptr) {
			pListaPersona->inserirEnt(personagem);
			if (arma != nullptr) {
				pListaPersona->inserirEnt(arma);
			}
		}
	}

	void Fase::criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, IDs::IDs ID) {
		Entidade::Entidade* entidade = nullptr;
		if (ID == IDs::IDs::plataforma) {
			Entidade::Obstaculos::Plataforma* plataforma = nullptr;
			plataforma = new Entidade::Obstaculos::Plataforma(pos, tam, ID);
			if (plataforma == nullptr) {
				//cout << "Erro ao criar plataforma" << endl;
				exit(1);
			}
			entidade = static_cast<Entidade::Entidade*>(plataforma);
		}
		else if (ID == IDs::IDs::caixa) {
			Entidade::Obstaculos::Caixa* caixa = nullptr;
			caixa = new Entidade::Obstaculos::Caixa(pos, tam);
			if (caixa == nullptr) {
				//cout << "Erro ao criar caixa" << endl;
				exit(1);
			}
			entidade = static_cast<Entidade::Entidade*>(caixa);
		}
		else if (ID == IDs::IDs::espinho) {
			Entidade::Obstaculos::Espinho* espinho = nullptr;
			espinho = new Entidade::Obstaculos::Espinho(pos, tam);
			if (espinho == nullptr) {
				//cout << "Erro ao criar espinho" << endl;
				exit(1);
			}
			entidade = static_cast<Entidade::Entidade*>(espinho);
		}
		else if (ID == IDs::IDs::portao) {
			Entidade::Obstaculos::Portao* portao = nullptr;
			portao = new Entidade::Obstaculos::Portao(pos, tam);
			if (portao == nullptr) {
				//cout << "Erro ao criar portao" << endl;
				exit(1);
			}
			entidade = static_cast<Entidade::Entidade*>(portao);
		}
		else if (ID == IDs::IDs::maocondenados) {
			Entidade::Obstaculos::MaoCondenados* maocondenados = nullptr;
			maocondenados = new Entidade::Obstaculos::MaoCondenados(pos, tam);
			if (maocondenados == nullptr) {
				//cout << "Erro ao criar lama" << endl;
				exit(1);
			}
			entidade = static_cast<Entidade::Entidade*>(maocondenados);
		}

		if (entidade != nullptr) {
			pListaObstaculo->inserirEnt(entidade);
		}
	}

	void Fase::criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool arrastado, bool colisaoParede, bool aberto) {
		Entidade::Entidade* entidade = nullptr;
		if (ID == IDs::IDs::caixa) {
			Entidade::Obstaculos::Caixa* caixa = nullptr;
			caixa = new Entidade::Obstaculos::Caixa(pos, tam);
			if (caixa == nullptr) {
				//cout << "Erro ao criar caixa" << endl;
				exit(1);
			}
			caixa->setArrastado(arrastado);
			caixa->setColisaoParede(colisaoParede);
			entidade = static_cast<Entidade::Entidade*>(caixa);
		}
		else if (ID == IDs::IDs::portao) {
			Entidade::Obstaculos::Portao* portao = nullptr;
			portao = new Entidade::Obstaculos::Portao(pos, tam);
			if (portao == nullptr) {
				//cout << "Erro ao criar portao" << endl;
				exit(1);
			}
			portao->setAberto(aberto);
			entidade = static_cast<Entidade::Entidade*>(portao);
		}
		if (entidade != nullptr) {
			pListaObstaculo->inserirEnt(entidade);
		}
	}

	void Fase::criaLimite() {
		Entidade::Entidade* entidade = nullptr;
		Entidade::Obstaculos::Plataforma* limite = nullptr;
		//Limite da Esquerda
		limite = new Entidade::Obstaculos::Plataforma(sf::Vector2f(600, 768 - 100), sf::Vector2f(1366, 100), IDs::IDs::plataforma);
		limite->getCorpo().setFillColor(sf::Color::Red);
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

	Entidade::Item::Arma* Fase::carregaArma(Entidade::Personagem::Personagem* p, const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool colidiu, bool direcao, const sf::Vector2f velocidade, bool ataquePetrificante, bool ativo) {
		Entidade::Item::Arma* arma = nullptr;
		if (ID == IDs::IDs::projetil) {
			Entidade::Item::Projetil* projetil = new Entidade::Item::Projetil(p, tam);
			try {
				projetil->setPos(pos);
				projetil->setColidiu(colidiu);
				projetil->setDirecao(direcao);
				projetil->setVelocidade(velocidade);
				projetil->setAtivo(ativo);
			}
			catch (const std::exception& e) {
				cout << e.what() << endl;
			}
			arma = static_cast<Entidade::Item::Arma*>(projetil);
		}
		else if (ID == IDs::IDs::cobrasGorgona) {
			arma = new Entidade::Item::Arma(p, tam, ID);
			arma->setAtaquePetrificante(ataquePetrificante);
		}
		else {
			arma = new Entidade::Item::Arma(p, tam, ID);
		}

		if (arma != nullptr) {
			return arma;
		}
		else {
			//cout << "Erro ao criar arma" << endl;
			exit(1);
		}
	}

	void Fase::abrePortao(bool temInimigo) {
		Entidade::Obstaculos::Portao* portao = static_cast<Entidade::Obstaculos::Portao*>(pListaObstaculo->getEntidade(IDs::IDs::portao));
		portao->setAberto(!temInimigo);
	}

	void Fase::setAtivoObs(const bool ativo) {
		pObsFase->setAtivar(ativo);
		if (pJogador != nullptr) {
			pJogador->setAtivoObs(ativo);
		}
		if (pJogadorDois != nullptr) {
			pJogadorDois->setAtivoObs(ativo);
		}
	}

	void Fase::gerenciarColisoes() {
		pGC->executar();
	}

	void Fase::atualizaPontuacao() {
		if (pJogador != nullptr) {
			pontuacao = pJogador->getPontuacao();
		}
		if (pJogadorDois != nullptr) {
			pontuacao += pJogadorDois->getPontuacao();
		}
	}

	void Fase::atualizaFundo() {
		fundo->atualizar();
	}

	void Fase::desenhar() {
		fundo->desenhar(*pGG->getJanela());
		mapa->desenharMapa(*pGG->getJanela());
		pListaPersona->desenharEntidades();
		pListaObstaculo->desenharEntidades();

	}

	void Fase::salvarColocacao(string nome) {
		if (!nome.empty()) {
			pGS->salvarColocacao(nome, pontuacao);
		}
	}

	void Fase::salvar() {
		pGS->salvarJogo(*pListaPersona, *pListaObstaculo, getID(), getDoisJogadores());
	}

	void Fase::executar() {
		pJogador = getJogador();
		pJogadorDois = getJogadorDois();
		if (pJogadorDois != nullptr) {
			if (pJogador->getTempoMorte() <= 1.25f && pJogadorDois->getTempoMorte() <= 1.25f) {

				// Atualizar camera
				sf::Vector2f pos;
				if (pJogador) {
					pos = pJogador->getPos();
					if (pJogadorDois) {
						pos = (pJogador->getPos() + pJogadorDois->getPos()) / 2.0f;
						if (pJogador->getPos().x - pJogadorDois->getPos().x > pGG->getTamJanela().x || pJogador->getPos().x - pJogadorDois->getPos().x < -pGG->getTamJanela().x) {
							pos.x = 0.0f;
						}
					}
				}

				if (pos.x != 0.0f) {
					pGG->atualizarCamera(pos, pGG->getTamJanela());
				}

				// Atualizar e desenhar entidades e fundo
				atualizaFundo();
				pListaPersona->executar();
				pListaObstaculo->executar();
				temInimigoVivo = pObsFase->verificaInimigoVivo(*pListaPersona);
				desenhar();

				gerenciarColisoes();
				atualizaPontuacao();
				pObsFase->finalizaFase(pJogador, pJogadorDois, temInimigoVivo);
			}
			else {
				pObsFase->jogadorMorreu();
			}
		}
		else {
			if (pJogador->getTempoMorte() <= 1.25f) {
				pGG->atualizarCamera(pJogador->getPos(), pGG->getTamJanela());

				atualizaFundo();
				pListaPersona->executar();
				pListaObstaculo->executar();
				temInimigoVivo = pObsFase->verificaInimigoVivo(*pListaPersona);
				desenhar();

				gerenciarColisoes();
				atualizaPontuacao();
				pObsFase->finalizaFase(pJogador, nullptr, temInimigoVivo);
			}
			else {
				pObsFase->jogadorMorreu();
			}
		}
	}
}