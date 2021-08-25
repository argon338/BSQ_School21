#include "../BSQ.h"

int	ft_atoi(char *str)
{
	int		i;
	int		mult;
	int		nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

int	ft_isspace(int c)
{
	if (c == '\0' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_digit(int c)
{
	if (c == '1' || c == '2' || c == '3'
	|| c == '4' || c == '5' || c == '6'
	|| c == '7' || c == '8' || c == '9'
	|| c == '0')
		return (1);
	else
		return (0);
}

int	ft_is_number(const char *str)
{
	int	counter;

	counter = 0;
	while (!ft_isspace(str[counter]))
	{
		if (!ft_is_digit(str[counter]))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}

int	ft_is_printable(char c)
{
	if ((c >= 32 && c <= 126) || (c == '\n'))
		return (1);
	return (0);
}