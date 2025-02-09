
#include "../../include/mapas/Mapa.hpp"
#include <iostream>
#include <fstream>
#include "../fases/Fase.hpp"

//"assets/mapas/mapa1.tmj"

using json = nlohmann::json;

Mapa::Mapa(Fase::Fase* fase , const char* caminhoMapa, const std::string& caminhoTileset) {

	if (fase == nullptr) {
		std::cerr << "Erro: Fase passada para Mapa é nullptr!" << std::endl;
	}
	else {
		std::cout << "Fase recebida em Mapa: " << fase << std::endl;
	}

	this->fase = fase;

    if (!carregarTileset(caminhoTileset)) { // Carrega o tileset
        std::cerr << "Erro ao carregar o tileset!" << std::endl;
        exit(1); // Encerra o programa se não conseguir carregar o tileset
    }

    if (!carregarMapa(caminhoMapa)) {
        std::cerr << "Erro ao carregar o mapa!" << std::endl;
    }
}

bool Mapa::carregarMapa(const char* caminhoMapa) {
    std::ifstream arquivo(caminhoMapa);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o mapa!" << std::endl;
        return false;
    }

    nlohmann::json jsonMapa;
    arquivo >> jsonMapa;
    arquivo.close();

    largura = jsonMapa["width"];
    altura = jsonMapa["height"];
    larguraTile = jsonMapa["tilewidth"];
    alturaTile = jsonMapa["tileheight"];

    camadas.clear();

    for (const auto& layer : jsonMapa["layers"]) {
        std::vector<int> tileIDs = layer["data"];

        if (tileIDs.size() < largura * altura) {
            std::cerr << "Erro: JSON contém menos tiles do que o esperado!" << std::endl;
            return false;
        }

        camadas.push_back(tileIDs);

      
        if (layer["name"] == "Tile Layer 1") {
            for (int y = 0; y < altura; y++) {
                for (int x = 0; x < largura; x++) {
                    int index = y * largura + x;
                    int tileID = tileIDs[index];

                    if (tileID != 0) { // Se for um tile de colisão
                        sf::Vector2f pos(static_cast<float>(x * larguraTile), static_cast<float>(y * alturaTile));
                        sf::Vector2f tam(static_cast<float>(larguraTile), static_cast<float>(alturaTile));
                        fase->criaPlataforma(pos, tam, IDs::IDs::plataforma);
                    }
                }
            }
        }
    }
    return true;
}


bool Mapa::carregarTileset(const std::string& caminhoTileset) {
    if (!texturaTileset.loadFromFile(caminhoTileset)) {
        std::cerr << "Erro ao carregar tileset: " << caminhoTileset << std::endl;
        return false;
    }
    return true;
}

void Mapa::desenharMapa(sf::RenderWindow& janela) {
    if (texturaTileset.getSize().x == 0 || texturaTileset.getSize().y == 0) {
        std::cerr << "Erro: Textura do tileset não carregada corretamente!" << std::endl;
        return;
    }

    sf::RenderStates estados;
    estados.texture = &texturaTileset;

    for (const auto& camada : camadas) {
        sf::VertexArray vertices(sf::Quads, largura * altura * 4);

        for (int y = 0; y < altura; y++) {
            for (int x = 0; x < largura; x++) {
                int index = y * largura + x;
                int tileID = camada[index];

                if (tileID == 0) continue;

                // Calcula posição do tile na textura
                int tileX = (tileID - 1) % (texturaTileset.getSize().x / larguraTile);
                int tileY = (tileID - 1) / (texturaTileset.getSize().x / larguraTile);

                float posX = static_cast<float>(x * larguraTile);
                float posY = static_cast<float>(y * alturaTile);

                int vIndex = index * 4;

                vertices[vIndex].position = sf::Vector2f(posX, posY);
                vertices[vIndex + 1].position = sf::Vector2f(posX + larguraTile, posY);
                vertices[vIndex + 2].position = sf::Vector2f(posX + larguraTile, posY + alturaTile);
                vertices[vIndex + 3].position = sf::Vector2f(posX, posY + alturaTile);

                float texX = static_cast<float>(tileX * larguraTile);
                float texY = static_cast<float>(tileY * alturaTile);

                vertices[vIndex].texCoords = sf::Vector2f(texX, texY);
                vertices[vIndex + 1].texCoords = sf::Vector2f(texX + larguraTile, texY);
                vertices[vIndex + 2].texCoords = sf::Vector2f(texX + larguraTile, texY + alturaTile);
                vertices[vIndex + 3].texCoords = sf::Vector2f(texX, texY + alturaTile);
            }
        }
        janela.draw(vertices, estados);
    }
}
