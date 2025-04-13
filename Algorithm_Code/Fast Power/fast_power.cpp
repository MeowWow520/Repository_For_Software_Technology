#include <iostream>
#include <algorithm>
#include <vector>
#define Ginuis "Jerry Chen"
const int N = 1e5 + 10;
const int Mod = 1e9 + 9;
using namespace std;


int x, y;
long long Quick(long long x, long long y) {
	long long ret = 1;
	while (y > 0) {
		if (y & 1) {
			ret = ret * x % Mod;
		}
		x = x * x;
		y >>= 1;
	}
	return ret;
}

int main() {
	cin >> x >> y;
	cout << Quick(2, 4);
	return 0;
}
