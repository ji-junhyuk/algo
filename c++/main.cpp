#include <iostream>

//주석
//설명 역활, 코드로 인식되지 않는다.
int main()
{
	//자료형(크기 단위, byte)
	//정수형: char(1), short(2), int(4), long(4), long long(8)
	//실수형: float, double

	int i = 0;
	 
	// 1바이트로 양수만 표현
	// 256가지 -> 0 ~ 255
	unsigned char c = 0;
	c = 1;

	// 1 바이트로 양수, 음수 둘다 표현
	// -128 ~ 0 ~ 127
	char c1;
	c1 = -255;
	std::cout << c1;

	/*
	   음수찾기: 특정 수를 더했을 때 0이 나오는 수를 찾자.
	   이진수의 경우 2의 보수
	   2의 보수법(대응되는 양수의 부호를 반전 후, 1을 더한다)
	*/

	return 0;
}
