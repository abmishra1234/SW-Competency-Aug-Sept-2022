// Usefull Bit manipulation for performance of code...
using namespace std;
#include<stdio.h>
#include<iostream>

#ifndef FORREF

int CountNumberOfSetBits(int N) {
	int count = 0;
	while (N) {
		N &= (N - 1);
		count++;
	}

	return count;
}

bool CheckIfNthBitIsSet(int A, int N) {
	return A & (1 << N);
}

void SetNthBit(int &A, int N) {
	A |= (1 << N);
}

void UnSetNthBit(int& A, int N) {
	A &= (~(1 << N));
}

int main() {
	
	for (int i = 0; i < 32; ++i) {
		cout << "Number of set bits in " << i << " is " << CountNumberOfSetBits(i) << endl;
	}

	cout << "0th bit in 5 is " << CheckIfNthBitIsSet(5, 0) << endl;
	cout << "1st bit in 5 is " << CheckIfNthBitIsSet(5, 1) << endl;
	cout << "2nd bit in 5 is " << CheckIfNthBitIsSet(5, 2) << endl;
	cout << "0th bit in 7 is " << CheckIfNthBitIsSet(7, 0) << endl;
	cout << "1st bit in 7 is " << CheckIfNthBitIsSet(7, 1) << endl;
	cout << "2nd bit in 7 is " << CheckIfNthBitIsSet(7, 2) << endl;

	int A = 0;
	SetNthBit(A, 0);
	cout << "A = " << A << endl;

	SetNthBit(A, 1);
	cout << "A = " << A << endl;

	SetNthBit(A, 2);
	cout << "A = " << A << endl;

	UnSetNthBit(A, 0);
	cout << "A = " << A << endl;

	UnSetNthBit(A, 1);
	cout << "A = " << A << endl;

	UnSetNthBit(A, 2);
	cout << "A = " << A << endl;

}

#endif // !FORREF