#include<stdio.h>
#include<stdlib.h>

struct node{
  int val;
  struct node * next;

};
int size = 0;

struct node * head = NULL;
void insert(int);
void delete(int);

void insert(int n){

  struct node* temp = malloc(sizeof(struct node));
  temp->val=n;
  if(head==NULL){
    head=temp;
    head->next=NULL;
    size++;
  }
  else{

    struct node * curr = head;
    struct node * prev = NULL;

    while(curr!=NULL&&curr->val<temp->val){
      prev = curr;


      curr = curr->next;


    }


    if(curr==NULL||curr->val!=temp->val){

        if(prev==NULL){

        head = temp;
        head->next=curr;
      }
      else{

          prev->next=temp;
          temp->next=curr;

      }

      size++;
  }
}

}


void delete(int n){
  struct node * curr = head;
  struct node * prev = NULL;
  while(curr!=NULL&&curr->val!=n){

    prev=curr;
    curr=curr->next;
  }
  if(curr!=NULL){
    if(prev==NULL){
      head=curr->next;
      free(curr);
    }
    else{
      prev->next=curr->next;
      free(curr);
    }
    size--;
  }
}



int main(int argc, char** argv){
  FILE* fp = fopen(argv[1], "r");
  char c;
  int n;
  if(fp == NULL){
    printf("error\n");
  }
  else if(fscanf(fp, "%c %d\n", &c,&n) == EOF){
    printf("0\n\n");

  }
  else{

    do{

      if(c=='d'){
        delete(n);

      }
      else if(c=='i'){
       insert(n);

     }

    }
    while(fscanf(fp, "%c %d\n", &c,&n) != EOF);

  if(size==0)printf("0\n\n");

  else{
    struct node * res = head;
    printf("%d\n",size);
    while(res!=NULL){
      if(res->next==NULL)printf("%d\n",res->val);
      else printf("%d\t",res->val);
      res=res->next;

    }
  }

  struct node* temp = head;
  struct node * temp2 = temp;
  while(temp!=NULL){
    temp2=temp;
    temp = temp->next;
    free(temp2);
    
  }

  }
  return 0;
}
