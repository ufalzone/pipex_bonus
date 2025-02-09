/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:26:56 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 18:01:05 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *str)
{
	int	resultat;
	int	signe;

	resultat = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultat = resultat * 10 + (*str - '0');
		str++;
	}
	return (resultat * signe);
}

// // test_ft_atoi.c
// #include <stdio.h>

// void test_ft_atoi() {
//     // Test case 1: Basic positive number
//     printf("Test 1: %d\n", ft_atoi("123") == 123);

//     // Test case 2: Basic negative number
//     printf("Test 2: %d\n", ft_atoi("-123") == -123);

//     // Test case 3: Number with leading spaces
//     printf("Test 3: %d\n", ft_atoi("   456") == 456);

//     // Test case 4: Number with leading tabs
//     printf("Test 4: %d\n", ft_atoi("\t\t789") == 789);

//     // Test case 5: Number with leading newlines
//     printf("Test 5: %d\n", ft_atoi("\n\n101112") == 101112);

//     // Test case 6: Number with leading plus sign
//     printf("Test 6: %d\n", ft_atoi("+314") == 314);

//     // Test case 7: Number with mixed whitespace characters
//     printf("Test 7: %d\n", ft_atoi(" \t\n\r\v\f2021") == 2021);

//     // Test case 8: Zero
//     printf("Test 8: %d\n", ft_atoi("0") == 0);

//     // Test case 9: Invalid input (non-numeric characters)
//     printf("Test 9: %d\n", ft_atoi("abc") == 0);

//     // Test case 10: Number with trailing non-numeric characters
//     printf("Test 10: %d\n", ft_atoi("123abc") == 123);
// }

// int main() {
//     test_ft_atoi();
//     return (0);
// }
