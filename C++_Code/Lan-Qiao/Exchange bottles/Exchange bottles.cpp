#include <iostream>
const int N = 1e5 + 100;
using namespace std;

// Translated By DeepSeek R1 From Chinese Version


int n = 0, ans = 0;
int arr[N];

// Function: Count the number of bottles in the correct position (where arr[i] == i)
int ChkDiffNum() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == i) cnt++;
    }
    return cnt;
}

// Function: Swap the values of the two integers pointed to by i and j
void ExchangeNumber(int* i, int* j) {
    int temp = *i; 
    *i = *j;
    *j = temp;    
}

int main() {
    // Input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    // If all bottles are already in correct positions, output 0
    if (ChkDiffNum() == 0) cout << 0;
    else {
        // When there are misplaced bottles
        for (int i = 1; i <= n; i++) {
            if (arr[i] != i) {
                for (int j = 1; j <= n; j++) {
                    if (arr[j] == i) {
                        // Swap the positions of the two bottles and increment count
                        ans++;
                        ExchangeNumber(&arr[i], &arr[j]);
                    }
                }
            }
        }
    }
    // Output
    cout << ans;
    return 0;
}
