#include "../../include/fases/Castelo.hpp"

namespace Fase {

	Castelo::Castelo() :Fase(IDs::IDs::castelo)
	{
		mapa = new Mapa(this, MAPA2_PATH, TILESET1_PATH);

		iniciaFundo();
	}

	Castelo::~Castelo()
	{
		pListaObstaculo->limparLista();
		pListaPersona->limparLista();
	}

	void Castelo::iniciaFase(bool doisJogadores)
	{
		criarMapa(doisJogadores);
		//executar();
	}
	void Castelo::criarMapa(bool doisJogadores)
	{
		if (doisJogadores) {
			//Cria Jogadores
			criaPersonagem2Jog(sf::Vector2f(100, 100), IDs::IDs::jogador, true);
			criaPersonagem2Jog(sf::Vector2f(200, 100), IDs::IDs::jogador, false);

			// Criar inimigos
			float posX = 300.0f;
			float posY = 0.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 100), IDs::IDs::minotauro);
				posX += 600.0f;
			}
			posX = 200.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 100), IDs::IDs::guerreiraAthena);
				posX += 450.0f;
			}
			posX = 250.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 100), sf::Vector2f(50, 50), IDs::IDs::maocondenados);
				posX += 450.0f;
			}
			posX = 1000.0f;
			posY = 500.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, posY), sf::Vector2f(50, 50), IDs::IDs::espinho);
				posX += 500.0f;
			}
			
		}
		else {
			//Cria Jogador
			criaPersonagem1Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador);
			// Criar inimigos
			float posX = 300.0f;
			float posY = 0.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 100), IDs::IDs::minotauro);
				posX += 600.0f;
			}
			posX = 200.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 100), IDs::IDs::guerreiraAthena);
				posX += 450.0f;
			}
			posX = 250.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 100), sf::Vector2f(50, 50), IDs::IDs::maocondenados);
				posX += 750.0f;
			}
			posX = 1000.0f;
			posY = 500.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, posY), sf::Vector2f(50, 50), IDs::IDs::espinho);
				posX += 500.0f;
			}
		}
	}

	void Castelo::iniciaFundo()
	{
		fundo = new Fundo::Parallax();
		fundo->carregarTextura(CAMINHO_TEX_FUNDO2);
		if (fundo == nullptr) {
			//cout << "Erro ao criar fundo" << endl;
			exit(1);
		}
	}

	void Castelo::carregaFase()
	{
		carregar();
		//executar();
	}

	void Castelo::carregar()
	{
		nlohmann::json json;
		nlohmann::json::iterator it = json.begin();
		Entidade::Entidade* aux = nullptr;

		json = pGS->carregarFase();
		it = json.begin();
		bool doisJogadores = false;
		for (auto& it : json) {
			doisJogadores = it["doisJogadores"];
		}

		json = pGS->carregarObstaculo();
		it = json.begin();
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			bool arrastado = it["arrastado"];
			bool colisaoParede = it["colisaoParede"];
			if (ID == IDs::IDs::espinho) {
				criaPlataforma(pos, tam, ID);
			}
			if (ID == IDs::IDs::maocondenados) {
				criaPlataforma(pos, tam, ID);
			}
		}

		json = pGS->carregarPersonagem();
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			sf::Vector2f vel(it["velocidade"]["x"], it["velocidade"]["y"]);
			bool direcao = it["direcao"];
			bool atacando = it["atacando"];
			bool petrifica = it["petrificado"];
			float vida = it["vida"];
			float tempoAtaque = it["tempoAtaque"];
			int armaAtual = it["armaAtual"];
			sf::Vector2f posArma(it["posArma"]["x"], it["posArma"]["y"]);
			IDs::IDs IDArma = static_cast<IDs::IDs>(it["IDArma"]);
			sf::Vector2f velArma(it["velocidadeArma"]["x"], it["velocidadeArma"]["y"]);
			bool colidiu = it["colidiu"];
			bool direcaoArma = it["direcaoArma"];
			bool levandoDano = it["levandoDano"];
			float tempoDano = it["tempoDano"];
			bool morrendo = it["morrendo"];
			float tempoMorte = it["tempoMorte"];
			int pontuacao = it["pontuacao"];
			bool colisaoChao = it["colisaoChao"];
			bool ativo = it["ativo"];
			if (doisJogadores) {
				if (ID == IDs::IDs::jogador) {
					bool jogadorUm = it["jogadorUm"];
					carregaPersonagem2Jog(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, posArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
				if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::minotauro) {
					carregaPersonagem2Jog(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, posArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, 0, colisaoChao);
				}
			}
			else {
				if (ID == IDs::IDs::jogador) {
					bool jogadorUm = it["jogadorUm"];
					carregaPersonagem1Jog(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, armaAtual, posArma, IDArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
				if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::minotauro) {
					carregaPersonagem1Jog(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, armaAtual, posArma, IDArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
			}
		}
	}

	void Castelo::carregaTrocaFase() {
		nlohmann::json json = pGS->carregaTrocaFase();
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			sf::Vector2f vel(it["velocidade"]["x"], it["velocidade"]["y"]);
			bool direcao = it["direcao"];
			bool atacando = it["atacando"];
			bool petrifica = it["petrificado"];
			float vida = it["vida"];
			float tempoAtaque = it["tempoAtaque"];
			int armaAtual = it["armaAtual"];
			sf::Vector2f posArma(it["posArma"]["x"], it["posArma"]["y"]);
			IDs::IDs IDArma = static_cast<IDs::IDs>(it["IDArma"]);
			sf::Vector2f velArma(it["velocidadeArma"]["x"], it["velocidadeArma"]["y"]);
			bool colidiu = it["colidiu"];
			bool direcaoArma = it["direcaoArma"];
			bool levandoDano = it["levandoDano"];
			float tempoDano = it["tempoDano"];
			bool morrendo = it["morrendo"];
			float tempoMorte = it["tempoMorte"];
			int pontuacao = it["pontuacao"];
			bool colisaoChao = it["colisaoChao"];
			bool ativo = it["ativo"];
			bool jogadorUm = it["jogadorUm"];
		
			if (jogadorUm && pJogador != nullptr) {
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
				pJogador->setTempoMorte(tempoMorte);
				pJogador->addPontuacao(pontuacao);
				pJogador->setColisaoChao(colisaoChao);
				pJogador->inicializarBarraVida();
				pJogador->setAtivoObs(true);

				if (!getDoisJogadores()) {
					if (armaAtual == 1) {
						pJogador->trocarArma();
					}
				}
			}
			else if(!jogadorUm && pJogadorDois != nullptr) {
				pJogadorDois->setTam(tam);
				pJogadorDois->setVelocidade(vel);
				pJogadorDois->setDirecao(direcao);
				pJogadorDois->setJogadorUm(jogadorUm);
				pJogador->setArmaAtual(armaAtual);
				pJogadorDois->setVida(vida);
				pJogadorDois->setTempoAtaque(tempoAtaque);
				pJogadorDois->atacar(atacando);
				pJogadorDois->setPetrificado(petrifica);
				pJogadorDois->setLevandoDano(levandoDano);
				pJogadorDois->setTempoDano(tempoDano);
				pJogadorDois->setMorrendo(morrendo);
				pJogadorDois->setTempoMorte(tempoMorte);
				pJogadorDois->addPontuacao(pontuacao);
				pJogadorDois->setColisaoChao(colisaoChao);
				pJogadorDois->inicializarBarraVida();
				pJogadorDois->setAtivoObs(true);
				
			}
		}
	}

}
