using namespace std;

#include<iostream>
#include<unordered_map>
#include<map>
#include<chrono>

/*
	1. Use the reserve method in container class whenever is possible, specially incase of unordered_map
	2. 
	3. 
*/

// Defines
#define MAXE 200000
#define MAXL 25

char charset[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Let's write your own hash method for 

struct myhash {
#define SIZE 100019
	long long int operator()(const string &key) const {
		long long int h = 5381;
		int i = 0;
		while (key[i]) {
			h = ((h << 5) + h) + key[i];
			++i;
		}
		return h % SIZE;
	}
};


// UOM - unordered_map
struct MyCustomUOM {
	unordered_map<string, int>umap;
	unordered_map<string, int, myhash >uhmap;
	map<string, int >omap;

	MyCustomUOM() {
		umap.reserve(2*MAXE);
		uhmap.reserve(2 * MAXE);

	}

	void init() {
		umap.clear();
		omap.clear();

	}

	void upopulate() {
		// first of all let's create the 20 length string
		char key[20]; // key lenght is 20 including the null termination
		int ind = 0;
		const int MAX = 36;
		
		//------------------
		for (int i = 0; i < MAXE; ++i) {
			// making the key
			int ki = 0;
			for (; ki < 19; ++ki) {
				ind = rand() % MAX;
				key[ki] = charset[ind];
			}
			key[ki] = '\0'; // null termination
			umap[string(key)] = i;
		}
	}

	void uhpopulate() {
		// first of all let's create the 20 length string
		char key[20]; // key lenght is 20 including the null termination
		int ind = 0;
		const int MAX = 36;

		//------------------
		for (int i = 0; i < MAXE; ++i) {
			// making the key
			int ki = 0;
			for (; ki < 19; ++ki) {
				ind = rand() % MAX;
				key[ki] = charset[ind];
			}
			key[ki] = '\0'; // null termination
			uhmap[string(key)] = i;
		}
	}

	void opopulate() {
		// first of all let's create the 20 length string
		char key[20]; // key lenght is 20 including the null termination
		int ind = 0;
		const int MAX = 36;

		//------------------
		for (int i = 0; i < MAXE; ++i) {
			// making the key
			int ki = 0;
			for (; ki < 19; ++ki) {
				ind = rand() % MAX;
				key[ki] = charset[ind];
			}
			key[ki] = '\0'; // null termination
			omap[string(key)] = i;
		}
	}


	void uprint() {
		unordered_map<string, int >::iterator it = umap.begin();
		while (it != umap.end()) {
			cout <<"[" <<  it->first << ", " << it->second << "]\n";
			++it;
		}
	}

	void oprint() {
		map<string, int >::iterator it = omap.begin();
		while (it != omap.end()) {
			cout << "[" << it->first << ", " << it->second << "]\n";
			++it;
		}
	}

};

int main() {
	MyCustomUOM slnObj;
	 //1
	auto start = chrono::system_clock::now();
	slnObj.upopulate();
	auto end = chrono::system_clock::now();
	chrono::duration<double, milli> diff = (end - start);
	cout << "1-->Time Elapsed : " << diff.count() << " ms." << "\n";


	//2
	start = chrono::system_clock::now();
	slnObj.uhpopulate();
	end = chrono::system_clock::now();
	diff = (end - start);
	cout << "2-->Time Elapsed : " << diff.count() << " ms." << "\n";


	//3
	start = chrono::system_clock::now();
	slnObj.opopulate();
	end = chrono::system_clock::now();
	diff = (end - start);
	cout << "3-->Time Elapsed : " << diff.count() << " ms." << "\n";


	//slnObj.uprint();
	//cout << "\n\n\n---------------------------below is ordered map -----------------------\n\n" << endl;
	//slnObj.oprint();


	return 0;
}


