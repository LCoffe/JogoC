#include "../../include/menus/MenuColocacao.hpp"

namespace Menu {
	Gerenciador::GerenciadorSalvar* MenuColocacao::pGS = new Gerenciador::GerenciadorSalvar();

	MenuColocacao::MenuColocacao() : Menu(IDs::IDs::menuColocacao) {
		criarTitulo();
		criarFundo();
		criarBotoes();
	}

	MenuColocacao::~MenuColocacao() {
		pGS = nullptr;
	}

	void MenuColocacao::criarBotoes() {
		nlohmann::json jsonColocacao = pGS->carregarColocacao();
		if (!jsonColocacao.is_null()) {
			std::vector<std::string> nomes;
			std::vector<int> pontuacoes;

			for (auto& it : jsonColocacao) {
				nomes.push_back(it["nome"]);
				pontuacoes.push_back(it["pontuacao"]);
			}

			for (int i = 0; i < (int)nomes.size(); i++) {
				for (int j = i; j < (int)nomes.size(); j++) {
					if (pontuacoes[i] < pontuacoes[j]) {
						std::swap(pontuacoes[i], pontuacoes[j]);
						std::swap(nomes[i], nomes[j]);
					}
				}
			}

			int i = 0;
			for (auto& it : nomes) {
				std::string aux = it;
				std::string pontuacao = std::to_string(pontuacoes[i]);
				int size = static_cast<int>(it.size() + pontuacao.size());
				for (int j = 0; j < 40 - size; j++) {
					aux += ".";
				}
				aux += pontuacao;
				incluiBotao(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 5.0f + 50.0f * i), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoTextoColocacao, sf::Vector2f(400.0f, 100.0f), aux);
				i++;
			}
		}
		else {
			incluiBotao(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 5.0f + 50.0f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoTextoColocacao, sf::Vector2f(400.0f, 100.0f), "Lista de colocações vazia");
		}
		
		incluiBotao(sf::Vector2f(100.0f, pGG->getTamJanela().y - 150.f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoLimpar, sf::Vector2f(400.0f, 100.0f));
		incluiBotao(sf::Vector2f(100.0f, pGG->getTamJanela().y - 100.f), sf::Vector2f(100.0f, 50.0f), IDs::IDs::botaoVoltar, sf::Vector2f(400.0f, 100.0f));
	}

	void MenuColocacao::criarTitulo() {
		titulo = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.5f, pGG->getTamJanela().y / 10.0f), "Colocacao");
		titulo->setTamFonte(50);
	}

	void MenuColocacao::criarFundo() {
		fundo = new sf::RectangleShape(pGG->getTamJanela());
		fundo->setTexture(pGG->incluirTextura("..\\Jogo\\assets\\gamemenu.png"));
	}

	void MenuColocacao::limparColocacao() {
		pGS->limparColocacao();
	}

	void MenuColocacao::executar() {
		desenhar();
	}
}