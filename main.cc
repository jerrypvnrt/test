template <class T>
void shiftdown(T*, int, int);
template <class T>
void makeheap(T*, int);
template <class T>
void heapsort(T*, int);

template <class T>
void shiftdown(T* A, int index, int length) {
	int largechild;
	if (index * 2 + 1 < length) {		// This index has at least one child
		if (index * 2 + 2 >= length) {	// This index has exactly one child
			largechild = index * 2 + 1;
			if (A[index] < A[largechild]) {			//swap
				A[index] += A[largechild];
				A[largechild] = A[index] - A[largechild];
				A[index] -= A[largechild];
			}
		}
		else {		//This index has exactly two children
			largechild = index * 2 + 1;
			if (A[index * 2 + 2] > A[largechild]) largechild = index * 2 + 2;
			if (A[index] < A[largechild]) {			//swap
				A[index] += A[largechild];
				A[largechild] = A[index] - A[largechild];
				A[index] -= A[largechild];
				shiftdown(A, largechild, length);	//Need to check again
			}
		}
	}
}

template <class T>
void makeheap(T* A, int length) {
	for (int i = length - 1; i >= 0; --i) {
		shiftdown(A, i, length);
	}
}

template <class T>
void heapsort(T* A, int length) {
	makeheap(A, length);
	while (length > 1) {
		A[0] += A[length - 1];
		A[length - 1] = A[0] - A[length - 1];
		A[0] -= A[length - 1];
		--length;
		shiftdown(A, 0, length);
	}
}
// It is in master branch.
