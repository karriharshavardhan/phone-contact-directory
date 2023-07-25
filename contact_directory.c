#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node* pre;
    char name[20];
    long long int number;
    char MailId[50];
    struct node* next;
}*head = NULL;

int check_duplicate(struct node* p, struct node* temp) {
    while (p != NULL) {
        if (strcmp(p->name, temp->name) == 0 && p->number == temp->number && strcmp(p->MailId, temp->MailId) == 0) {
            return 0; // Duplicate found
        }
        p = p->next;
    }
    return 1; // No duplicate found
}

void display(struct node* p) {
    if (p == NULL) {
        printf("\n*contact list is empty*\n");
        return;
    }
    printf("\n");
    while (p) {
        printf("%s: %lld, %s\n", p->name, p->number, p->MailId);
        p = p->next;
    }
}

void save() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nMemory allocation failed.\n");
        return;
    }
    printf("enter the name of the contact: ");
    scanf("%s", temp->name);
    printf("enter the contact number of %s: ", temp->name);
    scanf("%lld", &temp->number);
    printf("enter the Mail id of %s: ", temp->name);
    scanf("%s", temp->MailId);
    temp->pre = temp->next = NULL;

    if (check_duplicate(head, temp)) {
        if (head == NULL) {
            head = temp;
        } else if (strcmp(head->name, temp->name) > 0) {
            head->pre = temp;
            temp->next = head;
            head = temp;
        } else {
            struct node* r = NULL;
            struct node* p = head;
            while (p && (strcmp(p->name, temp->name) <= 0)) {
                r = p;
                p = p->next;
            }
            temp->pre = r;
            temp->next = p;
            if (p != NULL) {
                p->pre = temp;
            }
            r->next = temp;
        }
        printf("\n*contact '%s' saved successfully*\n", temp->name);
    } else {
        free(temp);
        printf("\n*similar contact information is found in the contact list*\n");
    }
}

void edit(struct node* p) {
    if (p == NULL) {
        printf("\n*contact list is empty*\n");
        return;
    }

    char name[20];
    printf("enter the name of contact to be edited: ");
    scanf("%s", name);

    while (p != NULL && strcmp(p->name, name) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("\n*contact '%s' is not found*\n", name);
        return;
    }

    int x;
    printf("1.edit name\n2.edit number\n3.edit MailId\n");
    scanf("%d", &x);

    switch (x) {
        case 1:
            printf("enter new name: ");
            scanf("%s", p->name);
            printf("\n*contact info edited successfully*\n");
            break;

        case 2:
            printf("enter new number: ");
            scanf("%lld", &p->number);
            printf("\n*contact info edited successfully*\n");
            break;

        case 3:
            printf("enter new MailId: ");
            scanf("%s", p->MailId);
            printf("\n*contact info edited successfully*\n");
            break;

        default:
            printf("\n*invalid number*\n");
            break;
    }
}

void delete_(struct node* p) {
    if (p == NULL) {
        printf("\n*contact list is empty*\n");
        return;
    }

    char name[20];
    printf("enter the name of contact to be deleted: ");
    scanf("%s", name);

    while (p != NULL && strcmp(p->name, name) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("\n*contact '%s' is not found*\n", name);
        return;
    }

    if (p->pre == NULL) {
        head = p->next;
    } else if (p->next == NULL) {
        p->pre->next = NULL;
    } else {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    free(p);
    printf("\n*contact '%s' deleted successfully*\n", name);
}

void search(struct node* p) {
    if (p == NULL) {
        printf("\n*contact list is empty*\n");
        return;
    }

    char name[20];
    printf("enter the name of contact to be searched: ");
    scanf("%s", name);

    while (p != NULL && strcmp(p->name, name) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("\n*contact '%s' is not found*\n", name);
        return;
    }

    printf("\n*contact '%s' is found*\ncontact info: %lld, %s\n", name, p->number, p->MailId);
    int temp;
    printf("1.go to previous contact\n2.go to next contact\n");
    scanf("%d", &temp);

    switch (temp) {
        case 1:
            if (p->pre != NULL) {
                printf("%s: %lld %s\n", p->pre->name, p->pre->number, p->pre->MailId);
            } else {
                printf("%s is the starting contact of the list\n", p->name);
            }
            break;

        case 2:
            if (p->next != NULL) {
                printf("%s: %lld %s\n", p->next->name, p->next->number, p->next->MailId);
            } else {
                printf("%s is the ending contact of the list\n", p->name);
            }
            break;

        default:
            break;
    }
}

void free_memory(struct node* p) {
    while (p != NULL) {
        struct node* temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    int opr;
    do {
        printf("\n1.Display all the contacts\n2.Save a new contact\n3.Edit an existing contact\n4.Delete a contact\n5.Search for a contact\n");
        printf("enter -1 to exit\n");
        printf("enter the operation you want to perform: ");
        scanf("%d", &opr);

        switch (opr) {
            case 1:
                display(head);
                break;

            case 2:
                save();
                break;

            case 3:
                edit(head);
                break;

            case 4:
                delete_(head);
                break;

            case 5:
                search(head);
                break;

            default:
                if (opr != -1) {
                    printf("\n*invalid operation*\n");
                }
                break;
        }
    } while (opr != -1);

    free_memory(head);
    return 0;
}
