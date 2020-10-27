#include <stdio.h>
#include <string.h>
#include "command_functions.h"


int input_command_from_user(char command[])
{
	int read = 1, i = 0;
	printf("Please enter a command:\n");
		while (read)
		{
			scanf_s("%c", &command[i]);
			if (command[i] == '\n')
			{
				read = 0;
				command[i] = '\0';
			}
			++i;
		}
	return i-1;
}

int prune_whitespace(char str[], int idx)
{
	if (isspace(str[idx]))
	{
		str[idx] = '\0';
		return 1;
	}
	else return 0;
}

void str_to_up_case(char str[])//modify from-https://codeforwin.org/2015/04/c-program-convert-lower-case-string-to-upper.html
{
	int i = 0;
	for (i = 0; (str[i] != '\0') & (str[i] != '\n'); i++)
	{

		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
	prune_whitespace(str, i);
}

int char_to_int(char ch[]) // modified from-https://www.programmingsimplified.com/c/source-code/c-program-convert-string-to-integer-without-using-atoi-function
{
	int i = 0;
	int num = 0;


	for (i ; ch[i] != '\0'; i++)
	{
		num = num * 10 + ch[i] - '0';
	}

	return num;
}

int negative_number_fix(char command[], int* idx, int element)
{
	if (command[*idx] == '-')
	{
		command[*idx] = '\0';
		--* idx;
		return -1 * element;
	}
	else
		return element;
}

_Bool extract_numstring(char command[], char element_str[], int* idx)
{
	int cnt = 0;
	while (command[*idx] >= '0' && command[*idx] <= '9')
	{
		element_str[cnt] = command[*idx];
		++cnt;
		--*idx;
	}

	if (cnt == 0)
		return 0;

	command[*idx + 1] = '\0';
	element_str[cnt] = '\0';
	_strrev(element_str);

	return 1;
}

int pop_element_from_string(char command[], int* idx)
{
	char element_str[50];
	int element, cnt=0;


	while (prune_whitespace(command, *idx))
	{
		printf("%d\n", *idx);
		--*idx;
		printf("%d\n", *idx);
	}
	
	if (!extract_numstring(command, element_str, idx))
	{
		printf("Invalid input \n \t ...Exiting program\n");
		exit(1);
	}

	element = char_to_int(element_str);
	element = negative_number_fix(command, idx, element);

	while (prune_whitespace(command, *idx))
	{
		--*idx;
	}
	
	return element;
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
	if (idx >= count) {return 0;}
	else { return 1; }
}

void free_list(cell* head)
{
	if (head == NULL)
		return;

	free_list(head->next);
	free(head);
}

void exit_program(cell* head, char error_message)
{
	printf(error_message);
	free_list(head);
	exit(1);
}

