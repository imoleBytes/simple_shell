/**
 * is_digit - function checks if string is digit
 * @str: string as paramater
 * Return: the digit in string or 2 if all not digit
 */
int is_digit(char *str)
{
	char result, flag = 1;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
			return (2);
		str++;
	}
	return (result * flag);
}
