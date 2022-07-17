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
