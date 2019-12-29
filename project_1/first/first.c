#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){


  FILE* fp = fopen(argv[1], "r");
  int num;
  fscanf(fp, "%d\n", &num);


  for(int i =0;i<num;i++){
      int temp;
      int flag = 1;
      fscanf(fp, "%d\n", &temp);
      if(temp==0)flag=0;
      printf("temp:%d\n",temp);
      for(int j=temp;j>0;j/=10){
        printf("j:%d\n",j);
        if(j==1||j==0){
          flag=0;
          break;
        }

      for(int k=2;k<=j/2;k++){
        if(j!=2&&j%k==0){
          flag=0;
          break;
        }

      }
}
      if(flag==0){
        printf("no\n");
      }
      else {
        printf("yes\n");
      }
      flag=0;
  }
  fclose(fp);
  return 0;


  /* Now read the first line in the file */

}
