#pragma once

#include "../stdafx/stdafx.hpp"
#include "../IDs.hpp"
#include "../entes/Ente.hpp"


namespace Estado {
	class Estado : public Ente {
		private:
			bool remover;
		public:
			Estado(const IDs::IDs ID);
			virtual ~Estado();
			virtual void mudarAtivoObs(const bool ativo) = 0;
			virtual void executar() = 0;
			virtual void desenhar();
			void setRemover(bool remover) { this->remover = remover; }
			bool getRemover() { return remover; }
	};
}
