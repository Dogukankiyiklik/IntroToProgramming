#include <iostream>
using namespace std;

#define SIZE 5

int main()
{
	int A[SIZE][SIZE], B[SIZE][SIZE];
	int* p, * q, *t, *m;
	int i = 0;

	// 1. İşlem
	for (p = &A[0][0]; p <= &A[SIZE - 1][SIZE - 1]; p++) {

		*p = 0;
	}

	cout << "MATRIX A" << endl;
	cout << "___________" << endl;

	for (p = &A[0][0]; p <= &A[SIZE - 1][SIZE - 1]; p++) {

		if (p == &A[i][SIZE]) {

			cout << endl;
			i++;
		}
		cout << *p << "\t";
	}


	// 2. İşlem
	m = &A[0][0] + (SIZE - 1);
	t = &A[SIZE - 1][0];
	
	for (p = &A[0][0]; p <= &A[SIZE - 1][SIZE - 1]; p++) {

		if (p <= m || p >= t || (&A[SIZE - 1][SIZE - 1] - p + 1) % SIZE == 0 || (&A[SIZE - 1][SIZE - 1] - p + 1) % SIZE == 1) {

			*p = 1;
		}
	}

	cout << endl << endl << endl;
	cout << "MATRIX A" << endl;
	cout << "___________" << endl;
	i = 0;

	for (p = &A[0][0]; p <= &A[SIZE - 1][SIZE - 1]; p++) {

		if (p == &A[i][SIZE]) {

			cout << endl;
			i++;
		}
		cout << *p << "\t";
	}


	// 3. İşlem
	for (p = &A[0][0], q = &B[0][0]; p <= &A[SIZE - 1][SIZE - 1]; p++, q++) {

		*q = *p * 2;
	}

	cout << endl << endl << endl;
	cout << "MATRIX B" << endl;
	cout << "___________" << endl;
	i = 0;

	for (p = &B[0][0]; p <= &B[SIZE - 1][SIZE - 1]; p++) {

		if (p == &B[i][SIZE]) {

			cout << endl;
			i++;
		}
		
		cout << *p << "\t";
	}

	return 0;
}