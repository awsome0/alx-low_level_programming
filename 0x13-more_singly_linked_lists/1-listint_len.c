#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - Returns the number of elements in a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
    const listint_t *current = h;
    size_t count = 0;

    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    return count;
}
