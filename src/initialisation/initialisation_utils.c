/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:44:41 by tnicolau          #+#    #+#             */
/*   Updated: 2024/04/17 11:11:53 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_env_var(t_minishell *data, t_env *new_lst, char *s1, char *s2)
{
	new_lst = new_env_list(data, s1, s2);
	if (!new_lst)
		return (-1);
	lstadd_back_env(&data->env, new_lst);
	return (0);
}

int	check_var_env_exist(t_env *env, char *env_name)
{
	t_env	*env_copy;

	env_copy = env;
	while (env_copy)
	{
		if (!strncmp(env_name, env_copy->name, ft_strlen(env_name)))
			return (1);
		env_copy = env_copy->next;
	}
	return (0);
}

void	add_permanent_var(t_minishell *minishell)
{
	t_env	*new_lst;

	new_lst = NULL;
	if (!check_var_env_exist(minishell->env, "OLDPWD"))
		add_env_var(minishell, new_lst, "OLDPWD", NULL);
	if (!check_var_env_exist(minishell->env, "PWD"))
		add_env_var(minishell, new_lst, "PWD", getcwd(NULL, 0));
	if (!check_var_env_exist(minishell->env, "SHLVL"))
		add_env_var(minishell, new_lst, "SHLVL", "0");
	if (!check_var_env_exist(minishell->env, "_"))
		add_env_var(minishell, new_lst, "_", "/usr/bin/env");
}

t_env	*new_env_list(t_minishell *minishell, char *name_str, char *value_str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		free_all_struct(minishell, 1, MALLOC_ERROR);
	new->name = ft_strdup_minishell(minishell, name_str);
	if (!value_str)
		new->value = NULL;
	else
		new->value = ft_strdup_minishell(minishell, value_str);
	new->next = NULL;
	return (new);
}

void	lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
