#pragma once

#include "../../stdafx/stdafx.hpp"
#include "../entes/Ente.hpp"
#include "../elementosGraficos/Texto.hpp"
#include "../elementosGraficos/Botao.hpp"

namespace Observado {
	namespace Observador {
		class ObservadorMenu;
	}
}

namespace Menu {
	class Menu : public Ente {
		protected:
			Observado::Observador::ObservadorMenu* pObsMenu;
			std::vector<Botao::Botao*> botoes;
			int posVec;
			Texto* titulo;
			Texto* nome;
			sf::Vector2f posImagem;
			sf::RectangleShape* fundo;
			virtual void criarBotoes() = 0;
			virtual void criarTitulo() = 0;
			virtual void criarFundo() = 0;
		public:
			Menu(IDs::IDs ID);
			~Menu();
			void selecionaBaixo();
			void selecionaCima();
			void incluirLetra(char letra);
			void excluirLetra();
			string getNome();
			void incluiBotao(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs ID, sf::Vector2f tamSelec, std::string info = "");
			void inicializaIt();
			void setAtivoObs(const bool ativo);
			const IDs::IDs getIDBotao() const;
			
			virtual void executar() = 0;
			void desenhar();
	};
}