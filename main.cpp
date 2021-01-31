#include <iostream>		//std::ostream
#include "multiset.h"

struct intcmp{
	bool operator()(int i1, int i2) const {
		if(i1==i2)
			return true;
		else
			return false;
	}
};

struct strcmp{
	bool operator()(const std::string &s1, const std::string &s2) const {
		if(lcase(s1)==lcase(s2))
			return true;
		else
			return false;
	}

private:
	std::string lcase(const std::string &s) const {
		std::string tmp(s);
		for(int i=0;i<tmp.size();++i)
			tmp[i]=std::tolower(tmp[i]);
	
		return tmp;
	}	
};

//________________TEST________________//




//________________MAIN________________//

int main() {
	return 0;
}

