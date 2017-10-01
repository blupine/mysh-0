#include "utils.h"
#include <stdlib.h>
#include <string.h>
void mysh_parse_command(const char* command, int *argc, char*** argv)
{
	int command_count = 1;
	char copy_buf[8096];
	char * parse;
	*argv = (char**)malloc(sizeof(char) * 4);
	strcpy(copy_buf, command);

	parse = strtok(copy_buf, " \t\n");

	while (parse != NULL)
	{
		*(*argv + command_count - 1) = (char*)malloc(sizeof(char)*strlen(parse));
		strcpy(*(*argv + command_count - 1), parse);
		
		parse = strtok(NULL, " \t\n");
		if (parse == NULL) break;
		command_count++;
	}
	*argc = command_count;
}
