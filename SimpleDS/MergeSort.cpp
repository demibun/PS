using namespace std;

#include<iostream>
int array[7] = {7, 1, 5, 3, 4, 2, 6};
int array2[7] = {0, };

void merge(int left, int right) {
	int mid = (left + right) / 2;
	
	int i = left;
	int j = mid + 1;
	int k = left;
	
	while (i <= mid && j <= right) {
		if(array[i] <= array[j])
			array2[k++] = array[i++];
		else 
			array2[k++] = array[j++];
	}
	int temp = i>mid ? j : i;
	
	while(k <= right) {
		array2[k++] = array[temp++];
	}
	
	for(int i = left; i <= right; i++) {
		array[i] = array2[i];
	}
}

void partition(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid+1, right);
		merge(left, right);
	}
}

int main(void) {

	partition(0, 6);
	
	for(int i = 0; i<7; i++) {
		cout << array[i] << ' ';
	}
}
