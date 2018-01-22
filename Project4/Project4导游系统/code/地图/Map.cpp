#include "Map.h"

Map::Map()
{
}

void Map::store(string f)
{
	fstream file;
	int n;
	string x, y;
	file.open(f, ios::in | ios::out);
	file >> n;
	for (int i = 0; i < n; ++i) {
		file >> x;
		file >> y;
		lists.push_back(head(x, y));
	}
	int m;
	file >> m;
	for (int i = 0; i<m; ++i) {
		file >> x >> y >> n;
		int a = find(x);
		int b = find(y);
		lists[a].tail.push_back(node(b, n));
		lists[b].tail.push_back(node(a, n));
	}
	file.close();
}

void Map::shortest(vector<string>& path,vector<int>& dis,string x,string y)
{
	int n = lists.size();
	int a = find(x);
	int b = find(y);
	vector<int> visit(n);
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
		dis[i] = INT_MAX;
		path[i] = x + " --> " + lists[i].name;
	}
	dis[a] = 0;
	for (auto c : lists[a].tail) {
		dis[c.num] = c.val;
	}
	visit[a] = true;
	while (true) {
		int s = findSmallest(dis, visit);
		if (s <= 0)
			break;
		visit[s] = true;
		for (auto c : lists[s].tail) {
			if (c.val <= 0)
				continue;
			if (c.val + dis[s] < dis[c.num]) {
				dis[c.num] = c.val + dis[s];
				path[c.num] = path[s] + " --> " + lists[c.num].name;
			}
		}
	}
	
}

void Map::walk()
{
	string x, y;
	cout << "�����������յ�" << endl;
	cin >> x >> y;
	int a = find(x);
	int b = find(y);
	if (a == -1) {
		cout << "���� " << x << " ������" << endl;
	}
	if (b == -1) {
		cout << "���� " << y << " ������" << endl;
	}
	if (a == -1 || b == -1)
		return;
	if (a == b) {
		cout << "�����յ㲻����ͬ" << endl;
		return;
	}
	int n = lists.size();
	vector<string> path(n);
	vector<int> dis(n);
	shortest(path, dis, x, y);

	cout << x << " �� " + y + " �ľ���Ϊ��" << dis[b] << endl;
	cout << x << " �� " + y + " ��·��Ϊ��" << path[b] << endl;
}

void Map::search()
{
	string a;
	cout << "�����뾰������" << endl;
	cin >> a;
	if (find(a) == -1) {
		cout << "���㲻����" << endl;
		return;
	}
	auto temp = lists[find(a)];
	cout << "������" << endl;
	cout << temp.infor << endl;
}

void Map::printAll()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                       ����                                        " << endl;
	cout << "                                       /|\\										" << endl;
	cout << "                                    2 / | \\2										" << endl;
	cout << "                                     /  |  \\										" << endl;
	cout << "                    ��ѧԺ¥  �D�D�D/   |   \\�D�D�D�D ����¥ 			           " << endl;
	cout << "                  ��                    |              /							" << endl;
	cout << "                2��                     |4            /			  							" << endl;
	cout << "                ��                      |            /2					" << endl;
	cout << "               ��                       |           /								" << endl;
	cout << "              ��Ժ                    ͼ��� �D�D�D/								" << endl;
	cout << "             ��   \\                    | \\											" << endl;
	cout << "           1��     \\1                  |  \\ 2     							" << endl;
	cout << "           ��       \\                  |   \\      						" << endl;
	cout << "   	 ʵ������    ����Ժ            |2   \\											" << endl;
	cout << "                       \\               |    ���															" << endl;
	cout << "                        \\ 2            |           															" << endl;
	cout << "                        �ٲ�           |     							" << endl;
	cout << "                                       ����										" << endl;
	cout << "                                       / \\											" << endl;
	cout << "                                     2/   \\2										" << endl;
	cout << "                                     /     \\										" << endl;
	cout << "                 5         2        /   1   \\		1								" << endl;
	cout << "      ��ѧ�Ǳ� �D�D�D���� �D�D�D����԰ �D�D����� �D�D�D����									" << endl;
	cout << "                      |            |           |											" << endl;
	cout << "                      |            |1          |1												" << endl;
	cout << "                      |            |           |													" << endl;
	cout << "                      |     1      |     1     |												" << endl;
	cout << "                  ����԰ �D�D�D�Dһ�� �D�D�D����԰										" << endl;
	cout << "                                   |       /   |				" << endl;
	cout << "                                   |1     /    |						" << endl;
	cout << "                                   |     /1    |1		" << endl;
	cout << "                                   |    /      |							" << endl;
	cout << "                                   |   / 1     |								" << endl;
	cout << "                                   �ķ� �D�D��˼԰				        " << endl;
	cout << "                                       											" << endl;
	cout << "                                									" << endl;
	cout << "																					" << endl;
	cout << endl;
}

void Map::printCar()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                       ����                                        " << endl;
	cout << "                                       /|\\										" << endl;
	cout << "                                    2 / | \\2										" << endl;
	cout << "                                     /  |  \\										" << endl;
	cout << "                    ��ʵ��¥  �D�D�D/   |   \\�D�D�D�D ����¥ 			            " << endl;
	cout << "                  ��                    |											" << endl;
	cout << "                2��                     |										" << endl;
	cout << "                ��                    ͼ���									" << endl;
	cout << "               ��																	" << endl;
	cout << "              ��Ժ																" << endl;
	cout << "             ��																	" << endl;
	cout << "           1��             ��                          ��							" << endl;
	cout << "           ��               ����Ժ                      ���						" << endl;
	cout << "   	 ʵ����ѧ																	" << endl;
	cout << "																					" << endl;
	cout << "                           ��															" << endl;
	cout << "                            �ٲ�													" << endl;
	cout << "                                      ����										" << endl;
	cout << "                                       / \\											" << endl;
	cout << "                                     2/   \\2										" << endl;
	cout << "                                     /     \\										" << endl;
	cout << "                                    /       \\										" << endl;
	cout << "                      ���� �D�D�D����԰	�����									" << endl;
	cout << "                      /															" << endl;
	cout << "                     /																" << endl;
	cout << "                    /																" << endl;
	cout << "                ��ʵ��¥															" << endl;
	cout << "																					" << endl;
	cout << "                    ��   		     ��													" << endl;
	cout << "                     ����԰                   һ��											" << endl;
	cout << "                                                  ������԰						" << endl;
	cout << "                                    ��												" << endl;
	cout << "                                      �ķ�											" << endl;
	cout << "																					" << endl;
	cout << "                                         ��											" << endl;
	cout << "                                          ��˼԰									" << endl;
	cout << "																					" << endl;
	cout << endl;
}


int Map::find(string a)
{
	for (int i = 0; i < lists.size(); ++i) {
		if (a == lists[i].name)
			return i;
	}
	return -1;
}

int Map::findSmallest(vector<int> dis, vector<int> visit) {
	int a = -1;
	int temp = INT_MAX;
	for (int i = 0; i < dis.size(); ++i) {
		if (dis[i] <= 0 || visit[i])
			continue;
		if (dis[i] < temp) {
			a = i;
			temp = dis[i];
		}
	}
	return a;
}

Map::~Map()
{
}
