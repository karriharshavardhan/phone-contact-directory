void delete(struct node* p){
    if(head==NULL){
        printf("\n*contact list is empty*\n");
    }
    else{
        char* name;
        name=(char*)malloc(20*sizeof(char));
        printf("enter the name of contact to be deleted: ");
        scanf("%s",name);
        while(strcmp(p->name,name)!=0){
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
            free(p);
        }
        printf("\n*contact '%s' deleted successfully*\n",name);
    }
}
