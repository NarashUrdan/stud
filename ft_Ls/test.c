#include <stdlib.h>

char	**merge(char **s1, char **s2, int l1, int l2)
{
	char **str;
	int		i;
		int 	j;
		int	k;

		i = 0;
		j = 0;
		k = 0;
	str = (char **)malloc(sizeof(char *) * ((l1 + l2) + 1));
	str [l1 + l2] = NULL;
	while (s1[i] && s2[i])
	{
		if (ft_strcmp(s1[i], s2[i]) < 0)
			str[k++] = s1[i++];
		else
			str[k++] = s2[j++];
	}
	while (i < l1)
		str[k++] = s1[i++];
	while (j < l2)
		str[k++] = s2[j++];
	str[k] = NULL;
	return (str);
}

char **merge_sort(char **str, int l)
{
	char **s1;
	char **s2;
	int		l1;
	int		l2;

	l1 = l/2;
	if (l % 2 != 0)
		l2 = l/ 2 + 1;
	else
		l2 = l1;
	if (l < 2)
		return (str);
	s1 = (char **)malloc(sizeof(char *) * (l1 + 1));
	s2 = (char **)malloc(sizeof(char *) * (l2 + 1));
	while (l1--)
		s1[l1] = str[l1];
	while (l2--)
		s2[l2] = str[l2 +l1];
	printf("\n%s\n", s2[0]);
	l1 = l/2;
	if (l % 2 != 0)
		l2 = l/ 2 + 1;
	else
		l2 = l1;
	printf("%d", l2);
		s1[l1] = NULL;
		s2[l2] = NULL;
	s1 = merge_sort(s1, l1);

	s2 = merge_sort(s2, l2);
	str = merge(s1, s2, l1, l2);
	free(s1);
	free(s2);
	return (str);	
}

int	main(int argc, char **argv)
{
	char **str;
	str = merge_sort(argv, argc);
	ft_print_words_tables(str);
	return (0);
}
