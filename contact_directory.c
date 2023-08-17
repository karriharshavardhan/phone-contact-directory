#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* pre; 
    char* name;
    long long int number;
    char* MailId;
    struct node* next;
}*head=NULL;

int check_duplicate(struct node* p,struct node* temp){
    if(head==NULL){ //exucutes intially when there are no contacts
        return 1; //no duplicate found
    }
    else{
        while(p && (strcmp(p->name,temp->name)) && (p->number!=temp->number) && (strcmp(p->MailId,temp->MailId))){ //strcmp returns 0 if the strings are equal
            p=p->next;
        }
        if(p==NULL){ //reached the end of contact of contact list and no duplicate is found
            return 1;
        }
        else{
            return 0; //duplicate foud
        }
    }
}

void display(struct node* p){
    if(head==NULL){
        printf("\n*contact list is empty*\n");
    }
    printf("\n");
    while(p){
        printf("%s: %lld, %s \n",p->name,p->number,p->MailId);
        p=p->next;
    }
}

void save(struct node* p){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->name=(char*)malloc(20*sizeof(char));
    temp->MailId=(char*)malloc(50*sizeof(char));
    temp->pre=temp->next=NULL;
    printf("enter the name of the contact: ");
    scanf("%s",temp->name);
    printf("enter the contact number of %s: ",temp->name);
    scanf("%lld",&temp->number);
    printf("enter the Mail id of %s: ",temp->name);
    scanf("%s",temp->MailId);
    if(check_duplicate(head,temp)){
        if(head==NULL){ //when the contact list is empty and we are saving the first contact
            head=temp;
        }
        else if(strcmp(head->name,temp->name)>0){ //when the lexicographical order the newly inserting contact name is less than the name of the contact in the head
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
            if(p!=NULL){
                p->pre=temp;
            }
        }
        printf("\n*contact '%s' saved successfully*\n",temp->name);
    }
    else{
        printf("\n*could not save the contact '%s' as similar contact info is already present*\n",temp->name);
    }
}

void edit(struct node* p){
    if(head==NULL){
        printf("\n*contact list is empty*\n");
    }
    else{
        long long int k;
        char* name;
        name=(char*)malloc(20*sizeof(char));
        char* MailId;
        MailId=(char*)malloc(50*sizeof(char));
        printf("enter the name of contact to be edited: ");
        scanf("%s",name);
        while(p!=NULL && strcmp(p->name,name)!=0){
            p=p->next;
        }
        if(p==NULL){
            printf("\n*contact '%s' is not found*\n",name);
        }
        else{
            int x;
            printf("1.edit name\n2.edit number\n3.edit MailId\n");
            scanf("%d",&x);
            switch(x){
                case 1:
                printf("enter new name: ");
                scanf("%s",name);
                p->name=name;
                printf("\n*contact info edited successfully*\n");
                break;

                case 2:
                printf("enter new number: ");
                scanf("%lld",&k);
                p->number=k;
                printf("\n*contact info edited successfully*\n");
                break;
                
                case 3:
                printf("enter new MailId: ");
                scanf("%s",MailId);
                p->MailId=MailId;
                printf("\n*contact info edited successfully*\n");
                break;
                
                default:
                printf("\n*invalid number*\n");
                break;
            }
        }
    }
}

void delete(struct node* p){
    if(head==NULL){
        printf("\n*contact list is empty*\n");
    }
    else{
        char* name;
        name=(char*)malloc(20*sizeof(char));
        printf("enter the name of contact to be deleted: ");
        scanf("%s",name);
        while(p!=NULL && strcmp(p->name,name)!=0){
            p=p->next;
        }
        if(p==NULL){
            printf("\n*contact '%s' is not found*\n",name);
        }
        else{
            if(strcmp(head->name,name)==0){
                head=p->next;
            }
            else if(p->next==NULL){
                p->pre->next=NULL;
            }
            else{
                p->pre->next=p->next;
                p->next->pre=p->pre;
            }
            free(p); //removing the memory
            printf("\n*contact '%s' deleted successfully*\n",name);
        }
    }
}

int search(struct node* p){
    if(head==NULL){
        printf("\n*contact list is empty*\n");
    }
    else{
        char* name;
        name=(char*)malloc(20*sizeof(char));
        printf("enter the name of contact to be searched: ");
        scanf("%s",name);
        while(strcmp(p->name,name)!=0){
            p=p->next;
        }
        if(p==NULL){
            printf("\n*contact '%s' is not found*\n",name);
        }
        else{
            printf("\n*contact '%s' is  found* contact info: %lld, %s",name,p->number,p->MailId);
            int temp;
            printf("\n1.go to previous contact\n2.go to next contact\n");
            scanf("%d",&temp);
            switch(temp){
                case 1:
                if(p->pre!=NULL){
                    printf("%s: %lld %s\n",p->pre->name,p->pre->number,p->pre->MailId);
                }
                else{
                    printf("%s is the starting contact of the list\n",p->name);
                }
                break;

                case 2:
                if(p->next!=NULL){
                    printf("%s: %lld %s\n",p->next->name,p->next->number,p->next->MailId);
                }
                else{
                    printf("%s is the ending contact of the list\n",p->name);
                }
                break;

                default:
                break;
            }
        }
    }
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
        edit(head);
        break;

        case 4:
        delete(head);
        break;

        case 5:
        search(head);
        break;

        default:
        break;
    }
    }while(opr!=-1);

  return 0;
}
