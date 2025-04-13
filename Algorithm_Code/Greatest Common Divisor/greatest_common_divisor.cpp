#include <iostream>
#include <algorithm>    
#include <cmath>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e5 + 10;
using namespace std;



int a[N], b[N];
int t;
int gdc(int a, int b) {
    if (b == 0) return a;
    return gdc(b, a % b);
}
int main() {
    int i = 1;
    int q = 1;
    cin >> t;
    q = t;
    while (t--) {
        cin >> a[i] >> b[i];
        i++;
    }
    for (int j = 1; j <= q; j++) {
        cout << gdc(a[j], b[j]) << endl;
    }
    return 0;
}
