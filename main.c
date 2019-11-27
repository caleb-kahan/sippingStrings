#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char ** parse_args( char * line );

int main(){
  char line [100]  = "ls -a -l";
  char ** args = parse_args( line );
  execvp(args[0], args);
  free(args);
  return 0;
}

char ** parse_args( char * line){
  char * token;
  char ** returner = malloc(6*sizeof(char *));
  int i = 0;
  while(line){
    token = strsep(&line," ");
    returner[i] = token;
    i++;
  }
  returner[i] = 0;
  return returner;
}
