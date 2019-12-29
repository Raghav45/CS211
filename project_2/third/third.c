#include <stdlib.h>
#include <stdio.h>

double** allocate_matrix(int rows,int cols){

  double** ret_val = malloc(rows * sizeof(double*));
  for(int i = 0; i< rows; i++){
    ret_val[i] = malloc(cols * sizeof(double));
  }
  return ret_val;
}

void print_matrix(double** arr,int rows,int cols){
for(int i = 0; i < rows; i++){
  for(int j = 0; j < cols; j++){

    if(j<cols-1)printf("%lf,",arr[i][j]);
    else printf("%lf\n",arr[i][j]);

  }
}
}

double** multiply(double** arr1, int rows1, int cols1,double** arr2, int rows2, int cols2){

  double** res = allocate_matrix(rows1,cols2);

  for(int i=0; i< rows1; i++){
    for(int j=0;j<cols2;j++){
      double sum=0;
    for(int k=0; k < rows2; k++){
      sum+=arr1[i][k]*arr2[k][j];

    }
    res[i][j] = sum;
  }
}

return res;

}

void subtract(double** arr,int row, int col,int cols){

  double val = arr[row][col]/arr[col][col];


  for(int i=0;i<cols;i++){

      arr[row][i] = arr[row][i] - arr[col][i]* val;
  }

}


void multiply1(double** arr,int row, int col,int cols){
  //if(row==1&&col==1)print_matrix(arr,cols/2,cols);
  double val = 1/arr[row][col];

  //printf("%lf\n",val);
  for(int i=0;i<cols;i++){

      arr[row][i] = arr[row][i] * val;



  }
//if(row==1&&col==1)print_matrix(arr,cols/2,cols);

}

int main(int argc, char** argv){

FILE* fp = fopen(argv[1], "r");
FILE* fp2 = fopen(argv[2], "r");

int attributes,examples;
fscanf(fp,"%d\n",&attributes);
fscanf(fp,"%d\n",&examples);


double** X = allocate_matrix(examples,attributes+1);
int Xrows = examples;
int Xcols = attributes+1;
double** Y = allocate_matrix(examples,1);


for(int i=0;i<examples;i++){
  for(int j=0;j<attributes+1;j++){


    if(j==0){
      X[i][0]=1;
      fscanf(fp,"%lf,",&X[i][1]);

    }
    else{

      double val=0;


      if(j<attributes){
        fscanf(fp,"%lf,",&val);
        X[i][j+1]=val;
      }
      else {
        fscanf(fp,"%lf\n",&val);
        Y[i][0]=val;
      }

    }
}

}

double** transpose = allocate_matrix(Xcols,Xrows);

for(int i=0;i<Xrows;i++){

  for(int j=0;j<Xcols;j++){
    transpose[j][i] = X[i][j];
  }
}

double** prod1 = multiply(transpose,Xcols,Xrows,X,Xrows,Xcols);
double** aug = allocate_matrix(Xcols,2*Xcols);

int augrows = Xcols;
int augcols = 2 * Xcols;
for(int i=0;i<Xcols;i++){
  for(int j=0;j<Xcols;j++){
    aug[i][j]=prod1[i][j];

  }
}


for(int i=0;i<Xcols;i++){
  for(int j=0;j<Xcols;j++){

    if(i==j)aug[i][j+Xcols]=1;
    else aug[i][j+Xcols]=0;

  }
}

for(int i=0;i<augrows;i++){
  for(int j=0;j<i+1;j++){
    if(i==j){
      multiply1(aug,i,j,augcols);

      }
  else{
      subtract(aug,i,j,augcols);
    }
  }
}

for(int i=augrows-2;i>=0;i--){
  for(int j=augrows-1;j>i;j--){


      subtract(aug,i,j,augcols);

  }
}

double** inverse = allocate_matrix(augrows,augrows);

for(int i=0;i<augrows;i++){
  for(int j=0;j<augrows;j++){

    inverse[i][j]=aug[i][augrows+j];
  }
}


double** temp2 = multiply(inverse,augrows,augrows,transpose,Xcols,Xrows);

double** W = multiply(temp2,augrows,Xrows,Y,examples,1);



int examples2;
fscanf(fp2,"%d\n",&examples2);


double** prices = allocate_matrix(examples2,1);
for(int i=0;i<examples2;i++){
  double sum=W[0][0];
  for(int j=0;j<attributes;j++){
    double n;
    if(j<attributes-1)fscanf(fp2,"%lf,",&n);
    else fscanf(fp2,"%lf\n",&n);
    sum+=n*W[j+1][0];
  }
  prices[i][0]=sum;

}

for(int i=0;i<examples2;i++)printf("%0.0lf\n",prices[i][0]);

free(prices);
free(W);
free(temp2);
free(inverse);
free(aug);
free(prod1);
free(transpose);
free(Y);
free(X);
return 0;
}
