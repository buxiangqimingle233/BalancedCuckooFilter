#include <iostream>
#include <fstream>
#include <sstream>
#include <locale> 
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <map>  
#include <queue>

#include "fk_cuckoo_hashing.h"
using namespace std;

int main(int argc, char *argv[]){
	//define N size, file name and create hashmap
	if(argc < 3){
		cout << "you need to enter the N value and file name" << endl;
		return 0;
	}
	int n = stoi(argv[1]);

	ifstream finput;
	finput.open(argv[2]);

	int hash[n][2];
	int i;
	for(i = 0; i < n; i++){
		hash[i][0] = -1;
		hash[i][1] = -1;
	}
	printMap(hash, n);
	
	string type = "";
	int x;

	while(finput >> type >> x){
		if(type == "i") {
			cuInsert(hash, n, x);
			printMap(hash, n);
		}
		else if(type == "s") {
			int fail = cuSearch(hash, n, x);
			if(fail == -1)
				cout << "search fail:  " <<  x << " was not found in table"<< endl;
			else
				printMap(hash, n);
		}
		else if(type == "d"){
			cuDelete(hash, n, x);
			printMap(hash, n);

		}
	}

	return 0;
}