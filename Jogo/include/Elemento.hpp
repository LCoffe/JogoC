#pragma once

#include <iostream>

namespace Lista {
	template<class TE>
	class Elemento {
		private:
			TE* elemento;
			Elemento<TE>* prox;
		public:
			Elemento();
			~Elemento();
			void setElemento(TE* elemento) { this->elemento = elemento; }
			Elemento<TE>* getProx() const { return prox; }
			TE* getElemento() const { return elemento; }
			void setProx(Elemento<TE>* prox) { this->prox = prox; }
	};
	template<class TE>
	Elemento<TE>::Elemento() : elemento(nullptr), prox(nullptr) {}

	template<class TE>
	Elemento<TE>::~Elemento() {}
}