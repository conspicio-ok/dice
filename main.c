#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void	ok_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ok_putint(int nb)
{
	char	nbr;
	if (nb > 9)
		ok_putint(nb / 10);
	nbr = nb % 10 + '0';
	write(1, &nbr, 1);
}

int	dice(int face)
{
	int	nb;

	srand(time(NULL));
	nb = rand() % face + 1;
	ok_putstr("Your number is : ");
	ok_putint(nb);
	ok_putstr("\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	face;

	face = 0;
	if (argc != 2)
	{
		ok_putstr("Please try again with one number\n");
		return (0);
	}
	while (*argv[1] >= '0' && *argv[1] <= '9')
	{
		face = face * 10 + *argv[1] - '0';
		argv[1]++;
	}
	if (face < 2)
	{
		ok_putstr("Please enter biggest number\n");
		return (0);
	}
	dice(face);
	return (0);
}
