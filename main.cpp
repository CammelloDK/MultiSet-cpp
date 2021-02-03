#include <iostream>		//std::ostream
#include "multiset.h"

/**
	@file main.cpp
**/

//________________FUNTORI________________//

/**
	@brief Funtore di confronto per interi

	@param i1 primo intero da confrontare
	@param i2 secondo intero da confrontare

	@return true se contengono lo stesso valore, false altrimenti
**/
struct intcmp{
	bool operator()(int i1, int i2) const {
		if(i1==i2)
			return true;
		else
			return false;
	}
};

/**
	@brief Funtore di confronto per char

	@param c1 primo char da confrontare
	@param c2 secondo char da confrontare

	@return true se contengono lo stesso valore, false altrimenti
**/
struct charcmp{
	bool operator()(char c1, char c2) const {
		if(c1==c2)
			return true;
		else
			return false;
	}
};

/**
	@brief Funtore di confronto per stringhe

	@param s1 prima stringa da confrontare
	@param s2 seconda stringa da confrontare

	@return true se contengono lo stesso valore, false altrimenti
**/
struct strcmp{
	bool operator()(const std::string &s1, const std::string &s2) const {
		if(lcase(s1)==lcase(s2))
			return true;
		else
			return false;
	}

private:

	/**
		Metodo per convertire i caratteri di una stringa in caratteri minuscoli

		@param s stringa da convertire

		@return tmp stringa convertita
	**/
	std::string lcase(const std::string &s) const {
		std::string tmp(s);
		for(int i=0;i<tmp.size();++i)
			tmp[i]=std::tolower(tmp[i]);
	
		return tmp;
	}	
};

//________________TEST________________//

