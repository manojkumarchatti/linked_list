#include<stdio.h>
#include <stdlib.h>
 
struct slist {
    int data;
    struct slist* next;
};
typedef struct slist node;
node* create(node* first){
    node* new,*prev;
    int x;
    printf("enter the data value(enteer -1 to stop)");
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
    return first;

}
void display(node* first){
    node* temp=first;
    if(first==NULL){
        printf("no list to print");

    }
    else{
        while(temp!=NULL){
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
        printf("NULL");

    }
}
int main(){
    node* head=NULL;
    head=create(head);
    display(head);

return 0;
}
