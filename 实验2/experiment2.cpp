// experiment2.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "Stack.h"
#include "Quene.h"
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "1----������ջ" << endl;
	cout << "2----��������" << endl;
	string s;
	cin >> s;
	system("pause");
	system("cls");
	if (s == "1") {
		Stack st;
		while (true) {
			cout << "1----��ջ" << endl;
			cout << "2----��ջ" << endl;
			cout << "3----�˳�" << endl;
			cin >> s;
			if (s == "1") {
				cout << "������Ҫ��ջ���ַ�: " << endl;
				char a;
				cin >> a;
				if (st.push(a))
					cout << "��ջ�ɹ�" << endl;
				else
					cout << "��ջʧ��" << endl;
				st.display();
			}
			else if (s == "2") {
				if (st.pop())
					cout << "��ջ�ɹ�" << endl;
				else
					cout << "��ջʧ��" << endl;
				st.display();
			}
			else if(s=="3")
				break;
			else {
				cout << "����ָ�����������" << endl;
			}
			system("pause");
			system("cls");
		}
		
	}
	else if (s == "2") {
		Quene qu;
		while (true) {
			cout << "1----���" << endl;
			cout << "2----����" << endl;
			cout << "3----�˳�" << endl;
			cin >> s;
			if (s == "1") {
				cout << "������Ҫ��ӵ��ַ�: " << endl;
				char a;
				cin >> a;
				if (qu.append(a))
					cout << "��ӳɹ�" << endl;
				else
					cout << "���ʧ��" << endl;
				qu.display();
			}
			else if (s == "2") {
				if (qu.pop())
					cout << "���ӳɹ�" << endl;
				else
					cout << "����ʧ��" << endl;
				qu.display();
			}
			else if (s == "3")
				break;
			else {
				cout << "����ָ�����������" << endl;
			}
			system("pause");
			system("cls");
		}
	}
	else {
		cout << "ָ�����" << endl;
	}
    return 0;
}

