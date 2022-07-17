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
