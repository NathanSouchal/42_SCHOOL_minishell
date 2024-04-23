/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:51:41 by tnicolau          #+#    #+#             */
/*   Updated: 2024/04/22 10:12:31 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_tilde(t_minishell *minishell, char *str)
{
	char	*result;
	int		length;

	if (find_else_tilde(str) == 1 || find_else_tilde(str) == 2)
	{
		if (minishell->home)
			free(minishell->home);
		minishell->home = get_env_value(minishell, "HOME");
		length = ft_strlen(minishell->home) + ft_strlen(str) - 1;
		result = malloc(sizeof(char) * (length + 1));
		if (!result)
			free_all_struct(minishell, 1, MALLOC_ERROR);
		if (find_else_tilde(str) == 1)
			replace_tilde_str(minishell->home, result, str);
		else if (find_else_tilde(str) == 2)
			replace_tilde_only(minishell->home, result, str);
		return (free(str), result);
	}
	return (str);
}

void	replace_tilde_str(char *home, char *result, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && str[i] != '~')
	{
		result[j] = str[i];
		i++;
	}
	if (str[i] == '~')
	{
		while (home[k])
		{
			result[j] = home[k];
			k++;
			j++;
		}
		i++;
	}
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
}

void	replace_tilde_only(char *home, char *result, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '~' && str[i])
	{
		result[j] = str[i];
		i++;
	}
	if (str[i] == '~')
	{
		while (home[k])
		{
			result[j] = home[k];
			k++;
			j++;
		}
		i++;
	}
	result[j] = '\0';
}
