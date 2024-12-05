#pragma once

#include "../include/Ente.hpp"

namespace Entidade {
	class Entidade: public Ente {
	protected:
		sf::RectangleShape corpo;
		sf::Vector2f pos;
		sf::Vector2f tam;
	public:
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
		~Entidade();

		void setTam(sf::Vector2f tam) { corpo.setSize(tam); }
		const sf::Vector2f& getTam() const { return corpo.getSize(); }

		void setPos(sf::Vector2f pos) { corpo.setPosition(pos); }
		const sf::Vector2f& getPos() const { return corpo.getPosition(); }

		sf::RectangleShape& getCorpo(){ return corpo; }

		virtual void desenhar();
		virtual void atualizar() = 0;

		virtual void colisao(Entidade* ent, const sf::Vector2f) = 0;
	};
}