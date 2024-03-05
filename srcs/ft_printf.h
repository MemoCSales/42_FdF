/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:43:28 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/02/24 18:02:25 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define UPPERHEXABASE "0123456789ABCDEF"
# define LOWERHEXABASE "0123456789abcdef"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// ft_printf.c
int		ft_printf(const char *format, ...);
// char	*ft_strchr(const char *s, int c);
int		ft_placeholders(const char *format, va_list args);
void	ft_putchar_fd(char c, int fd);
int		printchar(char c);

// ft_printf_src.c
// int		ft_intlen(int n);
char	*ft_itoa(int n);
int		printdecimal(int n);
int		printunsigned(unsigned int n);

// ft_printf_src2.c
void	ft_putstr_fd(char *s, int fd);
int		printstring(char *s);
int		printhexa(unsigned long long n, const char *format);
int		intlen(unsigned int n);
char	*itoa(unsigned int n);

// get_next_line.c
char	*get_next_line(int fc);
char	*read_from_file(int fd, char *buffer, char *backup);
char	*read_line(char *full_line);
void	*ft_calloc(size_t count, size_t size);

// get_next_line_utils.c
char	*ft_strchr2(char *s, int c);
// size_t	ft_strlen(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char *s2);

#endif