#include "shell.h"

/**
 * print_alias - a function that add, remove or show aliases
 * @data: program's data struct
 * @alias: name of the alias to be printed
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int print_alias(data_of_program *data, char *alias)
{
	int m, n, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (m = 0; data->alias_list[m]; m++)
		{
			if (!alias || (str_compare(data->alias_list[m], alias, alias_length)
				&&	data->alias_list[m][alias_length] == '='))
			{
				for (n = 0; data->alias_list[m][n]; n++)
				{
					buffer[n] = data->alias_list[m][n];
					if (data->alias_list[m][n] == '=')
						break;
				}

				buffer[n + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[m] + n + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - a function that add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */

char *get_alias(data_of_program *data, char *name)
{
	int m, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (m = 0; data->alias_list[m]; m++)
	{
		if (str_compare(name, data->alias_list[m], alias_length) &&
			data->alias_list[m][alias_length] == '=')
		{
			return (data->alias_list[m] + alias_length + 1);
		}
	}

	return (NULL);

}

/**
 * set_alias - a function that add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int set_alias(char *alias_string, data_of_program *data)
{
	int m, n;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);

	for (m = 0; alias_string[m]; m++)
		if (alias_string[m] != '=')
			buffer[m] = alias_string[m];
		else
		{
			temp = get_alias(data, alias_string + m + 1);
			break;
		}

	for (n = 0; data->alias_list[n]; n++)
		if (str_compare(buffer, data->alias_list[n], m) &&
			data->alias_list[n][m] == '=')
		{
			free(data->alias_list[n]);
			break;
		}


	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[m] = str_duplicate(buffer);
	}
	else
		data->alias_list[n] = str_duplicate(alias_string);
	return (0);
}
