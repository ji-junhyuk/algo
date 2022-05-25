/*
 * 1. 리스트를 생성 및 초기화한 다음, 정수 1부터 9까지 리스트에 저장한다.
 * 2. 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력한다.
 * 3. 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제한다.
 * 4. 마지막으로 리스트에 저장된 데이터를 순서대로 출력한다.
 */

#include "ArrayList.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void)
{
	List list;
	int	data;
	int	sum;

	ListInit(&list);
	for (int idx = 0; idx < 10; ++idx)
		LInsert(&list, idx);
	sum = 0;
	if (LFirst(&list, &data))
	{
		sum += data;
		while (LNext(&list, &data))
			sum += data;
	}
	printf("sum:%d\n", sum);

	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	return (0);
}
