#pragma once

#include "../../include/entes/personagens/Personagem.hpp"

#define DANO_ARMA 05.0F

namespace Entidade {
	namespace Item {
		class Arma : public Entidade {
		protected:
			float dano;
			bool ataquePetrificante;
			bool ativo;
			Personagem::Personagem *pPersonagem;
		
		public:
			Arma(Personagem::Personagem* p, sf::Vector2f tam, const IDs::IDs ID);
			~Arma();
			float getDano() { return dano; }
			Personagem::Personagem* getPersonagem() { return pPersonagem; }
			void setAtaquePetrificante(const bool ataquePetrificante) { this->ataquePetrificante = ataquePetrificante; }
			bool getAtaquePetrificante() { return ataquePetrificante; }
			void setAtivo(const bool ativo) { this->ativo = ativo; }
			bool getAtivo() { return ativo; }
			virtual void desenhar();
			virtual void atualizar();
			virtual	void inicializarSprite();
			virtual void colisao(Entidade* ent, const sf::Vector2f diferenca);
			virtual void salvar(nlohmann::json& j);
		};
	}
}