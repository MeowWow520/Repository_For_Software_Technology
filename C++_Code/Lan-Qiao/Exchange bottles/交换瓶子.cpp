#include <iostream>
const int N = 1e5 + 100;
using namespace std;


int n = 0, ans = 0;
int arr[N];

// 函数: 检查不同数字的数目，如果为 0 那么就不需要交换 
int ChkDiffNum() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == i) cnt++;
    }
    return cnt;
}
// 函数: 交换arr[i] 和 arr[j] 的数字 
void ExchangeNumber(int* i, int* j) {
    int temp = *i; 
    *i = *j;
    *j = temp;    
}

int main() {
	// 输入 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    if (ChkDiffNum() == 0)/*答案为 0 的情况*/ cout << 0;
    else {
    	// 答案非 0 的情况
        for (int i = 1; i <= n; i++) {
            if (arr[i] != i) {
                for (int j = 1; j <= n; j++) {
                    if (arr[j] == i) {
                    	// 找到正确的数字，然后交换 
                        ans++;
                        ExchangeNumber(&arr[i], &arr[j]);
                    }
                }
            }
        }
    }
    // 输出 
    cout << ans;
    return 0;
}
