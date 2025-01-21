#pragma once

#include "../include/Entidade.hpp"
#include "../include/Jogador.hpp"
#include "../include/Personagem.hpp"

namespace Entidade {
	namespace Item {
		class Arma : public Entidade {
		protected:
			float dano;
			bool ataquePetrificante;
			Personagem::Personagem *pPersonagem;
		
		public:
			Arma(Personagem::Personagem* p, sf::Vector2f tam, const IDs::IDs ID);
			~Arma();
			float getDano() { return dano; }
			Personagem::Personagem* getPersonagem() { return pPersonagem; }
			void setAtaquePetrificante(const bool ataquePetrificante) { this->ataquePetrificante = ataquePetrificante; }
			bool getAtaquePetrificante() { return ataquePetrificante; }
			virtual void desenhar();
			virtual void atualizar();
			virtual	void inicializarSprite();
			void colisao(Entidade* ent, const sf::Vector2f diferenca);
			void salvar(nlohmann::json& j);
		};
	}
}