#include "push_swap.h"

void			i_b_right_insert(t_roll *r, int *rot, int min, int max)
{
	int			i;
	int			value;

	i = -1;
	value = min;
	while (++i < r->nb_b)
	{
		if (BLNBR > min && BLNBR < max && BLNBR > value
		&& ((value = BLNBR) || !(value = BLNBR)))
			*rot = i;
		rotate(NULL, &r->b, 0);
	}
}

void			i_b_left_insert(t_roll *r, int *rot, int min, int max)
{
	int			i;
	int			value;

	i = r->nb_b;
	value = BLNBR;
	while (--i >= 0)
	{
		r_rotate(NULL, &r->b, 0);
		if (BLNBR > min && BLNBR < max && BLNBR < value
		&& ((value = BLNBR) || !(value = BLNBR)))
			*rot = i;
	}
}

static	void	left_insert(t_roll *r, int rot, int min, int max)
{
	ft_printf("{bold}{red}IN\tEASY_INSERT LEFT\n{eoc}");
	!rot ? i_b_left_insert(r, &rot, min, max) : 0;
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
		BLBD = CHECK;
		r->nb_b > 0 && BLNBR < max && BLNBR > ATNBR ? rotate(r, &r->a, 'a') : 0;
	}
	BLBD = GOOD;
	ft_printf("{bold}{red}END\tEASY_INSERT LEFT\n{eoc}");
}

static	void	right_insert(t_roll *r, int rot, int min, int max)
{
	ft_printf("{bold}{red}IN\tEASY_INSERT RIGHT\n{eoc}");
	i_b_right_insert(r, &rot, min, max);
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
	ft_printf("{bold}{red}END\tEASY_INSERT RIGHT\n{eoc}");
}

void	easy_insert(t_roll *r, int rot, int min, int max)
{
	ft_printf("{bold}{red}IN\tEASY_INSERT\n{eoc}");
	ft_printf("r->nb_a = %d r->b_rot = %d\n", r->nb_a, r->b_rot);
	int		i;
	int		left;
	int		right;
	int		value;

	i = -1;
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
	ft_printf("left = %d right = %d\n", left, right);
	if (left <= right || (left == r->nb_a && right == r->nb_a - 1))
	{
		if (left == r->nb_a && right == r->nb_a - 1 && ALNBR <= r->pvt)
			return (left_insert(r, rot, min, max));
		right_insert(r, rot, min, max);
	}
	else
		left_insert(r, rot, min, max);
}
