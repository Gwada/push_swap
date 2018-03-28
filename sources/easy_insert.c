#include "push_swap.h"

void		i_b_right_insert(t_roll *r, int *rot, int min, int max)
{
	int		i;
	int		value;

	i = -1;
	value = min;
	while (++i < r->nb_b)
	{
		if (BLNBR > min && BLNBR < max && BLNBR > value)
		{
			value = BLNBR;
			*rot = i;
		}
		rotate(NULL, &r->b, 0);
	}

}

void		i_b_left_insert(t_roll *r, int *rot, int min, int max)
{
	ft_printf("{bold}{red}IN\tI_B_LEFT_INSERT\n{eoc}");
	ft_printf("min = %d max = %d\n", min, max);
	int		i;
	int		value;

	i = -1;
	value = max;
	while (++i < r->nb_b)
	{

		if (BLNBR > min && BLNBR < max && BLNBR < value)
		{
			value = BLNBR;
			*rot = i;
		}
		rotate(NULL, &r->b, 0);
	}
	ft_printf("value = %d rot = %d\n", value , *rot);
	ft_printf("{bold}{red}END\tI_B_LEFT_INSERT\n{eoc}");
}

void		left_insert(t_roll *r, int rot, int min, int max)
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

void		right_insert(t_roll *r, int rot, int min, int max)
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

int			easy_insert(t_roll *r, int value, int ret, int i)
{
	ft_printf("{bold}{red}IN\tEASY_INSERT\n{eoc}");
	ft_printf("ALNBR %d\n", ALNBR);
	ft_printf("r->nb_a = %d r->b_rot = %d\n", r->nb_a, r->b_rot);
	int		left;
	int		right;
	int		min_t;
	int		max_t;
	int		min_l;
	int		max_l;

	left = 0;
	right = 0;
	while (ATBD & GOOD && ++left && ++i < r->nb_a)
	{
		r_rotate(NULL, &r->a, 0);
		max_t = ALNBR;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		min_t = ATNBR;
		if (value_insert(r, NULL, min_t, max_t) && ++left)
		{
			while (ALNBR != value)
				rotate(NULL, &r->a, 0);
			break ;
		}
		while (ALNBR != max_t)
			rotate(NULL, &r->a, 0);
	}
	while (ALNBR != value)
		rotate(NULL, &r->a, 0);
	i = -1;
	while (ALBD & GOOD && ++right && ++i < r->nb_a)
	{
		rotate(NULL, &r->a, 0);
		min_l = ATNBR;
		while (ALBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		max_l = ALNBR;
		if (value_insert(r, NULL, min_l, max_l) && ++right)
		{
			while (ALNBR != value)
				r_rotate(NULL, &r->a, 0);
			break ;
		}
		while (ATNBR != min_l)
			r_rotate(NULL, &r->a, 0);
	}
	while (ALNBR != value)
		r_rotate(NULL, &r->a, 0);
	ft_printf("min_t = %d max_t = %d\n", min_t, max_t);
	ft_printf("min_l = %d max_l = %d\n", min_l, max_l);
	ft_printf("left = %d right = %d\n", left, right);
	if (left == right && (i = -1))
	{
		while (++i < r->best_dif_dep)
			rotate(NULL, &r->a, 0);
		ALBD ^ NO_CHECK ? ret = 1 : 0;
		while (ALNBR != value)
			r_rotate(NULL, &r->a, 0);
	}
	left < right ? ret = 1 : 0;
	return (ret);
}
