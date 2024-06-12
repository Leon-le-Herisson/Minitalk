/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:13:11 by bmagere           #+#    #+#             */
/*   Updated: 2024/06/12 12:32:52 by bmagere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*minitalk_utils.c//////////////////////////////*/
/*										   		*/
int     ft_atoi(const char *nptr);
char    *ft_strjoin(char const *s1, char const *s2);
/*ft_printf.c///////////////////////////////////*/
/*										   		*/
int		ft_printf(const char *format, ...);
int		print_char(int arg, int i);
int		print_nb(int arg, int i);
int		print_p(size_t arg, int i);
int		print_nb_base_x(size_t arg, int i);
int		print_nb_base_bigx(size_t arg, int i);
int		print_nb_u(unsigned int arg, int i);

#endif