/**
 * mem_cpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @pter: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void mem_cpy(void *newptr, const void *pter, unsigned int size)
{
	char *c_ptr = (char *)pter;
	unsigned int i;
	char *c_newptr = (char *)newptr;

	for (i = 0; i < size; i++)
		c_newptr[i] = c_ptr[i];
}
