#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Ente.hpp"

class Personagem: public Ente {
	protected:
		sf::Vector2f velocidade;
	public:
		Personagem(sf::Vector2f pos, sf::Vector2f tam, const string& path);
		~Personagem();
		

		void setVelocidade(sf::Vector2f vel) { velocidade = vel; }
		const sf::Vector2f& getVelocidade() const { return velocidade; }
	};