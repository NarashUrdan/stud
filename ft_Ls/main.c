#include "ft_ls.h"

int	ft_att(char **argv, char *ar)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			return (1);
		j = 1;	
		while (argv[i][j] !='\0')
		{
			if (argv[i][j] == '-')
				return (1);
			ar[k++] = argv[i][j];
			j++;
		}
		i++;
	}
	while (k < 6)
	{
		ar[k] = '\0';
		k++;
	}
	return (0);
}

int	check_error(char *ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		if (ar[i] != 't' && ar[i] !='l' && ar[i] != 'a' && ar[i] != 'r' && ar[i] !='t')
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char	ar[6];
	int	i;

	i = 0;
	if (argc > 1)
	{
		if (ft_att(argv, ar) == 1)
		{
			ft_putendl("error");
			return (0);
		}
		if (check_error(ar) == 1)
		{
			ft_putendl("error");
			return (0);
		}
	}
	if (ft_path(ar) == 1)
	{
		ft_putendl("error");
		return (0);
	}
	return (0);
}
