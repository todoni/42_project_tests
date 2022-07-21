#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
       int fd[2];
	   char	*cmd[5];

	   cmd[0] = "/usr/bin/mktemp";
	   cmd[1] = "/tmp/tmp.XXXXXXXX";
	   cmd[2] = NULL;
	   cmd[3] = NULL;
       pipe(fd);
       if (fork() == 0) {
              dup2(fd[1], STDOUT_FILENO);
              //execve(cmd[0], cmd, NULL);
              if (execve(cmd[0], cmd, NULL) == -1)
			  {	
				  printf("ddd\n");
				  //printf("%s\n", strerror(errno));
				  //exit(errno);
       		}
	   }
	   else {
              char buffer[1000];
              ssize_t size = read(fd[0], buffer, 1000);
              if ( (size>0) && (size<sizeof(buffer)) )
              {
                     buffer[size]='\0';
                     printf("%s", buffer);
					 printf("%lu\n", strlen(buffer));
              }
       }
	   cmd[0] = NULL;
	   
	   if (execve(cmd[0], cmd, NULL) == -1)
		   printf("failed\n");
}
