#include <iostream>
using namespace std;



/** 晨跑
 *  小蓝每周六、周日都晨跑, 每月的1、11、21、31日也晨跑。其它时间不晨跑。
 *  已知2022年1月1日是周六, 请问小蓝整个2022年晨跑多少天？
 */

int Mouth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int IsRun(int day, int weekdays) {
    if (day == 1 || day == 11 || day == 21 || day == 31 || weekdays == 6 || weekdays == 0) return 1;
    else return 0;
}

int main() {
    int weekdays = 0;
    int ans = 0;
    int daycount = 6;
    for (int mouth = 1; mouth <= 12; mouth++) {
        for (int day = 1; day <= Mouth[mouth]; day++) {
            weekdays = daycount % 7;
            if (IsRun(day, weekdays) == 1) ans++;
            daycount++;
        }
    }
    cout << ans;
    return 0;
}
