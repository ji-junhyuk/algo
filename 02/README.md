### C++ 함수 이용하기, 다음엔 vector로 풀어보기
max({a,b,c})

sort(arr, arr+3);

d = min({a,b,c});

f = max({a,b,c});

if (x & 1) 

swap(a,b);

reverse(num+a, num+b+1);

*max_element(a, a+9) << '\n';

max_element(a, a+9) - a + 1;



### outofbounds 에러 //선언 int arr[21];
int arr[20];

        i = 0;
        while (++i < 21)
                arr[i] = i;
{
배열에 할당된 크기를 넘어서 접근했을 때
전역 배열의 크기가 메모리 제한을 초과할 때
지역 배열의 크기가 스택 크기 제한을 넘어갈 때
0으로 나눌 떄
라이브러리에서 예외를 발생시켰을 때
재귀 호출이 너무 깊어질 때
이미 해제된 메모리를 또 참조할 때
}
