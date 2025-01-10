#include "../include/Estado.hpp"

namespace Estado {
	Estado::Estado(const IDs::IDs ID) : Ente(ID), remover(false) {
	}
	Estado::~Estado() {
	}
	void Estado::desenhar() {
	}
}
