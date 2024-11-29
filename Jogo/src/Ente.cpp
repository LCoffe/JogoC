#include "../include/Ente.hpp"

Ente::Ente(const IDs::IDs ID) : ID(ID) {
	pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();
}

Ente::~Ente() {}

const string Ente::salvarEnte() { 
	ostringstream ss; 
	ss << "ID: " << static_cast<int>(ID) << std::endl;
	return ss.str();
}