
#include "../../include/mapas/Mapa.hpp"
#include <iostream>
#include <fstream>
#include "../fases/Fase.hpp"

//"assets/mapas/mapa1.tmj"

using json = nlohmann::json;

Mapa::Mapa(Fase::Fase* fase , const std::string& caminhoMapa, const std::string& caminhoTileset) {

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

bool Mapa::carregarMapa(const std::string& caminhoMapa) {
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

    for (const auto& layer : jsonMapa["layers"]) {
        if (layer["name"] == "Tile Layer 1") {
            std::vector<int> tileIDs = layer["data"];

            // Verifica se o JSON tem o tamanho correto
            if (tileIDs.size() < largura * altura) {
                std::cerr << "Erro: JSON contém menos tiles do que o esperado! Esperado: "
                    << (largura * altura) << ", Obtido: " << tileIDs.size() << std::endl;
                return false;
            }

            tiles = tileIDs; // Agora armazenamos os tiles corretamente
            std::cout << "Total de tiles carregados: " << tiles.size() << std::endl;

            for (int y = 0; y < altura; y++) {
                for (int x = 0; x < largura; x++) {
                    int index = y * largura + x;
                    int tileID = tiles[index];

                    if (tileID != 0) { // Se não for um tile vazio
                        sf::Vector2f pos(x * larguraTile, y * alturaTile);
                        sf::Vector2f tam(larguraTile, alturaTile);

                        if (fase == nullptr) {
                            std::cerr << "Erro: ponteiro fase em Mapa é nullptr!" << std::endl;
                        }

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

    if (tiles.empty()) {
        std::cerr << "Erro: Vetor de tiles está vazio!" << std::endl;
        return;
    }

    sf::VertexArray vertices(sf::Quads, largura * altura * 4);

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            int index = y * largura + x;

            if (index >= static_cast<int>(tiles.size())) {
                std::cerr << "Erro: Índice de tile fora do alcance: " << index
                    << " (tamanho: " << tiles.size() << ")" << std::endl;
                continue;
            }

            int tileID = tiles[index];
            if (tileID == 0) continue;

            // Calcula posição do tile na textura
            int tileX = (tileID - 1) % (texturaTileset.getSize().x / larguraTile);
            int tileY = (tileID - 1) / (texturaTileset.getSize().x / larguraTile);

            // Calcula posição do tile no mapa
            float posX = x * larguraTile;
            float posY = y * alturaTile;

            int vIndex = index * 4;

            vertices[vIndex].position = sf::Vector2f(posX, posY);
            vertices[vIndex + 1].position = sf::Vector2f(posX + larguraTile, posY);
            vertices[vIndex + 2].position = sf::Vector2f(posX + larguraTile, posY + alturaTile);
            vertices[vIndex + 3].position = sf::Vector2f(posX, posY + alturaTile);

            float texX = tileX * larguraTile;
            float texY = tileY * alturaTile;

            vertices[vIndex].texCoords = sf::Vector2f(texX, texY);
            vertices[vIndex + 1].texCoords = sf::Vector2f(texX + larguraTile, texY);
            vertices[vIndex + 2].texCoords = sf::Vector2f(texX + larguraTile, texY + alturaTile);
            vertices[vIndex + 3].texCoords = sf::Vector2f(texX, texY + alturaTile);
        }
    }

    if (texturaTileset.getSize().x == 0 || texturaTileset.getSize().y == 0) {
        std::cerr << "Erro: Textura do tileset não carregada corretamente!" << std::endl;
        return;
    }

    sf::RenderStates estados;
    estados.texture = &texturaTileset;

    
    janela.draw(vertices, estados);
}