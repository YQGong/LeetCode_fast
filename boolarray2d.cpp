#include<iostream>
#include<sstream>
#include<list>
#include<string>
#include<algorithm>
#include <assert.h>

using namespace std;

static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class boolarray2d {
	static const unsigned int label[32];
	unsigned int* p= NULL,x_size,y_size;
	
public:
	boolarray2d(unsigned int x, unsigned int y) {
		p = new unsigned int[(x / 32 + 1)*(y)]();
		x_size = x / 32 + 1;
		y_size = y;
	}

	~boolarray2d() {
		free(p);
	}

	unsigned int get(unsigned int x, unsigned int y) {
		unsigned int xgroup = x / 32, xmod = x % 32;
		return !((p[x_size*y+xgroup] & label[xmod]) == 0);
	}

	void set(unsigned int x, unsigned int y, bool value) {
		unsigned int xgroup = x / 32, xmod = x % 32;
		if (value) {
			p[x_size*y + xgroup] = (p[x_size*y + xgroup] | label[xmod]);
		}
		else {
			p[x_size*y + xgroup] = (p[x_size*y + xgroup] & (~label[xmod]));
		}
	}
};

const unsigned int boolarray2d::label[32] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, \
16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, \
4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, \
536870912, 1073741824, 2147483648 };


int main() {
	int x = 40, y = 40;

	boolarray2d bools(x,y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << bools.get(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl<< "phase 2" <<endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			bools.set(i,j, true);
		}
		cout << endl;
	}
	cout << endl << "phase 3" << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << bools.get(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl << "phase 4" << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			bools.set(i,j, false);
		}
		cout << endl;
	}
	cout << endl << "phase 5" << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << bools.get(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	getchar();

	return 0;
}
