#include <cstdio>
#include <cstdlib>

struct node {
    int value;
    struct node *next;
};

void free_list(struct node *head) {
    struct node *q;
    for (struct node *p = head; p != NULL; p = q) {
        q = p->next;
        free(p);
    }
}

int main() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->value = 1; head->next = second;
    second->value = 2; second->next = third;
    third->value = 3; third->next = NULL;

    for (struct node *p = head; p != NULL; p = p->next) {
        std::printf("%d ", p->value);
    }
    std::printf("\n");

    free_list(head);
    head = NULL;
    std::printf("List has been freed.\n");
    return 0;
}
