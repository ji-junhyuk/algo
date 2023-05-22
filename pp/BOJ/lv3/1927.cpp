#include <bits/stdc++.h>
using namespace std;

/*
   priority queue STL
   
   priority_queue<자료형, Container, 비교함수> 변수명
   - 비교함수에 따라 정렬됨. 기본적으로 내림차순 정렬.
   - 비교함수에 greater<int>를 넣으면 오름차순 정렬.
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	while (N--)
	{
		int number;
		cin >> number;
		if (!number)
		{
			if (pq.size())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
			pq.push(number);
	}
}
