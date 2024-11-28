#include "../include/Jogador.hpp"

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, const string& path): Personagem(pos, tam, path) {}

Jogador::~Jogador() {}

void Jogador::mover() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {  // W = cima
		pos = corpo.getPosition();
		pos.y -= velocidade.y;
		corpo.setPosition(pos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // S = baixo
		pos = corpo.getPosition();
		pos.y += velocidade.y;
		corpo.setPosition(pos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // A = esquerda
		pos = corpo.getPosition();
		pos.x -= velocidade.x;
		corpo.setPosition(pos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // D = direita
		pos = corpo.getPosition();
		pos.x += velocidade.x;
		corpo.setPosition(pos);
	}
}