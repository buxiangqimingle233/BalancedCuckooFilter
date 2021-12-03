#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>  
#include <map>
#include <math.h>
#include <map>

using namespace std;

//printing related functions 
void printMap(int arr[][2], int n);
void printArrow(int n, int val);

//main search, delete and insert functions
int cuSearch(int arr[][2], int n, int val);
int cuDelete(int arr[][2], int n, int val);
int cuInsert(int arr[][2], int n, int val);


//deals with eviction loops
int place(int arr[][2], int n, int key, int tSwitch, int val, map< string, int> cycles);
//deals with cycles --> failstate loops
bool cycleDetection(map< string, int> cycles);