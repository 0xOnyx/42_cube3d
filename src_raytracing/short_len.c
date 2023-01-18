/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:08 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:08 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static double	find_vertical_len(double angle, int *vertical_off)
{
	double			xa;
	double			ya;
	t_posd			current;

	if (angle == 90 || angle == 270)
		return (10000);
	ya = MAP_SIZE * tan(angle_to_rad(angle));
	xa = MAP_SIZE;
	if (angle < 90 || angle > 270)
		ya *= -1;
	if (angle > 90 && angle < 270)
		xa *= -1;
	get_first_vertical(&current, angle);
	while (is_on_grid(current))
	{
		current.x = current.x + xa;
		current.y = current.y + ya;
	}
	*vertical_off = (int)floor(current.y) % MAP_SIZE;
	return (get_len_pos(current));
}

static double	find_horizontal_len(double angle, int *horizontal_off)
{
	double			xa;
	double			ya;
	t_posd			current;

	if (angle == 180 || angle == 0)
		return (10000);
	xa = MAP_SIZE / tan(angle_to_rad(angle));
	ya = MAP_SIZE;
	if (angle < 180 && angle > 0)
		ya *= -1;
	if (angle > 180 && angle < 360)
		xa = -xa;
	get_first_horizontal(&current, angle);
	while (is_on_grid(current))
	{
		current.x = current.x + xa;
		current.y = current.y + ya;
	}
	*horizontal_off = (int)floor(current.x) % MAP_SIZE;
	return (get_len_pos(current));
}

double	find_short_len(double angle)
{
	double	vertical_len;
	int		vertical_off;
	double	horizontal_len;
	int		horizontal_off;
	t_data	*data;

	data = get_data(NULL);
	horizontal_len = absd(find_horizontal_len(angle, &horizontal_off));
	vertical_len = absd(find_vertical_len(angle, &vertical_off));
	if (horizontal_len < vertical_len)
	{
		data->player.offset = horizontal_off;
		data->player.face = SO * (angle < 180) + NO * (angle >= 180);
		if (angle > 0 && angle < 180)
			data->player.offset = MAP_SIZE - data->player.offset - 1;
		return (horizontal_len);
	}
	data->player.offset = vertical_off;
	data->player.face = WE * (angle > 90 && angle < 270) \
	+ EA * !(angle > 90 && angle < 270);
	if (angle > 90 && angle < 270)
		data->player.offset = MAP_SIZE - data->player.offset - 1;
	return (vertical_len);
}
