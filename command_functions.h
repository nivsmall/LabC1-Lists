#pragma once
#ifndef COMMAND_FUNCTIONS_H
#define COMMAND_FUNCTIONS_H

typedef struct cell
{
	int data;
	struct cell* next;
} cell;


cell* create_cell(int new_data);

cell* add_cell_start(cell* head, int new_data);

cell* add_cell_end(cell* head, int new_data);

cell* add_cell_after(cell* head, int new_data, int insert_after_int);

cell* delete_cell(cell* head, int value_to_delete);

int find_first_index(cell* head, int int_to_find);

void print_list(cell* head);

#endif
