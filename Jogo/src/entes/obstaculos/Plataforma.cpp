#include "../../include/entes/obstaculos/Plataforma.hpp"


constexpr auto PLATAFORMA_PATH = "..\\Jogo\\assets\\plataformas\\pedra.png";


namespace Entidade {
	namespace Obstaculos {
		

		sf::Texture Plataforma::texturaTileset;
		bool texturaCarregada = false; // Controla se já carregamos a textura

		Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID)
			: Obstaculo(pos, tam, ID) {

			corpo.setSize(tam);
			corpo.setPosition(pos);
			static bool texturaCarregada = false;
			if (!texturaCarregada) {
				if (!texturaTileset.loadFromFile(TILESET1_PATH)) {
					std::cerr << "Erro ao carregar o tileset!" << std::endl;
				}
				texturaCarregada = true;
			}
		}
		void Plataforma::desenhar() {
			
			
		}

		Plataforma::~Plataforma() {}


		void Plataforma::colisao(Entidade* ent, sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
				if (pp->getColisaoParede()) {
					pp->setAndando(false);
					pp->setVelocidade(sf::Vector2f(0.0f, 0.0f));
				}
			}
			else if (ent->getID() == IDs::IDs::guerreiraAthena || ent->getID() == IDs::IDs::gorgona) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
				if (pp->getColisaoParede() && pp->getDirecao()) { //se a plataforma estiver a direita do inimigo e ele estiver indo para a direita
					pp->setDirecao(false);
				}
				else if (pp->getColisaoParede() && !pp->getDirecao()) { //se a plataforma estiver a esquerda do inimigo e ele estiver indo para a esquerda
					pp->setDirecao(true);
				}
			}
			else if (ent->getID() == IDs::IDs::projetil) {
				Item::Projetil* proj = static_cast<Item::Projetil*>(ent);
				proj->setColidiu(true);
			}
		}

		void Plataforma::atualizar() {
			sprite.atualizar(pos);
		}

		void Plataforma::inicializar() {
			
		}

		void Plataforma::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["arrastado"] = false;
			j["colisaoParede"] = false;
		}
	}
}