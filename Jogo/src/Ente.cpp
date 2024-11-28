#include "../include/Ente.hpp"

Ente::Ente(sf::Vector2f pos, sf::Vector2f tam, const string& path): pos(pos), tam(tam){
	this->setTam(tam);
	this->setPos(pos);
	this->setTexture(path);
}

Ente::~Ente() {}

void Ente::setTexture(const string& path) {
	if (!text.loadFromFile(path)) {
		cout << "Erro ao carregar textura" << endl;
	}
	corpo.setTexture(&text);
}