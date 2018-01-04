#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
	struct stat buf;
	struct passwd *uid;
	struct group *bite;
	char *merde;

	stat(argv[1], &buf);
	if (buf.st_mode & S_IFMT)
	{
		if (buf.st_mode & S_IFDIR)
			printf ("repertoire\n");
		else if (buf.st_mode & S_IFREG)
			printf ("fichier ordinaire\n");
	}
	printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
	printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
	printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
	printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
	printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
	printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
	printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
	printf( (buf.st_mode & S_IROTH) ? "r" : "-");
	printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
	printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
	printf("\t");
	printf("%u", buf.st_nlink);
	printf("\t");
	 uid = getpwuid(buf.st_uid);
	 bite = getgrgid(buf.st_gid);
	printf("%s  %s  ", uid->pw_name, bite->gr_name);
	printf("%lld  ", buf.st_size);
	merde = ctime(&buf.st_ctime);
	merde = ft_strsub(merde, 3, ft_strlen(merde) - 10);
	printf("%s  ", merde);
	printf(" %s\n", argv[1]);
	return (0);
}
