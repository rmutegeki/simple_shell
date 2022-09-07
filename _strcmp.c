#include "headersh.h"

/**
 **_strcmp - compares two strings and tells whether they are greater than, less
 *than, or equal
 *@s1: first string to be compared
 *@s2: second string to be compared
 *
 *Return: result of subtraction between the two strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res;

	while (s1[i] != 0 && s2[i] != 0)
	{
		res = s1[i] - s2[i];
		if (res == 0)
		{
			i++;
		}
		else
		{
			break;
			return (res);
		}
	}
	return (res);
}

/**
 **_strcmp_c - compares two strings and tells whether they are greater than
 *, less than, or equal
 *@s1: first string to be compared
 *@s2: second string to be compared
 *
 *Return: result of subtraction between the two strings
 */
int _strcmp_c(char *s1, char *s2)
{
	int i = 0;
	int res;

	while (s1[i] && s2[i])
	{
		res = s1[i] - s2[i];
		if (res == 0)
			i++;
		else
			return (res);
	}
	res = s1[i] - s2[i];
	return (res);
}

/**
 **_strcmp_n - compares two strings and tells whether they are greater than
 *, less than, or equal
 *@s1: first string to be compared
 *@s2: second string to be compared
 *@n: # of chars to compare
 *
 *Return: result of subtraction between the two strings
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0;
	int res;

	while (s1[i] && s2[i] && i < n)
	{
		res = s1[i] - s2[i];
		if (res == 0)
			i++;
		else
			return (res);
	}
	if (res == 0 && s1[i] == '\0' && s2[i] == '\0')
		res = 0;
	else if (res == 0 && s1[i] == '\n' && s2[i] == '\0')
		res = 0;
	else if (res == 0 && s1[i] == '\0' && s2[i] == '\n')
		res = 0;
	else
		res = s1[i] - s2[i];
	return (res);
}

/**
 **_strcpy - copy s1
 *@s1: first string to be compared
 *
 *Return: the copy of s1
 */
char *_strcpy(char *s1)
{
	int i = 0, len_s1 = 0;
	char *new_s = NULL;

	for (len_s1 = 0; s1[len_s1]; len_s1++)
		continue;
	new_s = malloc(sizeof(char) * (len_s1 + 1));
	if (!new_s)
		return (NULL);
	for (i = 0; s1[i]; i++)
		new_s[i] = s1[i];
	new_s[i] = '\0';
	return (new_s);
}
