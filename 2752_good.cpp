#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int j;
	int temp;
	int arr[3];

	i = 0;
	while (i < 3)
	{
		cin >> arr[i];
		i++;
	}
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		cout << arr[i] << ' ';
		i++;
	}
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(void)
//{
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//
//  int a, b, c; // 입력
//  cin >> a >> b >> c;
//  int d, e, f; // 크기 순으로 출력할 세 수
//  d = min({a,b,c});
//  f = max({a,b,c});
//  e = a+b+c-d-f;
//  cout << d << ' ' << e << ' ' << f;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(void){
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//
//  int arr[4];
//  for(int i=0;i<3;i++){
//    cin>>arr[i];
//  }
//  sort(arr, arr+3);
//  for(int i=0;i<3;i++){
//    cout<<arr[i]<<" ";
//  }
//}
