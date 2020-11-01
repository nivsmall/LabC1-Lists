#include <stdio.h>
#include "linked_lists_functions.h"
#include "input_handling_functions.h"

#define  MAX_CHAR_PER_LINE  100  // TODO check where this goes!

void main(int args, char* argv[])
{

	cell* list_pointer = NULL;
	while (1)
	{
		int element, insert_after, command_len;
		char command[MAX_CHAR_PER_LINE];

		command_len = input_command_from_user(command);
		str_to_up_case(command);

		if (!strcmp(command, "EXIT"))
		{
			free_list(list_pointer);
			exit(0);
		}

		else if (!strcmp(command, "PRINT"))
		{
			print_list(list_pointer);
			continue;
		}

		--command_len;
		element = pop_element_from_string(command, &command_len);

		if (!strcmp(command, "ADD_START"))
		{
			list_pointer = add_cell_start(list_pointer, element);
			continue;
		}

		else if (!strcmp(command, "ADD_END"))
		{
			list_pointer = add_cell_end(list_pointer, element);
			continue;
		}

		else if (!strcmp(command, "DEL"))
		{
			if (!index_is_inbound(list_pointer, element))	// Notice: this is the only occurance wher element is to be inputed/served as index
			{
				//exit_program(list_pointer, "Out of Bounds Error: index to delete too large! \n");
				printf("Out of Bounds Error: index to delete too large! \n");
				free_list(NULL);
				exit(1);
			}
			else
			{

				list_pointer = delete_cell(list_pointer, element);
				continue;
			}
		}

		else if (!strcmp(command, "INDEX"))
		{
			printf(find_first_index(list_pointer, element));
			continue;
		}

		insert_after = element;
		element = pop_element_from_string(command, &command_len);

		if (!strcmp(command, "ADD_AFTER"))
		{
			list_pointer = add_cell_after(list_pointer, element, insert_after);
			continue;
		}

		printf("The command was not properly processed \n \t ...Try Again'\n");

	}
}