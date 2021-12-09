#include <bits/stdc++.h>
using namespace std;

bool compare(string &a, string &b)
{
	if (a.length() == b.length())
		return (a < b);
	else
		return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string temp;
	string input[20001];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i];
	sort(input, input + N, compare);
	for (int i = 0; i < N; i++)
	{
		if (temp == input[i])
			continue;
		cout << input[i] << '\n';
		temp = input[i];
	}
}
/* 정렬알고리즘을 힙정렬로 구현할 수 있으면 시간초과가 안날꺼같다.
   #include <bits/stdc++.h>
using namespace std;

char arr[20000][51];

int p_strcmp(char *s1, char *s2)
{
        while (*s1 && (*s1 == *s2))
        {
                s1++;
                s2++;
        }
        return (*s1 - *s2);
}

int compare_length(char *s1, char *s2)
{
        int length1;
        int length2;

        length1 = 0;
        while (*s1)
        {
                length1++;
                *s1++;
        }
        length2 = 0;
        while (*s2)
        {
                length2++;
                *s2++;
        }
        if (length1 > length2)
                return 1;
        else if (length1 == length2)
                return 0;
        else
                return -1;
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int N;
        int length;

        cin >> N;
        for (int idx = 0; idx < N; idx++)
                cin >> arr[idx];
//cout << '\n';
        for (int idx = 0; idx < N - 1; idx++)
        {
                for (int jdx = 0; jdx < N - idx - 1; jdx++)
                {
                        if (compare_length(arr[jdx], arr[jdx + 1]) > 0)
                                swap(arr[jdx], arr[jdx + 1]);
                }
        }
        //for (int idx = 0; idx < N; idx++)
        //      cout << arr[idx] << '\n';
//cout << '\n';

        for (int idx = 0; idx < N - 1; idx++)
        {
                for (int jdx = 0; jdx < N - idx - 1; jdx++)
                {
                        if (p_strcmp(arr[jdx], arr[jdx + 1]) > 0 && compare_length(arr[jdx], arr[jdx + 1]) == 0)
                                swap(arr[jdx], arr[jdx + 1]);
                }
        }
        string temp;
        for (int idx = 0; idx < N; idx++)
        {
                if (temp == arr[idx])
                        continue;
                cout << arr[idx] << '\n';
                temp = arr[idx];
        }
}
*/
