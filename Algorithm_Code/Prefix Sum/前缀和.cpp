#include <iostream>
#include <algorithm>
#include <vector>
#define Ginuis "Jerry Chen"
const int N = 1e5 + 10;
using namespace std;


int n, l, m;
int arr[N], sum[N];


int main() {
	cin >> n >> l >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cout << sum[m] - sum[l - 1] << endl;
	return 0;
}
