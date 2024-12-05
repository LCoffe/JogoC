#include "../include/GerenciadorColisoes.hpp"

namespace Gerenciador {
	GerenciadorColisoes::GerenciadorColisoes(Lista::ListaEntidade* listaPersonagem, Lista::ListaEntidade* listaObstaculo):
		pListaPersonagem(listaPersonagem),
		pListaObstaculo(listaObstaculo)
	{
	}

	GerenciadorColisoes::~GerenciadorColisoes() {
		pListaPersonagem = nullptr;
		pListaObstaculo = nullptr;
	}

	const bool GerenciadorColisoes::verificaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2) const {
		sf::FloatRect r1 = static_cast<sf::FloatRect>(ent1->getCorpo().getGlobalBounds());
		sf::FloatRect r2 = static_cast<sf::FloatRect>(ent2->getCorpo().getGlobalBounds());
		return r1.intersects(r2);
	}

	const sf::Vector2f GerenciadorColisoes::calcColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2) {
		sf::Vector2f p1 = ent1->getPos();
		sf::Vector2f p2 = ent2->getPos();

		sf::Vector2f t1 = ent1->getTam();
		sf::Vector2f t2 = ent2->getTam();

		sf::Vector2f distCentros(
			fabs((p1.x + (t1.x / 2.0f)) - (p2.x + (t2.x / 2.0f))),
			fabs((p1.y + (t1.y / 2.0f)) - (p2.y + (t2.y / 2.0f)))	
		);
		sf::Vector2f somaMetadeRec(
			t1.x / 2.0f + t2.x / 2.0f,
			t1.x / 2.0f + t2.y / 2.0f
		);
		return sf::Vector2f(
			distCentros.x - somaMetadeRec.x,
			distCentros.y - somaMetadeRec.y
		);
	}

	void GerenciadorColisoes::tratarColisaoJogInimigo() {
		for (int i = 0; i < pListaPersonagem->getTamanho(); i++) {
			Entidade::Entidade* ent1 = pListaPersonagem->operator[](i);
			for (int j = i + 1; j < pListaPersonagem->getTamanho(); j++) { //retira jogador do segundo loop.
				Entidade::Entidade* ent2 = pListaPersonagem->operator[](j);
				if (verificaColisao(ent1, ent2)) { //verifica se as entidades colidiram.
					sf::Vector2f diferenca = calcColisao(ent1, ent2);
					ent1->colisao(ent2, diferenca); //caso sim chama a funcao colisao.]
				}
			}
		}
	}

	void GerenciadorColisoes::tratarColisaoJogObst() {
		for (int i = 0; i < pListaPersonagem->getTamanho(); i++) {
			Entidade::Entidade* ent1 = pListaPersonagem->operator[](i);
			for (int j = 0; j < pListaObstaculo->getTamanho(); j++) { 
				Entidade::Entidade* ent2 = pListaObstaculo->operator[](j);
				if (verificaColisao(ent1, ent2)) { //verifica se as entidades colidiram.
					sf::Vector2f diferenca = calcColisao(ent1, ent2);
					ent2->colisao(ent1, diferenca); //caso sim chama a funcao colisao.
				}
			}
		}
	}
	void GerenciadorColisoes::executar() {
		tratarColisaoJogObst();
		tratarColisaoJogInimigo();
	}
}