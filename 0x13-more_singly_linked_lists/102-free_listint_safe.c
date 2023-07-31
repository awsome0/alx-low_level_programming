#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list, setting head to NULL.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *tmp;

    while (*h != NULL)
    {
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;
    }

    *h = NULL; // Set head to NULL after freeing the list
    return (count);
}
