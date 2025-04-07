#include <iostream>
#include <algorithm>    
#define genius "JerryChen";
typedef long long ll;
const ll mod  = 998244353;
using namespace std;


// 递推-全排列的价值
// 思路: 探究第 n 个排列的价值和第 n - 1 个的关系


// 计算 n 的阶乘
ll jiecheng(ll n) {
    if (2 == n) return 2;
    else if (1 == n) return 1;
    else return (jiecheng(n - 1) * n) % mod;
}

/** 定义 fn 为第 n 个排列的价值
 * 
 *  ------增加的价值------
 *  思路: 我们假设是将数字 n 插入到 n - 1 的一个排列中去
 *  那么因为任意的 n 大于 n - 1
 *  所以插入 n 对价值的影响只与 n 的位置有关
 *  例如: 把 4 插入到 3 的一个排列"2 3 1"中, 4 可以插入 4 个位置其中
 *  第一个位置对"2 3 1"这个排列的价值没有影响
 *  同理: 二、三、四个位置分别为于位置上的数字无关的价值1, 2, 3
 *  即: 插入 n 会对排列产生s = 1+2+3+...+n 的价值
 *  又以为 n - 1 的排列有 (n-1)! 个
 *  所以增加的价值为: [(n+1)*n / 2] * (n-1)!
 * 
 *  ------原本的价值------
 *  对于原本的价值, 本应该有fn(n - 1)个由于 n 的加入
 *  原来的一个排序被插入 n 个位置变成新的 n 的排序
 *  例如: "1 2 3" 会变为 4123、1423、1243、1234
 *  故原来的价值应为: fn(n - 1) * n
 *  
 *  ------总表达式--------
 *  fn(n) = fn(n - 1) * n + [(n+1)*n / 2] * (n-1)!
 */ 
ll fn(long long n) {
    if (2 == n) return 1;
    else if (1 == n) return 0;
    else { 
        ll ret = 0;
        ll qian = (fn(n - 1) * n);
        ll hou = ((n - 1) * n / 2) % mod;
        ll jc = jiecheng(n - 1);
        ret = (qian + hou * jc) % mod;
        return ret;
    }
}

int main() {
    ll n = 0;
    cin >> n;
    cout << fn(n);
    return 0;
}
