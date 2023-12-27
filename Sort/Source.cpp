#include<iostream>
#include<Windows.h>
#include<ctime>

#define MIN 0
#define MAX 1000000

using namespace std;

//int a[1000000];
//int a[] = { 7,-1,2,0,3,-8,6,12,5,3,-12,123,35 };
//int n = sizeof(a)/sizeof(int);

void create(int*& a, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = MIN + rand() % (MAX - MIN + 1);
	}
}
void print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}

void SelectionSort(int* a, int n) {
	int min = 0;
	for (int i = 0; i < n; i++) { //Sau moi lan lap, nhay den phan tu ke tiep
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;          //Tim vi tri cua phan tu nho nhat
		if (a[min] < a[i])
			swap(a[min], a[i]);   //Day phan tu nho nhat len dau
	}
}

void InsertionSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int saved = a[i];
		int j = i;
		// Neu j>0 va saved<a[j-1] thi day phan tu (j-1) len vi tri i
		// day cho den khi j==0 hoac saved>=a[j-1]
		while (j > 0 && saved < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}
		// sau do j va vi tri trong de chen saved
		a[j] = saved;
	}
}

void BubbleSort(int* a, int n) {
	for (int i = 0; i < n - 2; i++) {
		// j chay tu cuoi den (i+1)
		for (int j = n - 1; j >= i + 1; j--) {
			// So sanh j voi (j-1) neu nho hon thi day j len j-1
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
		// sau moi vong for ta them i 1 don vi 
		// de thao tac trong vong lap coi nhu phan tu dau tien cua mang la i+=1
	}
}

void ShellSort(int* a, int n) {
	for (int interval = n / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < n; i++) {
			int saved = a[i];
			int j = i;
			while (j >= interval && saved < a[j - interval]) {
				a[j] = a[j - interval];
				j -= interval;
			}
			a[j] = saved;
		}
	}
}

// Heap sort
// Heap la cay nhi phan hoan chinh
// Chuyen mang a thanh max heap(not cha lon hon 2 not con)
void Heapify(int arr[], int n, int i) {
	int largest = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;

	// So sanh voi node con trai
	if (left_child < n && arr[left_child] > arr[largest])
		largest = left_child;

	// So sanh voi node con phai
	if (right_child < n && arr[right_child] > arr[largest])
		largest = right_child;

	// Neu largest khong phai la i, thuc hien hoan doi va de quy heapify
	if (largest != i) {
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void BuildHeap(int a[], int n) {
	// n/2-1 : la node la dau tien
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(a, n, i);
	}
}

void HeapSort(int a[], int n) {
	BuildHeap(a, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}

int main() {

	int n = 1000000;
	int* a = new int[n];
	create(a, n);
	clock_t start, end;


	//start = clock();
	//ShellSort(a, n);
	//end = clock();
	//cout << "***" << 1.0000 * (end - start) / CLOCKS_PER_SEC << "***\n";

	//start = clock();
	//InsertionSort(a, n);
	//end = clock();
	//cout << "***" << 1.0000 * (end - start) / CLOCKS_PER_SEC << "***\n";

	//start = clock();
	//SelectionSort(a, n);
	//end = clock();
	//cout << "***" << (end - start) / CLOCKS_PER_SEC << "***\n";

	//start = clock();
	//BubbleSort(a, n);
	//end = clock();
	//cout << "***" << (end - start) / CLOCKS_PER_SEC << "***\n";
	start = clock();
	HeapSort(a, n);
	end = clock();
//	print(a, n);
	cout << "***" << 1.000 * (end - start) / CLOCKS_PER_SEC << "***\n";

	cout << endl;

	return 0;
}