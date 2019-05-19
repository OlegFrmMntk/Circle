#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector < int > a[111];
int len, Met[111];
set < vector <int> > Answer;

void DFS(int v, int StartV, vector < int > Ans)
{
	Met[v] = 1;
	Ans.push_back(v);

	if (Ans.size() > len) return;

	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] == StartV && Ans.size() == len)
		{
			sort(Ans.begin(), Ans.end());
			Answer.insert(Ans);
			return;
		}
		else if (Met[a[v][i]] == 0) DFS(a[v][i], StartV, Ans);

	Met[v] = 0;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int n, m;
	cout << "Введите количество вершин графа: ";
	cin >> n;
	cout << "\nВведите количество ребер графа: ";
	cin >> m;

	cout << "Введите все ребра:\n";

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		a[x].push_back(y);
		a[y].push_back(x);
	}

	cout << "Введите длину цикла, который нужно найти: ";
	cin >> len;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			Met[j] = 0;

		vector < int > x;
		DFS(i, i, x);
	}

	for (auto now : Answer)
	{
		for (int i = 0; i < now.size(); i++)
			cout << now[i] << " ";
		cout << now[0] << "\n";
	}

	return 0;
}