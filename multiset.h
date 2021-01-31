#ifndef MULTISET_H
#define MULTISET_H

#include <stdexcept>	//std::runtime_error
#include <algorithm>	//std::swap
//#include <cassert>		//
//#include <stddef.h>		//
#include <iostream>		//std::ostream
#include "coppia.h"

/**
	Classe per gestione di eventuali eccezioni sollevate dal MultiSet
**/
class el_non_trovato : public std::runtime_error{

public:

	/**
		Costruttore secondario che prende in input un messaggio di errore

		@param mes messaggio di errore
	**/
	el_non_trovato(const char *mes) : std::runtime_error(mes){}
};


/**
	Classe che implementa un MultiSet di elementi generici T.
	I dati sono memorizzati attraverso una lista composta da coppie <elemento, occorrenze>

	@brief

	@param T tipo del dato
	@param C funtore di comparazione tra elementi
*/

template <typename T, typename C>
class multiset{

	typedef unsigned int size_type; ///< tipo che rappresenta il numero di occorrenze di un elemento

	/**
		Struct del nodo della lista di elementi
	**/
	struct nodo {
		coppia<T> dato; ///< dato di tipo T
		nodo *prossimo; ///< puntatore all'elemento successivo

		/**
			Costruttore del nodo partendo da un elemento

			@param elem elemento da inserire
		**/
		nodo(const T &elem) : dato(elem), prossimo(nullptr){}

		/**
			Costruttore del nodo partendo da un elemento ripetuto

			@param elem elemento da inserire
			@param occ numero di occorrenze dell'elemento
		**/
		nodo(const T &elem, size_type occ) : dato(elem, occ), prossimo(nullptr){}

		/**
			Costruttore del nodo dato un elemento ed il nodo successivo
			
			@param elem elemento da inserire
		**/
		nodo(const T &elem, nodo *n) : dato(elem), prossimo(n){}

		/**
			Costruttore del nodo dato un elemento ripetuto più volte ed il nodo successivo
			
			@param elem elemento da inserire
			@param occ numero di occorrenze dell'elemento
		**/
		nodo(const T &elem, size_type occ, nodo *n) : dato(elem, occ), prossimo(n){}

		/**
			Costruttore copia
			
			@param other nodo da copiare
		**/
		nodo(const nodo &other) : dato(other.dato), prossimo(other.prossimo){}

		/**
			Costruttore di default
		**/
		nodo() : prossimo(nullptr){}

		/**
			Distruttore
		**/
		~nodo(){}

		/**
			Operatore di assegnamento

			@param other nodo da assegnare
		**/
		nodo&operator=(const nodo &other){
			if(this!=&other){
				dato=other.dato;
				prossimo=other.prossimo;
			}
			return *this;
		}

	}; //fine struct nodo

	nodo *_testa; ///< testa del MultiSet
	int _dimensione; ///< numero di nodi
	int _numelementi; ///< numero totale di elementi inseriti

	/**
		Metodo helper utile per ritornare il puntatore all'elemento passato come argomento

		@param elem elemento da cercare
		
		@return puntatore al nodo se questo esite, 0 altrimenti
	**/
	nodo *find_helper(const T &elem) const{
		nodo *corr=_testa;
		C comp;

		while(corr!=nullptr){
			if(comp(corr->dato.elemento(), elem))
				return corr;
			corr=corr->prossimo;
		}
		return nullptr;
	}

	/**
		Metodo utile per ritornare il puntatore del nodo precedente

		@param mionodo nodo di cui cercare il precedente
		
		@return nodo precedente se non ne ha, sè stesso
	**/
	nodo *find_previous(const nodo *mionodo) const {
		nodo *corr = _testa;
		nodo *prossimo = corr->prossimo;

		while(mionodo!=prossimo || prossimo==nullptr) {
			corr = prossimo;
			prossimo = corr->prossimo;	
		}
		return corr;
	}
	
	public:

		//Costruttori|Distruttore

		/**
			Costruttore di default
		*/
		multiset() : _testa(nullptr), _dimensione(0), _numelementi(0){}

		/**
			Distruttore
		*/
		~multiset(){
			clear();
		}

		/**
			Metodo per svuotare il MultiSet
		**/
		void clear(){
			nodo *tmp=_testa;
			nodo *tmp2=nullptr;

			while(tmp!=nullptr){
				tmp2=tmp->prossimo;
				delete tmp;
				tmp=tmp2;
			}
		}

