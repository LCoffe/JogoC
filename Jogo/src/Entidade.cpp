#include "../include/Entidade.hpp"

constexpr auto PATH_JOGADOR = ".\\assets\\greeksoldier.png";
constexpr auto PATH_INIMIGO = ".\\assets\\athenasoldier.png";

namespace Entidade {
	Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const IDs::IDs ID) : Ente(ID), pos(pos), tam(tam){
		if (ID == IDs::IDs::jogador) {
			corpo.setTexture(pGG->includeTexture(PATH_JOGADOR));
		}
		else if (ID == IDs::IDs::inimigo) {
			corpo.setTexture(pGG->includeTexture(PATH_INIMIGO));
		}
		else {
			corpo.setFillColor(sf::Color::White);
		}
		this->setTam(tam);
		this->setPos(pos);
	}

	Entidade::~Entidade() {}

	void Entidade::draw() {
		pGG->drawElemento(corpo);
	}
}