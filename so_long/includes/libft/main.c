#include "libft.h"

static char plus_one(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

static void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int main()
{
	char s[] = "-124";
	printf("\033[1;33m===== ATOI =====\033[0m\n");
	printf("String: %s\nValue atoi: %d\n", s, ft_atoi(s));

	printf("\n\n");

	printf("\033[1;33m===== BZERO =====\033[0m\n");
	char str[6] = "Hello";
	printf("Before: %s\n", str);
	ft_bzero(str, 5);
	printf("After: %s", str);

	printf("\n\n");

	printf("\033[1;33m===== CALLOC =====\033[0m\n");
	int i_calloc = 0;
	int *calloc = ft_calloc(10, sizeof(int));

	while (i_calloc < 10)
	{
		printf("s[%d] = %d\n", i_calloc, calloc[i_calloc]);
		i_calloc++;
	}
	free(calloc);

	printf("\n\n");

	printf("\033[1;33m===== ISALNUM =====\033[0m\n");
	char c_isalnum = '1';

	if(ft_isalnum(c_isalnum) == 1)
		printf("'%c' is a alphanumeric character", c_isalnum);
	else
		printf("'%c' is \033[1mNOT\033[0m a alphanumeric character", c_isalnum);


	printf("\n\n");

	printf("\033[1;33m===== ISALPHA =====\033[0m\n");
	char c_isalpha = '1';

	if(ft_isalpha(c_isalpha) == 1)
		printf("The character '%c' is alphabetic", c_isalpha);
	else 
		printf("The character '%c' is \033[1mNOT\033[0m alphabetic", c_isalpha);


	printf("\n\n");

	printf("\033[1;33m===== ISASCII =====\033[0m\n");
	char c_isascii = 'a';
	if(ft_isascii(c_isascii) == 1)
		printf("'%c' is in the ascii table", c_isascii);
	else
		printf("'%c' is \033[1mNOT\033[0m on ascii table", c_isascii);


	printf("\n\n");

	printf("\033[1;33m===== ISDIGIT =====\033[0m\n");
	char c_isdigit = '0';

	if (ft_isdigit(c_isdigit) == 1)
		printf("'%c' is a digit", c_isdigit);
	else
		printf("'%c' is not a digit", c_isdigit);


	printf("\n\n");

	printf("\033[1;33m===== ISPRINT =====\033[0m\n");
	char  c_isprint = '\t';

	if(ft_isprint(c_isprint) == 1)
		printf("'%c' is a printable character", c_isprint);
	else
		printf("'%c' is \033[1mNOT\033[0m a printable character", c_isprint);


	printf("\n\n");

	printf("\033[1;33m===== ITOA =====\033[0m\n");
	int n_itoa = -2147483648;
	printf("The number before itoa: %d\n", n_itoa);
	printf("The string after itoa: %s", ft_itoa(n_itoa));

	printf("\n\n");

	printf("\033[1;33m===== MEMCHR =====\033[0m\n");
	char s_memchr[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaazaaaaaaaaaabbbbbbbbcc";
	char c_memchr = 'z';

	if (ft_memchr(s_memchr, c_memchr, sizeof(s_memchr)))
		printf("Found the first occurence of '%c' in the string.\n", c_memchr);
	else
		printf("Didn't found '%c' in the string.\n", c_memchr);


	printf("\n\n");

	printf("\033[1;33m===== MEMCMP =====\033[0m\n");
	char s1_memcmp[] = {1, 2, 3, 4, 5};
	char s2_memcmp[] = {1, 2, 5, 4, 5};

	if (ft_memcmp(s1_memcmp, s2_memcmp, sizeof(s1_memcmp)) == 0)
		printf("The memory areas s1 and s2 are equal\n");
	if (ft_memcmp(s1_memcmp, s2_memcmp, sizeof(s1_memcmp)) > 0)
		printf("The memory area s1 is greater than s2\n");
	if (ft_memcmp(s1_memcmp, s2_memcmp, sizeof(s1_memcmp)) < 0)
		printf("The memory area s1 is less than s2\n");

	printf("\n\n");

	printf("\033[1;33m===== MEMCPY =====\033[0m\n");
	char src_memcpy[6] = "hello";
	char dest_memcpy[10] = "ola"; //dest_memcpy as to have more memory allocated or overflow
	printf("Before: %s\n", dest_memcpy);
	ft_memcpy(dest_memcpy, src_memcpy, 5);
	dest_memcpy[5] = '\0';
	printf("After: %s", dest_memcpy);

	printf("\n\n");

	printf("\033[1;33m===== MEMMOVE =====\033[0m\n");
	char src_memmove[] = "12345678910";
	printf("Before: %s\n", src_memmove);
	ft_memmove(src_memmove + 2, src_memmove, 5);
	printf("After: %s\n", src_memmove);

	printf("\n\n");

	printf("\033[1;33m===== MEMSET =====\033[0m\n");
	unsigned char str_memset[] = "Ola tudo?";
	ft_memset(str_memset, 'A', sizeof(str_memset));
	str_memset[9] = '\0';
	printf("%s", str_memset);

	printf("\n\n");

	printf("\033[1;33m===== PUTCHAR_FD =====\033[0m\n");
	ft_putchar_fd('W', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('i', 1);
	ft_putchar_fd('t', 1);
	ft_putchar_fd('e', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('E', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);

	printf("\n\n");

	printf("\033[1;33m===== PUTSTR_FD =====\033[0m\n");
	ft_putstr_fd("Terminal", 1);
	ft_putstr_fd("Error!", 2);

	printf("\n\n");

	printf("\033[1;33m===== PUTNBR_FD =====\033[0m\n");
	ft_putnbr_fd(124, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(50614, 2);

	printf("\n\n");

	printf("\033[1;33m===== PUTENDL_FD =====\033[0m\n");
	ft_putendl_fd("Terminal", 1);
	ft_putendl_fd("Error!", 2);

	printf("\n\n");

	printf("\033[1;33m===== SPLIT =====\033[0m\n");
	char **result_split;
	int i_split = 0;
	char *str_split = "ola tudo bem 42";
	char delimiter_split = ' ';

	result_split = ft_split(str_split, delimiter_split);

	if (!result_split)
		printf("Erro: ft_split retornou NULL\n");

	printf("Resultado de ft_split(\"%s\", '%c'):\n", str_split, delimiter_split);
	while (result_split[i_split])
	{
		printf("Palavra %d: %s\n", i_split, result_split[i_split]);
		i_split++;
	}
	free(result_split);

	printf("\n\n");

	printf("\033[1;33m===== STRCHR =====\033[0m\n");
	char s_strchr[] = "ola como vai?";
	char c_strchr = 'z';
	if (ft_strchr(s_strchr, c_strchr))
		printf("Found the first occurence of '%c' in the string: %s\n", c_strchr, s_strchr);
	else
		printf("Didn't found '%c' in the string: '%s'\n", c_strchr, s_strchr);


	printf("\n\n");

	printf("\033[1;33m===== STRDUP =====\033[0m\n");
	char *s_strdup = "ola tudo bem contigo??";
	printf("New duplicated string: %s", ft_strdup(s_strdup));

	printf("\n\n");

	printf("\033[1;33m===== STRITERI =====\033[0m\n");
	char s_striteri[] = "Ola tudo?";
	printf("Before: '%s'\n", s_striteri);
	ft_striteri(s_striteri, to_upper);
	printf("After: '%s'\n", s_striteri);

	printf("\n\n");

	printf("\033[1;33m===== STRJOIN =====\033[0m\n");
	char *s1_strjoin = "ola ";
	char *s2_strjoin = "tudo bem?";
	printf("Joined string: %s\n", ft_strjoin(s1_strjoin, s2_strjoin));

	printf("\n\n");

	printf("\033[1;33m===== STRLCAT =====\033[0m\n");
	char dest_strcat[20] = "Hello, ";
	char src_strcat[] = "World.";  //dest_strcat has to have enough space for src_strcat
	printf("Dest before: %s\n", dest_strcat);
	size_t c_strlcat = ft_strlcat(dest_strcat, src_strcat, 20); //size has to be greater than the length of dest_strcat or else it stack overflows
	printf("Dest after and length: %s %zu\n", dest_strcat, c_strlcat);

	printf("\n\n");

	printf("\033[1;33m===== STRLCPY =====\033[0m\n");
	char dest_strlcpy[20];
	char src_strlcpy[] = "Hello, world";
	printf("Dest string before: %s\n", dest_strlcpy);  
	size_t c_strlcpy = ft_strlcpy(dest_strlcpy, src_strlcpy, sizeof(dest_strlcpy));
	printf("Dest string after and length: %s %zu\n", dest_strlcpy, c_strlcpy);

	printf("\n\n");

	printf("\033[1;33m===== STRLEN =====\033[0m\n");
	const char *str_strlen = "awfwaduabdwaipdwaoudhbkjwajdwaibjhdkbwajoohbj";
	size_t length_strlen = ft_strlen(str_strlen);
	printf("The length of the string: '%s' is: %zu", str_strlen, length_strlen);

	printf("\n\n");

	printf("\033[1;33m===== STRMAPI =====\033[0m\n");
	char *s_strmapi = "Ola tudo?";
	printf("Before: '%s'\n", s_strmapi);
	printf("After: '%s'\n", ft_strmapi(s_strmapi, plus_one));

	printf("\n\n");

	printf("\033[1;33m===== STRNCMP =====\033[0m\n");
	char s1_strncmp[] = "hello";
	char s2_strncmp[] = "hel";
	if (ft_strncmp(s1_strncmp, s2_strncmp, sizeof(s1_strncmp)) > 0)
		printf("s1 string: '%s' is bigger than s2 string: '%s'\n", s1_strncmp, s2_strncmp);

	if (ft_strncmp(s1_strncmp, s2_strncmp, sizeof(s1_strncmp)) < 0)
		printf("s2 string: '%s' is bigger than s1 string: '%s'\n", s2_strncmp, s1_strncmp);

	if (ft_strncmp(s1_strncmp, s2_strncmp, sizeof(s1_strncmp)) == 0)
		printf("The strings '%s' and '%s' are equal.\n", s1_strncmp, s2_strncmp);


	printf("\n\n");

	printf("\033[1;33m===== STRNSTR =====\033[0m\n");
	char haystack[] = "O2919191561------------------ydtrs como  tdxrcyv";
	char needle[] = "como";

	char *found = ft_strnstr(haystack, needle, 44);
	printf("String: '%s' and substring: '%s'\n", haystack, needle);

	if (found != NULL)
		printf("Part found in haystack: %s\n", found);

	else
		printf("Substring not found!\n");


	printf("\n\n");

	printf("\033[1;33m===== STRRCHR =====\033[0m\n");
	char s_strrchr[] = "aaaaeeeeeaaaaaaaaaaaaaaaaaeeeebeeebbbbbbeeeeeecccccccccc";
	char c_strrchr = 'e';
	if (ft_strrchr(s_strrchr, c_strrchr))
		printf("Found the last occurrence of '%c' in the string: '%s'\n", c_strrchr, s_strrchr);
	else
		printf("Didn't found '%c' in the string: '%s'\n", c_strrchr, s_strrchr);


	printf("\n\n");

	printf("\033[1;33m===== STRTRIM =====\033[0m\n");
	char *str_strtrim = "---?----        Ola tudo b?em ------?----";
	char *set_strtrim = "- ?";
	printf("Normal string: '%s'\nTrimmed string: '%s'\n", str_strtrim, ft_strtrim(str_strtrim, set_strtrim));

	printf("\n\n");

	printf("\033[1;33m===== SUBSTR =====\033[0m\n");
	char *s_substr = "Ola como estas?";
	printf("String: '%s'\nSubstring: '%s'\n", s_substr, ft_substr(s_substr, 4, 4));

	printf("\n\n");

	printf("\033[1;33m===== TOLOWER =====\033[0m\n");
	char c_tolower = 'A';
	printf("Before: %c\n", c_tolower);
	printf("After: %c", ft_tolower(c_tolower));

	printf("\n\n");

	printf("\033[1;33m===== TOUPPER =====\033[0m\n");
	char c_toupper = 'a';
	printf("Before: %c\n", c_toupper);
	printf("After: %c", ft_toupper(c_toupper));
}