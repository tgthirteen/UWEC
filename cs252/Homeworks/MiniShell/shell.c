#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void directory(){
  char buff[PATH_MAX] = "";
  char* currentDir = getcwd(buff, PATH_MAX);
  printf("%s> ", currentDir);
}

char* read_line(void){
  char* line = NULL;
  ssize_t bufferSize = 0;
  getline(&line, &bufferSize, stdin);
  return line;
}

void parseArgs(char *buffer, char** args, int argsSize, int *nargs) {
 char *bufArgs[argsSize];
 char **cp;
 char *wbuf;
 int i, j;
 wbuf=buffer;
 bufArgs[0]=buffer;
 args[0]=buffer;

 for(cp=bufArgs; (*cp=strsep(&wbuf, " \n\t")) != NULL ;){
    if ((*cp != '\0') && (++cp >= &bufArgs[argsSize]))
      break;
 }

 for (j=i=0; bufArgs[i]!=NULL; i++){
      if(strlen(bufArgs[i])>0)
        args[j++]=bufArgs[i];
 }
 // Add the NULL as the end argument because we need that for later
 *nargs=j;
 args[j]=NULL;
}

void cd(char* args){
  
  if (args == NULL) {
    fprintf(stderr, "minishell: expected argument to \"cd\"\n");
  }
  else {
    if (chdir(args) != 0) {
      perror("minishell");
    }
  }
}

int bgProcess(char** args){

  for(int i = 0; i < 10; i++){
     if(strcmp(args[i], "&") == 0){
        if(args[i+1] == NULL){
          return 1;
        }
        else{
          return 0;
        }
      }        
  }
   
  return 0;

}

int execute(char** args){

  pid_t pid, wpid;
  int status;
  int background;

  pid = fork();
  if (pid == 0) {
    
    if (execvp(args[0], args) == -1) {
      perror("minishell");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("minishell");
  } else {
    
      if(bgProcess(args) == 1){
        printf("waiting...\n");
        waitpid(pid, &status, 0);
      }
          
  }

  return 1;


}


void outRedirect(char** args){

    /*


    */

}


void inRedirect(char** args){

  /*


  */ 

}


void loop(){
  
  int elements = 100;
  char* line = malloc(sizeof(char) * (elements + 1));
  char** args = malloc(sizeof(char*) * (elements + 1));
  int exit = 0;
  int nargs;
  int background = 0; 
 
  do{
    directory();
    line = read_line();
    parseArgs(line, args, 10, &nargs); 
    
    if(strcmp(args[0], "cd") == 0){
      cd(args[1]);
     }

    else if(strcmp(args[0], "exit") == 0){
     // printf("Should Exit");
      exit = 1; 
    }
    else{
       execute(args);
    }
   
     free(line);
  }
  while(exit == 0);
}


int main(int argc, char **argv){
  
  int exit = 0;
  
  //loop
  loop(); 
  
  return EXIT_SUCCESS;
}
