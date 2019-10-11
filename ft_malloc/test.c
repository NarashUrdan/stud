#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_hex(unsigned char value, int index)
{
    if (index < 2)
    {
        print_hex(value / 16, index + 1);
        if (value % 16 >= 10) {
            ft_putchar('a' + value % 16 % 10);
        }
        else if (value % 16 >= 0){
            ft_putchar('0' + value % 16);
        }
    }
}

int    print_memory(const void *addr, size_t size)
{
    char    *ptr;
    size_t  i;

    if (addr && size > 0)
    {
      ptr = (char *)addr;
        i = size;
        write(1,"0x", 2);
        while (i > 0)
        {
            print_hex(ptr[i], 0);
            i--;
        }
        print_hex(ptr[0], 0);
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
