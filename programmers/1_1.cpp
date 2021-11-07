int check_divisor(int number)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (++i <= number)
	{
		if (number % i == 0)
			count++;
	}
	return (count);
}

int solution(int left, int right) 
{
    int i;
    int result;

    i = left - 1;
    result = 0;
    while (++i <= right)
		result += (check_divisor % 2) : result -= i ? result += i;
    return (result);
}
