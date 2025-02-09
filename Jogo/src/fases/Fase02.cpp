#include "../../include/fases/Fase02.hpp"

namespace Fase {

	Fase02::Fase02() :Fase(IDs::IDs::fase02)
	{
		mapa = new Mapa(this, MAPA1_PATH, TILESET1_PATH);

		iniciaFundo();
	}

	Fase02::~Fase02()
	{
		pListaObstaculo->limparLista();
		pListaPersona->limparLista();
	}

	void Fase02::iniciaFase(bool doisJogadores)
	{
		criarMapa(doisJogadores);
		//executar();
	}
	void Fase02::criarMapa(bool doisJogadores)
	{
		if (doisJogadores) {
			//Cria Jogadores
			criaPersonagem2Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador, true);
			criaPersonagem2Jog(sf::Vector2f(200, 768 - 252), IDs::IDs::jogador, false);

			// Criar inimigos
			//criaPersonagem2Jog(sf::Vector2f(300, 768 - 251), IDs::IDs::gorgona, false);
			
		}
		else {
			//Cria Jogador
			criaPersonagem1Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador);
			// Criar inimigos
			float posX = 300.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				//criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 768 - 251), IDs::IDs::gorgona);
				posX *= 2.5f;
			}
			posX = 150.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				//criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 768 - 251), IDs::IDs::guerreiraAthena);
				//posX *= 5.0f;
			}
			posX = 200.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				//criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 500), sf::Vector2f(50, 30), IDs::IDs::lama);
				posX *= 4.0f;
			}
			posX = 250.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				//criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 500), sf::Vector2f(50, 50), IDs::IDs::espinho);
				posX *= 5.0f;
			}
		}
	}

	void Fase02::iniciaFundo()
	{
		fundo = new Fundo::Parallax();
		fundo->carregarTextura(CAMINHO_TEX_FUNDO2);
		if (fundo == nullptr) {
			//cout << "Erro ao criar fundo" << endl;
			exit(1);
		}
	}

	void Fase02::carregaFase()
	{
		carregar();
		//executar();
	}

	void Fase02::carregar()
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
			sf::Vector2f tam(it["posicao"]["x"], it["posicao"]["y"]);
			bool arrastado = it["arrastado"];
			bool colisaoParede = it["colisaoParede"];
			if (ID == IDs::IDs::plataforma) {
				criaPlataforma(pos, tam, ID);
			}
			if (ID == IDs::IDs::caixa) {
				criaPlataforma(pos, tam, ID, arrastado, colisaoParede, false);
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
				if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::gorgona) {
					carregaPersonagem2Jog(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, posArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, 0, colisaoChao);
				}
			}
			else {
				if (ID == IDs::IDs::jogador) {
					bool jogadorUm = it["jogadorUm"];
					carregaPersonagem1Jog(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, armaAtual, posArma, IDArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
				if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::gorgona) {
					carregaPersonagem1Jog(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, armaAtual, posArma, IDArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
			}
		}
	}

	void Fase02::carregaTrocaFase() {
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
				pJogadorDois->setAtivoObs(true);
				
			}
		}
	}

}
