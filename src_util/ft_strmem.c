/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:46 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:47 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_strdup(char **dst, char *src)
{
	size_t	len;

	len = ft_strlen(src);
	if (ft_calloc((void **)dst, sizeof(char), len + 1)
		|| ft_memcpy((void *)*dst, (void *)src, len))
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len_str;

	i = 0;
	j = 0;
	len_str = ft_strlen(s);
	if (start > len_str)
		len = 0;
	else if (len >= len_str)
		len = len_str - start;
	if (ft_calloc((void **)&res, sizeof(char), len + 1))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			res[j++] = s[i];
		i++;
	}
	return (res);
}
