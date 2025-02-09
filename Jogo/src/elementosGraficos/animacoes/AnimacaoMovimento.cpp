#include "../../include/elementosGraficos/animacoes/AnimacaoMovimento.hpp"

namespace ElementosGraficos {


	AnimacaoMovimento::AnimacaoMovimento(): mapaAnimacao(),ID_ATUAL(ID_ANIMACAO::idle){}

	AnimacaoMovimento::~AnimacaoMovimento() {

		std::map<ID_ANIMACAO, AnimacaoUnica*>::iterator it;
		for (it = mapaAnimacao.begin(); it != mapaAnimacao.end(); it++)
			delete(it->second);

		mapaAnimacao.clear();
	}

	void AnimacaoMovimento::adicionarNovaAnimacao(ID_ANIMACAO id, const char* path, unsigned int imagemCount, const float switchTime)
	{
		AnimacaoUnica* tmp = new AnimacaoUnica(path, imagemCount, switchTime);

		if (tmp == nullptr) {
			//std::cout << "ERRO ao criar animacao em AnimacaoMovimento::adicionarNovaAnimacao" << std::endl;
			exit(1);
		}

		mapaAnimacao.insert(std::pair<ID_ANIMACAO, AnimacaoUnica*>(id, tmp));

		sf::IntRect tamRect = tmp->getTam();

		corpo.setSize(sf::Vector2f(tamRect.width, tamRect.height));
		corpo.setOrigin(sf::Vector2f(tamRect.width, tamRect.height) / 2.0f);

	}

	void AnimacaoMovimento::atualizar(ID_ANIMACAO id, bool olhandoEsquerda, sf::Vector2f pos, float dt)
	{
		if (ID_ATUAL != id) {
			ID_ATUAL = id;
			if (this == nullptr) {
				//std::cerr << "Erro: Tentativa de acessar um objeto nulo em resetar()." << std::endl;
				return;
			}
			else {
				mapaAnimacao[ID_ATUAL]->resetar();
			}
		}

		mapaAnimacao[ID_ATUAL]->atualizar(dt, olhandoEsquerda);

		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
		corpo.setTextureRect(mapaAnimacao[ID_ATUAL]->getTam());
		corpo.setTexture(mapaAnimacao[ID_ATUAL]->getTextura());


	}



}
