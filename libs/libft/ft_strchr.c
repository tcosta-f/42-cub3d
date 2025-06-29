/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:22:38 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/06/29 10:22:43 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strchr(const char *str, int c)
{
	int				i;
	char			*ptr;
	unsigned char	equal_c;

	i = 0;
	ptr = NULL;
	equal_c = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == equal_c)
		{
			ptr = (char *)&str[i];
			return (ptr);
		}
		i++;
	}
	if (equal_c == '\0')
		return (ptr = (char *)&str[i]);
	return (ptr);
} */

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
