#include "../../include/fases/Fase.hpp"
#include "../../include/ObservadorFase.hpp"
#include "../../include/elementosGraficos/Texto.hpp"

namespace Fase {
	Entidade::Personagem::Jogador::Jogador* Fase::pJogador = nullptr;
	Entidade::Personagem::Jogador::Jogador* Fase::pJogadorDois = nullptr;
	Observado::Observador::ObservadorFase* Fase::pObsFase = nullptr;

	Fase::Fase(IDs::IDs ID_Fase) : Ente(ID_Fase), pGS(), doisJogadores(false), pontuacao(0) {
		pListaPersona = new Lista::ListaEntidade();
		pListaObstaculo = new Lista::ListaEntidade();

		pGC = new Gerenciador::GerenciadorColisoes(pListaPersona, pListaObstaculo);

		if (pObsFase == nullptr) {
			pObsFase = new Observado::Observador::ObservadorFase(this);
		}
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
	}

	void Fase::criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID, bool jogadorUm) {
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
				Entidade::Item::Arma* armaJog = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
				//pJogador->setArma(armaJog);
				personagem = static_cast<Entidade::Entidade*>(pJogador);
				pArma = static_cast<Entidade::Entidade*>(armaJog);
			}
			else {
				doisJogadores = true;
				pJogadorDois = new Entidade::Personagem::Jogador::Jogador(pos);
				if (pJogadorDois == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				Entidade::Item::Arma* armaJog = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogadorDois), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
				//pJogador->setArma(armaJog);
				personagem = static_cast<Entidade::Entidade*>(pJogadorDois);
				pArma = static_cast<Entidade::Entidade*>(armaJog);
			}
		}
		else if (ID == IDs::IDs::guerreiraAthena) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::GuerreiraAthena* pInimigo = nullptr;
			if (doisJogadores) {
				pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, this->pJogador, this->pJogadorDois);
				Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo);
				//pInimigo->setArma(armaInim);
				pArma = static_cast<Entidade::Entidade*>(armaInim);
			}
			else {
				pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, this->pJogador);
				Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo);
				//pInimigo->setArma(armaInim);
				pArma = static_cast<Entidade::Entidade*>(armaInim);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			personagem = static_cast<Entidade::Entidade*>(pInimigo);
		}
		else if (ID == IDs::IDs::gorgona) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Gorgona* pInimigo = nullptr;
			if (doisJogadores) {
				pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, this->pJogador, this->pJogadorDois);
				Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona);
				//pInimigo->setArma(armaInim);
				pArma = static_cast<Entidade::Entidade*>(armaInim);
			}
			else {
				pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, this->pJogador);
				Entidade::Item::Arma* armaInim = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona);
				//pInimigo->setArma(armaInim);
				pArma = static_cast<Entidade::Entidade*>(armaInim);
			}
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

	void Fase::criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, sf::Vector2f posArma, bool atacando, bool petrifica, bool levandoDano, 
		float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao, bool colisaoChao) { //Usado para carregar os personagens
		Entidade::Entidade* personagem = nullptr;
		Entidade::Entidade* arma = nullptr;
		if (ID == IDs::IDs::jogador) {
			if (jogadorUm) {
				pJogador = new Entidade::Personagem::Jogador::Jogador(pos);
				Entidade::Item::Arma* pArma = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogador), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
				if (pArma == nullptr) {
					//cout << "Erro ao criar arma" << endl;
					exit(1);
				}
				if (pJogador == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				pJogador->setPosArma(posArma);
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

				pJogador->setAtivoObs(true);
				personagem = static_cast<Entidade::Entidade*>(pJogador);
				arma = static_cast<Entidade::Entidade*>(pArma);
			}
			else {
				doisJogadores = true;
				pJogadorDois = new Entidade::Personagem::Jogador::Jogador(pos);
				Entidade::Item::Arma* pArma = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pJogadorDois), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaJogador);
				if (pArma == nullptr) {
					//cout << "Erro ao criar arma" << endl;
					exit(1);
				}
				pJogadorDois->setArma(pArma);
				if (pJogadorDois == nullptr) {
					//cout << "Erro ao criar jogador" << endl;
					exit(1);
				}
				pJogadorDois->setPosArma(posArma);
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

				pJogadorDois->setAtivoObs(true);
				personagem = static_cast<Entidade::Entidade*>(pJogadorDois);
				arma = static_cast<Entidade::Entidade*>(pArma);
			}
		}
		else if (ID == IDs::IDs::guerreiraAthena) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::GuerreiraAthena* pInimigo = nullptr;
			if (doisJogadores) {
				pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, pJogador, pJogadorDois);
			}
			else {
				pInimigo = new Entidade::Personagem::Inimigo::GuerreiraAthena(pos, pJogador);
			}
			Entidade::Item::Arma* pArma = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::espadaInimigo);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			pInimigo->setPosArma(posArma);
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

			personagem = static_cast<Entidade::Entidade*>(pInimigo);
			arma = static_cast<Entidade::Entidade*>(pArma);
		}
		else if (ID == IDs::IDs::gorgona) {
			if (pJogador == nullptr) {
				//cout << "Erro ao criar inimigo, jogador nao foi criado" << endl;
				exit(1);
			}
			Entidade::Personagem::Inimigo::Gorgona* pInimigo = nullptr;
			if (doisJogadores) {
				pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, pJogador, pJogadorDois);
			}
			else {
				pInimigo = new Entidade::Personagem::Inimigo::Gorgona(pos, pJogador);
			}
			Entidade::Item::Arma* pArma = new Entidade::Item::Arma(static_cast<Entidade::Personagem::Personagem*>(pInimigo), sf::Vector2f(10.0f, 10.0f), IDs::IDs::cobrasGorgona);
			if (pArma == nullptr) {
				//cout << "Erro ao criar arma" << endl;
				exit(1);
			}
			if (pInimigo == nullptr) {
				//cout << "Erro ao criar inimigo" << endl;
				exit(1);
			}
			pInimigo->setPosArma(posArma);
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
		if (ID == IDs::IDs::caixa) {
			Entidade::Obstaculos::Caixa* caixa = nullptr;
			caixa = new Entidade::Obstaculos::Caixa(pos, tam);
			if (caixa == nullptr) {
				//cout << "Erro ao criar caixa" << endl;
				exit(1);
			}
			entidade = static_cast<Entidade::Entidade*>(caixa);
		}

		if (entidade != nullptr) {
			pListaObstaculo->inserirEnt(entidade);
		}
	}

	void Fase::criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool arrastado, bool colisaoParede) {
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

	void Fase::desenhar() {
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

				// Atualizar e desenhar entidades
				pListaPersona->executar();
				pListaObstaculo->executar();
				desenhar();

				gerenciarColisoes();
				atualizaPontuacao();
			}
			else {
				pObsFase->jogadorMorreu();
			}
		}
		else {
			if (pJogador->getTempoMorte() <= 1.25f) {
				pGG->atualizarCamera(pJogador->getPos(), pGG->getTamJanela());

				pListaPersona->executar();
				pListaObstaculo->executar();
				pontuacao = pJogador->getPontuacao();

				desenhar();

				gerenciarColisoes();
				atualizaPontuacao();
			}
			else {
				pObsFase->jogadorMorreu();
			}
		}
	}
}