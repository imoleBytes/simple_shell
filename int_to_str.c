
/**
* intToStr - intToStr func
* @a: char sring
* @num: int
* @base: int
* @upper: boolean to check for x or X
* Return: poinyer
*/

char *intToStr(char *a, int num, int base, int upper)
{
	char t;
	int i, j;
	int negNum = num;

	if (num < 0)
	{
		num = num * -1;
	}

	for (i = 0; num > 0; i++)
	{
		if ((num % base) > 9)
		{
			if (upper == 1)
				a[i] = ((num % base) - 10) + 'A';
			else
				a[i] = ((num % base) - 10) + 'a';
		}
		else
			a[i] = (num % base) + '0';
		num = num / base;
	}
	if (negNum < 0)
	{
		a[i] = '-';
		i++;
	}

	a[i] = '\0';

	for (j = 0, i--; j < i; j++, i--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	return (a);
}
