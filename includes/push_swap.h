/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:39:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/18 12:35:26 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
**	LIBRARIES
*/

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/*
**	BINARY MASK
*/

# define STRING		(1 << 3)
# define MIN		(1 << 4)
# define VISUAL		(1 << 5)
# define COLOR		(1 << 6)
# define ERR		(1 << 7)

# define CHR		ft_strchr
# define ISNUM		"0123456789"

/*
** STRUCTURES
*/

typedef struct		s_pile
{
	int				nbr;
	struct s_pile	*root;
	struct s_pile	*top;
	struct s_pile	*low;
}					t_pile;

typedef struct		s_tab
{
	long long		n;
	t_pile			m;
}					t_tab;

typedef	struct		s_roll
{
	int				size;
	char			bd;
	t_pile			a;
	t_pile			b;
	unsigned		nb_ea;
	unsigned		nb_eb;
}					t_roll;

/*
** PROTOTYPES
*/

int					init_struct(t_roll *r, char **argv, int size);
void				init_tab(t_tab *t, t_roll *r, char **a, int i);
void				init_sort(t_tab *t, t_roll *r, int i);

void				ft_qsort(t_tab *t, int size, int i, int j);

void				push_swap(t_roll *r, char **p, int size);

#endif
