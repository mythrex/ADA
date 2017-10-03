#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arr_functions.h"
using namespace std;

#define ARR_SIZE 100000000

void merge(long *arr,int l,int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	//set the size of new array
	long* left = new long[n1];
	long* right = new long[n2];
	//copy the content in each array
	for (i = 0; i < n1; ++i){
		*(left + i) = *(arr + l + i);
	}
	for (j = 0; j < n2; ++j){
		*(right + j) = *(arr + m + 1 + j);
	}
	//merge the two arrays
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			*(arr + k) = *(left + i);
			++i;
		}else{
			*(arr + k) = *(right + j);
			++j;
		}
		++k;
	}
	//copy rest of left and right array
	while(i < n1){
		*(arr + k) = *(left + i);
		i++;
		k++;
	}
	while(j < n2){
		*(arr + k) = *(right +j);
		j++;
		k++;
	}
	delete left;
	delete right;
}

void mergeSort(long *a,int l,int r){
	if (l < r){
		int m = (l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(int argc, char const *argv[]){
	long* a = new long[ARR_SIZE];

	//set the array here
	setArrayDesc(a,ARR_SIZE);

	clock_t start,end;
	double time;
	start = clock();

	//sort_function here
	mergeSort(a,0,ARR_SIZE-1);
	
	end = clock();
	time = (double) (end - start) / CLOCKS_PER_SEC;

	cout<<time;
	delete a;
	return 0;
}