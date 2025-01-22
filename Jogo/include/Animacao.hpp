#pragma once
#include "../include/GerenciadorGrafico.hpp"
#include <SFML/Graphics.hpp>

namespace ElementosGraficos {

	enum ID_ANIMACAO {
		walk = 0,
		idle = 1,
		attack = 2,
		jump = 3,
		levouDano = 4,
		especialGorgona = 5,
		petrificado = 6,
		morte = 7
	};

	class Animacao
	{
	private:static Gerenciador::GerenciadorGrafico* pGG;

		class AnimacaoUnica {

		private:
			const unsigned int imagemCount;
			unsigned int imagemAtual;
			sf::Texture* textura;
			float tempoTotal;
			sf::IntRect tamRect;
			static const float switchTime;

		public:
			AnimacaoUnica(const char* path, const unsigned int imagemCount)
				: imagemCount(imagemCount),
				imagemAtual(0),
				textura(pGG ? pGG->incluirTextura(path) : nullptr),  // Verifica pGG antes de usar
				tempoTotal(0.0f),
				tamRect()
			{
				if (!pGG) {
					std::cerr << "Erro: GerenciadorGrafico (pGG) não inicializado!" << std::endl;
					exit(1);
				}

				if (!textura) {
					std::cerr << "Erro ao carregar textura: " << path << std::endl;
					exit(1);
				}

				tamRect.width = textura->getSize().x / imagemCount;
				tamRect.height = textura->getSize().y;
			}
			
			~AnimacaoUnica(){}

			void atualizar(float dt, bool olhandoEsquerda) {

				tempoTotal += dt;

				if (tempoTotal >= switchTime) {
					tempoTotal -= switchTime;
					imagemAtual++;

					if (imagemAtual >= imagemCount) {
						imagemAtual = 0;
					}
				}

				if (olhandoEsquerda) {
					tamRect.left = (imagemAtual + 1) * abs(tamRect.width);
					tamRect.width = -abs(tamRect.width);
				}
				else {
					tamRect.left = imagemAtual * tamRect.width;
					tamRect.width = abs(tamRect.width);
				}


			}

			void resetar() {
				imagemAtual = 0;
				tempoTotal = 0;
			}

			sf::IntRect getTam() const { return tamRect; }
			sf::Texture* getTextura() const { return textura; }

		};
	
	private:
	
		sf::RectangleShape corpo;
		std::map<ID_ANIMACAO, AnimacaoUnica*> mapaAnimacao;
		ID_ANIMACAO IDatual;
	public:
		Animacao();
		~Animacao();
		void adicionarNovaAnimacao(ID_ANIMACAO id, const char* path, unsigned int imagemCount);
		void atualizar(ID_ANIMACAO id, bool olhandoEsquerda, sf::Vector2f pos, float dt);
		void desenhar();	
	};

}