		/**
			Costruttore copia
			
			@param other MultiSet da copiare
		**/
		multiset(const multiset &other) : _testa(nullptr), _dimensione(0), _numelementi(0){
			nodo *tmp=other._testa;

			try{
				while(tmp!=nullptr){
					add(tmp->dato.elemento(), tmp->dato.occorrenze());
					tmp=tmp->prossimo;
				}
			}
			catch(...){
				clear();
				throw;
			}
		}

		/**
			Costruttore a partire da sequenza di dati Q (iteratori generici)

			@param inizio iteratore di inizio sequenza
			@param fine iteratore di fine sequenza
		**/

		template<typename Q>
		multiset(Q inizio, Q fine) : _testa(nullptr), _dimensione(0), _numelementi(0) {
			try{
				while(begin != end) {
		    		add(static_cast<T>(*begin));
		    		begin++;
		   		}
		  	}
		  	catch(...){
		   		clear();
		   		throw;
		  	}
		}


		/**
			Operatore di assegnamento

			@param other MultiSet da assegnare
		**/
		multiset& operator=(const multiset &other){
			if(this!=&other){
				multiset tmp(other);
				std::swap(this->_testa, tmp._testa);
				std::swap(this->_dimensione, tmp._dimensione);
				std::swap(this->_numelementi, tmp._numelementi);
			}
			return *this;
		}

		/**
			Operatore di confronto

			@param other MultiSet da confrontare
			
			@return true se MultiSet contengono stessi elementi con stesse ricorrenze, false altrimenti
		**/
		bool operator==(const multiset &other) const{
			typename multiset<T,C>::const_iterator i,ie,j,je;
			if(this->_dimensione!=other._dimensione)
				return false;
			else{
				for(i=this->begin(), ie=this->end();i!=ie;++i){
					bool ok=false;
					for(j=other.begin(), je=other.end();j!=je;++j){
						if(comp(i,j))
							ok=true;
					}
					if(!ok)
						return false;
				}
			}
			return true;
		}

		/**
			Metodo che inserisce nel MultiSet un nuovo elemento T

			@param elem elemento da inserire
			@param occ numero occorrenze dell'elemento
		**/
		void add(const T &elem, size_type occ){
			if(!contains(elem)){
				if(_testa==nullptr)
					_testa=new nodo(elem, occ);
				else{
					nodo *tmp=_testa;
					_testa=new nodo(elem, occ);
					_testa->prossimo=tmp;
				}
				_dimensione++;
				_numelementi +=occ;
			}
			else{
				nodo *n=find_helper(elem);
				n->dato.set_occorrenze(n->dato.occorrenze()+occ);
				_numelementi +=occ;
			}
		}

		/**
			Metodo che inserisce nel MultiSet un nuovo elemento T senza occorrenze

			@param elem elemento da inserire
		**/
		void add(const T &elem){
			if(!contains(elem)){
				if(_testa==nullptr)
					_testa=new nodo(elem);
				else{
					nodo *tmp=_testa;
					_testa=new nodo(elem);
					_testa->prossimo=tmp;
				}
				_dimensione++;
				_numelementi++;
			}
			else{
				nodo *n=find_helper(elem);
				n->dato.set_occorrenze(n->dato.occorrenze()+1);
				_numelementi++;
			}
		}

	/**
		Metodo che rimuove dal MultiSet un'occorrenza dell'elemento passato come parametro

		@param elem elemento di cui rimuovere l'occorrenza
	**/
	void remove(const T &elem){
		if(contains(elem)){
			nodo *n=find_helper(elem);
			if(n->dato.occorrenze()>1)
				n->dato.set_occorrenze(n->dato.occorrenze()-1);
			else{
				nodo *precedente=find_previous(n);
				precedente->prossimo=n->prossimo;
				delete n;
			}
		}else
			throw el_non_trovato("Elemento non trovato");
	}

	/**
		Metodo che rimuove dal MultiSet un numero di occorrenze definito dell'elemento passato come parametro

		@param elem elemento di cui rimuovere l'occorrenza
		@occ numero di occorrenze da eliminare
	**/
	void remove(const T &elem, size_type occ){
		for(int i=0;i<occ;i++)
			remove(elem);
	}

