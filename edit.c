void edit(struct node* p){
    if(head==NULL){
        printf("\n**contact list is empty**\n");
    }
    else{
        long long int k;
        char* name;
        name=(char*)malloc(100*sizeof(char));
        printf("enter the name of contact to be edited: ");
        scanf("%s",name);
        while(strcmp(p->name,name)!=0){
            p=p->next;
        }
        if(p==NULL){
            printf("\n**contact '%s' is not found**\n",name);
        }
        else{
            int x;
            printf("1.edit name\n2.edit number\n");
            scanf("%d",&x);
            switch(x){
                case 1:
                printf("enter new name: ");
                scanf("%s",name);
                p->name=name;
                printf("\n**contact info edited successfully**\n");
                break;

                case 2:
                printf("enter new number: ");
                scanf("%lld",&k);
                p->number=k;
                printf("\n**contact info edited successfully**\n");
                break;

                default:
                printf("\n**invalid number**\n");
                break;
            }
        }
    }
}