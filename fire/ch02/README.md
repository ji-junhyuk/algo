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
```
1. 함수의 정의: int fibo(int n) // n번째 피보나치 수열항을 찾는다
2. 종료조건: 특정 항을 구하기 위해서 2개의 수열이 필요하므로 첫번째항 0, 두번째항 1로 설정
3. 재귀식: func(n - 1) + func(n - 2)
```

```c
// 시간복잡도 O(1.6^n)
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

// 시간복잡도 O(n)
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
```
함수의 정의: BSearch(int arr[], int left, int right, int number) // 배열 특정 인덱스에 있는 숫자를 찾기 위해 반씩 줄여나가야 하는 연산을 해야 하므로, arr은 정렬된 배열이다
종료 조건: if (left > right) // 배열에 그 값이 없는 경우
재귀식: 
BSearch(arr, left, center -1, number) // 특정값이 인덱스 중간값보다 작은 경우 
BSearch(arr, center + 1, right, number) // 특정값이 인덱스 중간값보다 큰 경우
```

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
```
함수의 정의: void hanoi(int a, int c, int number) // 원반 number개를 a기둥에서 c기둥으로 이동한다. ,작은 원반 위에 큰 원반은 올 수 없음. 원반은 1개씩만 이동.
종료 조건: if (number == 1) // 원반의 개수가 1개인 경우 이동시킨다
재귀식: 
1단계. 작은 원반 n-1개(맨 아래를 제외한 원반)를 A에서 6 - A - C로 이동
2단계. 큰 원반 1개(맨 아래의 원반)를 A에서 C로 이동
3단계. 작은 원반 n-1개(1에서 옮겨진 원반들)를 6 - A - C에서 C로 이동
```

```c
void hanoi(int a, int c, int number) // 큰 원반(number)을 a에서 b로 이동
{
    if (number == 1)
       printf("원반1을 %d, %d로 이동\n", a, c);
    else
    {
        hanoi(a, 6 - a - c, number - 1); // 중간 기둥으로 이동
        printf("원반%d를 %d, %d로 이동\n", number, a, c);
        hanoi(6 - a - c, c, number - 1); // 목표 기둥으로 이동
    }
}
```
