/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 07:52:44 by sahrandr          #+#    #+#             */
/*   Updated: 2026/02/14 09:19:36 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main()
{
	// char	str[] = "123abc";
	// int		num = ft_atoi(str);
	// printf("%d\n", num);

	// int n = 5;
    // int *arr = (int*) ft_calloc(n, sizeof(int));
    // if (arr == NULL) {
    //     printf("Memory allocation failed!\n");
    //     return 1;
    // }
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // free(arr);
    // arr = NULL;
	
	// ft_bzero(str, sizeof(str));
	// printf(" \n");
	// int *ptr = (int *)ft_calloc(5, sizeof(int));
    // if (ptr == NULL) {
    //     printf("Memory allocation failed.\n");
    //     return 1;
    // for (int i = 0; i < 5; i++) {
    //     printf("%d ", ptr[i]);
    // }
    // printf("\n");
    // free(ptr);
	
    // int num = 12345;
    // char str[20];
    // ft_itoa(num, str, 10);
    // printf("Integer: %d\n", num);
    // printf("String: %s\n", str);
	// char text[] = "Hello, World!";
    // char *result = (char *)ft_memchr(text, 'W', strlen(text));
    // if (result != NULL) {
    //     printf("Character 'W' found at position %ld\n", result - text + 1);
    // } else {
    //     printf("Character 'W' not found\n");
    // }
	
	// char	s1[] = "Hello World";
	// char	s2[20];
	// ft_memcpy(s1, s2, 10);
	// printf("%s\n", s1);
	// printf("%s\n", s2);

	// char	str[] = "ABCDEFGH";
	// ft_memmove(str + 1, str, 4);
	// printf("%s\n", str);
	
	// char str[10] = "Hello World";
	// ft_memset(str, 'A', 7);
	// printf("%s\n", str);

	// char	s1[] = "ABCD";
	// char	s2[] = "ASCD";
	// int	r = ft_memcmp(s1, s2, 2);
	// printf("%d\n", r);

	// char source[] = "Hello, World!";
    // char destination[50];
    // ft_strcpy(destination, source);
    // printf("Copied string: %s\n", destination);

	// char dest[256] = "Hello, ";
    // const char *src = "world!";
    // size_t size = sizeof(dest);
    // size_t result = ft_strlcat(dest, src, size);
    // printf("Concatenated string: %s\n", dest);
    // printf("Total length: %zu\n", result);
    // if (result >= size) {
    //     printf("String was truncated.\n");
    // } else {
    //     printf("String was fully copied.\n");
    // }
		
	// char	str[22];
	// ft_strcpy(str, "Hello World");
	// printf("%s\n", str);

    // const char* str = "GeeksforGeeks";
    // char ch = 's';
    // const char* result = ft_strchr(str, ch);
    // if (result != NULL) {
    //     printf("Character '%c' found at position: %ld\n",
    //            ch, result - str);
    // }
    // else {
    //     printf("Character '%c' not found.\n", ch);
    // }

	// char str[] = "GeeksforGeeks";
    // char chr = 'k';
    // char* ptr = ft_strrchr(str, chr);
    // if (ptr) {
    //     printf("Last occurrence of %c in %s is at index %d",
    //            chr, str, ptr - str);
    // }
    // else {
    //     printf("%c is not present in %s ", chr, str);
    // }

	// char source[] = "GeeksForGeeks";
    // char* target = ft_strdup(source); 
    // printf("%s", target);

// 	void changer_si_pair(unsigned int i, char *c)
// {
//     if (i % 2 == 0) // Si l'index est pair (0, 2, 4...)
//     {
//         if (*c >= 'a' && *c <= 'z')
//             *c = *c - 32; // On passe en majuscule
//     }
// }

// int main()
// {
//     // On crée une chaîne modifiable (pas de "const")
//     char texte[] = "abcdefghi";

//     printf("Avant : %s\n", texte);

//     // On lance ft_striteri sur notre texte avec notre fonction de test
//     ft_striteri(texte, changer_si_pair);

//     printf("Après  : %s\n", texte);

// char **resultat;
//     int i;

//     printf("--- Test 1 : Séparation par espace ---\n");
//     resultat = ft_split("Hello world this is 42", ' ');
    
//     i = 0;
//     while (resultat[i] != NULL)
//     {
//         printf("Mot %d : [%s]\n", i, resultat[i]);
//         free(resultat[i]); // On libère chaque mot
//         i++;
//     }
//     free(resultat); // On libère le tableau final

//     printf("\n--- Test 2 : Séparation par virgule ---\n");
//     resultat = ft_split("un,deux,trois,,quatre", ',');
    
//     i = 0;
//     while (resultat[i] != NULL)
//     {
//         printf("Mot %d : [%s]\n", i, resultat[i]);
//         free(resultat[i]);
//         i++;
//     }
//     free(resultat);

//  char *result;

//     printf("--- Test 1 : Standard ---\n");
//     result = ft_substr("Hello World", 6, 5);
//     if (result)
//     {
//         printf("Attendu : 'World'\n");
//         printf("Résultat : '%s'\n", result);
//         free(result);
//     }
//     printf("\n--- Test 2 : Start trop grand ---\n");
//     result = ft_substr("abc", 10, 5);
//     if (result)
//     {
//         printf("Attendu : '' (vide)\n");
//         printf("Résultat : '%s'\n", result);
//         free(result);
//     }
//     printf("\n--- Test 3 : Len trop grand ---\n");
//     result = ft_substr("Hello", 1, 100);
//     if (result)
//     {
//         printf("Attendu : 'ello'\n");
//         printf("Résultat : '%s'\n", result);
//         free(result);
//     }
//     printf("\n--- Test 4 : Source vide ---\n");
//     result = ft_substr("", 0, 5);
//     if (result)
//     {
//         printf("Attendu : '' (vide)\n");
//         printf("Résultat : '%s'\n", result);
//         free(result);
//     }

// int main()
// {
//     char *result;

//     // Test 1 : Concaténation standard
//     printf("--- Test 1 : Standard ---\n");
//     result = ft_strjoin("Bonjour ", "le monde !");
//     if (result)
//     {
//         printf("Résultat : %s\n", result);
//         free(result); // Important de libérer la mémoire allouée par ft_strjoin
//     }

//     // Test 2 : Avec une chaîne vide au début
//     printf("\n--- Test 2 : s1 vide ---\n");
//     result = ft_strjoin("", "Seul s2");
//     if (result)
//     {
//         printf("Résultat : %s\n", result);
//         free(result);
//     }

//     // Test 3 : Avec une chaîne vide à la fin
//     printf("\n--- Test 3 : s2 vide ---\n");
//     result = ft_strjoin("Seul s1", "");
//     if (result)
//     {
//         printf("Résultat : %s\n", result);
//         free(result);
//     }

//     return (0);
// }

	return (0);
}