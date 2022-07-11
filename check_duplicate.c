#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* pre; //connection to previous contact 
    char* name; //contact name is a string
    long long int number; //as the phone number may be upto 10 digits
    struct node* next; //connection to next contact
}*head=NULL;

int check_duplicate(struct node* p){
    if(head==NULL){
        return 1;
    }
    else{
        while(p){
            if((strcmp(p->name,temp->name)) && (p->number!=temp->number)){
                p=p->next;
            }
            else{
                break;
            }
        }
        if(p==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main()
{
    
    return 0;
}