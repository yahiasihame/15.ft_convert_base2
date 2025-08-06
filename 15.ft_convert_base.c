#include<stdlib.h>


int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int get_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_itoa_len(long nb, int base_len)
{
	int	len = 0;

	if (nb <= 0)
	{
		len++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}


void	ft_fill_res(char *res, long nb, char *base, int base_len)
{
	int	len;

	len = ft_itoa_len(nb, base_len);
	res[len] = '\0';

	if (nb == 0)
	{
		res[0] = base[0];
		return ;
	}
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (len-- && nb > 0)
	{
		res[len] = base[nb % base_len];
		nb /= base_len;
	}
}
