/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:38:47 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/21 22:12:23 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char	*ft_handle_tmp2(t_data *data, char *str, t_flags *check)
{
	char	*tmp;
	char	*tmp3;

	tmp = my_substr(str, check->start, (check->end) - check->start);
	check->start = check->end;
	if (tmp[0] == '?')
		return (free(tmp), ft_itoa(data->exm));
	else
		tmp3 = gky_env(data, tmp);
	return (free(tmp), ft_strdup(tmp3));
}

void	ft_expand_and_append(char *str, t_flags *check, t_data *data)
{
	char	*tmp2;

	check->string = my_strnjoin(check->string, str + check->start,
			(check->end - 1) - check->start);
	check->end++;
	check->start = check->end;
	if (!my_isalpha(str[check->end]) && str[check->end] != '_')
	{
		if (str[check->end] != '?')
		{
			check->string = my_strnjoin(check->string, "$", 1);
			return ;
		}
	}
	while (my_isalnum(str[check->end])
		|| str[check->end] == '_')
		check->end++;
	if (str[check->end] == '?')
		check->end++;
	tmp2 = ft_handle_tmp2(data, str, check);
	if (tmp2 == NULL)
		return ;
	check->string = my_strnjoin(check->string, tmp2, my_strlen(tmp2));
	return (free(tmp2));
}

void	ft_str_check(char *str, t_flags *check, t_data *data)
{
	if (str[check->end] == '$')
		ft_expand_and_append(str, check, data);
	else
		check->end++;
	if (str[check->end] == '\0')
		check->string = my_strnjoin(check->string, str + check->start,
				(check->end - 1) - check->start);
}

char *ft_expand_str(char *str, t_data *data)
{
	t_flags	check;

	check.string = NULL;
	check.expand = NULL;
	check.start = 0;
	check.end = 0;
	check.d_end = 0;
	check.d_start = 0;
	check.quotes = 0;
	while (str[check.end])
		ft_str_check(str, &check, data);
    free(str);
    ft_remove_spaces(check.string);
    return (check.string);
}
