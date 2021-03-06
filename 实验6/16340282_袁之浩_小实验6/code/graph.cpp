
#include "graph.h"
using namespace std;


Graph::Graph()
{
}

void Graph::matrixStore()
{
	int n;
	cout << "请输入节点的个数" << endl;
	cin >> n;
	cout << "请输入节点名" << endl;
	string x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		point.push_back(x);
	}

	n = point.size();
	matrix = new int*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; ++j)
			matrix[i][j] = 0;
	}

	int m;
	cout << "请输入边的条数" << endl;
	cin >> m;
	string y;
	cout << "请输入边（格式：起点 终点 权）" << endl;
	for(int i=0;i<m;++i) {
		cin >> x >> y >> n;
		int a = find(x);
		int b = find(y);
		matrix[a][b] = n;
		matrix[b][a] = n;
	}
}

int Graph::find(string a)
{
	for (int i = 0; i < point.size(); ++i) {
		if (a == point[i])
			return i;
	}
	return -1;
}

int Graph::find1(string a)
{
	for (int i = 0; i < lists.size(); ++i) {
		if (a == lists[i].name)
			return i;
	}
	return -1;
}

void Graph::matrixDfs()
{
	cout << "深度优先搜索:" << endl;
	int n = point.size();
	bool* visit = new bool[n];
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
	}

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			dfs(i,visit);
		}
	}
	cout << endl;
}

void Graph::dfs(int i, bool*& visit) {
	visit[i] = true;
	cout << point[i] << " ";
	for (int j = 0; j < point.size(); ++j) {
		if (matrix[i][j] > 0 && !visit[j]) {
			dfs(j, visit);
		}
	}
}

void Graph::dfs1(int i, bool *& visit)
{
	visit[i] = true;
	cout << lists[i].name << " ";
	for (auto c : lists[i].tail) {
		if (c.val > 0 && !visit[c.num]) {
			dfs1(c.num, visit);
		}
	}
}

void Graph::matrixBfs()
{
	cout << "广度优先搜索：" << endl;
	int n = point.size();
	bool* visit = new bool[n];
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
	}

	for (int i = 0; i < n; ++i) {
		queue<int> a;
		if (!visit[i]) {
			a.push(i);
			visit[i] = true;
		}
		while (!a.empty()) {
			int b = a.front();
			cout << point[b] << " ";
			for (int j = 0; j < n; ++j) {
				if (matrix[b][j] > 0&&!visit[j]) {
					a.push(j);
					visit[j] = true;
				}
			}
			a.pop();
		}
	}
	cout << endl;
}

void Graph::listsDfs()
{
	cout << "深度优先搜索：" << endl;
	int n = lists.size();
	bool* visit = new bool[n];
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
	}

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			dfs1(i, visit);
		}
	}
	cout << endl;
	delete[] visit;
}

void Graph::listsBfs()
{
	cout << "广度优先搜索：" << endl;
	int n = lists.size();
	bool* visit = new bool[n];
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
	}

	for (int i = 0; i < n; ++i) {
		queue<int> a;
		if (!visit[i]) {
			a.push(i);
			visit[i] = true;
		}
		while (!a.empty()) {
			int b = a.front();
			cout << lists[b].name << " ";
			for (auto c : lists[b].tail) {
				if (c.val > 0 && !visit[c.num]) {
					a.push(c.num);
					visit[c.num] = true;
				}
			}
			a.pop();
		}
	}
	cout << endl;
}

int Graph::findSmallest(vector<int> dis, vector<int> visit) {
	int a = -1;
	int temp = INT_MAX;
	for (int i = 0; i < dis.size(); ++i) {
		if (dis[i] <= 0||visit[i])
			continue;
		if (dis[i] < temp) {
			a = i;
			temp = dis[i];
		}
	}
	return a;
}

void Graph::matrixShortest()
{
	string x;
	cout << "请输入起点" << endl;
	cin >> x;
	int n = point.size();
	vector<int> dis(n);
	vector<int> visit(n);
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
		int temp = matrix[find(x)][i];
		if (temp == 0)
			temp = INT_MAX;
		if (i == find(x))
			temp = 0;
		dis[i] = temp;
	}
	visit[find(x)] = true;
	while(true) {
		int s = findSmallest(dis,visit);
		if (s <= 0)
			break;
		visit[s] = true;
		for (int i = 0; i < n; ++i) {
			if (matrix[s][i] <= 0)
				continue;
			if (matrix[s][i] + dis[s] < dis[i])
				dis[i] = matrix[s][i] + dis[s];
		}
	}
	cout << x << "到其他各点的最短距离为：" << endl;
	for (int i = 0; i < n; ++i) {
		if (i == find(x))
			continue;
		if (dis[i] == INT_MAX)
			cout << point[i] << "   无穷" << endl;
		else
			cout << point[i] << "   " << dis[i] << endl;
	}
}

void Graph::listsShortest()
{
	string x;
	cout << "请输入起点" << endl;
	cin >> x;
	int n = lists.size();
	vector<int> dis(n);
	vector<int> visit(n);
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
		dis[i] = INT_MAX;
	}
	dis[find1(x)] = 0;
	for (auto c : lists[find1(x)].tail) {
		dis[c.num] = c.val;
	}
	visit[find1(x)] = true;
	while (true) {
		int s = findSmallest(dis, visit);
		if (s <= 0)
			break;
		visit[s] = true;
		for (auto c: lists[s].tail) {
			if (c.val <= 0)
				continue;
			if (c.val + dis[s] < dis[c.num]) {
				dis[c.num] = c.val + dis[s];
			}
		}
	}
	cout << x << "到其他各点的距离为：" << endl;
	for (int i = 0; i < n; ++i) {
		if (i == find1(x))
			continue;
		if (dis[i] == INT_MAX)
			cout << lists[i].name << "   无穷" << endl;
		else
			cout << lists[i].name << "   " << dis[i] << endl;
	}
}

void Graph::listStore()
{
	int n;
	cout << "请输入节点的个数" << endl;
	cin >> n;
	cout << "请输入节点名" << endl;
	string x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		lists.push_back(head(x));
	}

	n = point.size();
	int m;
	cout << "请输入边的条数" << endl;
	cin >> m;
	string y;
	cout << "请输入边（格式：起点 终点 权）" << endl;
	for (int i = 0; i<m; ++i) {
		cin >> x >> y >> n;
		int a = find1(x);
		int b = find1(y);
		lists[a].tail.push_back(node(b, n));
		lists[b].tail.push_back(node(a, n));
	}
}