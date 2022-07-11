    if(head==NULL){
        head=temp;
    }
    else if(head->next==NULL){
        if(strcmp(head->name,temp->name))
    }
    else{
        int i=0,j=0;
        if(p->name[i]<temp->name[j]){
            p=p->next;
        }
        else if(p->name[i]==temp->name[j]){
            i++;j++;
        }
        else{
            if(p->next==NULL){
                temp->pre=p;
                p->next=temp;
            }
            else{
                temp->pre=p;
                temp->next=p->next;
                p->next->pre=temp;
                p->next=temp;
            }
        }
    }