#include <cstdio>
#include <cstdlib>

struct node {
    int value;
    struct node *next;
};

void free_list(struct node *head) {
    for (struct node *p = head; p != NULL; p = p->next) {
        free(p); /* wrong: p->next is read after p is freed in the loop increment */
    }
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->value = 1;
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->value = 2;
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->value = 3;
    head->next->next->next = NULL;

    free_list(head);
    /* USE AFTER FREE: undefined behaviour */
    std::printf("First value after free: %d\n", head->value);
    return 0;
}
