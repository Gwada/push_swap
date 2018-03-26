#include "push_swap.h"

static	int		calibrate(t_roll *r, int rot_a, int rot_b)
{
	if (!rot_b)
		return (0);
	if (rot_a >= r->nb_b)
		return (1);
	if (rot_a <= r->nb_a / 2)
	{
		if (rot_b <= r->nb_b / 2)
			return (1);
		else if (rot_b > r->nb_b / 2 && rot_a + (r->nb_b - rot_b) > rot_b)
			return (1);
	}
	else
	{
		if (rot_b > r->nb_b / 2)
			return (1);
		else if (rot_b <= r->nb_b / 2 && r->nb_a - rot_a >= r->nb_b - rot_b)
			return (1);
	}
	return (0);
}

static	int		p_calibrate(t_roll *r, int rot, int i)
{
//	ft_printf("{bold}{cyan}{underline}IN\tPUSH_CALIBRATE{eoc}\n");
	int			rot_b;

	rot_b = 0;
	while (++i < r->nb_b)
	{
		if ((ALNBR > BTNBR && ALNBR < BLNBR)
		|| (BTNBR > BLNBR && (ALNBR > BTNBR || ALNBR < BLNBR)))
			rot_b = i;
		rotate(NULL, &r->b, 0);
	}
//	ft_printf("{bold}{cyan}{underline}END\tPUSH_CALIBRATE{eoc}\n");
	return (calibrate(r, rot, rot_b));
}

static	int		i_calibrate(t_roll *r, int rot_a, int i)
{
	ft_printf("{bold}{magenta}{underline}IN\tINSERT_CALIBRATE{eoc}\n");
	int			max;
	int			min;
	int			value;
	int			rot_b;

	max = ALNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
	min = ATNBR;
	while (ALBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	i = -1;
	value = min;
	ft_printf("{bold}{green}min = %d max = %d\n{eoc}", min, max);
	if (min < max)
	{
		ft_printf("\n{bold}{green}{underline}min < max\n{eoc}");
		if (ATBD ^ GOOD)
		{
			while (++i < r->nb_b)
			{
				if (ATBD ^ GOOD && BLNBR > min && BLNBR < max && BLNBR > value)
				{
					value = BLNBR;
					rot_b = i;
				}
				rotate(NULL, &r->b, 0);
			}
		}
		else if (ATBD & GOOD)
		{
			value = max;
			while (++i < r->nb_b)
			{
				if (ATBD & GOOD && BLNBR > min && BLNBR < max && BLNBR < value)
				{
					value = BLNBR;
					rot_b = i;
				}
				rotate(NULL, &r->b, 0);
			}
		}
		ft_printf("rot_b = %d\n", rot_b);
	}
	else
		ft_printf("min > max\n");
	ft_printf("{bold}{magenta}{underline}END\tINSERT_CALIBRATE{eoc}\n");
	return (calibrate(r, rot_a, rot_b));
}

int			calibrate_rot(t_roll *r, int rot, int i)
{
	ft_printf("{bold}{underline}\nIN\tCALIBRATE_ROT{eoc}\n");
	ft_printf("r->nb_a = %d r->b_rot = %d rot = %d\n", r->nb_a, r->b_rot, rot);
	int		ret;

	ret = 0;
	if (rot <= r->nb_a / 2)
	{
		while (++i < rot)
			rotate(NULL, &r->a, 0);
		ret = ALBD ^ GOOD ? p_calibrate(r, rot, -1) : i_calibrate(r, rot, -1);
		while (i-- > 0)
			r_rotate(NULL, &r->a, 0);
	}
	else
	{
		i = r->nb_a;
		while (i-- > rot)
			r_rotate(NULL, &r->a, 0);
		ret = ALBD ^ GOOD ? p_calibrate(r, rot, -1) : i_calibrate(r, rot, -1);
		while (++i < r->nb_a)
			rotate(NULL, &r->a, 0);
	}
	ft_printf("{bold}{underline}END\tCALIBRATE_ROT{eoc}\n");
	return (ret);
}
