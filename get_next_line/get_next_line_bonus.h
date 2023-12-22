/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:47:46 by lmartin2          #+#    #+#             */
/*   Updated: 2022/03/10 12:39:06 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		read_next_line(int fd, char **next_line);
int		my_feeder(char **pantry, int fd);
int		my_spender(char **pantry, char **str);
int		my_saver(char **pantry);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char    *ft_free(char *str);

#endif
