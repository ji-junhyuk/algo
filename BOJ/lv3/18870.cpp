#include <bits/stdc++.h>
using namespace std;

// find 선형탐색, lower_bound 이진탐색
// 좌표압축: 해당 좌표의 값을 그 값보다 작은 좌표값들의 개수로 대체한다
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	vector<int> v;

	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	set<int> s(v.begin(), v.end()); // 중복제거, 오름차순 정렬
	vector<int> vec(s.begin(), s.end());
	for (int n : v)
	{
		auto it = lower_bound(vec.begin(), vec.end(), n); // n 이상, lower_boud(찾으려는 key값 인덱스) cf. n 초과, upper_bound 찾으려는 key값보다 바로 다음으로 큰 값의 인덱스
		cout << it - vec.begin() << " "; // iter값이 아닌 index를 반환받기 위해서
	}
}
