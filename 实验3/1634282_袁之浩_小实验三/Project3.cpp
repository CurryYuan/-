// Project3.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
using namespace std;

int T, N;

void re(int k, int sum, vector<int>& temp, int* a);
int main()
{
	cout << "请输入背包容量T和物品数量N" << endl;
	cin >> T >> N;
	cout << "请分别输入每件物品的体积" << endl;
	int *a = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	vector<int> temp;

	cout << "------------------------" << endl;

	re(0, 0, temp, a);
    return 0;
}

void re(int k, int sum, vector<int>& temp, int* a)
{
	if (sum == T) {
		cout << "[ ";
		for (auto c : temp)
			cout << c << " ";
		cout <<']'<< endl;
		return;
	}
	if (k >= N)
		return;
	if (sum > T)
		return;
	temp.push_back(a[k]);
	re(k + 1, sum + a[k], temp, a);
	temp.pop_back();
	re(k + 1, sum, temp, a);
}
