/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:18:57 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/13 14:12:02 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	int		j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		dst_len = size;
	if (dst_len == size)
		return (dst_len + src_len);
	j = 0;
	while (src[j] && (j + dst_len) < size - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dst1[20] = "Hello ";
// 	char	dst2[20] = "Hello ";
// 	char	dst3[20] = "";
// 	char	dst4[20] = "";
// 	char	dst5[20] = "Hello";
// 	char	dst6[20] = "Hello";
// 	char	dst7[20] = "Hello";
// 	char	dst8[20] = "Hello";
// 	char	dst11[20] = "Hello";
// 	char	dst12[20] = "Hello";
// 	char	dst13[20] = "Hello";
// 	char	dst14[20] = "Hello";
// 	char	dst15[20] = "Hello";
// 	char	dst16[20] = "Hello";
// 	char	dst9[20] = "Hello";
// 	char	dst10[20] = "Hello";

// 	// Test 1: Normal concatenation
// 	printf("\nTest 1: Normal concatenation\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst1, "World!", 20), dst1);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst2, "World!", 20), dst2);
// 	// Test 2: Empty destination
// 	printf("\nTest 2: Empty destination\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst3, "Hello!", 20), dst3);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst4, "Hello!", 20), dst4);
// 	// Test 3: Empty source
// 	printf("\nTest 3: Empty source\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst5, "", 20), dst5);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst6, "", 20), dst6);
// 	// Test 4: Size smaller than destination length
// 	printf("\nTest 4: Size smaller than destination length\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst7, "World!", 3), dst7);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst8, "World!", 3), dst8);
// 	// Test 4a: Size equal to destination length
// 	printf("\nTest 4a: Size equal to destination length\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst11, "World!", 5), dst11);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst12, "World!", 5), dst12);
// 	// Test 4b: Size one more than destination length
// 	printf("\nTest 4b: Size one more than destination length\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst13, "World!", 6), dst13);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst14, "World!", 6), dst14);
// 	// Test 4c: Size zero
// 	printf("\nTest 4c: Size zero\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst15, "World!", 0), dst15);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst16, "World!", 0), dst16);
// 	// Test 5: Size exactly fits concatenation
// 	printf("\nTest 5: Size exactly fits concatenation\n");
// 	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dst9, "World", 11), dst9);
// 	printf("strlcat   : %zu, %s\n", strlcat(dst10, "World", 11), dst10);
// 	return (0);
// }
