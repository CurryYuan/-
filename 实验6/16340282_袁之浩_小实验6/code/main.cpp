#include "graph.h"

int main() {
	Graph a;
	while (true) {
		cout << "����ͼ��Сʵ��" << endl;
		cout << "��1���ڽӾ��󴢴�" << endl;
		cout << "��2���ڽӱ���" << endl;
		cout << "��3���ڽӾ��������������" << endl;
		cout << "��4���ڽӾ�������������" << endl;
		cout << "��5���ڽӾ������·��" << endl;
		cout << "��6���ڽӱ������������" << endl;
		cout << "��7���ڽӱ�����������" << endl;
		cout << "��8���ڽӱ����·��" << endl;
		cout << "��9���˳�" << endl;
		int x;
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			a.matrixStore();
			system("pause");
			system("cls");
			break;
		case 2:
			a.listStore();
			system("pause");
			system("cls");
			break;
		case 3:
			a.matrixDfs();
			system("pause");
			system("cls");
			break;
		case 4:
			a.matrixBfs();
			system("pause");
			system("cls");
			break;
		case 5:
			a.matrixShortest();
			system("pause");
			system("cls");
			break;
		case 6:
			a.listsDfs();
			system("pause");
			system("cls");
			break;
		case 7:
			a.listsBfs();
			system("pause");
			system("cls");
			break;
		case 8:
			a.listsShortest();
			system("pause");
			system("cls");
			break;
		case 9:
			return 0;
		default:
			break;
		}
	}
	
}