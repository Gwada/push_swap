#include "push_swap.h"

void			i_b_max_finder(t_roll *r, int *rot, int i)
{
	int			left;
	int			right;
	int			value;

	left = 0;
	right = 0;
	value = ALNBR;
	while (ATBD & GOOD && ++left && ++i < r->nb_a)
		r_rotate(NULL, &r->a, 0);
	while (ALNBR != value)
		rotate(NULL, &r->a, 0);
	i = -1;
	while (ALBD & GOOD && ++right && ++i < r->nb_a)
		rotate(NULL, &r->a, 0);
	while (ALNBR != value)
		r_rotate(NULL, &r->a, 0);
	i = -1;
	if (left > right || (left == r->nb_a && right == r->nb_a))
	{
		*rot = -1;
		while (++i < r->nb_b)
		{
			*rot == -1 && BLNBR > ATNBR ? value = BLNBR : 0;
			*rot == -1 && BLNBR > ATNBR ? *rot = i : 0;
			*rot > -1 && BLNBR > ATNBR && BLNBR < value ? *rot = i : 0;
			*rot > -1 && BLNBR > ATNBR && BLNBR < value ? value = BLNBR : 0;
			rotate(NULL, &r->b, 0);
		}
	}
	else
		while (++i < r->nb_b)
		{
			BLNBR == r->b_max ? *rot = i : 0;
			rotate(NULL, &r->b, 0);
		}
}

void			i_b_min_finder(t_roll *r, int *rot, int i)
{
	while (++i < r->nb_b)
	{
		BLNBR == r->b_min ? *rot = i : 0;
		rotate(NULL, &r->b, 0);
	}
}

static	void	max_insert(t_roll *r, int rot, int i, int max)
{
//	ft_printf("{bold}{red}in max insert\n{eoc}");////////////////////////////////
	i_b_max_finder(r, &rot, i);
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (r->nb_b > 0 && BLNBR > ALNBR && BLNBR > max)
	{
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
		r->nb_b > 0 ? rotate(r, &r->a, 'a') : 0;
	}
}

static	void	min_insert(t_roll *r, int rot, int i, int min)
{
//	ft_printf("{bold}{red}in min insert\n{eoc}");////////////////////////////////
	i_b_min_finder(r, &rot, i);
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (r->nb_b > 0 && BLNBR < min && BLNBR < ALNBR)
	{
//	ft_printf("{bold}{red}in min insert\n{eoc}");////////////////////////////////
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
		if (r->nb_b > 0 && BLNBR < min && BLNBR < ALNBR)
			rotate(r, &r->a, 'a');
	}
}

void	hard_insert(t_roll *r, int rot, int min, int max)
{
//	ft_printf("{bold}{red}in hard insert\n{eoc}");///////////////////////////////
	if (ALBD & GOOD)
	{
//		ft_printf("{bold}{red}1\n{eoc}");////////////////////////////////////////
		r->b_max > max ? max_insert(r, rot, -1, max) : 0;
		r->b_min < min ? min_insert(r, rot, -1, min) : 0;
	}
	else if (ATBD & GOOD)
	{
//		ft_printf("{bold}{red}2\n{eoc}");////////////////////////////////////////
		if (r->b_max > max)
		{
			max_insert(r, rot, -1, max);
			rotate(r, &r->a, 'a');
		}
		r->b_min < min ? min_insert(r, rot, -1, min) : 0;
	}
}

