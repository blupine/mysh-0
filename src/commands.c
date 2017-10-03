#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include <sys/stat.h>
#include <sys/types.h>
int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  else 
  {
    chdir(*(argv+1));
    return 0;
  }
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  else
  {
    char dir[4096];
    getcwd(dir, 4096);
    printf("%s\n", dir);
    return 0;
  }
}

int validate_cd_argv(int argc, char** argv) {
	struct stat buf;
	if (argc == 2 && strcmp(*argv, "cd")==0 && access(*(argv+1), F_OK | R_OK ) ==0)
	{
		if( stat(*(argv+1), &buf) < 0 )
		{	return 0;}
		if(S_ISDIR(buf.st_mode))
		{	return 1;}
		else
			return 0;
	}
	else
		return 0;
}

int validate_pwd_argv(int argc, char** argv) {
	if(strcmp(*argv, "pwd")==0 && argc==1)
		return 1;
	else
		return 0;
}
