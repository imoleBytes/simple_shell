/**
* mem_cpy - this func copies information between pointers.
* @newptr: dest pointer.
* @pter: src pointer.
* @size: size of the new pointer.
*/

void mem_cpy(void *newptr, const void *pter, unsigned int size)
{
	char *c_ptr = (char *)pter;
	char *c_newptr = (char *)newptr;
	unsigned int i;


	for (i = 0; i < size; i++)
		c_newptr[i] = c_ptr[i];
}
