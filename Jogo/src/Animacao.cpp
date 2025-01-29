#include "../include/Animacao.hpp"

namespace ElementosGraficos {

	const float Animacao::AnimacaoUnica::switchTime = 0.25f;

	Gerenciador::GerenciadorGrafico* Animacao::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

	Animacao::Animacao() :corpo(), mapaAnimacao(), IDatual(ID_ANIMACAO::walk) {
		corpo.setScale(sf::Vector2f(3, 3));
	}

	Animacao::~Animacao() {
		std::map<ID_ANIMACAO, AnimacaoUnica*>::iterator it;
		for (it = mapaAnimacao.begin(); it != mapaAnimacao.end(); ++it)
			delete (it->second);

		mapaAnimacao.clear();
	}

	void Animacao::adicionarNovaAnimacao(ID_ANIMACAO id, const char* path, unsigned int imagemCount) {

		AnimacaoUnica* tmp = new AnimacaoUnica(path, imagemCount);

		if (tmp == NULL) {
			//std::cout << " Erro criando a animacao" << std::endl;
			exit(1);
		}

		mapaAnimacao.insert(std::pair<ID_ANIMACAO, AnimacaoUnica*>(id, tmp));

		sf::IntRect tamRect = tmp->getTam();

		corpo.setSize(sf::Vector2f(static_cast<float>(tamRect.width), static_cast<float>(tamRect.height)));
		corpo.setOrigin(sf::Vector2f(static_cast<float>(tamRect.width), static_cast<float>(tamRect.height) / 2.0f));

	}

	void Animacao::atualizar(ID_ANIMACAO id, bool olhandoEsquerda, sf::Vector2f pos, float dt) {
		if (IDatual != id) {
			IDatual = id;
			if (this == nullptr) {
				//std::cerr << "Erro: Tentativa de acessar um objeto nulo em resetar()." << std::endl;
				return;
			}
			else {
				mapaAnimacao[IDatual]->resetar();	
			}
		}

		mapaAnimacao[IDatual]->atualizar(dt, olhandoEsquerda);

		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
		corpo.setTextureRect(mapaAnimacao[IDatual]->getTam());
		corpo.setTexture(mapaAnimacao[IDatual]->getTextura());
	}

	void Animacao::desenhar(){
		corpo.setScale(1.0f, 1.0f);
		pGG->desenharElemento(corpo);	
	}

}
