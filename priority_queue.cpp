using namespace std;
#include<iostream>
#include<unordered_map>
#include<map>
#include<chrono>
#include<queue>

priority_queue<int, vector<int>, less<int>> p;

//#define FORREF
#ifndef FORREF

int main() {

	// suppose you have N number of inputs
	int N;
	cin >> N;

	while (N-- > 0) {
		char ch;
		int val;

		cin >> ch;
		if (ch == '+') {
			cin >> val;
			p.push(val);
		}
		else if (ch == '-') {
			int largest = p.top();
			while (largest == p.top()) {
				p.pop();
			}
		}
	}

	return 0;
}

#endif // FORREF

