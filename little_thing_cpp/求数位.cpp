int	GetNum(int n)
{
	int count = 0;
	while (n >= 1)
	{
		n /= 10;
		count++;
	}
	return count;
}
