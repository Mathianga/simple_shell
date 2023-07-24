#include "shell.h"

/**
 * env_get_key - gets value of an env var
 * @key: the env var of interest
 * @data: struct of the program's data
 * Return: a pointer to the val of the var or NULL if it doesn't exist
 */
char *env_get_key(char *key, data_of_program *data)
{
	int m, key_length = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);

	/* obtains the leng of the var requested */
	key_length = str_length(key);

	for (m = 0; data->env[m]; m++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (str_compare(key, data->env[m], key_length) &&
		 data->env[m][key_length] == '=')
		{/* returns the value of the key NAME=  when find it*/
			return (data->env[m] + key_length + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);
}

/**
 * env_set_key - overwrite the value of the env var
 * or create it if does not exist.
 * @key: name of the var to set
 * @value: new value
 * @data: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an error 0 if sucess.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int m, key_length = 0, is_new_key = 1;

	/* validate the arguments */
	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (m = 0; data->env[m]; m++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (str_compare(key, data->env[m], key_length) &&
		 data->env[i][key_length] == '=')
		{/* If key already exists */
			is_new_key = 0;
			/* free the entire variable, it is new created below */
			free(data->env[m]);
			break;
		}
	}
	/* make an string of the form key=value */
	data->env[m] = str_concat(str_duplicate(key), "=");
	data->env[m] = str_concat(data->env[m], value);

	if (is_new_key)
	{/* if the variable is new, it is create at end of actual list and we need*/
	/* to put the NULL value in the next position */
		data->env[m + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - remove a key from the env
 * @key: the key to remove
 * @data: the sructure of the program's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int m, key_length = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (0);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (m = 0; data->env[m]; m++)
	{/* iterates through the environ and checks for coincidences */
		if (str_compare(key, data->env[m], key_length) &&
		 data->env[m][key_length] == '=')
		{/* if key already exists, remove them */
			free(data->env[m]);

			/* move the others keys one position down */
			m++;
			for (; data->env[m]; m++)
			{
				data->env[m - 1] = data->env[m];
			}
			/* put the NULL value at the new end of the list */
			data->env[m - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */
void print_environ(data_of_program *data)
{
	int n;

	for (n = 0; data->env[n]; n++)
	{
		_print(data->env[n]);
		_print("\n");
	}
}
