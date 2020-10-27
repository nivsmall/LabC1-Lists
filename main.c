#include <stdio.h>
#include "command_functions.h"
#include "supproting_function.h"


void main(int args, char* argv[])
{
	cell* list_pointer = NULL;
	while (1)
	{
		int element, insert_after, len;
		char command[100];

		len = input_command_from_user(command);
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

		--len;
		element = pop_element_from_string(command, &len);

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
				exit_program(list_pointer, "Out of Bounds Error: index to delete too large! \n");
			}
			else
			{

				list_pointer = delete_cell(list_pointer, element);
				continue;
			}
		}

		else if (!strcmp(command, "INDEX"))
		{
			if (find_first_index(list_pointer, element) == -1)
			{
				exit_program(list_pointer, "Error: element was not found in list \n");
			}
			continue;
		}

		insert_after = element;
		element = pop_element_from_string(command, &len);

		if (!strcmp(command, "ADD_AFTER"))
		{
			list_pointer = add_cell_after(list_pointer, element, insert_after);
			continue;
		}

		printf("The command was not properly processed \n \t ...Try Again'\n");

	}
}