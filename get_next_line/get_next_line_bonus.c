/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:54:31 by lmartin2          #+#    #+#             */
/*   Updated: 2022/08/22 12:58:05 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Function to read the next line from a file descriptor
char	*get_next_line(int fd)
{
	// variable to store the next line
	char *next_line;

	// Initialize variable to store the next line
	next_line = NULL;
	// Call function to read the next line
	if (read_next_line(fd, &next_line))
		// Free memory if an error occurs
		ft_free((void *)next_line);
	// Return the next line read from the file descriptor
	return (next_line);
}

// Function to read the next line from the file descriptor and manage buffer
int	read_next_line(int fd, char **next_line)
{
	// Static buffer to store lines for each file 
	static char	*pantry[OPEN_MAX];
	// error flag
	int			error;

	// Initialize error flag and next line
	error = 0;
	*next_line = NULL;
	// Check for valid file descriptor and buffer size
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		error = 10;
	if (!error)
		// Read from file descriptor and populate the pantry buffer
		error = my_feeder(&pantry[fd], fd);
	if (!error)
		 // Extract the next line from the pantry buffer
		error = my_spender(&pantry[fd], next_line);
	if (!error)
		// Save the remaining buffer for the file descriptor
		error = my_saver(&pantry[fd]);
	// Return the error code
	return (error);
}

// Function to read from the file descriptor and manage buffer
int my_feeder(char **pantry, int fd)
{
	// Variable to store the number of characters read
    int numchars;
    // Buffer to store the characters read from the file
	char buffer[BUFFER_SIZE + 1]; 
     // Temporary pointer for string manipulation
	char *tmp;

    numchars = 1;
	// Continue reading until newline is found or end of file is reached
    while (numchars && !ft_strchr(*pantry, '\n')) 
	{
		// Read from the file descriptor into the buffer
        numchars = read(fd, buffer, BUFFER_SIZE); 
		// If there was an error and pantry is not empty
        if (numchars == -1 && *pantry) 
			// Free the memory and set pantry to NULL
            *pantry = (char *)ft_free((void *)*pantry); 
        // If there was an error
		if (numchars == -1) 
			// Return error code 20
            return (20); 
        // Null-terminate the buffer
		buffer[numchars] = 0; 
		// If pantry is empty
        if (!*pantry) 
			// Allocate memory for pantry
            *pantry = (char *)ft_calloc(sizeof(char), 1);
		// If memory allocation failed
        if (!*pantry) 
			// Return error code 30
            return (30); 
		// Concatenate pantry and buffer into tmp
        tmp = ft_strjoin(*pantry, buffer); 
		// Free the memory occupied by pantry
        *pantry = (char *)ft_free((void *)*pantry); 
		// If concatenation failed
        if (!tmp) 
			// Return error code 30
            return (30);
		// Set pantry to the concatenated string
        *pantry = tmp; 
    }
	// Return success
    return (0); 
}

// Function to extract the next line from the buffer
int my_spender(char **pantry, char **str) 
{	// Variable to store the size of the next line
    int size; 
	
	// If pantry is empty or the first character is null
    if (!*pantry || !**pantry) 
    	// Return 0 (no next line)
	    return (0); 
	// If newline is found in the pantry
    if (ft_strchr(*pantry, '\n')) 
		// Calculate the size of the next line including newline
        size = ft_strchr(*pantry, '\n') - *pantry + 1; 
    // If newline is not found
	else 
		// Set the size to the length of the entire string
        size = ft_strlen(*pantry); 
	// Allocate memory for the next line including null-terminator
    *str = (char *)ft_calloc(sizeof(char), (size_t)(size + 1)); 
    // If memory allocation failed and pantry is not empty
	if (!*str && *pantry)
	{	// Free the memory occupied by pantry 
        free(*pantry); 
		// Set pantry to NULL
        *pantry = NULL; 
    }
	// If memory allocation failed
    if (!*str)
		// Return error code 30 
        return (30); 
	// Copy the next line from pantry to str
    ft_strlcpy(*str, *pantry, size + 1); 
    // Return success
	return (0); 
}

// Function to remove the first line from the buffer
int my_saver(char **pantry) 
{
    size_t len;
    char *ptr;
    int gap;

    if (!*pantry)
		// Return 0 if pantry is empty
        return (0); 
	// Calculate the length of the string in pantry
    gap = ft_strlen(*pantry); 
	// Find the first occurrence of newline in pantry
    ptr = ft_strchr(*pantry, '\n'); 
	// Update the gap if newline is found
    if (ptr)
        gap = ptr - *pantry; 
	//If the next character after the newline is null
    if (!*(*pantry + gap)) 
	{
		// Free the memory occupied by pantry
        *pantry = (char *)ft_free((void *)*pantry);
		// Return 0 (success)
        return (0); 
    }
	// Calculate the length of the remaining string after removing the first line
    len = (ft_strlen(*pantry) - gap); 
	// Allocate memory for the remaining string
    ptr = ft_calloc(sizeof(char), (len + 1));
    if (!ptr && *pantry)
		// Free the memory occupied by pantry if memory allocation failed
        *pantry = (char *)ft_free((void *)*pantry); 
    if (!ptr)
		// Return error code 30 if memory allocation failed
        return (30); 
	// Copy the remaining string to ptr
    ft_strlcpy(ptr, *pantry + gap + 1, len + 1); 
	// Free the memory occupied by pantry
    free(*pantry); 
	// Update pantry with the remaining string
    *pantry = ptr; 
	// Return success
    return (0); 
}
