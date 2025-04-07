#include <iostream>
using namespace std;

// Translated By DeepSeek R1 From Chinese Version


/**
 * Morning Run
 * Xiao Lan goes for a morning run every Saturday and Sunday. He also runs on the 1st, 11th, 21st, and 31st of each month. Other days, he does not run.
 * Given that January 1, 2022, is a Saturday, how many days does Xiao Lan run in the entire year 2022?
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
