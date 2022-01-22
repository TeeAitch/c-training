#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next; // pointer to the next node
    struct node *prev; // pointer to the previous node

} node_t;

node_t *head = NULL;

void add_node(int value)
{
    if (head == NULL)
    {
        head = (node_t *)malloc(sizeof(node_t));
        head->value = value;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        node_t *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        node_t *new_element = (node_t *)malloc(sizeof(node_t));
        if (new_element == NULL)
        {
            perror("allocating new element gone wrong");
        }
        current->next = new_element;
        new_element->value = value;
        new_element->prev = current;
        new_element->next = NULL;
    }
}

void print_nodes(node_t *head)
{
    node_t *current = head;
    while (current != NULL)
    {
        if (current == head)
        {
            printf("NULL <- %d -> %d\n", current->value, current->next->value);
            current = current->next;
        }
        if (current->next == NULL)
        {
            printf("%d <- %d -> NULL\n", current->prev->value, current->value);
            current = current->next;
        }
        else
        {
            printf("%d <- %d -> %d\n", current->prev->value, current->value, current->next->value);
            current = current->next;
        }
    }
}

void delete_node(node_t **head_ptr, int value)
{

    if (value == (*head_ptr)->value)
    {
        node_t *tmp = (*head_ptr)->next;
        tmp->prev = NULL;
        free(*head_ptr);
        *head_ptr = tmp;
    }
    else
    {
        node_t *current = (*head_ptr)->next;
        while (current->next != NULL)
        {
            if (current->next->value == value)
            {
                current->next->next->prev = current;
                current->next = current->next->next;
                current = current->next;
            }
            else if (current->prev->value == value)
            {
                current->prev->prev->next = current;
                current->prev = current->prev->prev;
                current = current->next;
            }
            current = current->next;
        }
    }
}

void add_node_eol(int start, int end)
{
    if (start > end)
    {
        perror("the starting number have to be smaller than the ending number");
    }
    for (int i = start; i <= end; i++)
    {
        add_node(i);
    }
}

int main()
{
    add_node_eol(1, 30);

    print_nodes(head);

    delete_node(&head, 1);

    print_nodes(head);
    return 0;
}