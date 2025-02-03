
/*


#include "../../include/mapas/Mapa.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

Mapa::Mapa(Fase::Fase* fase , const std::string& caminhoMapa, const std::string& caminhoTileset) {
    if (!carregarMapa(caminhoMapa)) {
        std::cerr << "Erro ao carregar o mapa!" << std::endl;
    }
    if (!carregarTileset(caminhoTileset)) {
        std::cerr << "Erro ao carregar o tileset!" << std::endl;
    }



}

bool Mapa::carregarMapa(const std::string& caminhoMapa)
{
    
    std::ifstream arquivo(caminhoMapa);


	if (!arquivo.is_open()) {
		std::cerr << "Erro ao abrir o mapa!" << std::endl;
		return false;
	}


	nlohmann::json jsonMapa;
	arquivo >> jsonMapa;
	arquivo.close();


	std::cout << "Mapa carregado! Tamanho: " << jsonMapa["width"] << "x" << jsonMapa["height"] << std::endl;
	std::cout << "Tile Size: " << jsonMapa["tilewidth"] << " x " << jsonMapa["tileheight"] << std::endl;

	//  Pegar os dados do mapa
	int tileWidth = jsonMapa["tilewidth"];
	int tileHeight = jsonMapa["tileheight"];
	int width = jsonMapa["width"];
	int height = jsonMapa["height"];

	// Encontrar a camada de plataformas

	for (const auto& layer : jsonMapa["layers"]) {
		std::cout << "Encontrando camada: " << layer["name"] << std::endl;
		if (layer["name"] == "Tile Layer 1") {
			std::vector<int> tiles = layer["data"];
			std::cout << "Camada 'Plataformas' encontrada!" << std::endl;

			//  Criar as plataformas com base no mapa
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					int index = y * width + x;
					int tileID = tiles[index];

					if (tileID != 0) { // Se não for um tile vazio
						sf::Vector2f pos(x * tileWidth, y * tileHeight);
						sf::Vector2f tam(tileWidth, tileHeight);

						std::cout << "Chamando criaPlataforma() para o tile (" << x << ", " << y << ") | ID: " << tileID << std::endl;
						fase->criaPlataforma(pos, tam, IDs::IDs::plataforma);
					}
				}
			}
		}
	}

	return true;

}

bool Mapa::carregarTileset(const std::string& caminhoTileset) {
	if (!tileset.loadFromFile(caminhoTileset)) {
		std::cerr << "Erro ao carregar a textura do tileset!" << std::endl;
		return false;
	}

	for (int y = 0; y < largura; y++) {
		for (int x = 0; x < altura; x++) {
			int index = y * largura + x;
			int tileID = tiles[index];

			if (tileID != 0) {
				sf::Vertex* quad = &tilemap[(x + y * largura) * 4];

				quad[0].position = sf::Vector2f(x * larguraTile, y * alturaTile);
				quad[1].position = sf::Vector2f((x + 1) * larguraTile, y * alturaTile);
				quad[2].position = sf::Vector2f((x + 1) * larguraTile, (y + 1) * alturaTile);
				quad[3].position = sf::Vector2f(x * larguraTile, (y + 1) * alturaTile);

				int tu = (tileID - 1) % (tileset.getSize().x / larguraTile);
				int tv = (tileID - 1) / (tileset.getSize().x / larguraTile);

				quad[0].texCoords = sf::Vector2f(tu * larguraTile, tv * alturaTile);
				quad[1].texCoords = sf::Vector2f((tu + 1) * larguraTile, tv * alturaTile);
				quad[2].texCoords = sf::Vector2f((tu + 1) * larguraTile, (tv + 1) * alturaTile);
				quad[3].texCoords = sf::Vector2f(tu * larguraTile, (tv + 1) * alturaTile);
			}
		}
	}

	return true;
}

void Mapa::desenharMapa(sf::RenderWindow& janela) {
	sf::RenderStates states;
	states.texture = &tileset;
	janela.draw(tilemap, states);
}
*/