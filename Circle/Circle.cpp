#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector < int > a[111];
int len, Met[111];
set < vector <int> > Answer1;
vector < vector < int > > Answer;

void DFS(int v, int StartV, vector < int > Ans)
{
	Met[v] = 1;
	Ans.push_back(v);

	if (Ans.size() > len) return;

	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] == StartV && Ans.size() == len)
		{
			vector < int > Ans1 = Ans;
			sort(Ans1.begin(), Ans1.end());
			int x = Answer1.size();
			Answer1.insert(Ans1);
			if (x < Answer1.size())
			{
				Answer.push_back(Ans);
			}
			return;
		}
		else if (Met[a[v][i]] == 0) DFS(a[v][i], StartV, Ans);

	Met[v] = 0;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int n, m, kol;

	ifstream fin("input.txt");
	fin >> kol;

	for (int j = 0; j < kol; j++) {
		cout << "Test " << j + 1 << endl;
		fin >> n >> m;

		for (int i = 0; i < 111; i++)
		{
			Met[i] = 0;
			a[i].clear();
		}
		Answer.clear();

		for (int i = 0; i < m; i++)
		{
			int x, y;
			fin >> x >> y;

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
	}
	fin.close();
}