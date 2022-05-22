#include <iostream>
using namespace std;
#define ll long long

ll N;
ll space;
ll flag;

void	print_space(ll N, ll space)
{
	for (int idx = 4 * N; idx < space; ++idx)
		cout << '_';
}

void recur(ll N)
{
	if (N == 0)
		return ;
	print_space(N, space);
	cout << "\"재귀함수가 뭔가요?\"\n";
	print_space(N, space);
	if (N == 1)
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	else
	{
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		print_space(N, space);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		print_space(N, space);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	}
	recur(--N);
	print_space(N + 1, space);
	cout << "라고 답변하였지.\n";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	space = 4 * (N + 1);
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	recur(N + 1);
}
