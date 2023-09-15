#include "shell.h"

/**
 * displayPrompt - function stdout
 */
void displayPrompt(void)
{
	char *prompt = "$ ";

	write(1, prompt, 2);
}
