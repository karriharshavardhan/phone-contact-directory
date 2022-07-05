#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* pre;
    char* name;
    int number;
    struct node* next;
};

void display(){
    printf("this is display function\n\n");
}

void save(){
    printf("this is save function\n\n");
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
    printf("\nenter the operation you want to perform:");
    printf("\n1.Display all the contacts\n2.Save a new contact\n3.Edit an existing contact\n4.Delete a contact\n5.Search for a contact\n");
    printf("enter -1 to exit\n");
    scanf("%d",&opr);
        switch(opr){
        case 1:
        display();
        break;

        case 2:
        save();
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