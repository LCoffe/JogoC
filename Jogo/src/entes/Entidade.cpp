#include "../../include/entes/Entidade.hpp"

constexpr auto PATH_JOGADOR = ".\\assets\\jogador\\jogador.png";
constexpr auto PATH_INIMIGO = ".\\assets\\athenasoldier.png";

namespace Entidade {
	Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const IDs::IDs ID) : Ente(ID), pos(pos), tam(tam),sprite(),
	remover(false){
		this->setTam(tam);
		this->setPos(pos);
	}

	Entidade::~Entidade() {}

	void Entidade::desenhar() {
		pGG->desenharElemento(corpo);
	}
}