#include "../include/GerenciadorSalvar.hpp"
#include "../include/Fase01.hpp"
#include "../include/Fase.hpp"

namespace Gerenciador {
    GerenciadorSalvar::GerenciadorSalvar(){}

    GerenciadorSalvar::~GerenciadorSalvar() {}

    std::ofstream GerenciadorSalvar::abreArqSave(const char* caminho) {
		std::ofstream jsonOut(caminho);
        if (!jsonOut) {
            exit(1);
        }
		return jsonOut;
    }

	void GerenciadorSalvar::fechaArqSave(std::ofstream& jsonOut) {
		jsonOut.close();
	}

	std::ifstream GerenciadorSalvar::abreArqLoad(const char* caminho) {
		std::ifstream jsonIn(caminho);
		if (!jsonIn) {
			exit(1);
		}
		return jsonIn;
	}

	void GerenciadorSalvar::fechaArqLoad(std::ifstream& jsonIn) {
		jsonIn.close();
	}

    nlohmann::json GerenciadorSalvar::salvarPersonagem(Lista::ListaEntidade& LP){
        if (LP.getTamanho() == 0) {
			exit(1);
        }
        nlohmann::json aux;
        aux = LP.save();

		return aux;
    }

	nlohmann::json GerenciadorSalvar::salvarObstaculo(Lista::ListaEntidade& LO) {
		if (LO.getTamanho() == 0) {
			exit(1);
		}
		nlohmann::json aux;
		aux = LO.save();
		return aux;
	}

	void GerenciadorSalvar::salvarColocacao(string nome, int pontuacao) {
		nlohmann::json jsonSave = carregarColocacao();
		std::ofstream jsonOut = abreArqSave(CAMINHO_SAVE_COLOCACAO);

		if (jsonSave.is_null()) {
			jsonSave = nlohmann::json::array();
		}

		nlohmann::json aux;
		aux["nome"] = nome;
		aux["pontuacao"] = pontuacao;

		if (jsonSave.is_array() && jsonSave.size() < 10) {
			jsonSave.push_back(aux);
		}
		else {
			// Handle the error or convert jsonSave to an array
		}

		jsonOut << jsonSave.dump(4);
		fechaArqSave(jsonOut);
	}

	nlohmann::json GerenciadorSalvar::carregarPersonagem(Fase::Fase01 &Fase) {
		std::ifstream jsonIn = abreArqLoad(CAMINHO_SAVE_PERSONA);
		if (!jsonIn.is_open()) {
			std::cerr << "Erro ao abrir o arquivo." << std::endl;
			// Trate o erro apropriadamente
		}
		if (jsonIn.peek() == std::ifstream::traits_type::eof()) {
			std::cerr << "Arquivo est� vazio." << std::endl;
			// Trate o erro apropriadamente
		}
		nlohmann::json jsonLoad = nlohmann::json::parse(jsonIn);
		fechaArqLoad(jsonIn);
		return jsonLoad;
	}

	nlohmann::json GerenciadorSalvar::carregarObstaculo(Fase::Fase01& Fase) {
		std::ifstream jsonIn = abreArqLoad(CAMINHO_SAVE_OBST);
		if (!jsonIn.is_open()) {
			std::cerr << "Erro ao abrir o arquivo." << std::endl;
			// Trate o erro apropriadamente
		}
		if (jsonIn.peek() == std::ifstream::traits_type::eof()) {
			std::cerr << "Arquivo est� vazio." << std::endl;
			// Trate o erro apropriadamente
		}
		nlohmann::json jsonLoad = nlohmann::json::parse(jsonIn);
		fechaArqLoad(jsonIn);
		return jsonLoad;
	}

    void GerenciadorSalvar::salvarJogo(Lista::ListaEntidade LP, Lista::ListaEntidade LO, IDs::IDs IDFase, bool doisJogadores) {
		std::ofstream jsonOut = abreArqSave(CAMINHO_SAVE_PERSONA);
		nlohmann::json jsonSave;
		jsonSave = salvarPersonagem(LP);
		jsonOut << jsonSave.dump(4);
		fechaArqSave(jsonOut);
		
		jsonOut = abreArqSave(CAMINHO_SAVE_OBST);
		jsonSave.clear();
		jsonSave = salvarObstaculo(LO);
		jsonOut << jsonSave.dump(4);
		fechaArqSave(jsonOut);
		
		jsonOut = abreArqSave(CAMINHO_SAVE_FASE);
		jsonSave.clear();
		nlohmann::json jsonFase;
		jsonFase["IDFase"] = static_cast<int>(IDFase);
		jsonFase["doisJogadores"] = doisJogadores;
		jsonSave.push_back(jsonFase);
		jsonOut << jsonSave.dump(4);
		fechaArqSave(jsonOut);
    }

	nlohmann::json GerenciadorSalvar::carregarFase() {
		std::ifstream jsonIn = abreArqLoad(CAMINHO_SAVE_FASE);
		if (!jsonIn.is_open()) {
			std::cerr << "Erro ao abrir o arquivo." << std::endl;
			// Trate o erro apropriadamente
		}
		if (jsonIn.peek() == std::ifstream::traits_type::eof()) {
			std::cerr << "Arquivo est� vazio." << std::endl;
			// Trate o erro apropriadamente
		}
		nlohmann::json jsonLoad = nlohmann::json::parse(jsonIn);
		fechaArqLoad(jsonIn);
		return jsonLoad;
	}

	nlohmann::json GerenciadorSalvar::carregarColocacao() {
		std::ifstream jsonIn = abreArqLoad(CAMINHO_SAVE_COLOCACAO);
		if (!jsonIn.is_open()) {
			std::cerr << "Erro ao abrir o arquivo." << std::endl;
			// Trate o erro apropriadamente
		}
		if (jsonIn.peek() == std::ifstream::traits_type::eof()) {
			return nullptr;
		}
		nlohmann::json jsonLoad = nlohmann::json::parse(jsonIn);
		fechaArqLoad(jsonIn);
		return jsonLoad;
	}

	void GerenciadorSalvar::limparColocacao() {
		std::ofstream jsonOut = abreArqSave(CAMINHO_SAVE_COLOCACAO);
		jsonOut.clear();
		fechaArqSave(jsonOut);
	}

	void GerenciadorSalvar::carregarJogo(Fase::Fase01 &Fase) {
		Fase.carregar();
	}
}