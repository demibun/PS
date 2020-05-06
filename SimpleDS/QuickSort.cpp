using namespace std;

#include<iostream>

int array[8] = {6, 8, 1, 5, 2, 3, 7, 4};

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *array, int start, int end) {
	
	if(start >= end) {
		return;
	}
	
	int pivot = start;
	int left = pivot + 1;
	int right = end;
	
	while(left <= right) {
		while(left <= end && array[left] <= array[pivot]) {
			left++;
		}
		while(right > start && array[right] >= array[pivot]) {
			right--;
		}
		
		if(left > right) {
			swap(&array[right], &array[pivot]);
		} else {
			swap(&array[right], &array[left]);
		}
	}
	sort(array, start, right-1);
	sort(array, right+1, end);
}


int main(void) {

	sort(array, 0, 7);
	
	for(int i = 0; i<8; i++) {
		cout << array[i] << ' ';
	}
}
