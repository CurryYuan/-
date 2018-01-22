// ConsoleApplication59.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

vector<stack<int>> temp; //�г����ݴ����� 
vector<int> res;
int j = 1; // j ��ָ ͷ���� 
int most_big_size = 0;
int path = 0;

bool check(int a);
bool out(int a);



int main()
{
	vector<int> s; // ������һ�������Ļ� 
	cout << "�����복���ܽ����� " << endl;
	int n;
	cin >> n;
	cout << "�����복��˳��ÿ�ڳ�����Կո�����" << endl;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.push_back(x);
	}
		
	cout << "-----------------------------------------------" << endl;
	
	for (int i = 0; i < s.size(); ++i) {
		if (out(s[i]))
			continue;
		if (temp.size() == 0 || check(s[i])) {
			stack<int> a;
			a.push(s[i]);
			temp.push_back(a);
			if(most_big_size < temp.size()) most_big_size = temp.size();
			cout <<"���� "<<left<<setw(2)<<s[i]<<" ����  "<< "��� " << setw(2) << temp.size()<<"���¿���" << endl;
			path++;
		}
	}

	cout << "-----------------------------------------------" << endl;
	cout << "�����";
	for (auto c : res)
		cout <<setw(3)<< c;
	cout << endl;
	cout << "ʹ�õ����������Ϊ�� " << most_big_size << endl; 
	cout << "������һ���ǣ� " << path << endl;
    return 0;
}

bool check(int a)//�ѳ��������� 
{
	for (int i = 0; i < temp.size(); ++i) {
		if (!temp[i].empty()&&a < temp[i].top()) {
			temp[i].push(a);
			cout << "���� " << setw(2) << a << " ����  ��� " << setw(2) << i+1 << endl;
			++path;
			return false;
		}
	}
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i].empty()) {
			temp[i].push(a); 
			cout << "���� " << setw(2) << a << " ����  ��� " << setw(2) << i+1 << endl;
			++path;
			return false;
		}
	}
	return true;
}

bool out(int a) //�����ѳ���ų� 
{
	if (a == j) {
		res.push_back(a);
		++j;
		cout << "���� " << left<< setw(2) << a << " ����         ��ֱ�ӣ�" << endl; //ָ����ֱ�Ӵ�ԭ�г����� ����Ҫ������� 
		++path;
		out(a);
		return true;
	}
	for (int i = 0; i < temp.size(); ++i) {
		if (!temp[i].empty()&&temp[i].top() == j) {
			temp[i].pop();
			res.push_back(j);
			cout << "���� " << left<< setw(2) << j << " ����  ��� " << setw(2) << i + 1 << endl;
			++j;
			++path;
			out(a);
		}
	}
	return false;
}
