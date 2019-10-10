#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		is1;
	int		is2;
	char	*str;

	if (s1 && s2)
	{
		is1 = ft_strlen(s1);
		is2 = ft_strlen(s2);
		if (!(str = (char *)malloc((sizeof(char) * (is1 + is2)) + 1)))
			return (NULL);
		is1 = -1;
		is2 = 0;
		while (s1[++is1] != '\0')
			str[is1] = s1[is1];
		while (s2[is2] != '\0')
		{
			str[is1] = s2[is2];
			is1++;
			is2++;
		}
		str[is1] = '\0';
		return (str);
	}
	return (NULL);
}
void	ft_putstr(char const *s)
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}
void	ft_putnbr(int n)
{
	if (n == (-2147483648))
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = n * (-1);
		ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	return ;
}
void    ft_rev(char *str)
{
    int     i;
    char    *tmp;
    int     j;

    i = 0;
    j = 8;
        write(1, "\n*****\n", 6);
//    ft_putstr(str);
    ft_putnbr(ft_strlen(str));
        write(1, "\n", 1);
    tmp = (char *)malloc(sizeof(ft_strlen(str)));
    while ( j >= 0){
        tmp[i++] = str[j++];
        tmp[i++] = str[j];
        i++;
        j = j - 4;
    }
    ft_putstr(tmp);
}

void    *ft_memset(void *b, int c, size_t len)
{
	char		*mem;
	size_t		i;

	mem = b;
	i = 0;
	while (i < len)
	{
		mem[i] = c;
		i++;
	}
	return (mem);
}

void    print_hex(unsigned char value, char **str,int size, int index)
{
    char c;

    c = 'a';
    if (index < 2)
    {
        print_hex(value / 16, str, size, index + 1);
        if (value % 16 >= 10) {
            c = ('a' + value % 16 % 10);
            *str = ft_strjoin(*str, &c);
        }
        else {
            c = ('0' + value % 16 % 10);
            *str = ft_strjoin(*str, &c);
        }
    }
}

int    print_memory(const void *addr, size_t size)
{
    char    *ptr;
    size_t  i;
    char    *str;
    int  j;

    if (!(str = (char *)malloc(sizeof(1))))
        return 1;
    str[0] = '\0';
//    str = ft_memset(str, 0, 10);
    if (addr && size > 0)
    {
      ptr = (char *)addr;
        i = 0;
        j = 0;
        write(1,"0x7f", 4);
        while (i < size)
        {
            print_hex(*(ptr + i),&str, j, 0);
            i++;
            j = j + 2;
        }
        write(1, "\n", 1);
        ft_rev(str);
    }
    return 0;
}

int main()
{
    void *str;
    size_t size;

    size = 5;
    str=(void *)malloc(sizeof(size));
    print_memory(&str, size);
    printf("\n%p", str);
    return (0);
}
