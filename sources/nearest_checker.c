/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:42:59 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/02 15:43:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		first_check(t_roll *r, int *fst, int *lst)
{
	*lst = ALNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	*fst = ATNBR;
	while (ALBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	if (ALLBD ^ GOOD && ((ALLNBR > *fst && ALLNBR < *lst)
	|| (*fst > *lst && (ALLNBR > *fst || ALLNBR < *lst))))
	{
		swap(r, &r->a, 'a');
		return (1);
	}
	ATBD ^ GOOD ? *fst = ALNBR : 0;
	return (0);
}

static	int		second_check(t_roll *r, int *fst, int *lst)
{
	while (ALLBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	*lst = ALLNBR;
	while (ALBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	if ((ATNBR > *fst && ATNBR < *lst)
	|| (*fst > *lst && (ATNBR > *fst || ATNBR < *lst)))
	{
		r_rotate(r, &r->a, 'a', GOOD);
		swap(r, &r->a, 'a');
		return (1);
	}
	*lst = ALNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	*fst = ATNBR;
	while (ALBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	return (0);
}

static	int		third_check(t_roll *r, int *fst, int *lst)
{
	*fst = ALLNBR;
	while (ALLLBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	*lst = ALLLNBR;
	while (ALLBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	if ((ALNBR > *fst && ALNBR < *lst)
	|| (*fst > *lst && (ALNBR > *fst || ALNBR < *lst)))
	{
		swap(r, &r->a, 'a');
		return (1);
	}
	if (ATBD ^ GOOD)
	{
		*lst = ALLNBR;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0, 0);
		*fst = ATNBR;
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0, 0);
	}
	return (0);
}

static	int		fourth_chech(t_roll *r, int *fst, int *lst)
{
	*lst = ATNBR;
	while (ATTBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	*fst = ATTNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	if ((ALNBR > *fst && ALNBR < *lst)
	|| (*fst > *lst && (ALNBR > *fst || ALNBR < *lst)))
	{
		r_rotate(r, &r->a, 'a', GOOD);
		swap(r, &r->a, 'a');
		return (1);
	}
	return (0);
}

int				nearest_checker(t_roll *r, int fst, int lst)
{
	if (ALBD & GOOD)
	{
		if (first_check(r, &fst, &lst))
			return (1);
		if (ATBD ^ GOOD && second_check(r, &fst, &lst))
			return (1);
	}
	else if (ALLBD & GOOD && third_check(r, &fst, &lst))
		return (1);
	else if (ATBD & GOOD && fourth_chech(r, &fst, &lst))
		return (1);
	return (0);
}
