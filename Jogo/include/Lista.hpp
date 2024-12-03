#pragma once


#include <iostream>

using namespace std;

namespace Lista {
	template<class TL>
	class Lista {
		public:
			//Classe Elemento aninhada na classe Lista
			template<class TE>
			class Elemento {
			private:
				TE* elemento;
				Elemento<TE>* prox;
			public:
				Elemento() { prox = nullptr; elemento = nullptr; }
				~Elemento() { prox = nullptr; elemento = nullptr; }
				void setElemento(TE* elemento) { this->elemento = elemento; }
				void setProx(Elemento<TE>* prox) { this->prox = prox; }
				Elemento<TE>* getProx() const { return prox; }
				TE* getElemento() const { return elemento; }
			};
		private:
			Elemento<TL>* pInicio;
			Elemento<TL>* pFim;
			unsigned int tam; // Tamanho da lista (nao precisa ter sinal)
		public:
			Lista();
			~Lista();
			void inserir(TL* elemento);
			void remover(TL* elemento);
			TL* buscar(const TL* elemento) const;
			int getTamanho() const { return static_cast<int>(tam); }
			void limpar();
			void operator++() { tam++; }
			void operator--() { tam--; }
			TL* operator[](int pos);
	};
	template<class TL>
	Lista<TL>::Lista() : pInicio(nullptr), pFim(nullptr), tam(0) {}

	template<class TL>
	Lista<TL>::~Lista() { /*limpar(); vou chamar limpar nas Listas com tipos*/ }

	template<class TL>
	void Lista<TL>::inserir(TL* elemento) {
		if(elemento == nullptr){
			cout << "Elemento nulo" << endl;
			exit(1);
		}
		Elemento<TL>* novo = new Elemento<TL>();
		novo->setElemento(elemento);
		if (pInicio == nullptr) {
			pInicio = novo;
			pFim = novo;
		}else {
			pFim->setProx(novo);
			pFim = novo;
		}
		operator++();
	}

	template<class TL>
	void Lista<TL>::remover(TL * elemento) {
		Elemento<TL>* anterior = nullptr;
		Elemento<TL>* atual = pInicio;
		while (atual != nullptr && atual->getElemento() != elemento) {
			anterior = atual;
			atual = atual->getProx();
		}
		if (atual != nullptr) { // Elemento encontrado
			if (anterior == nullptr) { // Elemento a ser removido eh o primeiro
				pInicio = atual->getProx();
			}else { // Elemento a ser removido nao eh o primeiro
				anterior->setProx(atual->getProx());
			}
			delete atual;
			operator--();
		}
	}

	template<class TL>
	TL* Lista<TL>::buscar(const TL * elemento) const {
		Elemento<TL>* atual = pInicio;
		while (atual != nullptr && atual->getElemento() != elemento) {
			atual = atual->getProx();
		}
		if (atual != nullptr) { // Elemento encontrado
			return atual->getElemento();
		}
		return nullptr;
	}

	template<class TL>
	void Lista<TL>::limpar() {
		Elemento<TL>* atual = pInicio;
		while (atual != nullptr) {
			Elemento<TL>* temp = atual;
			atual = atual->getProx();
			delete temp;
		}
		pInicio = nullptr;
		pFim = nullptr;
		tam = 0;
	}
	template<class TL>
	TL* Lista<TL>::operator[](int pos) {
		if (pos < 0 || static_cast<unsigned int>(pos) >= tam) {
			cout << "Posicao invalida" << endl;
			exit(1);
		}
		Elemento<TL>* atual = pInicio;
		for (int i = 0; i < pos; i++) {
			atual = atual->getProx();
		}
		return atual->getElemento();
	}
}