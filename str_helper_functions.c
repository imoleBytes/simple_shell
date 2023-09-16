/**
* *str_cpy - Copies the string pointed to by src.
* @dest: pointer to the dest of the copied string
* @src: pointer to the source of string
* Return: the dest.
*/

char *str_cpy(char *dest, char *src)
{

	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
