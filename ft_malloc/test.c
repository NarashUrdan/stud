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

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void    print_hex(unsigned char value, char *str, int index)
{
    char *tmp;

    tmp = (char *)malloc(sizeof(ft_strlen(str) + 1));
    tmp = ft_strcpy(tmp, str);
    if (index < 2)
    {
        print_hex(value / 16, tmp, index + 1);
        if (value % 16 >= 10)
            str = ('a' + value % 16 % 10);
        else
            str = ('0' + value % 16);
    }
}

void    print_memory(const void *addr, size_t size)
{
    char    *ptr;
    size_t  i;
    char    *str;

    str = (char *)malloc(sizeof(11));
    str[10] = '\0';
    if (addr && size > 0)
    {
      ptr = (char *)addr;
        i = 0;
        write(1,"0x7f", 4);
        while (i < size)
        {
            print_hex(*(ptr + i),str, 0);
            i++;
        }
    }
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
