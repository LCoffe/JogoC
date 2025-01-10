#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Ente.hpp"
#include "../include/Texto.hpp"

namespace Menu {
	namespace Botao {
		class Botao : public Ente {
			private:
				const sf::Vector2f tamSelec;
				const sf::Vector2f tamInicial;
				Texto* texto;
				bool selecionado;
			protected:
				sf::RectangleShape caixa;
				//sf::Texture* textura;
				sf::Vector2f pos;
				sf::Vector2f tam;
			public:
				Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tamSelec);
				virtual ~Botao();
				void desenhar();
				void atualizarPosicao(const sf::Vector2f pos);
				void seleciona();
				void setInfoTexto(const std::string info);
				//void setTextura(sf::Texture* textura);
				const sf::Vector2f getPos() const;
		};
	}
}