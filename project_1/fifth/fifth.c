#include<stdio.h>
#include<stdlib.h>

int** allocate(int rows, int cols){

  int** ret_val = malloc(rows * sizeof(int*));
  for(int i = 0; i< rows; i++){
    ret_val[i] = malloc(cols * sizeof(int));
  }
  return ret_val;
}

int check(int** arr,int size){

  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){

      int val = arr[i][j];
      for(int k=0;k<size;k++){
        for(int g=0;g<size;g++){
          if((k!=i||g!=j)&&arr[k][g]==val)return 0;
        }
      }
    }
  }

  int sum = 0;
  int flag = 0;
  for(int i=0;i<size;i++){
    int csum = 0;
    for(int j=0;j<size;j++){
      if(i==0){
        sum+=arr[i][j];

      }
      else{
      csum+=arr[i][j];
      flag=1;
      }
    }
    //printf("%d\n",csum);
    if(flag&&csum!=sum)return 0;
  }

  //printf("hi\n");
  for(int i=0;i<size;i++){
    int csum=0;
    for(int j=0;j<size;j++){
      csum+=arr[j][i];
    }
    if(csum!=sum)return 0;
  }

  int csum=0;
  for(int i=0;i<size;i++){

    csum+=arr[i][i];

  }
  if(csum!=sum)return 0;

  csum=0;
  for(int i=0;i<size;i++){

    csum+=arr[i][size-1-i];

  }
  if(csum!=sum)return 0;
  return 1;
}



int main(int argc, char** argv){
  int size;
  FILE* fp = fopen(argv[1], "r");
  fscanf(fp,"%d\n",&size);

  int** arr = allocate(size,size);

  int val;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(j<size-1)fscanf(fp,"%d\t",&val);
      else fscanf(fp,"%d\n",&val);
      arr[i][j] = val;
    }
  }
  int res = check(arr,size);
  if(res)printf("magic\n");
  else printf("not-magic\n");

  for(int i=0;i<size;i++){
    free(arr[i]);
  }
  free(arr);
  return 0;
}
