#pragma once
#ifndef INPUT_HANDLING_FUNCTIONS_H
#define INPUT_HANDLING_FUNCTIONS_H
#include "linked_lists_functions.h"


int input_command_from_user(char command[]);

int prune_whitespace(char str[], int idx);

void str_to_up_case(char str[]);

int char_to_int(char ch[]);

int negative_number_fix(char command[], int* idx, int element);

_Bool extract_numstring(char command[], char element_str[], int* idx);

int pop_element_from_string(char command[], int* idx);

//void exit_program(char error_message[], cell* head_);
#endif;