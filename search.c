int search(struct node* p){
    if(head==NULL){
        printf("\n**contact list is empty**\n");
    }
    else{
        char* name;
        name=(char*)malloc(100*sizeof(char));
        printf("enter the name of contact to be searched: ");
        scanf("%s",name);
        while(strcmp(p->name,name)!=0){
            p=p->next;
        }
        if(p==NULL){
            printf("\n**contact '%s' is not found**\n",name);
        }
        else{
            printf("\n**contact '%s' is  found**contact number: %lld",name,p->number);
        }
    }
}