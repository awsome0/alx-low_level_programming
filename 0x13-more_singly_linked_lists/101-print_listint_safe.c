#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list, avoiding cycles.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;

    slow = head;
    fast = (head != NULL) ? head->next : NULL;

    while (fast != NULL && fast->next != NULL && fast != slow)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }

    if (fast == slow)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        printf("-> [%p] %d\n", (void *)fast, fast->n);
        exit(98);
    }

    while (head != NULL)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
        count++;
    }

    return (count);
}
