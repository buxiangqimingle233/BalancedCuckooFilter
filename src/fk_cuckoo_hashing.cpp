#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>  
#include <map>
#include <math.h>
#include <map>


#include "fk_cuckoo_hashing.h"
using namespace std;

void printMap(int arr[][2], int n){
	int i, j;
	for(i = 0; i < 2; i++){
		cout << "TABLE h" << i+1 << "|";
		for(j = 0; j < n; j++){
			if(arr[j][i] == -1)
				cout << "-";
			else 
				cout << arr[j][i];
			cout << "|";
		}
		cout << endl;
	}
}
void printArrow(int n, int val){
	string arrow = "         ";
	int i;
	for(i = 0; i < n; i++){
		if(i == val)
			arrow += "| ";
		else
			arrow += "  ";
	}
	cout << arrow << endl;
}




int cuSearch(int arr[][2], int n, int val){
	int hKey = val%n;
	int gKey = (val/n)%n;
	if(arr[hKey][0] == val){
		cout << val << " found at index " << hKey << " in table h1" << endl;
		return hKey;
	}
	else if(arr[gKey][1] == val){
		cout << val << " found at index " << gKey << " in table h2" << endl;
		return gKey;
	}
	else{
		return -1;
	}
}
int cuDelete(int arr[][2], int n, int val){
	int hKey = val%n;
	int gKey = (val/n)%n;
	if(arr[hKey][0] == val){
		cout << val << " deleted from index " << hKey << " in table h1" << endl;
		arr[hKey][0] = -1;

		return hKey;
	}
	else if(arr[gKey][1] == val){
		cout << val << " deleted from index  " << gKey << " in table h2" << endl;
		arr[gKey][1] = -1;

		return gKey;
	}
	else{
		cout << "delete failed: " <<  val << " Not found" << endl;
	}
	return 0;
}
int cuInsert(int arr[][2], int n, int val){
	int hKey = val%n;
	int gKey = (val/n)%n;

	int check = cuSearch(arr, n, val);
	if(check != -1){
		cout << "insert failed: " << val << " already exists in table" <<  endl;
	}
	else{
		if(arr[hKey][0] == -1){
			cout << "success: insert of " << val  << " into slot " << hKey <<  endl;
			arr[hKey][0] = val;
			return hKey;
		}
		else if(arr[hKey][0] != -1){
			cout << "eviction needed" << endl;
			int loopCount = 0;

			int oldVal = arr[hKey][0];
			arr[hKey][0] = val;
			int key = (oldVal/n)%n;
			int tSwitch = 1;

			map<string, int> cycles;
			string x = to_string(val) + " 0 " + to_string(hKey);
			cycles[x] = 1;
			while(oldVal != -1 && !(cycleDetection(cycles))){
				string x = to_string(oldVal) + " " + to_string(tSwitch) + " " + to_string(key);
				if(cycles.count(x) == 0){
					cycles[x] = 1;
				}
				else{
					cycles[x] = cycles[x]+1;
				}

				oldVal = place(arr, n, key, tSwitch, oldVal, cycles);
				if(tSwitch == 0){
					tSwitch = 1;
					key = (oldVal/n)%n;
				}
				else{
					tSwitch = 0;
					key = oldVal%n;
				}
				loopCount++;	
			}
			printMap(arr, n);
		}
	}

	return 0;
}



int place(int arr[][2], int n, int key, int tSwitch, int val, map< string, int> cycles){
	int oldVal = arr[key][tSwitch];
	arr[key][tSwitch] = val;
	return oldVal;
}

bool cycleDetection(map< string, int> cycles){
	for(map<string,int>::iterator it=cycles.begin(); it!=cycles.end(); ++it){
		if(it->second > 2){
			cout << "insertion failed: entered loop failstate - need to rehash" << endl;
			return true;
		}
	}
	return false;
}

