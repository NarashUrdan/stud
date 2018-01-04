#include "ft_ls.h"

void	ft_write_lst(struct dirent *lst)
{
	while (lst)
	{
		ft_putendl(lst->d_name);
		lst = lst->next;
	}
}

int	ft_path(char *ar)
{
	DIR	*fd;
	struct dirent *lst;

	fd = opendir(".");
	while ((lst = readdir(fd)) != NULL)
		lst = lst->next;
	
	ft_write_lst(lst);
	return (0);
}
