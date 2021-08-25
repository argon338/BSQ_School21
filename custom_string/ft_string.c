#include "../BSQ.h"
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		write(1, &str[counter++], 1);
}