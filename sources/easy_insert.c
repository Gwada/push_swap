#include "push_swap.h"

static	void	left_insert(t_roll *r, int rot, int min, int max)
{
	int			i;
	int			value;

	i = -1;
	value = BLNBR;
	if (!rot && (rot = r->nb_b))
		while (++i < r->nb_b)
		{
			r_rotate(NULL, &r->b, 0);
			if (BLNBR > min && BLNBR < max && BLNBR < value && (value = BLNBR))
				--rot;
		}
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (r->nb_b > 0 && BLNBR > ATNBR && BLNBR < max)
	{
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
		if (r->nb_b > 0 && BLNBR < max && BLNBR > ATNBR)
			rotate(r, &r->a, 'a');
	}
}

static	void	right_insert(t_roll *r, int rot, int min, int max)
{
	int			i;
	int			value;

	i = -1;
	value = min;
	while (++i < r->nb_b)
	{
		if (BLNBR > min && BLNBR < max && BLNBR > value && (value = BLNBR))
			rot = i;
		rotate(NULL, &r->b, 0);
	}
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (r->nb_b > 0 && BLNBR > min && BLNBR < ALNBR)
	{
		simple_push(r, &r->b, &r->a, 'a');
		ALBD = GOOD;
		if (r->nb_b > 0 && BTNBR > min && BTNBR < ALNBR)
			r_rotate(r, &r->b, 'b');
	}
}

void	easy_insert(t_roll *r, int rot, int min, int max)
{
	if (ATBD & GOOD)
		left_insert(r, rot, min, max);
	else if (ALBD & GOOD)
		right_insert(r, rot, min, max);
}
