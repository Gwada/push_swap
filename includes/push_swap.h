/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:39:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/15 14:56:45 by dlavaury         ###   ########.fr       */
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
** STRUCTURES
*/

typedef struct		s_pile
{
	void			*root;
	struct s_pile	*top;
	struct s_pile	*low;
}					t_pile;

typedef	struct		s_roll
{
	t_pile			a;
	t_pile			b;
	unsigned		nb_ea;
	unsigned		nb_eb;
}					t_roll;

/*
** PROTOTYPES
*/

void				init_main(t_roll *r);

#endif
