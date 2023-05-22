#include <bits/stdc++.h>
using namespace std;

struct s_tool
{
	char left;
	char right;
};

struct s_tool arr[100];

void	preorder(char root)
{
	if (root == '.')
		return ;
	cout << root;
	preorder(arr[root - 'A'].left);
	preorder(arr[root - 'A'].right);
}

void	inorder(char root)
{
	if (root == '.')
		return ;
	inorder(arr[root - 'A'].left);
	cout << root;
	inorder(arr[root - 'A'].right);
}

void	postorder(char root)
{
	if (root == '.')
		return ;
	postorder(arr[root - 'A'].left);
	postorder(arr[root - 'A'].right);
	cout << root;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	while (N--)
	{
		char a, b, c;
		cin >> a >> b >> c;
		arr[a - 'A'].left = b;
		arr[a - 'A'].right = c;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}
