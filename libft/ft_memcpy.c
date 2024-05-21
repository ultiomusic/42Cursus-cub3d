/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:50:19 by beeligul          #+#    #+#             */
/*   Updated: 2024/05/21 15:42:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if ((!dst && !src) || !len)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
