#include "shell.h"

/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @old: size, in bytes, of the allocated space of ptr.
 * @new: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new == old, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new));

	if (new == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new == old)
		return (ptr);

	newptr = malloc(new);
	if (newptr == NULL)
		return (NULL);

	if (new < old)
		/*_memcpy(newptr, ptr, new);*/
		mem_cpy(newptr, ptr, new);
	else
		/*_memcpy(newptr, ptr, old);*/
		mem_cpy(newptr, ptr, new);

	free(ptr);
	return (newptr);
}
