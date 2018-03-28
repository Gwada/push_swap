#include "push_swap.h"

static	int		first_check(t_roll *r, int *fst, int *lst)
{
	*lst = ALNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
	*fst = ATNBR;
	while (ALBD ^ GOOD)
		rotate(NULL, &r->a, 0);
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
		rotate(NULL, &r->a, 0);
	*lst = ALLNBR;
	while (ALBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
	if ((ATNBR > *fst && ATNBR < *lst)
	|| (*fst > *lst && (ATNBR > *fst || ATNBR < *lst)))
	{
		r_rotate(r, &r->a, 'a');
		swap(r, &r->a, 'a');
		return (1);
	}
	if (*fst - *lst != 1 && value_insert(r, NULL, *fst, *lst) && (r->b_rot = 1))
	{
		rotate(r, &r->a, 'a');
		return (b_push(r, *fst, *lst));
	}
	*lst = ALNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
	*fst = ATNBR;
	while (ALBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	return (0);
}

static	int		third_check(t_roll *r, int *fst, int *lst)
{
	*fst = ALLNBR;
	while (ALLLBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	*lst = ALLLNBR;
	while (ALLBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
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
			r_rotate(NULL, &r->a, 0);
		*fst = ATNBR;
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
	}
	return (0);
}

static	int		fourth_chech(t_roll *r, int *fst, int *lst)
{
	*lst = ATNBR;
	while (ATTBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	*fst = ATTNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
	if ((ALNBR > *fst && ALNBR < *lst)
	|| (*fst > *lst && (ALNBR > *fst || ALNBR < *lst)))
	{
		r_rotate(r, &r->a, 'a');
		swap(r, &r->a, 'a');
		return (1);
	}
	if (ALLBD ^ GOOD)
	{
		*fst = ATNBR;
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		*lst = ALLNBR;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		if (*fst - *lst != 1 && b_push(r, *fst, *lst))
			return(1);
	}
	return (0);
}

int				nearest_checker(t_roll *r, int fst, int lst)
{
//	ft_printf("{bold}{yellow}in nearest checker{eoc}\n");////////////////////////
	if (ALBD & GOOD)
	{
//		ft_printf("{bold}{red}1.{eoc}\n");///////////////////////////////////////
		if (first_check(r, &fst, &lst))
			return (1);
		if (ATBD ^ GOOD && second_check(r, &fst, &lst))
			return (1);
		if (fst - lst != 1 && b_push(r, fst, lst))
			return (1);
//		ft_printf("{bold}{red}.1{eoc}\n");///////////////////////////////////////
	}
	else if (ALLBD & GOOD)
	{
//		ft_printf("{bold}{red}2.{eoc}\n");///////////////////////////////////////
		if (third_check(r, &fst, &lst))
			return (1);
		if (ATBD ^ GOOD && fst - lst != 1 && value_insert(r, NULL, fst, lst))
		{
			r->b_rot = 1;
			rotate(r, &r->a, 'a');
			b_push(r, fst, lst);
			return (1);
		}
//		ft_printf("{bold}{red}.2{eoc}\n");///////////////////////////////////////
	}
	else if (ATBD & GOOD && fourth_chech(r, &fst, &lst))
	{
//		ft_printf("{bold}{red}3{eoc}\n");////////////////////////////////////////
		return (1);
	}
	return (0);
}
