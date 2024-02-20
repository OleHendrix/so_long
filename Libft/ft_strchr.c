/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:49:37 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:00:50 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (&((char *)s)[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (&((char *)s)[i]);
	}
	return (0);
}

// int main(void)
// {
//     const char s[] = "Whatsapp";
//     char *ptr = ft_strchr(s, 's');
//     char *ptr2 = strchr(s, 's');

//     printf("%ld\n", ptr - s);
//     printf("%ld", ptr2 - s);
// }