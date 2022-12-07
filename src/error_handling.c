/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:38:43 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/05 20:37:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*get_error_message(int errcode)
{
	static char	*error_messages[] = {\
		BGRAY "Undefined error message" RESET, \
		"Run: " BWHITE "./cub3d " RESET UPURPLE "PATH_TO_MAP" RESET, \
		"File extension must be " UPURPLE ".cub" RESET, \
		"Invalid texture parameter. Must be either " UPURPLE "NO" RESET ", " \
			UPURPLE "SO" RESET ", " UPURPLE "EA" RESET ", " UPURPLE "WE" RESET \
			", " UPURPLE "F" RESET " or " UPURPLE "C" RESET \
			", followed by a space and the path to the texture file.", \
		"Missing parameter. Provide " UPURPLE "4 texture file paths" RESET \
			" and " UPURPLE "2 colours." RESET, \
		"Redundant parameter found. Parameter duplicates not allowed.", \
		"Invalid colour format. Use: " UPURPLE "R, G, B" RESET \
			", each value ranging from 0 to 255.", \
		"Invalid map.", \
		"Error allocating memory. Ran out of RAM?", \
		"Map has invalid char. Valid chars are: " UPURPLE VALID_CHARS RESET, \
		"Invalid map size.", \
		"No starting position character found. Valid chars are: " \
			UPURPLE "N" RESET ", " UPURPLE "S" RESET ", " UPURPLE "E" RESET \
			", " UPURPLE "W" RESET ".", \
		"Multiple starting position characters found. Only one allowed.", \
		"Player starting position is outside the map.", \
		"MLX error"};

	return (error_messages[errcode]);
}

void	print_err_exit(int errcode, t_data *data)
{
	int i, j;
	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
			printf("%c", data->map_data.map[i][j]);
		printf("\n");
	}
	free_data(data);
	printf(PURPLEB " ❌ Error " RESET "\n");
	if (errcode)
		printf("%s\n", get_error_message(errcode));
	else
		perror(NULL);
	exit(errcode || errno);
}
