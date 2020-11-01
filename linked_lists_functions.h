#pragma once
#ifndef LINEKD_LISTS_FUNCTIONS_H
#define LINEKD_LISTS_FUNCTIONS_H
#include "input_handling_functions.h"

typedef struct _cell
{
	int data;
	struct _cell* next;
} cell;


cell* create_cell(int new_data);

cell* add_cell_start(cell* head, int new_data);

cell* add_cell_end(cell* head, int new_data);

cell* add_cell_after(cell* head, int new_data, int insert_after_int);

cell* delete_cell(cell* head, int value_to_delete);

int find_first_index(cell* head, int int_to_find);

void print_list(cell* head);

_Bool index_is_inbound(cell* iter, int idx);

void free_list(cell* head);

#endif
