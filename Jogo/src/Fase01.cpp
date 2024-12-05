#include "../include/Fase01.hpp"

namespace Fase {
	Fase01::Fase01(): Fase(IDs::IDs::fase01){
		criarMapa();
		executar();
	}

	Fase01::~Fase01() {}

	void Fase01::criarMapa() {
		// Cria limite
		criaLimite();

		// Criar jogador
		criaPersonagem(sf::Vector2f(50, 350), IDs::IDs::jogador);

		// Criar inimigos
		criaPersonagem(sf::Vector2f(600, 768 - 101), IDs::IDs::inimigo);
		criaPersonagem(sf::Vector2f(400, 768 - 101), IDs::IDs::inimigo);

		// Criar plataformas
		criaPlataforma(sf::Vector2f(0, 768 - 100), sf::Vector2f(1366, 100), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(800, 500), sf::Vector2f(100, 268), IDs::IDs::plataforma);
	}

	void Fase01::executar() {
		pJogador = getJogador();
		if (pJogador) {
			pListaPersona->executar();
			pListaObstaculo->executar();
			gerenciarColisoes();
			desenhar();
		}
	}
}