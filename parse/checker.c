/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:27:46 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int check_par(char line ,bool s_quote, bool d_quote)
{
    if(line == '(' && !d_quote && !s_quote)
        return 1;
    else if(line == ')' && !d_quote && !s_quote)
        return -1;
    return 0;
}

void check_error(int par, bool d_quote, bool s_quote)
{
    if(par < 0)
    {
        printf("parse Error near : ')'\n");
        exit(EXIT_FAILURE);
    }
    else if(par > 0)
    {
        printf("parse Error near : '('\n");
        exit(EXIT_FAILURE);
    }
    else if(d_quote == true)
    {
        printf("parse Error near : '\"'\n");
        exit(EXIT_FAILURE);
    }
    else if(s_quote == true)
    {
        printf("parse Error near : '\''\n");
        exit(EXIT_FAILURE);
    }
}
void checker(char *line)
{
    int i;
    bool s_quote;
    bool d_quote;
    int par;

    i = 0;
    par = 0;
    s_quote = false;
    d_quote = false;
    while(line[i])
    {
        if (line[i] == '\'' && !d_quote && !s_quote)
            s_quote = true;
        else if (line[i] == '\'' && !d_quote && s_quote)
            s_quote = false;
        if(line[i] == '"' && !s_quote && !d_quote)
            d_quote = true;
        else if (line[i] == '"' && !s_quote && d_quote)
            d_quote = false;
        par += check_par(line[i], s_quote, d_quote);
        if(par == -1)
            break;
        i++;
    }
    check_error(par, d_quote, s_quote);
}

        // printf("before : s=> %d, d=> %d\n", s_quote, d_quote);
        // s_quote = check_s_quote(line[i], s_quote, d_quote);
        // d_quote = check_d_quote(line[i], s_quote, d_quote);
        // printf("after : s=> %d, d=> %d\n", s_quote, d_quote);

// NIGGER
