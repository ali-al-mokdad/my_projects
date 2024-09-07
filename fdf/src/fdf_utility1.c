/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utility1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:06:25 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/07 13:55:23 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_structs(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->x)
	{
		printf("%s", vars->map[i]);
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars);
}

// void	save_to_struct(char *line, t_vars *vars)
// {
// 	char	**temp_map;

// 	temp_map = realloc(vars->map, sizeof(char *) * (vars->x + 1));
// 	if (!temp_map)
// 	{
// 		perror("Error reallocating memory");
// 		exit(-1);
// 	}
// 	vars->map = temp_map;
// 	vars->map[vars->x] = line;
// }

void save_to_struct(char *line, t_vars *vars)
{
    char **temp_map;
    char **tokens;
    int i = 0;
    
    tokens = ft_split(line, ' '); // Use a suitable function to split the line
    if (!tokens)
    {
        perror("Error splitting line");
        exit(-1);
    }
    
    temp_map = realloc(vars->map, sizeof(int *) * (vars->x + 1));
    if (!temp_map)
    {
        perror("Error reallocating memory");
        exit(-1);
    }
    vars->map = temp_map;
    
    vars->map[vars->x] = malloc(sizeof(int) * (vars->y));
    if (!vars->map[vars->x])
    {
        perror("Error allocating memory for row");
        exit(-1);
    }
    
    while (tokens[i])
    {
        vars->map[vars->x][i] = atoi(tokens[i]); // Convert string to integer
        i++;
    }
    
    free(tokens);
}


// void	save_map(int file, t_vars *vars)
// {
// 	char	*line;
// 	int		cols;
// 	int		i;

// 	vars->y = 0;
// 	vars->x = 0;
// 	line = get_next_line(file);
// 	while (line != NULL)
// 	{
// 		cols = 0;
// 		i = 0;
// 		while (line[i])
// 		{
// 			if (line[i] == ' ')
// 				cols++;
// 			i++;
// 		}
// 		if (vars->y < cols)
// 			vars->y = cols + 1;
// 		save_to_struct(line, vars);
// 		line = get_next_line(file);
// 		vars->x++;
// 	}
// }

void save_map(int file, t_vars *vars)
{
    char *line;
    int  i;
    
    vars->y = 0; // Number of rows
    vars->x = 0; // Number of columns

    while ((line = get_next_line(file)) != NULL)
    {
        char **tokens = ft_split(line, ' ');
        if (!tokens)
        {
            perror("Error splitting line");
            exit(-1);
        }

        // Count columns in the current line
        for (i = 0; tokens[i]; i++);

        if (vars->x < i)
            vars->x = i; // Maximum columns in the map

        // Allocate memory for the map row
        vars->map = realloc(vars->map, sizeof(int *) * (vars->y + 1));
        if (!vars->map)
        {
            perror("Error reallocating memory");
            exit(-1);
        }
        
        vars->map[vars->y] = malloc(sizeof(int) * vars->x);
        if (!vars->map[vars->y])
        {
            perror("Error allocating memory for row");
            exit(-1);
        }
        
        // Store the row data
        for (i = 0; i < vars->x; i++)
            vars->map[vars->y][i] = (tokens[i] ? atoi(tokens[i]) : 0); // Default to 0 if missing

        // Free tokens
        for (i = 0; tokens[i]; i++)
            free(tokens[i]);
        free(tokens);
        
        vars->y++; // Increment row count
        free(line);
    }

    // Null-terminate the map array
    vars->map = realloc(vars->map, sizeof(int *) * (vars->y + 1));
    if (!vars->map)
    {
        perror("Error reallocating memory");
        exit(-1);
    }
    vars->map[vars->y] = NULL;
}

// void	read_map(char *filename, t_vars *vars)
// {
// 	int		file;
// 	char	**temp_map;

// 	file = open(filename, O_RDONLY);
// 	if (file < 0)
// 	{
// 		perror("Error opening file");
// 		exit(-1);
// 	}
// 	vars->map = NULL;
// 	save_map(file, vars);
// 	close (file);
// 	temp_map = realloc(vars->map, sizeof(char *) * (vars->x + 1));
// 	if (!temp_map)
// 	{
// 		perror("Error reallocating memory");
// 		exit(-1);
// 	}
// 	vars->map = temp_map;
// 	vars->map[vars->x] = NULL;
// }

void read_map(char *filename, t_vars *vars)
{
    int file;

    file = open(filename, O_RDONLY);
    if (file < 0)
    {
        perror("Error opening file");
        exit(-1);
    }

    vars->map = NULL;
    save_map(file, vars);
    close(file);
    
    // Ensure last row pointer is null
    vars->map = realloc(vars->map, sizeof(int *) * (vars->x + 1));
    if (!vars->map)
    {
        perror("Error reallocating memory");
        exit(-1);
    }
    vars->map[vars->x] = NULL;
}
