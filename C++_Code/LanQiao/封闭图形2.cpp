#include <iostream>
#include <algorithm>
#include <vector>
const int N = 1e6 + 10;
using namespace std;

/*
��������
���������������ֵĴ�С������ȡ�������ǵ���ֵ��С����ȡ�����������γɵġ����ͼ�Ρ��ĸ�����
���ͼ����ָ��������ȫ��յĿռ䣬��������1��2��3��5��7��û���γɷ��ͼ�Σ�������0��4��6��9�ֱ��γ���1�����ͼ�Σ����� 8���γ���2�����ͼ�Ρ�ֵ��ע����ǣ����ͼ�εĸ����ǿ����ۼӵġ����磬��������68������6�γ���1�����ͼ�Σ���8�γ���2 ��������68�γɵķ��ͼ�εĸ����ܹ�Ϊ3��
�ڱȽ��������Ĵ�Сʱ��������ǵķ��ͼ�θ�����ͬ����ô���ͼ�θ����϶�����������磬����41������18�����Ƕ�Ӧ�ķ��ͼ�εĸ����ֱ�Ϊ1��2���������41С������18������������ķ��ͼ�θ�����ͬ����ô��ֵ�ϴ�����������磬����14������41�����ǵķ��ͼ�εĸ�������1����14<41����������14С������ 41������������ֵķ��ͼ�θ�������ֵ����ͬ����ô���������ֱ���Ϊ����ȵġ�
С�����������������ִ�С����ʮ�ָ���Ȥ�����ڣ�����������n������1,��2����������Qn�����㰴���������������ִ�С���򣬽���n����С�������򣬲�������������

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
