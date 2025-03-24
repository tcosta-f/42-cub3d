/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:12:06 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/03/21 01:37:01 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_file_extension(char *filename);
int		ft_open_file(char *filename);
int		ft_count_tabs(char *line);
void	ft_expand_tabs(char *src, char *dest);
char	*ft_replace_tabs(char *line);
t_list	*ft_read_file_list(int fd);
void	ft_free_list(t_list *list);
void	ft_print_list(t_list *list); // teste
int		main(int argc, char **argv);

/**
 * @brief  Checks if the file has a valid .cub extension.
 * 
 * @param  filename  The name of the file to check.
 * @return int       
 *         1 if valid, 0 if invalid.
 */
int	ft_check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(&filename[len - 4], ".cub") != 0)
	{
		write(2, "Error\nInvalid file extension. Must be .cub\n", 43);
		return (0);
	}
	return (1);
}

/**
 * @brief  Opens the .cub file for reading.
 * 
 * @param  filename  The name of the file to open.
 * @return int       
 *         The file descriptor if successful, -1 on error.
 */
int	ft_open_file(char *filename)
{
	int	fd;

	if (!ft_check_file_extension(filename))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file\n", 26);
		return (-1);
	}
	return (fd);
}

/**
 * @brief  Counts the number of tab characters in a string.
 * 
 * @param  line  The input string.
 * @return int   
 *         Number of tab characters found.
 */
int	ft_count_tabs(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\t')
			count += 3;
		i++;
	}
	return (count);
}

/**
 * @brief  Expands tabs in a string, replacing each '\t' with four spaces.
 * 
 * @param  src  The input string.
 * @param  dest The destination buffer.
 */
void	ft_expand_tabs(char *src, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\t')
		{
			dest[j++] = ' ';
			dest[j++] = ' ';
			dest[j++] = ' ';
			dest[j++] = ' ';
		}
		else
			dest[j++] = src[i];
		i++;
	}
	dest[j] = '\0';
}

/**
 * @brief  Replaces tab characters in a line with four spaces.
 * 
 * @param  line  The input string to modify.
 * @return char* 
 *         A new dynamically allocated string with tabs replaced.
 */
char	*ft_replace_tabs(char *line)
{
	int		extra_spaces;
	char	*new_line;

	if (!line)
		return (NULL);
	extra_spaces = ft_count_tabs(line);
	new_line = malloc(sizeof(char) * (ft_strlen(line) + extra_spaces + 1));
	if (!new_line)
		return (NULL);
	ft_expand_tabs(line, new_line);
	return (new_line);
}

/**
 * @brief  Reads the file line by line and stores it in a linked list.
 * 
 * @param  fd  The file descriptor of the opened .cub file.
 * @return t_list*  
 *         The head of the linked list containing file lines.
 */
t_list	*ft_read_file_list(int fd)
{
	char	*line;
	char	*clean_line;
	t_list	*head;
	t_list	*temp;
	t_list	*new_node;

	head = NULL;
	temp = NULL;
	while ((line = get_next_line(fd)))
	{
		clean_line = ft_replace_tabs(line);
		free(line);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (NULL);
		new_node->content = clean_line;
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
			temp->next = new_node;
		temp = new_node;
	}
	return (head);
}

/**
 * @brief  Frees all memory allocated for the linked list.
 * 
 * @param  list  The head of the linked list.
 */
void	ft_free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}

/**
 * @brief  Prints the content of the linked list (for testing).
 * 
 * @param  list  The head of the linked list.
 */
void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putstr_fd((char *)list->content, 1);
		list = list->next;
	}
}

/**
 * @brief  Main entry point of the program.
 * 
 * @param  argc  Argument count.
 * @param  argv  Argument vector.
 * @return int   
 *         Exit code of the program.
 */
int	main(int argc, char **argv)
{
	int			fd;
	t_list		*file_lines;
	t_config	config;

	if (argc != 2)
	{
		write(2, "Usage: ./cub3D <map.cub>\n", 26);
		return (1);
	}
	fd = ft_open_file(argv[1]);
	if (fd < 0)
		return (1);
	file_lines = ft_read_file_list(fd);
	close(fd);
	if (!file_lines || !ft_validate_map_presence(file_lines))
	{
		write(2, "Error\nInvalid map file\n", 24);
		return (1);
	}
	ft_parse_config(file_lines, &config);
	if (!ft_validate_config(&config))
	{
		ft_free_list(file_lines);
		ft_free_config(&config);
		return (1);
	}
	if (!ft_extract_map(file_lines, &config) || !ft_validate_player_position(&config))
	{
		ft_free_list(file_lines);
		ft_free_config(&config);
		return (1);
	}
	ft_free_list(file_lines);
	ft_free_config(&config);
	return (0);
}
