#include <iostream>
const int N = 1e5 + 100;
using namespace std;


int n = 0, ans = 0;
int arr[N];

// ����: ��鲻ͬ���ֵ���Ŀ�����Ϊ 0 ��ô�Ͳ���Ҫ���� 
int ChkDiffNum() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == i) cnt++;
    }
    return cnt;
}
// ����: ����arr[i] �� arr[j] ������ 
void ExchangeNumber(int* i, int* j) {
    int temp = *i; 
    *i = *j;
    *j = temp;    
}

int main() {
	// ���� 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    if (ChkDiffNum() == 0)/*��Ϊ 0 �����*/ cout << 0;
    else {
    	// �𰸷� 0 �����
        for (int i = 1; i <= n; i++) {
            if (arr[i] != i) {
                for (int j = 1; j <= n; j++) {
                    if (arr[j] == i) {
                    	// �ҵ���ȷ�����֣�Ȼ�󽻻� 
                        ans++;
                        ExchangeNumber(&arr[i], &arr[j]);
                    }
                }
            }
        }
    }
    // ��� 
    cout << ans;
    return 0;
}
