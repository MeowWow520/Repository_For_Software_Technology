#include <iostream>
using namespace std;
const int Mod = 998244353;



/**  
 *  小蓝面临一个数学问题: 定义一个函数f(x)如下:
 *  f(x）= 2 * x * f(x-6) (x > 10) 
 *  f(x）= x * (x - 1）   (x <= 10)
 *  现在给定一个整数n, 小蓝想知道 f(x) 对 998244353 取模的结果
 * 
 *  ------输入格式------
 *  输入包含一个整数n, 表示函数f的参数
 * 
 *  ------输出格式------
 *  输出一个整数, 表示 f(x) 对 998244353 取模的结果
 */
int fx(int x) {
    if (x > 10) return 2 * x * fx(x - 6);
    else return (x * (x - 1) % Mod);
}

int main() {
    int n;
    cin >> n;
    cout << fx(n);
    return 0;
}
