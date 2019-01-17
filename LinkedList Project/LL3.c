#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
  struct node *next;
}*head;


void create(int size);
void concat(int data);
void insertItem(int pos, int data);
void removeItem(int pos);
void searchItem(int item);
void swap(struct node *a, struct node *b);
void sort();
void display();
int min();
int max();

//________________________________________________________________________________________
int main()
{
    int size;
    int data;
    int choice;
    int num;
    int item;
    int pos;

	printf("input size: ");
    scanf("%d", &size);
    create(size);

  printf("1 -> ADD ITEM TO LIST \n");
  printf("2 -> SEARCH FOR ITEM \n");
  printf("3 -> FIND MAX OF LIST \n");
  printf("4 -> FIND MIN OF LIST \n");
  printf("5 -> REMOVE ITEM AT POS \n");
  printf("6 -> CONCAT LIST \n");
  printf("7 -> SORT \n");
  printf("8 -> TO DISLAY: ");


 	scanf("%d",&choice);

 	//MENUE for userrr
 	while(choice!=0){
 		switch(choice){
    	case 1:
          printf("Please enter the item you want to add: ");
          scanf("%d",&num);
          printf("Please enter the position: ");
          scanf("%d",&pos);
          insertItem(pos, num);
  	 	   break;
   		 case 2:
          printf("Enter item you want to search for (INT): ");
          scanf("%d",&item);
          searchItem(item);
     			break;
      case 3:
        printf("Max is %d\n", max());
        break;
      case 4:
          printf("Min is %d\n", min());
          break;
      case 5:
        printf("Please enter the pos of item you want to remove: ");
        scanf("%d",&pos);
        removeItem(pos);
        break;
      case 6:
        printf("Please enter size of second list");
        scanf("%d",&size);
        for(int i = 0; i<size; i++){
          printf("Please enter the item you want to add: ");
          scanf("%d",&num);
          concat(num);
        }
        break;
      case 7:
        sort();
        break;
      case 8:
        display();
   		 default:
      			break;
   			 }

     printf("1 -> ADD ITEM TO LIST \n");
     printf("2 -> SEARCH FOR ITEM \n");
     printf("3 -> FIND MAX OF LIST \n");
     printf("4 -> FIND MIN OF LIST \n");
     printf("5 -> REMOVE ITEM AT POS \n");
     printf("6 -> CONCAT LIST \n");
     printf("7 -> SORT \n");
     printf("8 -> TO DISLAY: \n");
     printf("0 -> TO EXIT: ");


  	scanf("%d",&choice);

  	}

    printf("YOUR LIST BELOW: \n");
    display();

    return 1;
}


//________________________________________________________________________________________
void create(int size)
{
    struct node *newNode;
    struct node *temp;
    int data;
    int i;


    head = malloc(sizeof(struct node));


    printf("input data 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;

    i=2; //LOOP SKIPSSSS 0 and 1

    while(i<=size){
      newNode = malloc(sizeof(struct node));
      printf("input data %d: ", i);
      scanf("%d", &data);
      newNode->data = data;
      newNode->next = NULL;
      temp->next = newNode;
      temp = temp->next;
      i++;
    }
  }


//________________________________________________________________________________________
void concat(int data){
  struct node *new;
  struct node *temp;
  new=malloc(sizeof(struct node));
  new->data=data;
  new->next=NULL;
  temp=head;
  while(temp->next!=NULL){
      temp = temp->next;
  }
  temp->next = new;
}

//________________________________________________________________________________________
void display()
{
    struct node *temp;

    temp = head;
    while(temp != NULL)
    {
      printf("%d\t ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }

//________________________________________________________________________________________
int max(){
  int flag = 0;


  struct node *temp;

  temp = head;
  while(temp != NULL){
    if(flag < temp->data){
      flag = temp->data;
    }
    temp = temp->next;
  }
  //printf("Max is %d\n", flag);
  return flag;
}

//________________________________________________________________________________________

int min(){
  int flag = max();
  struct node *temp;

  temp = head;
  while(temp != NULL){
    if(flag > temp->data){
      flag = temp->data;
    }
    temp= temp->next;
  }
  return flag;
}
//________________________________________________________________________________________
void searchItem(int item){
  struct node *temp;

  temp = head;

  int index = 1;
  while(temp != NULL){
    if(temp->data == item){
      printf("%d is found at index %d \n",item,index);
      temp = temp->next;
      index++;
    }else{
      temp = temp->next;
      index++;
    }
  }
}
//________________________________________________________________________________________
void insertItem(int pos, int data){
  struct node *newNode;
  newNode = malloc(sizeof(struct node));
  newNode->data = data;

  struct node* temp;
  temp = head;

  while(pos-1 > 1) {
    temp = temp->next;
    pos--;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

//________________________________________________________________________________________
void removeItem(int pos){
  struct node *newNode;
  newNode = malloc(sizeof(struct node));

  struct node* temp;
  temp = head;
  int i = 1;
  while(i < pos - 1 && temp!=NULL ) {
    temp = temp->next;
    i++;
  }
  newNode = temp->next->next;

  temp->next = newNode;
}
//________________________________________________________________________________________
void swap(struct node *a, struct node *b){
  int temp =  a->data;
  a->data = b->data;
  b->data = temp;
}
//________________________________________________________________________________________
void sort(){
  int min = max();
  struct node *a;
  struct node *b;
  a = head;


  struct node* temp;
  temp = head;

while(a!=NULL){
  while(temp!= NULL){
    if(min > temp->data){
      min = temp->data;
      b = temp;
    }
    temp = temp->next;
  }
  if(min < a->data){
    swap(a,b);
  }
  a=a->next;
  temp = a;
  min = max();
 }

}
