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
            if(p!=NULL){
                p->pre=temp;
            }
        }
    }
    else{
        printf("similar contact information is found in the contact list\n");
    }
}
