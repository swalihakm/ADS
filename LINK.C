#include<stdio.h>
#include<stdio.h>
struct node{
	int data;
	struct node *next;
};
struct node *temp,*head,*newnode,*prev;

struct node* insert(struct node* head,int data){
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=0;
if(head==0){
	newnode->next=head;
	return newnode;
}
temp=head;
while(temp->next!=0){
temp=temp->next;
}
temp->next=newnode;
return head;
}
struct node* insertatpos(struct node* head,int pos,int data){
int i=1;
if(pos<1){
	printf("invalid position\n");
	return head;

}
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=0;
if(pos==1){
	newnode->next=head;
	return newnode;

}
temp=head;
prev=0;
while(i<pos && temp!=0){
	prev=temp;
	temp=temp->next;
	i++;
}
if(i<pos){
	printf("out of range\n");
	return head;
}
prev->next=newnode;
newnode->next=temp;
return head;
}
struct node* delete(struct node* head,int pos){
int i=1;
	if(pos<1){
		printf("invalid position\n");
		return head;
	}
	if(pos==1){
		temp=head;
		temp->next=head;
		free(temp);
		return head;
	}
	temp=head;
	prev=0;

	while(i<pos && temp!=0){
		prev=temp;
		temp=temp->next;
		i++;
	}
	if(i<pos || temp==0){
		printf("out of range \n");
		return head;
	}
	prev->next=temp->next;
	free(temp);
	return head;

}
void display(struct node* head){
	temp=head;
	while(temp!=0){
	printf("%d ",temp->data);
	temp=temp->next;
	}
}
void main(){
	int c,data,pos;
	head=0;
	clrscr();
	while(1){
		printf("enter your choice\n 1.insert\n 2.delete \n3.display \n 4.exit \n");
		scanf("%d",&c);
		switch(c){
		      case 1:  	printf("enter data");
				scanf("%d",&data);
				printf("enter position");
				scanf("%d",&pos);
				head=insertatpos(head,pos,data);

				break;
		      case 2:   printf("enter position\n");
				scanf("%d",&pos);
				head=delete(head,pos);
				break;
		      case 3:   display(head);
				break;

		      case 4:   exit(0);

		      default: printf("enter a valid choice\n");
				break;
		}

	}

getch();  }
}



