#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;

}node;

struct node *head;
node* createList(int ele);
void displayList();
void deleteElement();
void insertElement();
void concatenate(node *head);
int main(){
   struct node *HEAD;
   int ele,number;
   printf("enter the number of elements.\n");
   scanf("%d",&ele);
   HEAD = createList(ele);
   displayList();
   
   
   printf("Choose an operation to be executed.\n");
   printf("Enter 1 for delete \nEnter 2 for insert \nEnter 3 for conactenate \n");
   scanf("%d",&number);
   switch(number){
   	case 1:
	deleteElement();
	break;
    case 2:
	insertElement();
	break;
    case 3:
	concatenate(HEAD);
	break;
    default:
	printf("enter the valid number");
	break;			
   }
   getch();
}

//create the linked list
node* createList(int ele){
    node *ptr,*cur;
    int x,i;
    x = ele;
    cur = NULL;
    ptr = NULL;
    head = NULL;
    printf("enter the data\n");
    for(i=0;i<x;i++){
        ptr = (node*)malloc(sizeof(node));
        scanf("%d",&(ptr->data));
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
        }
        else{
            cur = head;
            while(cur->next!=NULL)
                cur = cur->next;
            cur->next = ptr;

        }
    }
    return head;
}

//display the linked list
void displayList(){
    node *cur = head;
    printf("This is the linked list\n");
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//delete an element from the linked list.
void deleteElement(){
    struct node *temp1 = head;
    int num,i ;
    printf("enter the position of an element to be deleted :");
    scanf("%d",&num);
    if(num==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    for(i = 0; i<num-2;i++){
        temp1 = temp1->next;
        struct node *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
    node *cur = head;
    printf("This is the linked list\n");
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur = cur->next;
    }
}

//insert list into the linked list based on its position. 
void insertElement(){
    printf("\n");
    struct node *tempo1,*tempo2;
    int num,i;
    printf("enter the data and position respectively:");
    scanf("%d %d",&(tempo1->data),&num);
    tempo1->next = NULL;
    if(num==1){
        tempo1->next = head;
        head = tempo1;
        return;
    }
    tempo2 = head;
    for(i = 0;i<num-2;i++){
        tempo2 = tempo2->next;
    }
    tempo1->next = tempo2->next;
    tempo2->next = tempo1;

    //display the linked list
    node *dis= head;
    printf("This is the linked list\n");
    while(dis!=NULL){
        printf("%d->",dis->data);
        dis = dis->next;
    }
    printf("\n");
}

//conatenate the linked lists but first enter the new linked list.
void concatenate(node *head){
	
	node *pt,*cu,*head1,*emp2;
    int x,i;
    cu = NULL;
    pt = NULL;
    head1 = NULL;
    printf("enter the new  linked lists .its length and the data to be concatenated with the old linked list.\n");
    scanf("%d",&x);
    printf("Enter the data:\n")
    for(i=0;i<x;i++){
        pt = (node*)malloc(sizeof(node));
        scanf("%d",&(pt->data));
        pt->next = NULL;
        if(head1 == NULL){
            head1 = pt;
        }
        else{
            cu = head1;
            while(cu->next!=NULL)
                cu = cu->next;
            cu->next = pt;

        }
    }
    
    cu = head1;
    printf("This is the new  linked list\n");
    while(cu!=NULL){
        printf("%d->",cu->data);
        cu = cu->next;
    }
    printf("\n");
    
    //concatenate
    node *tempx=head;
    while(tempx->next!=NULL){
    	tempx = tempx->next;
	}
	tempx->next = head1;
	
    emp2 = head;
    printf("This is the concatenated linked list\n");
    while(emp2!=NULL){
        printf("%d->",emp2->data);
        emp2 = emp2->next;
    }
}
