/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:08:59 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/24 18:09:05 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

char fun1(char c)
{
	printf("%c\n", c);
	return (c);
}

char fun2(unsigned int i, char c)
{
	printf("%u", i);
	printf("%c\n", c);
	return (c);
}

t_list	*list_fun(t_list *list)
{
//	printf("Test_listik\n");
	return (list);
}

int main(void)
{


/*                 MEMCMP
    const char str1[42] = "something written here";
    const char str2[42] = "something zritten";
    int i = memcmp(str1, str2, 11);
    printf("%i\n", i);
    int j = ft_memcmp(str1, str2, 11);
    printf("%i\n", j);
    */

/*                 MEMCHR

	const char src[50] = "something written here";
	char *ret;
	ret = memchr(src, 101, 200);
	printf("After memchr ret = %s\n", ret);

	const char src1[50] = "something written here";
	char *ret1;
	ret1 = ft_memchr(src1, 101, 200);
	printf("After memchr ret = %s\n", ret1);

*/

/*                  MEMMOVE

	char src[50] = "0123456789";
	char *dst;
	printf("Before memmove src = %s\n", src);
	dst = memmove(&src[2], &src[8], 30);
	printf("After memmove src = %s\n", src);
	printf("After memmove dst = %s\n", dst);
	printf("%c\n", src[6]);

	char src1[50] = "0123456789";
	char *dst1;
	printf("Before memmove src1 = %s\n", src1);
	dst1 = ft_memmove(&src1[2], &src1[8], 30);
	printf("After memmove src1 = %s\n", src1);
	printf("After memmove dst1 = %s\n", dst1);
	printf("%c\n", src1[6]);
 */

/*                 MEMCCPY

  	const char src[50] = "something written here";
	char dest[50];
	char *ret;
	strcpy(dest,"Heloooo!!");
	printf("Before memccpy dest = %s\n", dest);
	ret = memccpy(dest, src, 101, strlen(src)+1);
	printf("After memccpy dest = %s\n", dest);
	printf("After memccpy ret = %s\n", ret);

	const char src1[50] = "something written here";
	char dest1[50];
	char *ret1;
	strcpy(dest1,"Heloooo!!");
	printf("Before memccpy dest = %s\n", dest1);
	ret1 = ft_memccpy(dest1, src1, 101, strlen(src1)+1);
	printf("After memccpy dest = %s\n", dest1);
	printf("After memccpy ret = %s\n", ret1);


 */


/*                   MEMCPY

	const char src[50] = "something written here";
	char dest[50];
	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);

	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);



 	int i = 0;
	const int src[50] = {2, 3, 4};
	int dest[50] = {1, 2};
	printf("Before memcpy dest = ");
	while (dest[i]){
		printf("%i ", dest[i]);
		i++;
	}
	printf("\n");
	i = 0;
	memcpy(dest, src, 1);
	printf("After memcpy dest = ");
	while (dest[i]){
		printf("%i ", dest[i]);
		i++;
	}
	printf("\n");
	i = 0;

	const int src1[50] = {2, 3, 4};
	int dest1[50] = {1, 2};
	printf("Before memcpy dest = ");
	while (dest1[i]){
		printf("%i ", dest1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_memcpy(dest1, src1, 1);
	printf("After memcpy dest = ");
	while (dest1[i]){
		printf("%i ", dest1[i]);
		i++;
	}
	printf("\n");
	i = 0;
 */


/*	                     BZERO
  	char str[50];

	strcpy(str,"This is string.h library function");
	printf("%s\n", str);

	bzero(str, 3);
	printf("%c\n", str[2]);

	strcpy(str,"This is string.h library function");
	printf("%s\n", str);

	ft_bzero(str, 3);
	printf("%c\n", str[2]); */



/*                       MEMSET
	char str[50];

	strcpy(str,"This is string.h library function");
	printf("%s\n", str);

	memset(str, 333, 3);
	printf("%s\n", str);

	strcpy(str,"This is string.h library function");
	printf("%s\n", str);

	ft_memset(str, 333, 3);
	printf("%s\n", str); */


//                       STRINGS!!!!!!!!!!!!
// --------------------------------
//	int		i;
//	char	*str = "Deleted";
//	char	*str1 = "ted";
//	char	*str2;
//	int i = ft_strlen(str);
//	int i = ft_strcmp(str, str2);
//	int j = strcmp(str, str2);
//	printf("%i\n", ft_strncmp("hell", "hello", 4));
//	printf("%i\n", strncmp("hell", "hello", 4));
//	char *str3 = ft_strdup(str);
//	char *str4 = strdup(str);
//	str2 = ft_memalloc(40);
//	ft_strcpy(str2, str1);
//	ft_strncpy(str2, str1, 2);
//	str2 = ft_strcat(str2, str1);
//	str2 = ft_strcat(str2, str);
//	str2 = ft_strncat(str2, str1, 4);
//	str2 = ft_strncat(str2, str, 4);
//	i = ft_strlcat(str2, str1, 40);
//	i = ft_strlcat(str2, str, 5);
//	str2 = ft_strstr(str, str1);
//	str2 = ft_strnstr(str, str1, 5);
//	printf("%s\n", str2);
//	str2 = strnstr(str, str1, 5);
//	str2 = ft_strchr(str, 357);
//	printf("%s\n", str2);
//	str2 = strchr(str, 357);
//	str2 = ft_strrchr(str, 256);
//	printf("%s\n", str2);
//	str2 = strrchr(str, 256);
//	i = ft_atoi("  - 22");
//	printf("%i\n", i);
//	i = atoi("  - 22");
//	i = ft_isalpha(97);
//	printf("%i\n", i);
//	i = isalpha(97);
//	printf("%i\n", i);
//	printf("%i\n", isdigit(306));
//	printf("%i\n", ft_isdigit(306));
//	printf("%i\n", isalpha(333));
//	printf("%i\n", ft_isalpha(333));
//	printf("%i\n", isalnum(306));
//	printf("%i\n", ft_isalnum(306));
//	printf("%i\n", isascii(-2));
//	printf("%i\n", ft_isascii(-2));
//	printf("%i\n", isprint(32));
//	printf("%i\n", ft_isprint(32));
//	printf("%c\n", toupper(-70));
//	printf("%c\n", ft_toupper(-70));
//	printf("%c\n", tolower(110));
//	printf("%c\n", ft_tolower(110));


/*                            PART 2

	int		i;
	const char	*str = "Deleted";
	char		*str1 = "ted";
	char		*str2;
	str2 = ft_memalloc(40);
	ft_strcpy(str2, str);
	printf("%s\n", str2);
	ft_memdel((void**)&str2);
	printf("%s\n", str2);
*/

//	printf("%s\n", ft_strmap("Hello", fun1));
//	printf("%s\n", ft_strmapi("Hello", fun2));
//	printf("%i\n", ft_strequ("helo", "hello"));
//	printf("%i\n", ft_strnequ("hell", "hello", 5));
//	printf("%s\n", ft_strsub("hell0", 6, 6));
//	printf("%s\n", ft_strjoin("hell0", " world"));
//	printf("%s\n", ft_strtrim("  \t hell0  \n  \t"));
/*	char **split = ft_strsplit("        ", ' ');
	while (*split)
	{
		printf("%s\n", *split);
		split++;
	} */
//	printf("%s\n", ft_itoa(-2147483648));
//	ft_putnbr(-2147483648);
//	ft_putstr(str);

/*                            LISTS
	char *c = "Hello ";
	char *b = "freak ";
	char *a = "bitches";

	t_list *listik1 = ft_lstnew(c, 8);
	t_list *listik2 = ft_lstnew(b, 8);
	t_list *listik3 = ft_lstnew(a, 8);

	ft_lstadd(&listik3, listik2);
	ft_lstadd(&listik3, listik1);
	printf("Listik3 content is: %s\n", listik3->content);

	t_list *listik_map = ft_lstmap(listik3, list_fun);
	printf("Listik_map content is: %s\n", listik_map->content); */


//                            ADDITIONAL
/*
	char *str = "Hello freak bitches";
	char *str3 = ft_strndup(str, 9);
	printf("%s\n", str3);
	char *str4 = strndup(str, 9);
	printf("%s\n", str4); */

//	char *str = "???hgfkgjh???fdf????";
//	printf("%s\n", ft_strtrimc(str, '?'));

/*
	char *str1 = "Hello freak bitches";
	char *str2 = ft_memalloc(40);
	char *str3 = ft_memalloc(40);
	printf("%zu\n", ft_strlcpy(str2, str1, -2));
	printf("%lu\n", strlcpy(str3, str1, -2));
	printf("%s\n", str2);
	printf("%s\n", str3); */

/*	char *dest1;
	char *dest2;

	dest1 = (char *)malloc(sizeof(*dest1) * 15);
	memset(dest1, 0, 15);
	memset(dest1, 'r', 6);

	dest2 = (char *)malloc(sizeof(*dest2) * 15);
	memset(dest2, 0, 15);
	memset(dest2, 'r', 6);

	dest1[11] = 'a';
	printf("%zu\n",strlcat(dest1, "lorem ipsum", 15));
	printf("%s\n", dest1);

	dest2[11] = 'a';
	printf("%zu\n",ft_strlcat(dest2, "lorem ipsum", 15));
	printf("%s\n", dest2);  */

	char *ab = ft_strnew(10);
	char *bc = ft_strnew(10);
	ab = "Hello";
	bc = " world!";
	char *res = ft_strjoin(ab, bc);

	printf("%s\n", ab);
	printf("%s\n", bc);
	printf("%s\n", res);


	return (0);
}
