#ifndef FT_LIST_H
# define FT_LIST_H

# include <sys/stat.h> 
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../libft/libft.h"
# include <errno.h>  
typedef struct t_lst
{
//	char			*kiwi;
	struct stat		buf;
	struct passwd	*uid;
	struct group	*bite;
	char			*merde;
	struct t_lst	*next;
}				s_lst;

int		ft_l(struct t_lst *lst, struct dirent *zob);
int		ft_path(char *ar);

#endif
