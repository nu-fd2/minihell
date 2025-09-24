/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:43 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 16:44:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

char	*rdd(char *buff, int fd);
char	*one_line(const char *buff);
char	*updtt(char *buff);

char	*ftg_strdup(const char *s1);
char	*ftg_strchr(const char *str, int c);
void	*ftg_calloc(size_t count, size_t size);
char	*ftg_strjoin(char const *s1, char const *s2);
size_t	ftg_strlen(const char *who);
size_t	ftg_strlcpy(char *dst, const char *src, size_t n);

#endif
