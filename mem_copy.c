/**
 * mem_cpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void mem_cpy(void *newptr, const void *pter, unsigned int size)
{
	char *c_ptr = (char *)pter;
	char *c_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		c_newptr[i] = c_ptr[i];
}
