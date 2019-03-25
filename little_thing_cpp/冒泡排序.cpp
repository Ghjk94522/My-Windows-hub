void sort(int a[],int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		int min = a[i]; int t = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < min)
			{
				min = a[j];
				t = j;
			}
		if (min != a[i])
		{
			temp = a[i];
			a[i] = min;
			a[t] = temp;
		}
	}
}