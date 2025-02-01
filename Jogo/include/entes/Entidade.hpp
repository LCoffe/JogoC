#pragma once

#include "../../include/entes/Ente.hpp"
#include "../../include/elementosGraficos/animacoes/AnimacaoMovimento.hpp"
#include "../json.hpp"
#include "../../stdafx/stdafx.hpp"
namespace Entidade {
	class Entidade : public Ente {
	protected:
		bool remover;
		sf::RectangleShape corpo;
		sf::Vector2f pos;
		sf::Vector2f tam;

		ElementosGraficos::AnimacaoMovimento sprite;

	public:
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
		virtual ~Entidade();

		void setTam(sf::Vector2f tam) { corpo.setSize(tam); }
		const sf::Vector2f& getTam() const { return corpo.getSize(); }

		void setPos(sf::Vector2f pos) { corpo.setPosition(pos); }
		const sf::Vector2f& getPos() const { return corpo.getPosition(); }

		sf::RectangleShape& getCorpo() { return corpo; }
		void podeRemover() { remover = true; }
		bool getRemover() { return remover; }
		virtual void desenhar();
		virtual void atualizar() = 0;
		virtual void salvar(nlohmann::json& j) = 0;
		virtual void colisao(Entidade* ent, const sf::Vector2f diferenca) = 0;
		
	};
}