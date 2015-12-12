#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

static struct node *add_to_list(struct node *list, int n);
static struct node *read_numbers(void);
static int count_occurences(struct node *list, int n);

int 
main(int argc, char* argv[]) {
    int n, count;
    struct node *list;
    
    list = read_numbers();
    printf("Enter the value to search: ");
    scanf("%d", &n);    
    count = count_occurences(list, n);
    printf("Found %d nodes with value %d.\n", count, n);

    return 0;
}

static struct node
*add_to_list(struct node *list, int n) {
    struct node *new_node;
    
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

static struct node
*read_numbers(void) {
    struct node *first = NULL;
    int n;
    
    printf("Enter a series of integers (0 to terminate): \n");
    for (;;) {
        scanf("%d", &n);
        if (n == 0)
            return first;
        first = add_to_list(first, n);
    }
}

static int
count_occurences(struct node *list, int n) {
    struct node *p;
    int counter = 0;

    for (p = list; p != NULL; p = p->next) {
        if (p->value == n)
            counter += 1;       
    }
    return counter;
}
    
