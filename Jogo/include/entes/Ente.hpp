#pragma once

#include "../../stdafx/stdafx.hpp"
#include "../IDs.hpp"
#include "../gerenciadores/GerenciadorGrafico.hpp"

class Ente {
	protected:
		Gerenciador::GerenciadorGrafico* pGG;
		const IDs::IDs ID;
	public:
		Ente(const IDs::IDs ID);
		virtual ~Ente() = 0;
		const IDs::IDs getID() const { return ID; }
		virtual void desenhar() = 0;
};