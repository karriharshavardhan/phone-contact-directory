#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* pre; //connection to previous contact 
    char* name; //contact name is a string
    long long int number; //as the phone number may be upto 10 digits
    struct node* next; //connection to next contact
}*head=NULL;

void display(struct node* p){
    while(p){
        printf("%s: %lld\n",p->name,p->number); //displaying name along with phone number
        p=p->next;
    }
}

int check_duplicate(struct node* p,struct node* temp){
    if(head==NULL){
        return 1;
    }
    else{
        while(p && (strcmp(p->name,temp->name)) && (p->number!=temp->number)){
            p=p->next;
        }
        if(p==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void save(struct node* p){
    struct node* temp; //to store contact info
    temp=(struct node*)malloc(sizeof(struct node));
    temp->name=(char*)malloc(20*sizeof(char)); //assuming string has a max size of 20
    temp->pre=temp->next=NULL;
    printf("enter the name of the contact: ");
    scanf("%s",temp->name);
    printf("enter the contact number of %s: ",temp->name);
    scanf("%lld",&temp->number);
    if(check_duplicate(head,temp)){
        if(head==NULL){
            head=temp;
        }
        else if(strcmp(head->name,temp->name)>0){
            head->pre=temp;
            temp->next=head;
            head=temp;
        }
        else{
            struct node* r=NULL;
            while(p && (strcmp(p->name,temp->name)<=0)){
                r=p;
                p=p->next;
            }
            temp->pre=r;
            temp->next=p;
            r->next=temp;
            if(p!=NULL){ //will face a segmentation error if this if statement is absent
                p->pre=temp;
            }
        }
        printf("contact '%s' saved successfully!!\n",temp->name);
    }
    else{
        printf("similar contact information is found in the contact list\n");
    }
}

void edit(){
    printf("this is edit function\n\n");
}

void delete(){
    printf("this is delete function\n\n");
}

int search(){
    printf("this is search function\n\n");
}

int main()
{
    int opr;
    do{
    printf("\n1.Display all the contacts\n2.Save a new contact\n3.Edit an existing contact\n4.Delete a contact\n5.Search for a contact\n");
    printf("enter -1 to exit\n");
    printf("enter the operation you want to perform:");
    scanf("%d",&opr);
        switch(opr){
        case 1:
        display(head);
        break;

        case 2:
        save(head);
        break;        
        
        case 3:
        edit();
        break;

        case 4:
        delete();
        break;

        case 5:
        search();
        break;

        default:
        break;
    }
    }while(opr!=-1);
    
    return 0;
}
