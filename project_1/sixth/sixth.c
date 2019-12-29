#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isVowel(char c){
  if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U'){

    return 0;
  }
  return 1;
}

int main(int argc, char** argv){
  int size = 0;
  for(int i=1;i<argc;i++){
    size+=strlen(argv[i]);
  }
  size+=(argc+10);
  size+=(3*(argc-1));

  char * new= (char*) malloc ((size) * sizeof(char));

  for(int i=1;i<argc;i++){

    char* word = argv[i];



    if(isVowel(word[0])==1){


      strcat(new,word);
      strcat(new,"yay");

    }
    else{

      char * bef= (char*) malloc (1000*sizeof(char));
      char * after=(char*) malloc (1000*sizeof(char));


      for(int j=0;j<strlen(word);j++){

        if(isVowel(word[j])){

          strncpy(bef,word,j);

          strncpy(after,word+j,strlen(word)-j);

          strcat(new,after);
          strcat(new,bef);
          free(bef);
          free(after);

          strcat(new,"ay");

          break;
        }
      }
    }

    if(i<argc-1)strcat(new," ");

  }


  printf("%s\n",new);
  free(new);
  return 0;
}
