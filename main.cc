#include <iostream>
using namespace std;

template <class T>
void mergesort(T*, int);
template <class T>
void _mergesort(T*, int, int);
template <class T>
void merge(T*, int, int, int);

template <class T>
void mergesort(T* A, int length) {
	_mergesort(A, 0, length - 1);
}

template <class T>
void _mergesort(T* A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		_mergesort(A, p, q);
		_mergesort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

template <class T>
void merge(T* A, int p, int q, int r) {
	int leftstart = p, leftend = q, rightstart = leftend + 1, rightend = r;
	int leftlength = q - p + 1, rightlength = r - q, mergelength = leftlength + rightlength;
	int i = leftstart, j = rightstart, k = 0;		//warning: pointer k location

	T* M = new T[mergelength];
	while (i <= leftend && j <= rightend) {
		if (A[i] < A[j]) {
			M[k] = A[i];
			++i;
		}
		else {
			M[k] = A[j];
			++j;
		}
		++k;
	}
	if (i > leftend) {
		while (j <= rightend) {
			M[k] = A[j];
			++j;
			++k;
		}
	}
	else {
		while (i <= leftend) {
			M[k] = A[i];
			++i;
			++k;
		}
	}
	int a = leftstart, m = 0;
	while (a <= rightend && m < mergelength) {
		A[a] = M[m];
		++a;
		++m;
	}
	delete[] M;
}

int main() {
	int A[10] = { 0,11,22,33,55,66,77,99,88,45 };
	mergesort<int>(A, 10);
	for (int i = 0; i < 10; ++i) cout << A[i] << " ";
	cout << endl;

	cin.get();
	return 0;
}
