/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_access_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:40:56 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 17:44:42 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

bool	check_rights(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == BAD_FILE_DESCRIPTOR)
		return (false);
	close(fd);
	return (true);
}

bool	check_image_access(void)
{
	size_t		i;
	const char	*image_path[] = {IMG_PATH_GROUND, IMG_PATH_WALL,
		IMG_PATH_PLAYER, IMG_PATH_DOOR, IMG_PATH_COLLECTIBLE};

	i = 0;
	while (i <= NBR_IMAGES)
	{
		if (check_rights(image_path[i]) == false)
			return (false);
		++i;
	}
	return (true);
}
