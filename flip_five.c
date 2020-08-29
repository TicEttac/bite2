#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 	s_square {
	char			**square;
	struct	s_square	*next;
}		t_square;

int	out(char *s, t_square *list)
{
	t_square	*tmp;

	printf("%s", s);
	while (list != NULL)
	{
		printf("first loop.\n");
		while (tmp->next != NULL)
		{
			printf("second loop.\n");
			tmp = tmp->next;
		}
		free(tmp->square);
		free(tmp);
		tmp = NULL;
		tmp = list; 
	}
	free(list->square);
	free(list);
	return (0);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char *ret;
	int i = 0, size = ft_strlen(s);

	if (!(ret = malloc(size)))
		return (NULL);
	while (i < size)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	print_squares(t_square *list)
{
	int		i;
	t_square	*index;

	index = list;
	while (index != NULL)
	{
		i = 0;
		while (i < 3)
		{
			printf("%s\n", index->square[i]);
			i++;
		}
		printf("\n");
		index = index->next;
	}
	return (0);
}

//[]{}\

int main()
{
	int			num;
	int			i;
	char		*tmp;
	t_square	*list;
	t_square	*index;

	i = 0;
	scanf("%d", &num);
	if (num < 1)
		return (0);
	list = NULL;
	index = list;
	while (i < num)
	{
		if (!(index = malloc(sizeof(t_square))))
			return (out("malloc error.\n", list));
		index->next = NULL;
		if (!(index->square = malloc(sizeof(char *) * 3)))
			return (out("malloc error.\n", list));
		if (!(tmp = malloc(3)))
			return (out("malloc error.\n", list));
		scanf("%s", tmp);
		if (ft_strlen(tmp) != 3)
			return (out("Wrong line's size.\n", list));
		index->square[0] = ft_strdup(tmp);
		scanf("%s", tmp);
		if (ft_strlen(tmp) != 3)
			return (out("Wrong line's size.\n", list));
		index->square[1] = ft_strdup(tmp);
		scanf("%s", tmp);
		if (ft_strlen(tmp) != 3)
			return (out("Wrong line's size.\n", list));
		index->square[2] = ft_strdup(tmp);
		index = index->next;
		i++;
	}
	free(tmp);
	print_squares(list);
	out("Well closed.\n", list);
//	system("leaks a.out");
}
