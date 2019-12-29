#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){

char * res= (char*) malloc ((argc-1) * sizeof(char));

for(int i=1;i<argc;i++){

  char c = argv[i][strlen(argv[i])-1];

  res[i-1]=c;
}
printf("%s\n",res);
free(res);
}
