#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ARR_SIZE 1000000

void insertionSort(long *a,long size){
	int key,i;
	for(long j = 1; j < size; j++){
		key = *(a + j);
		//insert the key in the sorted part!
		i = j-1;
		while(i > 0 && *(a + i) > key){
			*(a+i+1) = *(a+i);
			i--; 
		}
		*(a+i+1) = key;
	}
}

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


int main(int argc, char const *argv[]){
	long* a = new long[ARR_SIZE];
	setArrayRandom(a,ARR_SIZE);
	clock_t start,end;
	double time;
	start = clock();

	insertionSort(a,ARR_SIZE);

	end = clock();
	time = (double) (end - start) / CLOCKS_PER_SEC;

	cout<<time;
	delete a;
	return 0;
}