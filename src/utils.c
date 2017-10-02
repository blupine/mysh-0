#include "utils.h"
#include <stdlib.h>
#include <string.h>
void mysh_parse_command(const char* command, int *argc, char*** argv)
{
	int command_count = 0;
	char copy_buf[8096];
	char * parse;

	*argv = (char**)malloc(sizeof(char)*100);
	strcpy(copy_buf, command);
	copy_buf[strlen(command)] = '\0';
	parse = strtok(copy_buf, " ");

	while (parse!=NULL)
	{
		if(strcmp(parse, "\t") == 0 || strcmp(parse, "\n") == 0 )
		{
			parse = strtok(NULL, " ");
			continue;
		}
		*(*argv + command_count) = (char*)malloc(sizeof(char)*strlen(parse)+1);
		strcpy(*(*argv + command_count), parse);
		
		parse = strtok(NULL, " ");		
		command_count++;
	}
	if(command_count==0)
	{
		*(*argv) = (char*)malloc(sizeof(char));
		command_count = 1;
		strcpy(**argv, "");
	}
	*argc = command_count;
}
