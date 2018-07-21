#include<iostream>
#include<sstream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

class boolarray {
	static const unsigned int label[32];
	unsigned int p = 0;
public:
	boolarray() {}

	~boolarray(){}

	unsigned int get( unsigned int i) {
		return !((p & label[i]) == 0);
	}

	void set( unsigned int i, bool value) {
		if (value) {
			p = (p | label[i]);
		}
		else {
			p = (p & (~label[i]));
		}
	}
};

const unsigned int boolarray::label[32] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, \
16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, \
4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, \
536870912, 1073741824, 2147483648 };


int main() {

	boolarray bools;
	cout << endl;
	for (int i = 0; i < 32; i++) {
		cout << bools.get(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < 32; i++) {
		bools.set(i,true);
	}
	for (int i = 0; i < 32; i++) {
		cout << bools.get(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < 21; i++) {
		bools.set(i, false);
	}
	for (int i = 0; i < 32; i++) {
		cout << bools.get(i) << " ";
	}
	cout << endl;
	getchar();

	return 0;
}
