#include "../include/Personagem.hpp"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const string& path): Ente(pos, tam, path), velocidade(sf::Vector2f(0.1f, 0.1f)){}

Personagem::~Personagem() {}