#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Personagem.hpp"
#include "../include/Jogador.hpp"

class Inimigo : public Personagem {
	private:
		Jogador* pJog;
		sf::RectangleShape visao;
		sf::Vector2f posVisao;
	public:
		Inimigo(sf::Vector2f pos, sf::Vector2f tam, const string& path);
		~Inimigo();
		
		void setJogador(Jogador* pJog) { this->pJog = pJog;}

		void setPosVisao(sf::Vector2f pos) { visao.setPosition(pos); }
		const sf::Vector2f& getPosVisao() const { return visao.getPosition();}

		const sf::RectangleShape& getVisao() const { return visao; }

		void procuraJogador();
};