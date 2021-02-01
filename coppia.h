#ifndef COPPIA_H
#define COPPIA_H

#include <algorithm>	//std::swap

template<typename T>
class coppia{

	public:
		typedef unsigned int size_type; ///< tipo che rappresenta il numero di occorrenze di un elemento

		/**
			Costruttore di default
		**/
		coppia() : _occorrenze(0){}

		/**
			Costruttore secondario
			Crea una coppia con elemento e occorrenze di quell'elemento

			@param elem elemento della coppia
			@param occ numero di occorrenze
		**/
		coppia(const T &elem, size_type occ) : _elemento(elem), _occorrenze(occ){}

		/**
			Costruttore secondario
			Crea una coppia con un elemento ed una sola occorrenza
			
			@param elem elemento della coppia
		**/
		coppia(const T &elem) : _elemento(elem), _occorrenze(1){}

		/**
			Distruttore
		**/
		~coppia(){}

		/**
			Costruttore copia

			@param other coppia da copiare
		**/
		coppia(const coppia &other) : _elemento(other._elemento), _occorrenze(other._occorrenze){}

		/**
			Operatore di assegnamento

			@param other coppia da assegnare
		**/
		coppia& operator=(const coppia &other){
			if(this!=other){
				coppia tmp(other);
				std::swap(_elemento, tmp._elemento);
				std::swap(_occorrenze, tmp._occorrenze);
			}
			return *this;
		}

		/**
			Metodo getter per l'elemento

			@return variabile _elemento
		**/
		T &elemento(){
			return _elemento;
		}

		/**
			Metodo getter costante dell'elemento

			@return variabile constante _elemento
		**/
		const T &elemento() const{
			return _elemento;
		}

		/**
			Metodo getter per le occorrenze

			@return variabile _occorrenze
		**/
		size_type occorrenze() const{
			return _occorrenze;
		}

		/**
			Metodo setter per le occorrenze

			@param valore valore in input da assegnare alla variabile _occorrenze
		**/

		void set_occorrenze(size_type valore){
			_occorrenze=valore;
		}

	private:
		T _elemento; ///< elemento della coppia
		size_type _occorrenze; ///< numero di occorrenze dell'elemento
}; /// fine classe coppia
#endif
