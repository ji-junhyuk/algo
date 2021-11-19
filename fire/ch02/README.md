# 재귀(Recursion)
- 재귀함수는 자료구조나 알고리즘의 어려운 문제를 **단순화**하는데 사용되는 중요한 무기이다.
- 모든 재귀함수는 **반복문만으로 동일한 동작**을 하는 함수를 만들 수 있다.
- 재귀적인 **수학적 수식을 그대로 코드**에 옮길 수 있다.
- 재귀는 반복문으로 구현했을 때에 비해 코드는 **간결하지만 메모리/시간**에서는 손해를 본다.
(함수 호출은 비용이 큰 연산, 프로그래밍의 용이성과 메모리 소요 크기 중 선택이 필요하다.)
- 재귀함수가 자기 자신을 호출할 때마다 **Stack메모리**에 함수에 대한 정보가 계속 쌓임.
- 재귀 접근 순서
```c
1. 함수를 먼저 정의하자!
2. 종료조건을 생각하자!
3. 재귀식을 구현하자!
```
- 한 함수가 자기 자신을 여러 차례 호출하게 되면 **비효율적일 수** 있다.
(아래 코드에서 45번째 피보나치 수를 찾기 위해선 함수 호출을 약 11억번 한다.) 

### 01.피보나치수열(0, 1, 1, 2)
```c
int func(int n)
{
	printf("func call param %d\n", n);
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return func(n - 1) + func(n - 2);
}

// 연산 89회 메모이제이션(DP)
int memo[100000];
int func2(int n)
{
	printf("func call param %d\n", n);
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (memo[n] != 0)
		return memo[n];
	memo[n] = func2(n - 1) + func2(n - 2);
	return memo[n];
}
```

### 재귀구현연습
```c
- 피보나치수열 n번째 수
- 이진탐색
- 하노이타워
```

### 02.이진탐색
```c
int BinarySearch(int arr[], int left, int right, int number)
{
    int center;
    
    if (left > right)
        return -1; // 탐색 실패
    center = (left + right) / 2;
    
    if (arr[center] == number)
        return center;
    else if (arr[center] > number)
        BinarySearch(arr, left, center - 1, number);
    else
        BinarySearch(arr, center + 1, right, number);
}
```

### 03.하노이타워
```c
void hanoi(int a, int b, int number) // 큰 원반(number)을 a에서 b로 이동
{
    if (number == 1)
       printf("원반1을 %d, %d로 이동\n", a, b);
    else
    {
        hanoi(a, 6 - a - b, number - 1); // 중간 기둥으로 이동
        printf("원반%d를 %d, %d로 이동\n", number, a, b);
        hanoi(6 - a - b, b, number - 1); // 목표 기둥으로 이동
    }
}
```
