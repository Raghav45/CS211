#include <stdlib.h>
#include <stdio.h>

int** allocate_matrix(){

  int** ret_val = malloc(16 * sizeof(int*));
  for(int i = 0; i< 16; i++){
    ret_val[i] = malloc(16 * sizeof(int));
  }
  return ret_val;
}

int nearest(int number){
  return (number/ 4) * 4;
}

int notsame(int** arr,int row,int col,int i,int j){
  if((arr[i][j]!=-1)&&(row!=i||col!=j))return 1;
  return 0;
}

int check(int** arr, int val, int row, int col){


  for(int i=0;i<16;i++){
    if((arr[row][i]==val&&notsame(arr,row,col,row,i))||(notsame(arr,row,col,i,col)&&arr[i][col]==val))return 0;
    }

  int startrow = nearest(row);
  int startcol = nearest(col);


  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(notsame(arr,row,col,startrow+i,startcol+j)&&(arr[startrow+i][startcol+j]==val))return 0;
    }

  }


  return 1;
}
int main(int argc, char** argv){

int** arr;
arr = allocate_matrix();

 FILE* fp = fopen(argv[1], "r");


  char val;
  int val2;
 for(int i = 0; i < 16; i++){
   for(int j = 0; j < 16; j++){
     if(j<15){
       fscanf(fp,"%c\t",&val);
       if(val=='-')val2=-1;
       else if(val<58)val2=val-'0';
       else val2=val-55;
     }
     else {
       fscanf(fp,"%c\n",&val);
       if(val=='-')val2=-1;
       else if(val<58)val2=val-'0';
       else val2=val-55;
     }
    arr[i][j]=val2;

   }
}

//fill in single empty value rows
for(int i=0;i<16;i++){
  int ctr = 0;

  int srow,scol;
  for(int j=0;j<16;j++){
    if(arr[i][j]==-1){
      ctr++;
      srow=i;
      scol=j;

    }
    if(ctr==2){

      break;
    }
  }
  if(ctr==1){
    
    for(int k=0;k<16;k++){
      if(check(arr,k,srow,scol)){

        arr[srow][scol]=k;

        break;
      }
    }
  }
}

//fill in single empty value cols
for(int i=0;i<16;i++){
  int ctr = 0;

  int srow,scol;
  for(int j=0;j<16;j++){
    if(arr[j][i]==-1){
      ctr++;
      srow=j;
      scol=i;
    }
    if(ctr==2){

      break;
    }
  }
  if(ctr==1){
    for(int k=0;k<16;k++){
      if(check(arr,k,srow,scol)){

        arr[srow][scol]=k;

        break;
      }
    }
  }
}

//fill in single missing value subgrids

for(int i=0;i<16;i++){


  int ctr=0;
  int srow,scol=0;
  for(int j=0;j<16;j++){

    if(arr[i][j]==-1){
      ctr++;
      srow=i;
      scol=j;
      int startrow = nearest(i);
      int startcol = nearest(j);
      for(int k=startrow;k<4;k++){
        for(int l=startcol;l<4;l++){
          if(arr[k][l]==-1 && k!=srow&&l!=scol){
            ctr++;
            if(ctr==2)break;
          }

          }
        }
      if(ctr==1){
        for(int k=0;k<16;k++){
          if(check(arr,k,srow,scol)){
            arr[srow][scol]=k;
            break;
          }
        }

      }

        }
      }
    }




//fill in remaining values
for(int i=0;i<16;i++){

  for(int j=0;j<16;j++){

    if(arr[i][j]==-1){

      for(int k=0;k<16;k++){
        if(check(arr,k,i,j)){

          arr[i][j]=k;

          break;
        }
      }
    }
  }
}


for(int i = 0; i < 16; i++){
  for(int j = 0; j < 16; j++){
    //char* str= malloc(2 * sizeof(char));
    //sprintf(str,"%X",arr[i][j]);
    if(arr[i][j]==-1||check(arr,arr[i][j],i,j)==0){
      printf("no-solution\n");
      return 0;
}
  }
}





for(int i = 0; i < 16; i++){
  for(int j = 0; j < 16; j++){
    //char* str= malloc(2 * sizeof(char));
    //sprintf(str,"%X",arr[i][j]);
    if(j<15)printf("%X\t",arr[i][j]);
    else printf("%X\n",arr[i][j]);

  }
}
 free(arr);
 return 0;
}
