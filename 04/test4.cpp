#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	list<int> L = {1, 2};
	list<int>::iterator t = L.begin();
	L.push_front(10);
	cout << *t << '\n';
	L.push_back(5);
	L.insert(t, 6);
	t++;
	t = L.erase(t);
	cout << *t << '\n';
	list<int>::iterator it = L.begin();
	while (it != L.end())
		cout << *it++ << ' ';
}
