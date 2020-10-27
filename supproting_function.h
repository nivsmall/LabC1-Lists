#pragma once
#ifndef SUPPORTING_FUNCTIONS_H
#define SUPPORTING_FUNCTIONS_H
#include "command_functions.h"

int input_command_from_user(char command[]);

int prune_whitespace(char str[], int idx);

void str_to_up_case(char str[]);

int char_to_int(char ch[]);

int negative_number_fix(char command[], int* idx, int element);

_Bool extract_numstring(char command[], char element_str[], int* idx);

int pop_element_from_string(char command[], int* idx);

_Bool index_is_inbound(cell* iter, int idx);

void free_list(cell* head);

void exit_program(cell* head, char error_message)


#endif;