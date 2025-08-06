#include <stdio.h>
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return 1;
		i++;
	}
	return (0);
}


int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++; 

		if (str[i] && !is_sep(str[i], charset))
		{
			words++;
			while (str[i] && !is_sep(str[i], charset))
				i++; 
		}
	}
	return (words);
}

char	*malloc_word(char *str, char *charset)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = malloc(len + 1);
	if (!word)
		return NULL;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}
char	**ft_split(char *str, char *charset)
{
	int		i;
	int 	j;
	int		word_count;
	char	**result;

	i = 0;
	j = 0;
	word_count = count_words(str, charset);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return NULL;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;

		if (str[i] && !is_sep(str[i], charset))
		{
			result[j++] = malloc_word(&str[i], charset);
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
	}

	result[j] = NULL;
	return (result);
}

char **ft_split(char *str, char *charset);

/*int main()
{
	char *text = "salut,toi/ça-va:bien#inchallah";
	char *charset = ",/:#-";

	char **words = ft_split(text, charset);

	for (int i = 0; words[i]; i++)
	{
		printf("word[%d]: %s\n", i, words[i]);
		free(words[i]); 
	}

	free(words);

	return 0;
}*/
