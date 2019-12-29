#include<stdio.h>
#include<stdlib.h>

struct node{
  int val;
  struct node * left;
  struct node * right;
};




void search(int n,struct node* curr,int height){


  if(curr==NULL)printf("absent\n");
  else if(curr->val==n)printf("present %d\n",height);
  else if(curr->val<n)search(n,curr->right,height+1);
  else search(n,curr->left,height+1);

}

struct node* insert(int n,struct node* curr,int height){

  if(curr==NULL){

    struct node* temp = malloc(sizeof(struct node));
    temp->val=n;
    printf("inserted %d\n",height);
    return temp;

  }
  else if(curr->val==n)printf("duplicate\n");
  else if(curr->val<n)curr->right=insert(n,curr->right,height+1);
  else{

    curr->left=insert(n,curr->left,height+1);

}
  return curr;
}

void clear(struct node* curr){
  if(curr==NULL)return;
  clear(curr->left);
  clear(curr->right);
  
  free(curr);
}

int main(int argc, char** argv){
  struct node * root = NULL;
  FILE* fp = fopen(argv[1], "r");
  char c;
  int n;
  if(fp == NULL){
    printf("error\n");
  }

  else if(fscanf(fp, "%c %d\n", &c,&n) != EOF){

    do{

      if(c=='s'){
        search(n,root,1);

      }
      else if(c=='i'){
       root = insert(n,root,1);

     }

    }
    while(fscanf(fp, "%c %d\n", &c,&n) != EOF);
}
  clear(root);

  return 0;
}
