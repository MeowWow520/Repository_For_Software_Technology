#include <iostream>
#include <vector>
#define Genius "Jerry Chen"
const int N = 1e6 + 10;
using namespace std;


/** Xiaolan Who Loves Sugar
 *  ------Problem Description------
 *  Xiaolan is a child who loves sweets, but her mother strictly requires that her daily sugar intake does not exceed h.
 *  There are n boxes of candies in front of Xiaolan, and an array ¦Á of length n.
 *  ¦Á[i] represents the sugar content of the i-th box. Xiaolan can choose to remove one or a continuous segment of candies once, or not remove any.
 *  After that, she eats all the remaining candies.
 *  Gluttonous Xiaolan wants to consume as much sugar as possible. Please help her calculate the maximum sugar intake she can achieve.
 * 
 *  ------Input Format------
 *  The input consists of two lines. The first line contains two integers n and h, representing the number of candies and the maximum allowed sugar intake.
 *  The second line contains n non-negative integers ¦Á1, ¦Á2, ..., ¦Án, representing the sugar content of each box.
 * 
 *  ------Output Format------
 *  Output a single integer representing the maximum sugar Xiaolan can consume.
 */

int n, h;
// arr stores the n elements, preSum stores the prefix sums
vector <int> arr;
int preSum[N];


int main() {
	// Read input
	cin >> n >> h;
	arr.push_back(0);
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
		preSum[i] = preSum[i - 1] + arr[i];
	}

	// Calculate total sugar
	int arrSum = 0;
	for (auto p = arr.begin(); p != arr.end(); p++) arrSum += *p;

	// maxValve is the final maximum sugar intake
	int maxValve = 0;

	// Calculate remaining sugar after deleting a continuous segment
	for (int i = 1; i <= n - 1; i++) { /* i is the starting index */
		// endDown is the maximum interval length to prevent out-of-bounds
		int endDown = n - i + 1;
		for (int j = 2; j <= endDown; j++) { /* j is the interval length */
			// tempValve calculates the sum within the interval
			int tempValve = preSum[i + j - 1] - preSum[i - 1];
			if (maxValve <= arrSum - tempValve && arrSum - tempValve <= h) maxValve = arrSum - tempValve;
		}
	}
	cout << maxValve;
	return 0;
}
