#include "../include/Inimigo.hpp"

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const string& path) : Personagem(pos, tam, path), pJog(nullptr) {
    visao.setSize(sf::Vector2f(100, 10));
    visao.setFillColor(sf::Color::Red);
	setPosVisao(pos);
	setVelocidade(sf::Vector2f(0.01f, 0.01f));
}

Inimigo::~Inimigo() { pJog = nullptr; }

void Inimigo::procuraJogador() {
	if (pJog != nullptr) {
		sf::Vector2f posJog = pJog->getPos();
		sf::Vector2f posVis = getPosVisao();
		if ((posJog.x - posVis.x) == 0 || (posJog.x - posVis.x) < 0 || (posJog.y - posVis.y) == 0 || (posJog.y - posVis.y) < 0){
			sf::Vector2f posInim = getPos();
			sf::Vector2f dist = posJog - posInim;
			if (dist.x > 0) {
				pos = corpo.getPosition();
				pos.x += velocidade.x;
				corpo.setPosition(pos);
				visao.setPosition(pos);
			}
			else {
				pos = corpo.getPosition();
				pos.x -= velocidade.x;
				corpo.setPosition(pos);
				visao.setPosition(-pos);
			}
			if (dist.y > 0) {
				pos = corpo.getPosition();
				pos.y += velocidade.y;
				corpo.setPosition(pos);
				visao.setPosition(pos);
			}
			else {
				pos = corpo.getPosition();
				pos.y -= velocidade.y;
				corpo.setPosition(pos);
				visao.setPosition(pos);
			}
		}
	}
}