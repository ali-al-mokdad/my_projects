/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:39:50 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/05 15:06:15 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_issigne(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	count_numbers(const char *nptr)
{
	int			num_count;
	const char	*p;

	num_count = 0;
	p = nptr;
	while (*p)
	{
		while (ft_isspace(*p))
			p++;
		if (*p == '\0')
			break ;
		else if (ft_issigne(*p))
			p++;
		if (!ft_isdigit(*p))
			return (0);
		while (ft_isdigit(*p))
			p++;
		num_count++;
	}
	return (num_count);
}

int	parse_number(const char **p, int *result, int *sign)
{
	long	scan;

	*result = 0;
	*sign = 1;

	if (**p == '-')
	{
		*sign = -1;
		(*p)++;
	}
	else if (**p == '+')
		(*p)++;
	if (*sign == 1)
		scan = INT_MAX;
	else
		scan = 2147483648;
	while (ft_isdigit(**p))
	{
		if (*result > (scan - (**p - '0')) / 10)
			return (ft_printf("ERROR\n"), 1);
		*result = *result * 10 + (**p - '0');
		(*p)++;
	}
	return (0);
}

void	parse_numbers(const char *nptr, int *array)
{
	int			result;
	int			sign;
	const char	*p;
	int			*ptr;

	p = nptr;
	ptr = array;
	while (*p)
	{
		while (ft_isspace(*p))
			p++;
		if (*p == '\0')
			break ;
		if (parse_number(&p, &result, &sign))
		{
			free (array);
			exit (-1);
		}
		*ptr++ = result * sign;
	}
}

int	*push_swap_atoi(const char *nptr, int *count)
{
	int	num_count;
	int	*array;

	num_count = count_numbers(nptr);
	if (num_count == 0)
		return (NULL);
	array = (int *)malloc((num_count + 1) * sizeof(int));
	if (!array)
		return (NULL);
	parse_numbers(nptr, array);
	*count = num_count;
	return (array);
}
// int main(void)
// {
//     const char *text = "   \t\n 123 -456 789 ";
//     int *array;
//     int count;
//     int i;

//     array = push_swap_atoi(text, &count);
//     if (!array)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     for (i = 0; i < count; i++)
//     {
//         printf("%d\n", array[i]);
//     }

//     free(array); // Free allocated memory
//     return 0;
// }