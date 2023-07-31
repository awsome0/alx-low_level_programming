#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow, *fast;

    slow = fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // Loop detected
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow; // Node where the loop starts
        }
    }

    return NULL; // No loop found
}
