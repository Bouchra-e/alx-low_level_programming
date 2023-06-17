#include "lists.h"

/**
 * create_node - Creates a new node
 * @n: The data for the new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *create_node(int n)
{
  dlistint_t *new_node = malloc(sizeof(dlistint_t));

  if (new_node == NULL)
    return NULL;

  new_node->n = n;
  new_node->prev = NULL;
  new_node->next = NULL;

  return new_node;
}

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @head: A pointer to the head of the dlistint_t list
 * @idx: The index of the list where the new node should be added
 * @n: The data for the new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int idx, int n)
{
  dlistint_t *new_node, *current = *head;

  if (idx == 0)
    {
      new_node = create_node(n);
      if (new_node == NULL)
	return NULL;

      new_node->next = *head;
      if (*head != NULL)
	(*head)->prev = new_node;
      *head = new_node;

      return (new_node);
    }

  while (idx > 1)
    {
      if (current == NULL)
	return NULL;
      current = current->next;
      idx--;
    }

  if (current == NULL)
    return NULL;

  new_node = create_node(n);
  if (new_node == NULL)
    return NULL;

  new_node->next = current->next;
  if (current->next != NULL)
    current->next->prev = new_node;
  current->next = new_node;
  new_node->prev = current;

  return (new_node);
}
