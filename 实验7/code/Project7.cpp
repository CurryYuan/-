// Project7.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include "Hash.h"
int main()
{
	Hash cu;
	while (true) {
		cout << "学生通讯录" << endl
			<< "【1】查找元素" << endl
			<< "【2】插入元素" << endl
			<< "【3】删除元素" << endl
			<< "【4】显示哈希表" << endl
			<< "【5】退出" << endl;
		int x;
		cin >> x;
		getchar();
		string a;
		student b;
		switch (x)
		{
		case 1:
			cout << "请输入学生姓名（姓和名之间用空格隔开）： ";
			getline(cin, a);
			cu.find(a);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "请输入要插入的学生信息" << endl;
			cout << "请输入学生姓名（姓和名之间用空格隔开）： ";
			getline(cin, a);
			if (cu.find(a, false))
				cout <<"插入失败，学生已存在" << endl;
			else {
				b.name = a;
				cout << "请输入学生性别： ";
				cin >> b.sex;
				cout << "请输入学生学号： ";
				cin >> b.id;
				cout << "请输入学生电话号码：";
				cin >> b.phone;
				cu.insert(b);
				cout << "插入成功" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "请输入要删除的学生姓名（姓和名之间用空格隔开）： ";
			getline(cin, a);
			cu.dele(a);
			system("pause");
			system("cls");
			break;
		case 4:
			cu.display();
			system("pause");
			system("cls");
			break;
		case 5:
			return 0;
		default:
			system("pause");
			system("cls");
			break;
		}

	}
    return 0;
}

