#include "shell.h"

/**
* _re_alloc - this func reallocates a memory.
* @ptr: pointer to the memory allocated previously.
* @old: size of the allocated space.
* @newpt: new size (bytes) of the new memory.
*
* Return: (void) ptr.
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
		mem_cpy(newptr, ptr, newpt);
	else
		/*_memcpy(newptr, ptr, old);*/
		mem_cpy(newptr, ptr, old);

	free(ptr);
	return (newptr);
}
