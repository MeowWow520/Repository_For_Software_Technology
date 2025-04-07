#include <iostream>
#include <algorithm>
#include <vector>
const int N = 1e6 + 10;
using namespace std;

// Translated By DeepSeek R1 From Chinese Version


/*
Problem Description:
In Blue Bridge Kingdom, the size of numbers is determined not only by their numerical values but also by the number of "closed shapes" they form.
A closed shape refers to a fully enclosed space in a digit. For example:
- Digits 1, 2, 3, 5, 7 have no closed shapes.
- Digits 0, 4, 6, 9 each form 1 closed shape.
- Digit 8 forms 2 closed shapes.
The total number of closed shapes is cumulative. For example, the number 68 has 3 closed shapes (1 from 6 and 2 from 8).
When comparing two numbers:
- If their closed shape counts differ, the number with more closed shapes is larger. E.g., 41 (1 shape) < 18 (2 shapes).
- If counts are equal, the larger numerical value is greater. E.g., 14 < 41 (both have 1 shape).
- If both counts and values are equal, the numbers are considered equal.

Task:
Given n numbers ¦Á1, ¦Á2, ..., ¦Án, sort them in ascending order according to Blue Bridge Kingdom's rules and output the result.
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
        return a < b; // If counts are equal, sort by numerical value
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
