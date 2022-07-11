// Array vs Linklist
using namespace std;
#include<iostream>
#include<stdio.h>
#include<chrono>

//#define FORREF
//#define DTIME
#ifndef FORREF
#define MAX 2000000 // 2*10^6

// Array
int A[MAX];

// Linklist Node
typedef struct Node {
	Node* next;
	int data;
}Node;

// Head pointer for dynamic list
Node* head = NULL;

// Head pointer for list with pool
Node* headPool = NULL;

// Node Pool
Node B[MAX];

void ArrayTraversal()
{
#ifndef DTIME
	auto start = chrono::system_clock::now();
#endif // !DTIME

	int val = 0;
	for (int i = 0; i < MAX; ++i)
	{
		val += A[i];
	}

#ifndef DTIME
	auto end = chrono::system_clock::now();
	chrono::duration<double, milli> diff = (end - start);
	cout << "Time taken in Array Traversal :  " << diff.count() << " ms\n";
#endif // !DTIME
}

void LinkedListTraversal()
{
#ifndef DTIME
	auto start = chrono::system_clock::now();
#endif // !DTIME

	int val = 0;
	Node* tmp = head;
	while (tmp) {
		val += tmp->data;
		tmp = tmp->next;
	}

#ifndef DTIME
	auto end = chrono::system_clock::now();
	chrono::duration<double, milli> diff = (end - start);
	cout << "Time taken in Linked List  Traversal :  " << diff.count() << " ms\n";
#endif // !DTIME
}

void LinkedListPoolTraversal()
{
#ifndef DTIME
	auto start = chrono::system_clock::now();
#endif // !DTIME

	int val = 0;
	Node* tmp = headPool;
	while (tmp) {
		val += tmp->data;
		tmp = tmp->next;
	}

#ifndef DTIME
	auto end = chrono::system_clock::now();
	chrono::duration<double, milli> diff = (end - start);
	cout << "Time taken in Linked List Pool Traversal :  " << diff.count() << " ms\n";
#endif // !DTIME
}


int main()
{
#ifndef DTIME
	auto start = chrono::system_clock::now();
#endif // !DTIME
	for (int i = 0; i < MAX; ++i) {
		A[i] = i;
	}
#ifndef DTIME
	auto end = chrono::system_clock::now();
	chrono::duration<double, milli> diff = (end - start);
	cout << "Time taken to initialize the array : " << diff.count() << " ms\n";

	start = chrono::system_clock::now();
#endif // !DTIME
	for (int i = 0; i < MAX; ++i) {
		Node* tmp = new Node();
		tmp->data = A[i];
		tmp->next = head;
		head = tmp;
	}

#ifndef DTIME
	end = chrono::system_clock::now();
	diff = (end - start);
	cout << "Time taken to initialize the linked list : " << diff.count() << " ms\n";
	start = chrono::system_clock::now();
#endif // !DTIME

	for (int i = 0; i < MAX; ++i) {
		Node* tmp = &B[i];
		tmp->data = A[i];
		tmp->next = headPool;
		headPool = tmp;
	}

#ifndef DTIME
	end = chrono::system_clock::now();
	diff = (end - start);
	cout << "Time taken to initialize the linked list pool : " << diff.count() << " ms\n";
#endif // !DTIME

	cout << endl;
	cout << "Performance order of initialisation : Array > Linkedlist with pool > Linkedlist" << endl;
	cout << endl;

	ArrayTraversal();
	LinkedListTraversal();
	LinkedListPoolTraversal();

	cout << endl;
	cout << "Performance order of Traversal : Array > Linkedlist with pool > Linkedlist" << endl;
	cout << endl;
}
#endif // !FORREF
