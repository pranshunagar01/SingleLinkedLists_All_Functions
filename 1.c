#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *link;
};

struct node *add_beg(struct node *start, int data1){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data1;
  if(start == NULL){
    temp->link = NULL;
    start = temp;
  }
  else{
    temp->link = start;
    start = temp;
  }
  return start;
}

struct node *add_last(struct node *start, int data1){
  struct node *temp= (struct node *)malloc(sizeof(struct node));
  temp->data = data1;
  struct node *p = start;
  if(start == NULL){
    temp->link = NULL;
    start = temp;
  }
  else{
    while(p->link!=NULL){
    p = p->link;
  }
  p->link = temp;
  temp->link = NULL;
  }
  return start;
}

void display(struct node *start){
  struct node *p = start;
  if(start == NULL){
    printf("The list is empty!");
  }
  else{
  while(p!=NULL){
    printf("%d\t", p->data);
    p=p->link;
  }
  }
}

struct node *add_after(struct node *start, int num1, int num2){
  struct node *p = start;
  while(p->data != num1){
    p=p->link;
  }
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num2;
  temp->link = p->link;
  p->link = temp;
  return start;
}
struct node *reverse(struct node *start){
  struct node *p, *prev, *next;
  prev = NULL;
  p = start;
  while(p!=NULL){
    next = p->link;
    p->link = prev;
    prev = p;
    p = next;
  }
  start = p;
  return start;
}

struct node *sort_selection(struct node *start){
  struct node *p, *q;
  for(p=start; p->link!=NULL; p=p->link){
    for(q=p->link; q!=NULL; q=q->link){
      if(p->data > q->data){
        int temp = p->data;
        p->data = q->data;
        q->data = temp;
      }
    }
  }
  return start;
}

struct node *sort_bubble(struct node *start){
  struct node *p, *q;
  for(p=start; p->link!=NULL; p=p->link){
    for(q = start; q->link!=NULL; q=q->link){
      if(q->data >q->link->data){
        int temp = q->data;
        q->data = q->link->data;
        q->link->data = temp;
      }
    }
  }
  return start;
} 
struct node *concatenate(struct node *start1, struct node *start2){
  struct node *p = start1;
  while(p->link!=NULL){
    p=p->link;
  }
  p->link = start2;
  return start1;
}




int main(){
  struct node *start1 = NULL;
  struct node *start2 = NULL;
  while(1){
    printf("        Linked List 1             |          Linked List 2      \n");
    display(start1);
    printf("      |      ");
    display(start2);
    int choice1, choice2;
    int num1, num2;
    printf("\n\nPlease choose the linked list : ");
    scanf("%d", &choice1);
    printf("\n\n1). Exit\n");
    printf("2). Display\n");
    printf("3). Add in beginning\n");
    printf("4). Add in the last\n");
    printf("5). Add after (start, before, data\n");
    printf("6). Reverse\n");
    printf("7). Selection Sort\n");
    printf("8). Bubble Sort\n");
    printf("9). Concatenate\n");
    printf("\nPlease enter a choice : ");
    scanf("%d", &choice2);
    if(choice1 == 1){
      switch(choice2){
        case 1:
          exit(1);
          break;
        case 2:
          display(start1);
          break;
        case 3:
          printf("Please enter the data u want to add in beginning : ");
          scanf("%d", &num1);
          start1 = add_beg(start1, num1);
          break;
        case 4:
          printf("Please enter the data u want to add in last : ");
          scanf("%d", &num1);
          start1 = add_last(start1, num1);
          break;
        case 5:
          printf("Please enter the node data: ");
          scanf("%d", &num1);
          printf("\nPlease enter the data to be added : ");
          scanf("%d", &num2);
          start1 = add_after(start1, num1, num2);
          break;
        case 6:
          start1 = reverse(start1);
          break;
        case 7:
          start1 = sort_selection(start1);
          break;
        case 8:
          start1 = sort_bubble(start1);
          break;
        case 9:
          start1 = concatenate(start1, start2);
          break;
        default:
          printf("Please enter a valid choice!\n");
      }
    }
  else if(choice1 == 2){
      switch(choice2){
        case 1:
          exit(1);
          break;
        case 2:
          display(start2);
          break;
        case 3:
          printf("Please enter the data u want to add in beginning : ");
          scanf("%d", &num1);
          start2 = add_beg(start2, num1);
          break;
        case 4:
          printf("Please enter the data u want to add in last : ");
          scanf("%d", &num1);
          start2 = add_last(start2, num1);
          break;
        case 5:
          printf("Please enter the node data: ");
          scanf("%d", &num1);
          printf("\nPlease enter the data to be added : ");
          scanf("%d", &num2);
          start2 = add_after(start2, num1, num2);
          break;
        case 6:
          start2 = reverse(start2);
          break;
        case 7:
          start2 = sort_selection(start2);
          break;
        case 8:
          start2 = sort_bubble(start2);
          break;
        case 9:
          start2 = concatenate(start2, start1);
          break;
        default:
          printf("Please enter a valid choice!\n");
      }
    }
  }
}