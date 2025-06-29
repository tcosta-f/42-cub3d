/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:22:38 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/06/29 11:33:55 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	cc;

	cc = (char) c;
	p = (char *) s;
	while (*p != 0)
	{
		if (*p == cc)
			return (p);
		p++;
	}
	if (cc == 0)
		return (p);
	return (NULL);
}
