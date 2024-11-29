#pragma once

#include "../stdafx/stdafx.hpp"
#include "IDs.hpp"
#include "GerenciadorGrafico.hpp"

class Ente {
	protected:
		Gerenciador::GerenciadorGrafico* pGG;
		const IDs::IDs ID;

		const string salvarEnte();
	public:
		Ente(const IDs::IDs ID);
		virtual ~Ente() = 0;
		const IDs::IDs getID() const { return ID; }
		virtual void draw() = 0;
};