#include "push_swap.h"

void			i_b_max_finder(t_roll *r, int *rot, int i)
{
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
	i_b_min_finder(r, &rot, i);
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (r->nb_b > 0 && BLNBR < min && BLNBR < ALNBR)
	{
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
		r->nb_b > 0 ? rotate(r, &r->a, 'a') : 0;
	}
	rotate(r, &r->a, 'a');
}

void	hard_insert(t_roll *r, int rot, int min, int max)
{
	if (ALBD & GOOD)
	{
		r->b_max > max ? max_insert(r, rot, -1, max) : 0;
		r->b_min < min ? min_insert(r, rot, -1, min) : 0;
	}
	else if (ATBD & GOOD)
	{
		if (r->b_max > max)
		{
			max_insert(r, rot, -1, max);
			rotate(r, &r->a, 'a');
		}
		r->b_min < min ? min_insert(r, rot, -1, min) : 0;
	}
}

