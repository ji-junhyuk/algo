#include <bits/stdc++.h>
using namespace std;

int is_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	strlen(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		;
	return (idx);
}
int GetOpPrec(char op)
{
	switch(op)
	{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	stack <char> s;
	int expLen = strlen(exp);
	char *convExp = (char *)malloc(expLen + 1); // 변환된 수식을 담을 공간 마련

	int i, idx = 0;
	char tok, popOp;
	char temp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // 할당된 배열을 0으로 초기화

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i]; //exp로 전달된 수식을 한 문자씩 tok에 저장
		if (is_char(tok)) // tok에 저장된 문자가 숫자인지 확인
			convExp[idx++] = tok; // 숫자이면 배열 convExp에 저장
		else
		{
			switch(tok)
			{
				case '(':
					s.push(tok);
					break;
				case ')':
					while (1)
					{
						popOp = s.top();
						s.pop();
						if (popOp == '(')
							break;
						convExp[idx++] = popOp;
					}
					break;
				case '+': case '-':
				case '*': case '/':
					while (!s.empty() && WhoPrecOp(s.top(), tok) >= 0) // 스택에 저장된 연산자가 먼저 연산이 되어야 하는 경우 
					{
						convExp[idx++] = s.top();
						s.pop();
					}
					s.push(tok);
					break;
			}
		}
	}
	while (!s.empty())
	{
		convExp[idx++] = s.top();
		s.pop();
	}
	strcpy(exp, convExp);
	free(convExp);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char arr[101];
	cin >> arr;
	ConvToRPNExp(arr);
	cout << arr;
}
