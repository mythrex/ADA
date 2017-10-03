#include <iostream>
using namespace std;

void dispArr(long *a,long size){
	for (long i = 0; i < size; ++i){
		cout<<*(a+i)<<",";
	}
	cout<<endl;
}

void setArrayAsec(long *a,long size){
	for (long i = 0; i < size; ++i){
		*(a+i) = i+1;
	}
}

void setArrayDesc(long *a,long size){
	for (long i = 0; i < size; ++i){
		*(a+i) = size-i;
	}
}

void setArrayRandom(long *a,long size){
	srand(time(NULL));
	for (long i = 0; i < size; ++i){
		*(a+i) = (long) rand() % size;
	}
}