	/**
		Metodo utile a verificare l'efettiva esistenza di un elemento all'interno del MultiSet

		@param elem elemento di cui verificare l'esistenza
		
		@return true se è verificata l'esistenza, false altrimenti
	**/
	bool contains(const T &elem) const{
		nodo *n=find_helper(elem);
		if(n!=nullptr)
			return true;
	}

	/**
		Metodo getter utile a conoscere il numero di elementi del MultiSet

		@return numero di elementi del MultiSet
	**/
	int get_numelementi() const{
		return _numelementi;
	}

	/**
		Metodo getter utile a conoscere il numero di occorrenze di un elemento passato come parametro

		@param elem elemento di cui conoscere il numero di occorrenze
		
		@return numero di occorrene dell'elemento
	**/
	size_type get_occorrenze(const T &elem) const{
		nodo *n=find_helper(elem);
		if(n!=nullptr)
			return n->dato.occorrenze();
		else
			return 0;
	}

	/**
		Iteratore forward di sola lettura per coppia di valori
	**/
	class const_iterator{
		public:
			typedef std::forward_iterator_tag	iterator_category;
			typedef coppia<T> 					value_type;
			typedef ptrdiff_t 					difference_type;
			typedef const coppia<T> 			pointer;

			/**
				Costruttore di default
			**/
			const_iterator(){
				n=nullptr;
			}

			/**
				Costruttore copia
				
				@param other iteratore da copiare
			**/
			const_iterator(const const_iterator &other){
				n=other.n;
			}

			/**
				Operatore di assegnamento

				@param other iteratore da assegnare
				
				@return *this
			**/
			const_iterator& operator=(const const_iterator &other){
				n=other.n;
				return *this;
			}

			/**
				Distruttore
			**/
			~const_iterator() {}

			/**
				Dereferenziamento per reference

				@return riferimento costante alla coppia
			**/
			const coppia<T>& operator*() const{
				return n->dato;
			}

			/**
				Dereferenziamento per puntatore

				@return puntatore costante alla coppia
			**/
			const coppia<T>* operator->() const{
				return&(n->dato);
			}

			/**
				Operatore di post incremento

				@return iteratore alla coppia precedente
			**/
			const_iterator operator++(int){
				const_iterator tmp(*this);
				n=n->prossimo;
				return tmp;
			}

			/**
				Operatore di pre incremento

				@return iteratore alla coppia successiva
			**/
			const_iterator operator++(){
				n=n->prossimo;
				return *this;
			}

			/**
				Operatore di confronto di uguaglianza

				@param other iteratore da confrontare
				
				@return true se i due confrontati puntano alla stessa posizione, false altrimenti
			**/
			bool operator==(const const_iterator &other) const{
				if(n==other.n)
					return true;
				else
					return false;
			}

			/**
				Operatore di confronto di disuguaglianza

				@param other iteratore da confrontare
				
				@return false se i due confrontati puntano alla stessa posizione, true altrimenti
			**/
			bool operator!=(const const_iterator &other) const{
				if(n!=other.n)
					return true;
				else
					return false;
			}

		private:
			const nodo *n; ///< puntatore al nodo corrente del MultiSet
			friend class multiset;

			/**
				Costruttore secondario di inizializzazione ad un nodo della lista BOH

				@param pn puntatore al nodo della lista
			**/
			const_iterator(const nodo *pn){
				n=pn;
			}

	}; //fine classe const_iterator

	/**
		Iteratore di inizio sequenza

		@return iteratore al primo elemento della sequenza
	**/
	const_iterator begin() const{
		return const_iterator(_testa);
	}

	/**
		Iteratore di fine sequenza

		@return iteratore all'ultimo elemento della sequenza
	**/
	const_iterator end() const{
		return const_iterator();
	}

	/**
		Iteratore forward di sola lettura per singolo elemento
	**/
	class const_elem_iterator{
		public:
			typedef std::forward_iterator_tag 	iterator_category;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef const T*					pointer;
			typedef const T&					reference;

			/**
				Costruttore di default
			**/
			const_elem_iterator(){
				n=nullptr;
				elem=nullptr;
				nocc=0;
			}

			/**
				Costruttore copia

				@param other iteratore da copiare
			**/
			const_elem_iterator(const const_elem_iterator &other){
				elem=other.elem;
				n=other.n;
				nocc=other.nocc;
			}

