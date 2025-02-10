#pragma once

#include "Animacao.hpp"
#include "AnimacaoUnica.hpp"

namespace ElementosGraficos {
	
		enum ID_ANIMACAO {
			walk = 0,
			idle = 1,
			attack = 2,
			jump = 3,
			levouDano = 4,
			especialGorgona = 5,
			petrificado = 6,
			morte = 7,
			walkL = 8,
			idleL = 9,
			attackL = 10,
			jumpL = 11,
			levouDanoL = 12,
			morteL = 13,
			petrificadoL = 14,
		};

		class AnimacaoMovimento : public Animacao{
		private:
			std::map<ID_ANIMACAO, AnimacaoUnica*> mapaAnimacao;
			ID_ANIMACAO ID_ATUAL;

		public:
			AnimacaoMovimento();
			~AnimacaoMovimento();
			void adicionarNovaAnimacao(ID_ANIMACAO id, const char* path, unsigned int imagemCount,const float switchTime = 0.25f);
			void atualizar(ID_ANIMACAO id, bool olhandoEsquerda, sf::Vector2f pos, float dt);


		};


}

