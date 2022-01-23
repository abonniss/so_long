/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:05:53 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/21 21:53:36 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

bool check_empty_file(int fd)
{
	int ret;
	char str[BUFFER_SIZE];

	ret = read(fd, str, BUFFER_SIZE);
	if (ret <= 0)
		return (false);
	return (true);
}

//pourquoi mettre file_name == NULL ? Alors que deja check avant dans main ? 
bool check_file_extension(const char *file_name)
{
	size_t name_len;
	size_t i;

	if (file_name == NULL || ft_strlen(file_name) <= EXTENSION_LEN)
		return (false);
	name_len = ft_strlen(file_name);
	i = 0;
	//remplacer par strncmp
	while (i <= EXTENSION_LEN)
	{
		if ((file_name[(name_len - EXTENSION_LEN) + i] != EXTENSION_NAME[i]))
			return (false);
		++i;
	}
	return (true);
}

bool file_checker(char **file)
{
	int fd;
	char str_buff[4096];
	int ret;

	fd = open(file[1], O_RDONLY);
	if (fd != -1)
		if (check_file_extension(file[1]) == true && check_empty_file(fd) != false)
		{	
			ret = read(fd, &str_buff, 10);
			printf("Ret : (%d)\n", ret);
			str_buff[ret] = '\0';
			printf("Str_buff: (%s)\n", str_buff);
			//return (true);
		}
	perror("Error message");
	
	// A FAIRE -> check if file is not a directory
	return (false);
}

int main (int argc, char **argv)
{	
	if (argc != 2 || file_checker(argv) != true)
	 return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}