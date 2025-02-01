#include "../../include/menus/Menu.hpp"
#include "../../include/ObservadorMenu.hpp"

namespace Menu {
	Menu::Menu(IDs::IDs ID) : Ente(ID), pObsMenu(new Observado::Observador::ObservadorMenu(this)),
		titulo(nullptr), posImagem(sf::Vector2f(0.0f, 0.0f)), 
		fundo(nullptr), botoes(), posVec(0), nome(nullptr){
		botoes.clear();
		if (ID == IDs::IDs::menuSalvarColocao) {
			nome = new Texto(sf::Vector2f(pGG->getTamJanela().x / 2.3f, pGG->getTamJanela().y / 2.8f), "");
			nome->setTamFonte(40);
		}
	}

	Menu::~Menu() {
		if (titulo) {
			delete titulo;
			titulo = nullptr;
		}
		if (fundo) {
			delete fundo;
			fundo = nullptr;
		}
		for (int i = 0; i < (int)botoes.size(); i++) {
			if (botoes[i]) {
				delete botoes[i];
				botoes[i] = nullptr;
			}
		}
		if (pObsMenu) {
			delete pObsMenu;
			pObsMenu = nullptr;
		}
		botoes.clear();
	}

	void Menu::inicializaIt() {
		if (!botoes.empty()) {
			posVec = 0;
		}
	}

	void Menu::selecionaBaixo() {
		Botao::Botao* botao = botoes[posVec];
		if (botao) {
			botao->seleciona();
			posVec++;
			if (posVec == botoes.size()) {
				posVec = 0;
			}

			botao = botoes[posVec];
			botao->seleciona();
		}
		else {
			//cout << "Botao nulo" << endl;
			exit(1);
		}
	}

	void Menu::selecionaCima() {
		if (botoes.empty()) return;
		Botao::Botao* botao = botoes[posVec];
		if (botao) {
			botao->seleciona();
			posVec--;
			if (posVec < 0) {
				posVec = static_cast<int>(botoes.size()) - 1;
			}
			botao = botoes[posVec];
			botao->seleciona();
		}
		else {
			//cout << "Botao nulo" << endl;
			exit(1);
		}
	}

	void Menu::incluirLetra(char letra) {
		if (nome->getInfo().size() < 10) {
			nome->setInfoTexto(nome->getInfo() + letra);
		}
	}

	void Menu::excluirLetra() {
		std::string aux = nome->getInfo();
		if (aux.size() > 0) {
			aux.pop_back();
			nome->setInfoTexto(aux);
		}
	}

	string Menu::getNome() {
		return nome->getInfo();
	}

	void Menu::setAtivoObs(const bool ativo) {
		if (ativo) {
			pObsMenu->setAtivar(true);
		}
		else {
			pObsMenu->setAtivar(false);
		}
	}

	void Menu::incluiBotao(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs ID, sf::Vector2f tamSelec, std::string info) {
		Botao::Botao* botao = new Botao::Botao(tam, pos, ID, tamSelec);
		if (!info.empty() || info.compare("")) {
			botao->setInfoTexto(info);
		}
		if (botao != nullptr) {
			botoes.push_back(botao);
			if (botoes.size() == 1) {
				botao->seleciona();
			}
		}
	}

	const IDs::IDs Menu::getIDBotao() const {
		if (!botoes.empty() || posVec != botoes.size()) {
			return botoes[posVec]->getID();
		}
		return IDs::IDs::nulo;
	}

	void Menu::desenhar() {
		pGG->atualizarCamera(sf::Vector2f(pGG->getTamJanela().x / 2.0f, pGG->getTamJanela().y / 2.0f), pGG->getTamJanela());
		if (fundo) {
			//pGG->desenharElemento(*fundo);
		}
		if (titulo) {
			titulo->desenhar();
		}
		if (!botoes.empty()) {
			for (auto& it : botoes) {
				if (it) {
					it->desenhar();
				}
			}
		}
		if (nome) {
			nome->desenhar();
		}
	}
}