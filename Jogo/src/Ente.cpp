#include "../include/Ente.hpp"

Ente::Ente(const IDs::IDs ID) : ID(ID) {
	pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();
}

Ente::~Ente() {}