#include <iostream>		//std::ostream
#include "multiset.h"

/**
	Funtore di confronto per interi

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
	Funtore di confronto per stringhe

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

void test1(){
	std::cout<<"//________________TEST_#1_______________//"<<std::endl;

	multiset<int, intcmp> m1;

	typename multiset<int,intcmp>::const_elem_iterator ibegin,iend;

	//m1=new multiset<int,intcmp>(); //Costr default

	m1.add(1);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	m1.add(1);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	m1.add(3,4);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	m1.add(4,2);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	m1.add(1,2);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;


	m1.remove(1);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	m1.remove(3,2);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	/*m1.remove(3,20);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;*/

	m1.remove(1,3);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;

	m1.remove(3,2);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;


	/*m1.add(5);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;*/

	/*m1.remove(4,2);
	for(ibegin=m1.elem_begin(), iend=m1.elem_end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<", ";
	std::cout<<std::endl;
	std::cout<<m1<<std::endl;*/

	/*multiset<int, intcmp> m2=m1;

	std::cout<<m1<<std::endl;
	std::cout<<m2<<std::endl;

	std::cout<<(m1==m2)<<std::endl;*/

	multiset<int, intcmp> m3;
	m3.add(1);
	m3.add(2,3);
	m3.remove(2,2);
	multiset<int, intcmp> m4=m3;
	/*m3.add(1);
	m4.add(1);*/
	std::cout<<m3<<std::endl;
	std::cout<<m4<<std::endl;
	std::cout<<(m3==m4)<<std::endl;




}

void test2(){
	std::cout<<"//________________TEST_#2_______________//"<<std::endl;
}


//________________MAIN________________//

int main() {

	test1();
	//test2();

	return 0;
}

