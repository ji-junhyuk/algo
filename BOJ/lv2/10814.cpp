#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int num;
	int age;
	string name;
} Person;

int cmp(const Person &a, const Person &b)
{
	if (a.age == b.age) 
		return a.num < b.num;
	else
		return a.age < b.age;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	Person *arr = new Person[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].num = i;
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
		cout << arr[i].age << " " << arr[i].name << '\n';
	return 0;
}
