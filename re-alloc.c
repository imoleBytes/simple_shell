#include "shell.h"

/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @old: size, in bytes, of the allocated space of ptr.
 * @newpt: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new == old, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_re_alloc(void *ptr, unsigned int newpt, unsigned int old)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(newpt));

	if (newpt == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (newpt == old)
		return (ptr);

	newptr = malloc(newpt);
	if (newptr == NULL)
		return (NULL);

	if (newpt < old)
		/*_memcpy(newptr, ptr, new);*/
		mem_cpy(newptr, ptr, newpt);
	else
		/*_memcpy(newptr, ptr, old);*/
		mem_cpy(newptr, ptr, newpt);

	free(ptr);
	return (newptr);
}
