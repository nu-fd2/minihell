/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 05:18:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_EXEC_H
#define M_EXEC_H

#include "../includes/header.h"

#include "libft/libft.h"
#include "m_bul/bul_cmd.h"
#include "m_env/env.h"
#include "m_exc/ex_exc.h"
#include "m_red/hed_red.h"


typedef struct s_latest t_short;

typedef struct s_data t_data;

typedef struct s_env t_env;

typedef struct s_data
{
	int				fd;
	int				fd2;
	int				ex;
	int				exm;
	pid_t			kid;
	char			**chr_env;
	t_env			*env;
}					t_data;

// void	hnd_sig(int signum, siginfo_t *info, void *cnt);

// int prompt_msg();

// void	hnd_sig(int signum, siginfo_t *info, void *cnt);

#endif // M_EXEC_H
