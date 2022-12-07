#include<iostream>
int* cArr;
using namespace std;
void QuickSort(int* arr, int li, int di) {
	if (di > li) {
	int j = li, k = di;
		int etalon = arr[rand()%(di-li+1)+li];
		//cout << "Etalon: " << etalon << endl;
		do {
			while (arr[j] < etalon)j++;
			while (arr[k] > etalon)k--;
			if (j <= k) {
				int buffer = arr[j];
				arr[j] = arr[k];
				arr[k] = buffer;
				j++;
				k--;
			}
		} while (j<=k);
		QuickSort(arr, li, k);
		QuickSort(arr, j, di);
	}


}
void Merge(int*arr,int li, int di) {
	int j = li, k = (li + di) / 2 + 1, c = li;;
	while (j <= (li + di) / 2 && k <= di) {
		if (arr[j] < arr[k]) {
			cArr[c] = arr[j];
			j++;
		}
		else {
			cArr[c] = arr[k];
			k++;
		}
		c++;
	}
	for (int i = j; i <= (li + di) / 2; i++) {
		cArr[c] = arr[i];
		c++;
	}
	for (int i = k; i <= di; i++) {
		cArr[c] = arr[i];
		c++;
	}
	for (int i = 0; i <= di; i++) {
		arr[i] = cArr[i];
	}
}
void MergeSort(int*arr, int li, int di) {
	if (di > li) {
		MergeSort(arr,  li, (li + di) / 2);
		MergeSort(arr, (li + di) / 2 + 1, di);
	}
	Merge(arr, li, di);
}
void fillArray(int*arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
}
void printArray(int*arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	//cout << "time for Merge Sort:" << endl;
	//for (int i = 2; i <= 10; i++) {
     	int size = 20;
	    int* arr = new int[size];
	//	cArr = new int[size];
		fillArray(arr, size);
		QuickSort(arr, 0, 19);
	//	clock_t t1 = clock();
	//	MergeSort(arr, 0, size - 1);
	//	clock_t t2 = clock();
	//	std::cout << "Time " << i - 1 << ": " << float(t2 - t1) / CLOCKS_PER_SEC << endl;
	//}
		printArray(arr, size);

	return 0;
}