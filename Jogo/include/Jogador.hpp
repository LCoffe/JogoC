#pragma once

#include "../stdafx/stdafx.hpp"
#include "../Personagem.hpp"

class Jogador: public Personagem{
	private:
	
	public:
		Jogador(sf::Vector2f pos, sf::Vector2f tam, const string& path);
		~Jogador();
		void mover();
};