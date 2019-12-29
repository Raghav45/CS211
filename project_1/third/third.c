#include<stdio.h>
#include<stdlib.h>


struct node{
  int val;
  struct node * next;

};

struct node * arr[1000];

void search(int n){
  int loc = abs(n)%1000;
  if(arr[loc]==NULL)printf("absent\n");
  else{
    struct node * curr = arr[loc];
    while(curr!=NULL){
      if(curr->val==n){
        printf("present\n");
        return;
      }
      curr=curr->next;
    }
    printf("absent\n");
  }
}

void insert(int n){

  struct node* temp = malloc(sizeof(struct node));
  temp->val = n;

  int loc = abs(n)%1000;

  if(arr[loc] !=NULL){
    struct node * curr = arr[loc];

    while(curr->next!=NULL){
      if(curr->val==n)break;
      curr=curr->next;
    }

    if(curr->val!=n){

      curr->next=temp;
      printf("inserted\n");
    }
    else printf("duplicate\n");
  }
  else{
    arr[loc] = temp;
    printf("inserted\n");
  }
}

int main(int argc, char** argv){
  char c;
  int n;
  FILE* fp = fopen(argv[1], "r");
  while(fscanf(fp, "%c %d\n", &c,&n) != EOF){

    if(c=='s'){
      search(n);
    }
    if(c=='i')insert(n);
  }

for(int i=0;i<1000;i++){
  struct node* temp = arr[i];
  struct node * temp2 = temp;
  while(temp!=NULL){
    temp2=temp;
    temp = temp->next;
    free(temp2);

  }
}
return 0;
}
