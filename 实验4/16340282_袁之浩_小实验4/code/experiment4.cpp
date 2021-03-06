// experiment4.cpp: 定义控制台应用程序的入口点。
//
#include "Array.h"
#include "list.h"
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "1----建立顺序线性表" << endl;
	cout << "2----建立链接线性表" << endl;
	string s;
	cin >> s;

	if (s == "1") {
		cout << "请输入大小" << endl;
		int x;
		cin >> x;
		Array st(x);
		system("pause");
		system("cls");
		while (true) {
			cout << "1----插入" << endl;
			cout << "2----删除" << endl;
			cout << "3----退出" << endl;
			cin >> s;
			if (s == "1") {
				char a;
				int p;
				cout << "请输入要插入的位置： " << endl;
				cin >> p;
				cout << "请输入要插入的字符: " << endl;			
				cin >> a;
				
				if (st.insert(a,p))
					cout << "插入成功" << endl;
				else
					cout << "插入失败" << endl;
				st.display();
			}
			else if (s == "2") {
				cout << "请输入要删除的位置： " << endl;
				int p;
				cin >> p;
				if (st.del(p))
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;
				st.display();
			}
			else if (s == "3")
				break;
			else {
				cout << "错误指令，请重新输入" << endl;
			}
			system("pause");
			system("cls");
		}

	}
	else if (s == "2") {
		system("pause");
		system("cls");
		list qu;
		while (true) {
			cout << "1----插入" << endl;
			cout << "2----删除" << endl;
			cout << "3----退出" << endl;
			cin >> s;
			if (s == "1") {
				char a;
				int p;
				cout << "请输入要插入的位置： " << endl;
				cin >> p;
				cout << "请输入要插入的字符: " << endl;
				cin >> a;
				if (qu.insert(a, p))
					cout << "插入成功" << endl;
				else
					cout << "插入失败" << endl;
				qu.display();
			}
			else if (s == "2") {
				cout << "请输入要删除的位置： " << endl;
				int p;
				cin >> p;
				if (qu.remove(p))
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;
				qu.display();
			}
			else if (s == "3")
				break;
			else {
				cout << "错误指令，请重新输入" << endl;
			}
			system("pause");
			system("cls");
		}
	}
	return 0;
}