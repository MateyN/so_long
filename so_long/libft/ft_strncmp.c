/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:17:20 by mnikolov          #+#    #+#             */
/*   Updated: 2021/10/26 14:03:14 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	unsigned char	str1;
	unsigned char	str2;

	while (n-- > 0)
	{
		str1 = (unsigned char) *s1++;
		str2 = (unsigned char) *s2++;
		if (str1 != str2)
			return (str1 - str2);
		if (str1 == '\0')
			return (0);
	}
	return (0);
}
