/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:56:07 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 18:39:45 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *str, int chr);
void	*gnl_calloc(size_t elementCount, size_t elementSize);
char	*gnl_strdup(const char *src);
size_t	gnl_strlcat(char *dest, const char *src, size_t size);

#endif