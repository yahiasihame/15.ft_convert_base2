#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int	is_valid_base(char *base);
int	get_index(char c, char *base);
void	ft_fill_res(char *res, long nb, char *base, int base_len);
int	ft_itoa_len(long nb, int base_len);

int ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign = 1;
	int	result = 0;
	int	base_len = 0;

	i = 0;
	sign = 1;
	result = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;

	while (str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (get_index(str[i], base) != -1)
	{
		result = result * base_len + get_index(str[i], base);
		i++;
	}
	return (result * sign);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		base_len;
	long	nb;
	char	*res;

	base_len = 0;
	nb = nbr;
	while (base[base_len])
		base_len++;

	res = malloc(ft_itoa_len(nb, base_len) + 1);
	if (!res)
		return (NULL);

	ft_fill_res(res, nb, base, base_len);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	number;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	
	number = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(number, base_to));
}



/*int main(void)
{
	char *nbr = "   ---1011";
	char *base_from = "01";     
	char *base_to = "0123456789"; 

	char *converted = ft_convert_base(nbr, base_from, base_to);

	if (converted)
	{
		printf("Converted: %s\n", converted);
		free(converted); 
	}
	else
	{
		printf("Conversion failed.\n");
	}

	return 0;
}*/
