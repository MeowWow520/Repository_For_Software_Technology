#include <iostream>
#include <algorithm>
#include <vector>
const int N = 1e6 + 10;
using namespace std;

/*
问题描述
在蓝桥王国，数字的大小不仅仅取决于它们的数值大小，还取决于它们所形成的“封闭图形”的个数。
封闭图形是指数字中完全封闭的空间，例如数字1、2、3、5、7都没有形成封闭图形，而数字0、4、6、9分别形成了1个封闭图形，数字 8则形成了2个封闭图形。值得注意的是，封闭图形的个数是可以累加的。例如，对于数字68，由于6形成了1个封闭图形，而8形成了2 个，所以68形成的封闭图形的个数总共为3。
在比较两个数的大小时，如果它们的封闭图形个数不同，那么封闭图形个数较多的数更大。例如，数字41和数字18，它们对应的封闭图形的个数分别为1和2，因此数字41小于数字18。如果两个数的封闭图形个数相同，那么数值较大的数更大。例如，数字14和数字41，它们的封闭图形的个数都是1，但14<41，所以数字14小于数字 41。如果两个数字的封闭图形个数和数值都相同，那么这两个数字被认为是相等的。
小蓝对蓝桥王国的数字大小规则十分感兴趣。现在，他将给定你n个数α1,α2，···，Qn，请你按照蓝桥王国的数字大小规则，将这n数从小到大排序，并输出排序后结果。

*/

int fb[10] = { 1, 0, 0, 0, 1, 0, 1, 0, 2, 1 };

int count(int a) {
    int ans = 0;
    while (a != 0) {
        ans += fb[a % 10];
        a /= 10;
    }
    return ans;
}

bool comp(int a, int b) {
    int countA = count(a);
    int countB = count(b);
    if (countA != countB) {
        return countA < countB; // Sort by count in ascending order
    }
    else {
        return a < b; // If counts are equal, sort by numerical value in ascending order
    }
}
int main() {
    int n = 0;
    vector <int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
