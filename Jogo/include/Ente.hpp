#pragma once

#include "../stdafx/stdafx.hpp"

class Ente {
	protected:
		sf::RectangleShape corpo;
		sf::Texture text;
		sf::Vector2f pos;
		sf::Vector2f tam;
	public:
		Ente(sf::Vector2f pos, sf::Vector2f tam, const string& path);
		~Ente();

		void setTam(sf::Vector2f tam) { corpo.setSize(tam); }
		const sf::Vector2f& getTam() const { return corpo.getSize(); }

		void setPos(sf::Vector2f pos) { corpo.setPosition(pos); }
		const sf::Vector2f& getPos() const { return corpo.getPosition(); }

		const sf::RectangleShape& getCorpo() const { return corpo; }

		void setTexture(const string& path);

};