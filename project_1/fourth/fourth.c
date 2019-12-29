#include<stdio.h>
#include<stdlib.h>

int** allocate(int rows, int cols){

  int** ret_val = malloc(rows * sizeof(int*));
  for(int i = 0; i< rows; i++){
    ret_val[i] = malloc(cols * sizeof(int));
  }
  return ret_val;
}



void multiply(int** arr1, int rows1, int cols1,int** arr2, int rows2, int cols2){

  int ** res = allocate(rows1,cols2);

  for(int i=0; i< rows1; i++){
    for(int j=0;j<cols2;j++){
      int sum=0;
    for(int k=0; k < rows2; k++){
      sum+=arr1[i][k]*arr2[k][j];

    }
    res[i][j] = sum;
  }
}

for(int i = 0;i<rows1;i++){
  for(int j=0;j<cols2;j++){
    if(j<cols2-1)printf("%d\t",res[i][j]);
    else printf("%d\n",res[i][j]);
  }
}

}



int main(int argc, char** argv){
  FILE* fp = fopen(argv[1], "r");
  //int** matrix;
  //matrix = allocate(4, 5);
  int rows1,cols1;
  fscanf(fp,"%d\t",&rows1);
  fscanf(fp,"%d\n",&cols1);
  int** arr1 = allocate(rows1,cols1);

  int val;
  for(int i = 0; i < rows1; i++){
    for(int j = 0; j < cols1; j++){
      if(j<cols1-1)fscanf(fp,"%d\t",&val);
      else fscanf(fp,"%d\n",&val);
      arr1[i][j] = val;
    }
  }


  int rows2,cols2;
  fscanf(fp,"%d\t",&rows2);
  fscanf(fp,"%d\n",&cols2);
  int** arr2 = allocate(rows2,cols2);

  for(int i = 0; i < rows2; i++){
    for(int j = 0; j < cols2; j++){
      if(j<cols2-1)fscanf(fp,"%d\t",&val);
      else fscanf(fp,"%d\n",&val);
      arr2[i][j] = val;
    }
  }

  if(cols1!=rows2)printf("bad-matrices");
  else{multiply(arr1,rows1,cols1,arr2,rows2,cols2);}

  for(int i=0;i<rows1;i++){

    free(arr1[i]);

  }

  free(arr1);
  for(int i=0;i<rows2;i++){
    free(arr2[i]);
  }
  free(arr2);
  

  return 0;
}
