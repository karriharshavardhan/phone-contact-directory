int check_duplicate(struct node* p,struct node* temp){
    if(head==NULL){
        return 1;
    }
    else{
        while(p && (strcmp(p->name,temp->name)) && (p->number!=temp->number) && (strcmp(p->MailId,temp->MailId))){
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