			/**
				Operatore di assegnamento

				@param other iteratore da assegnare
				
				@return *this
			**/
			const_elem_iterator& operator=(const const_elem_iterator &other){
				elem=other.elem;
				n=other.n;
				nocc=other.nocc;
				return *this;
			}

			/**
				Distruttore
			**/
			~const_elem_iterator() {}

			/**
				Dereferenziamento per reference

				@return riferimento costante all'elemento
			**/
			const T& operator*() const{
				return *(elem);
			}

			/**
				Dereferenziamento per puntatore

				@return puntatore costante all'elemento
			**/
			const T* operator->() const{
				return elem;
			}

			/**
				Operatore di post incremento

				@return iteratore all'elemento precedente
			**/
			const_elem_iterator operator++(int){
				const_elem_iterator tmp(*this);
				if(nocc>1)
					nocc--;
				else{
					n=n->prossimo;
					if(n!=nullptr){
						elem=&(n->dato.elemento());
						nocc=n->dato.occorrenze();
					}else{
						elem=nullptr;
						nocc=0;
					}
				}
				return tmp;
			}

			/**
				Operatore di pre incremento

				@return iteratore all'elemento successivo
			**/
			const_elem_iterator& operator++(){
				if(nocc>1){
					nocc--;
					return *this;
				}
				else{
					n=n->prossimo;
					if(n!=nullptr){
						elem=&(n->dato.elemento());
						nocc=n->dato.occorrenze();
					}
					else{
						elem=nullptr;
						nocc=0;
					}
					return *this;
				}
			}

			/**
				Operatore di confronto di uguaglianza

				@param other iteratore da confrontare
				
				@return true se i due iteratori puntano alla stessa posizione, false altrimenti
			**/
			bool operator==(const const_elem_iterator &other) const{
				if(n==other.n && nocc==other.nocc && elem==other.elem)
					return true;
				else
					return false;
			}

			/**
				Operatore di confronto di disuguaglianza

				@param other iteratore da confrontare
				
				@return false se i due iteratori puntano alla stessa posizione, true altrimenti
			**/
			bool operator!=(const const_elem_iterator &other) const{
				if(n!=other.n || nocc!=other.nocc || elem!=other.elem)
					return true;
				else
					return false;
			}
		private:
			const nodo *n; ///< puntatore al nodo corrente del MultiSet
			const T *elem; ///< puntatore all'elemento del nodo corrente
			size_type nocc; ///< numero di occorrenze dell'elemento del nodo n
			friend class multiset;

			/**
				Costruttore secondario di inizializzazione ad un nodo della lista BOH

				@param pn puntatore al nodo della lista
			**/
			const_elem_iterator(const nodo *pn){
				n=pn;
				elem=&(pn->dato.elemento());
				nocc=pn->dato.occorrenze();
			}
	}; // fine classe const_elem_iterator

	/**
		Iteratore di inizio sequenza

		@return iteratore al primo elemento della sequenza
	**/
	const_elem_iterator elem_begin() const{
		return const_elem_iterator(_testa);
	}

	/**
		Iteratore di fine sequenza

		@return iteratore all'ultimo elemento della sequenza
	**/
	const_elem_iterator elem_end() const{
		return const_elem_iterator();
	}

	private:
		/**
			Metodo di supporto all'operatore ==

			@param primo primo iteratore
			@param secondo secondo iteratore
			
			@return true se i due MultiSet contengono stessi elemtni con stesse occorrenze BOH
		**/
		bool comp(typename multiset<T,C>::const_iterator primo, typename multiset<T,C>::const_iterator secondo) const{
			C comp;
			if(comp(primo->elemento(), secondo->elemento())){
				if(primo->occorrenze()==secondo->occorrenze()){
					return true;
				}
			}
			return false;
		}

}; // fine classe multiset

/**
	Operatore di stream di output per la stampa del multiset

	@param outstream stream di output
	@param ms MultiSet da stampare
	
	@return stream di output
**/
template<typename T, typename F>
std::ostream& operator<<(std::ostream &outstream, const multiset<T,F> &ms){
	typename multiset<T,F>::const_iterator i,ie;
	for(i=ms.begin(),ie=ms.end();i!=ie;++i)
		outstream<<"<"<<i->elemento()<<", "<<i->occorrenze()<<"> ";
	return outstream;
}

#endif
