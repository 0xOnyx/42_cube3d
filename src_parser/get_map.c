#include "includes.h"

//TODO: GET MAP TO CHAR ** NOT EXECTUE PARSING INI THE FUNCTION
static int	ft_strjoin_free(char **final, char *res)
{
	char	*tmp;

	if (ft_strjoin(&tmp, *final, res))
		return (1);
	del_malloc(*final);
	del_malloc(res);
	*final = tmp;
	return (0);
}

int	get_map(int fd, char ***map, char **buff)
{
	char	*final;
	char	*res;

	(void)map;
	final = NULL;
	while (!ft_readline(fd, buff, &res))
	{
		if (ft_strjoin_free(&final, res))
			return (1);
	}
	if (*buff)
		if (ft_strjoin_free(&final, res))
			return (1);
	return (0);
}