/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:23:31 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/20 01:53:22 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_flag
{
	int				sin;
	int				zero;
	int				width;
	int				press;
	int				j;
}					t_flag;

int					ft_printf(const char *str, ...);
int					ft_check_flags(const char *str, va_list args, int *i);

int					print_address(va_list args, int *i, t_flag flag);
int					print_char(int c, int *i, t_flag flag);
int					print_hex(va_list args, int *i, t_flag flag, int sig);
int					print_int(va_list args, int *i, t_flag flag);
int					print_string(va_list args, int *i, t_flag flag);
int					print_uint(va_list args, int *i, t_flag flag);
void				while_print(char *str, int len, int sig);
int					ft_print_type(const char *str, va_list args,
									int *i, t_flag flag);

int					ft_atoi(const char *nptr);
char				*ft_utoa_base(unsigned int n, char *base);
char				*ft_utoa(unsigned int n);

void				ft_init_struct(t_flag *flag);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_numdigt(int unsigned base, int n);
void				ft_putchar_fd(char c, int fd);
size_t				ft_strlen(const char *s);
int					ft_toupper(int c);

#endif
