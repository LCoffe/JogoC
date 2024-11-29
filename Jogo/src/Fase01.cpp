#include "../include/Fase01.hpp"

namespace Fase {
	Fase01::Fase01(): Fase(IDs::IDs::fase01){
		criarMapa();
	}

	Fase01::~Fase01() {}

	void Fase01::criarMapa() {
		// Criar jogador
		criaPersonagem(sf::Vector2f(50, 50), IDs::IDs::jogador);

		// Criar inimigos
		criaPersonagem(sf::Vector2f(100, 100), IDs::IDs::inimigo);
	}
}