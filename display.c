void display(struct node* p){
    while(p){
        printf("%s: %lld\n",p->name,p->number); //displaying name along with phone number
        p=p->next;
    }
}