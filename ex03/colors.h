/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:34:20 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/21 20:59:03 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# define COLOR_DEFAULT "\033[0m"
# define COLOR_RED "\033[31;1m"
# define COLOR_GREEN "\033[32;1m"
# define COLOR_YELLOW "\033[33;1m"
# define COLOR_BLUE "\033[34;1m"
# define COLOR_MAGENTA "\033[35;1m"
# define COLOR_CYAN "\033[36;1m"
# define COLOR_WHITE "\033[37;1m"
# define COLOR_ORANGE "\x1B[34m"
# ifndef DEBUG
#  define DEBUG 0
# endif
#endif