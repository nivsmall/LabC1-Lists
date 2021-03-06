#include <stdio.h>
#include "linked_lists_functions.h"

cell* create_cell(int new_data) //maybe delet all this
{
	cell* new_cell = (cell*)malloc(sizeof(cell));
	if (new_cell == NULL)//malloc failed- no need in excrsice so maybe dellet
		return NULL;
	if (new_cell != NULL)
	{

		new_cell->data = new_data;
		new_cell->next = NULL;
		return new_cell;
	}
}

cell* add_cell_start(cell* head, int new_data) {
	cell* new_cell = create_cell(new_data);
	if (new_cell == NULL)//maybe delete
	{
		return NULL;
	}
	new_cell->next = head;

	return new_cell;
}

cell* add_cell_end(cell* head, int new_data) {
	cell* iter = NULL;
	cell* prev = NULL;

	cell* new_cell = create_cell(new_data);

	if (new_cell == NULL)// maybe delete, need only when memory allocted failed
	{
		return NULL;
	}
	if (head == NULL)
	{
		head = new_cell;
		return new_cell;
	}
	iter = head;
	while (iter != NULL)
	{
		prev = iter;
		iter = iter->next;
	}
	prev->next = new_cell;
	new_cell->next = iter;

	return head;
}

cell* add_cell_after(cell* head, int new_data, int insert_after_int) {
	cell* iter = NULL;
	cell* prev = NULL;

	cell* new_cell = create_cell(new_data);

	if (new_cell == NULL)// maybe delete, need only when memory allocted failed
	{
		return NULL;
	}
	if (head == NULL)
	{
		head = new_cell;
		return new_cell;
	}
	iter = head;
	while (iter->data != insert_after_int)
	{
		prev = iter;
		iter = iter->next;
	}
	new_cell->next = iter->next;
	iter->next = new_cell;

	return head;
}

cell* delete_cell(cell* head, int index_to_delete) {
	cell* iter = head;
	cell* prev = NULL;
	int i = 0;

	if (head == NULL)// maybe delete, need only when memory allocted failed
	{
		return NULL;
	}
	if (index_to_delete == 0)
	{
		iter = head->next;
		free(head);
		return iter;
	}
	else
	{	
		for(i; i<index_to_delete; ++i)
		{

			prev = iter;
			iter = iter->next;
		}
		prev->next = iter->next;
		free(iter);
	}
	return head;
}

int find_first_index(cell* head, int int_to_find) {
	int count = 0;

	cell* current_cell = head;

	while (current_cell != NULL) {
		if (current_cell->data == int_to_find)
		{
			printf("The first occurance of %d is at index: %d\n", int_to_find, count);
			return count;
		}
		current_cell = current_cell->next;
		count += 1;
	}
	return -1;
}

void print_list(cell* head)// modified from https://www.opentechguides.com/how-to/article/c/141/linkedlist-add-del-print-count.html

{
	cell* current_cell = head;
	printf("[");
	while (current_cell != NULL) {

		if (current_cell->next == NULL) {
			printf("%d", current_cell->data);
		}
		else {
			printf("%d, ", current_cell->data);
		}
		current_cell = current_cell->next;
	}
	printf("]\n");
}

_Bool index_is_inbound(cell* iter, int idx)
{
	cell* prev = NULL;
	int count = 0;
	while (iter != NULL)
	{
		prev = iter;
		iter = iter->next;
		++count;
	}
	if (idx >= count) { return 0; }
	else { return 1; }
}

void free_list(cell* head)
{
	if (head == NULL)
		return;

	free_list(head->next);
	free(head);
}