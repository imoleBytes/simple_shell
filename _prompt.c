#include "shell.h"


void displayPrompt(void)
{
	char *prompt = "=>$ ";

	write(1, prompt, 4);
}