void test1_int(){
	std::cout<<"______//________________TEST_#1_-_INT_______________//______"<<std::endl<<std::endl;

	typename multiset<int,intcmp>::const_elem_iterator ibegin,iend;

	std::cout<<"//_______________COSTRUTTORE_DEFAULT______________//"<<std::endl;

	multiset<int, intcmp> m1;
	std::cout<<"multiset<int, intcmp> m1: "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;
	
	std::cout<<"//_______________ADD______________//"<<std::endl;
	
	m1.add(1);
	std::cout<<"M1.add(1): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.add(1);
	std::cout<<"M1.add(1): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.add(6,2);
	std::cout<<"M1.add(6,2): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//_______________REMOVE______________//"<<std::endl;

	m1.remove(6,2);
	std::cout<<"m1.remove(6,2): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.remove(1);
	std::cout<<"M1.remove(1): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.remove(1);
	std::cout<<"M1.remove(1): "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//______________OPERATOR=_____________//"<<std::endl;

	m1.add(9,5);
	std::cout<<"M1.add(9,5): "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	multiset<int, intcmp> m2=m1;

	std::cout<<"multiset<int, intcmp> m2=m1"<<std::endl;
	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M2: "<<m2<<std::endl<<std::endl;

	std::cout<<"//_____________COSTRUTTORE_COPIA____________//"<<std::endl;

	multiset<int, intcmp> m3(m2);

	std::cout<<"multiset<int, intcmp> m3(m2)"<<std::endl;
	std::cout<<"M2: "<<m2<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl<<std::endl;

	std::cout<<"//______________OPERATOR==_____________//"<<std::endl;

	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"m1==m3?: "<<(m1==m3)<<std::endl;
	std::cout<<"---------"<<std::endl;

	m3.remove(9,2);
	std::cout<<"M3.remove(9,2)"<<std::endl;
	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"m1==m3?: "<<(m1==m3)<<std::endl<<std::endl;

	std::cout<<"//______________CLEAR_____________//"<<std::endl;

	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"N_ELEM: "<<m3.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m3.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m3.clear();
	std::cout<<"m3.clear(): "<<m3<<std::endl;
	std::cout<<"N_ELEM: "<<m3.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m3.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//______________CONTAINS_____________//"<<std::endl;

	std::cout<<"M2: "<<m2<<std::endl;
	std::cout<<"m2.contains(9): "<<m2.contains(9)<<std::endl;
	std::cout<<"m2.contains(20): "<<m2.contains(20)<<std::endl<<std::endl;

	std::cout<<"//______________COSTRUTTORE_SEQUENZA_Q_____________//"<<std::endl;

	multiset<int, intcmp> m4;
	std::cout<<"M4: "<<m4<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl<<std::endl;

	m4.add(1,2);
	std::cout<<"M4.add(1,2): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m4.add(3,3);
	std::cout<<"M4.add(3,3): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m4.add(5,7);
	std::cout<<"M4.add(5,7): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	multiset<int, intcmp> m5(m4.elem_begin(),m4.elem_end());
	std::cout<<"multiset<int, intcmp> m5(m4.elem_begin(),m4.elem_end())"<<std::endl;
	std::cout<<"M5: "<<m5<<std::endl;
	for(ibegin=m5.elem_begin(), iend=m5.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m5.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m5.get_dimensione()<<std::endl<<std::endl;
}

void test2_str(){
	std::cout<<"______//________________TEST_#2_-_STRING_______________//______"<<std::endl<<std::endl;
	
	typename multiset<std::string,strcmp>::const_elem_iterator ibegin,iend;

	std::cout<<"//_______________COSTRUTTORE_DEFAULT______________//"<<std::endl;

	multiset<std::string, strcmp> m1;
	std::cout<<"multiset<std::string, strcmp> m1: "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;
	
	std::cout<<"//_______________ADD______________//"<<std::endl;
	
	m1.add("rosso");
	std::cout<<"M1.add(\"rosso\"): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.add("rosso");
	std::cout<<"M1.add(\"rosso\"): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.add("blu",2);
	std::cout<<"M1.add(\"blu\",2): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//_______________REMOVE______________//"<<std::endl;

	m1.remove("blu",2);
	std::cout<<"m1.remove(\"blu\",2): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.remove("rosso");
	std::cout<<"M1.remove(\"rosso\"): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.remove("rosso");
	std::cout<<"M1.remove(\"rosso\"): "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//______________OPERATOR=_____________//"<<std::endl;

	m1.add("verde",5);
	std::cout<<"M1.add(\"verde\",5): "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	multiset<std::string, strcmp> m2=m1;

	std::cout<<"multiset<std::string, strcmp> m2=m1"<<std::endl;
	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M2: "<<m2<<std::endl<<std::endl;

	std::cout<<"//_____________COSTRUTTORE_COPIA____________//"<<std::endl;

	multiset<std::string, strcmp> m3(m2);

	std::cout<<"multiset<std::string, strcmp> m3(m2)"<<std::endl;
	std::cout<<"M2: "<<m2<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl<<std::endl;

	std::cout<<"//______________OPERATOR==_____________//"<<std::endl;

	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"m1==m3?: "<<(m1==m3)<<std::endl;
	std::cout<<"---------"<<std::endl;

	m3.remove("verde",2);
	std::cout<<"M3.remove(\"verde\",2)"<<std::endl;
	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"m1==m3?: "<<(m1==m3)<<std::endl<<std::endl;

	std::cout<<"//______________CLEAR_____________//"<<std::endl;

	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"N_ELEM: "<<m3.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m3.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m3.clear();
	std::cout<<"m3.clear(): "<<m3<<std::endl;
	std::cout<<"N_ELEM: "<<m3.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m3.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//______________CONTAINS_____________//"<<std::endl;

	std::cout<<"M2: "<<m2<<std::endl;
	std::cout<<"m2.contains(\"verde\"): "<<m2.contains("verde")<<std::endl;
	std::cout<<"m2.contains(\"giallo\"): "<<m2.contains("giallo")<<std::endl<<std::endl;

	std::cout<<"//______________COSTRUTTORE_SEQUENZA_Q_____________//"<<std::endl;

	multiset<std::string, strcmp> m4;
	std::cout<<"M4: "<<m4<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl<<std::endl;

	m4.add("rosso",2);
	std::cout<<"M4.add(\"rosso\",2): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m4.add("blu",3);
	std::cout<<"M4.add(\"blu\",3): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m4.add("verde",7);
	std::cout<<"M4.add(\"verde\",7): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	multiset<std::string, strcmp> m5(m4.elem_begin(),m4.elem_end());
	std::cout<<"multiset<std::string, strcmp> m5(m4.elem_begin(),m4.elem_end())"<<std::endl;
	std::cout<<"M5: "<<m5<<std::endl;
	for(ibegin=m5.elem_begin(), iend=m5.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m5.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m5.get_dimensione()<<std::endl<<std::endl;
}

void test3_char(){
	std::cout<<"______//________________TEST_#3_-_CHAR_______________//______"<<std::endl<<std::endl;

	typename multiset<char,charcmp>::const_elem_iterator ibegin,iend;

	std::cout<<"//_______________COSTRUTTORE_DEFAULT______________//"<<std::endl;

	multiset<char, charcmp> m1;
	std::cout<<"multiset<char, charcmp> m1: "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;
	
	std::cout<<"//_______________ADD______________//"<<std::endl;
	
	m1.add('a');
	std::cout<<"M1.add('a'): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.add('a');
	std::cout<<"M1.add('a'): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.add('f',2);
	std::cout<<"M1.add('f',2): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//_______________REMOVE______________//"<<std::endl;

	m1.remove('f',2);
	std::cout<<"m1.remove('f',2): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.remove('a');
	std::cout<<"M1.remove('a'): "<<m1<<std::endl;
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m1.remove('a');
	std::cout<<"M1.remove('a'): "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//______________OPERATOR=_____________//"<<std::endl;

	m1.add('h',5);
	std::cout<<"M1.add('h',5): "<<m1<<std::endl;
	std::cout<<"N_ELEM: "<<m1.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m1.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	multiset<char, charcmp> m2=m1;

	std::cout<<"multiset<char, charcmp> m2=m1"<<std::endl;
	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M2: "<<m2<<std::endl<<std::endl;

	std::cout<<"//_____________COSTRUTTORE_COPIA____________//"<<std::endl;

	multiset<char, charcmp> m3(m2);

	std::cout<<"multiset<char, charcmp> m3(m2)"<<std::endl;
	std::cout<<"M2: "<<m2<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl<<std::endl;

	std::cout<<"//______________OPERATOR==_____________//"<<std::endl;

	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"m1==m3?: "<<(m1==m3)<<std::endl;
	std::cout<<"---------"<<std::endl;

	m3.remove('h',2);
	std::cout<<"M3.remove('h',2)"<<std::endl;
	std::cout<<"M1: "<<m1<<std::endl;
	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"m1==m3?: "<<(m1==m3)<<std::endl<<std::endl;

	std::cout<<"//______________CLEAR_____________//"<<std::endl;

	std::cout<<"M3: "<<m3<<std::endl;
	std::cout<<"N_ELEM: "<<m3.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m3.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m3.clear();
	std::cout<<"m3.clear(): "<<m3<<std::endl;
	std::cout<<"N_ELEM: "<<m3.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m3.get_dimensione()<<std::endl<<std::endl;

	std::cout<<"//______________CONTAINS_____________//"<<std::endl;

	std::cout<<"M2: "<<m2<<std::endl;
	std::cout<<"m2.contains('h'): "<<m2.contains('h')<<std::endl;
	std::cout<<"m2.contains('z'): "<<m2.contains('z')<<std::endl<<std::endl;

	std::cout<<"//______________COSTRUTTORE_SEQUENZA_Q_____________//"<<std::endl;

	multiset<char, charcmp> m4;
	std::cout<<"M4: "<<m4<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl<<std::endl;

	m4.add('a',2);
	std::cout<<"M4.add('a',2): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m4.add('c',3);
	std::cout<<"M4.add('c',3): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	m4.add('s',7);
	std::cout<<"M4.add('s',7): "<<m4<<std::endl;
	for(ibegin=m4.elem_begin(), iend=m4.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m4.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m4.get_dimensione()<<std::endl;
	std::cout<<"---------"<<std::endl;

	multiset<char, charcmp> m5(m4.elem_begin(),m4.elem_end());
	std::cout<<"multiset<char, charcmp> m5(m4.elem_begin(),m4.elem_end())"<<std::endl;
	std::cout<<"M5: "<<m5<<std::endl;
	for(ibegin=m5.elem_begin(), iend=m5.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<"N_ELEM: "<<m5.get_numelementi()<<std::endl;
	std::cout<<"DIM: "<<m5.get_dimensione()<<std::endl<<std::endl;
}

//________________MAIN________________//

int main() {

	test1_int();
	test2_str();
	test3_char();

	return 0;
}

