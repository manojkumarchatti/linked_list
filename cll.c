#include<stdio.h>
#include <stdlib.h>
 
struct clist {
    int data;
    struct clist* next;
};
typedef struct clist node;
node* create(node* first){
    node* new,*prev;
    int x;
    printf("enter the data value(enter -1 to stop)");
    scanf("%d",&x);
    while(x!=-1){
        new=(node*)malloc(sizeof(node*));
        new->data=x;
        new->next=NULL;
        if(first==NULL){
            first=new;
            prev=new;

        }
        else{
            prev->next=new;
            prev=new;

        }
        printf("enter data (enter -1 to stop)");
        scanf("%d",&x);
    }
    prev->next=first;
    return first;

}
void display(node* first){
    node* temp=first;
    if(first==NULL){
        printf("\nno list to print\n");

    }
    else{
        do{
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
        while(temp!=first);
        printf("|%d|",temp->data);

    }
}
int count(node* first){
    int c=0;
    node* temp=first;
    if(first==NULL){
        return c;
    }
    else
    {
        do
        {
            c++;
            temp=temp->next;
        }
        while (temp!=first);
    
        return c;
    }   
}
void search(node* first,int x){
    node* temp=first;
    int flag=0;
    if(first==NULL){
        printf("no list to search");
    }
    else{

    
        do{
            if(temp->data==x){
                flag=1;
                break;
            }
            else{
                temp=temp->next;
            }

        }
        while(temp!=first);
    }
    if(flag==1){
        printf("\nthe element %d is found\n",x);

    }
    else{
        printf("\nthe element %d is not found\n",x);
    }

}
node* insert_at_begin(node* first,int x){
    node*temp=first;
    node* new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if (first==NULL){
        first=new;
        new->next=first;

    }
    else{
        do
        {           
            temp=temp->next;
        }
        while (temp->next!=first);
        new->next=first;
        temp->next=new;
        first=new;
    }
    return first;
}
node* insert_at_end(node* first,int x){
    node* temp=first;
    node* new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if (first==NULL){
        first=new;
        new->next=first;
    }
    else{
        do
        {           
            temp=temp->next;
        }
        while (temp->next!=first);
        new->next=first;
        temp->next=new;
        
    }
    return first;
}
node* insert_at_pos(node* first,int pos,int x){
    node* temp=first,*new;
    int n=count(first);
    if(pos>1 && pos<n){
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        for ( int i = 0; i <pos-1; i++)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
        
    }
    return first;
}
node* delete(node* first,int x)
{
    node *temp,*temp1;
        int flag=0;
        if(first==NULL)
                printf("No element to delete");
        else if(first->data==x){
                temp1=first;
                temp=first;
                while(temp->next!=first)
                        temp=temp->next;
                first=first->next;
                temp->next=first;
                free(temp);
        }
        else{
                                temp1=first;
                                temp=temp->next;
                                while(temp!=first)
                                {
                                        if(temp->data==x)
                                        {
                                                flag=1;
                                                break;
                                        }
                                        else{
                                                temp1=temp;
                                                temp=temp->next;
                                        }
                                }
                
                if(flag==1){
                        temp1->next=temp->next;
                        free(temp);
                }
                else{
                        printf("element not found");
                }
        }
        return first;
}
void sort(node* first){
    node* temp,*temp1,*temp2;
    int x;
    for(temp1=first;temp1->next!=first;temp1=temp1->next){
        for(temp2=temp1->next;temp2!=first;temp2=temp2->next){
            if (temp1->data >temp2->data)
            {
                x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
            }
        }
    }
}
node* reverse(node* first){
    node* present=first,*prev=NULL,*same;
    do 
    {
        same=present->next;
        present->next=prev;
        prev=present;
        present=same;
    }
    while (present!=NULL);
    return prev;   
}

int main(){
    node* head=NULL;
    int ch,x,pos,n;
    while (1)
    {
        printf("\n1.create\n2.display\n3.count\n4.search\n5.insert at the begining\n6.insert at the ending\n7.insert at a position\n8.delete\n9.sort\n10.reverse\n11.exit");
        printf("\nenter your choice");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                head=create(head);
                break;
        case 2:printf("the list of the elements are");
                display(head);
                break;
        case 3:
                n=count(head);
                printf("the no.of nodes in the list=%d",n);
                break;
        case 4: 
                printf("\nenter element to search\n");
                scanf("%d",&x);
                search(head,x);
                break;
        case 5: 
                printf("\nenter element to insert\n");
                scanf("%d",&x);
                head=insert_at_begin(head,x);
                break;  
        case 6: 
                printf("\nenter element to insert\n");
                scanf("%d",&x);
                head=insert_at_end(head,x);
                break;
        case 7: 
                printf("\nenter element to insert\n");
                scanf("%d",&x);
                printf("\nenter position to insert");
                scanf("%d",&pos);
                head=insert_at_pos(head,pos,x);
                break; 
        case 8:
                printf("\nenter element to delete");
                scanf("%d",&x);
                head=delete(head,x);
                break;
        case 9:
                sort(head);
                break;
        case 10:
                head=reverse(head);
                break;
        case 11:
                exit(0);                                                         

        default:
           printf("invalid choice");
        }
    }
    
    

return 0;
}
