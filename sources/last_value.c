#include "push_swap.h"

static	void	easy_insert(t_roll *r, int rot, int min, int max)
{
//	ft_printf("{bold}{underline}{magenta}IN\tEASY{eoc}\n");
//	display_piles(r, &r->a, &r->b);
	int			i;
	int			value;

	i = -1;
	value = BLNBR;
//	ft_printf("rot = %d value = %d min = %d max = %d\n", rot, value, min, max);
	if (ATBD & GOOD)
	{
//		ft_printf("ATBD & GOOD 1\n");
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
		while (BLNBR > ATNBR && BLNBR < max)
		{
			simple_push(r, &r->b, &r->a, 'a');
			ALBD = GOOD;
			BLNBR < max && BLNBR > ATNBR ? rotate(r, &r->a, 'a') : 0;
		}
	}
	else if (ALBD & GOOD)
	{
//		ft_printf("ALBD & GOOD 1\n");
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
		while (BLNBR > min && BLNBR < ALNBR)
		{
			simple_push(r, &r->b, &r->a, 'a');
			ALBD = GOOD;
			BTNBR > min && BTNBR < ALNBR ? r_rotate(r, &r->b, 'b') : 0;
		}
	}
//	ft_printf("rot = %d value = %d min = %d max = %d\n", rot, value, min, max);
//	ft_printf("{bold}{underline}{magenta}END\tEASY{eoc}\n\n");
}

static	void	hard_insert(t_roll *r, int rot, int min, int max)
{
//	ft_printf("{bold}{underline}{blue}IN\tHARD\t");
//	ft_printf("rot = %d\tmin = %d\tmax = %d{eoc}\n\n", rot, min, max);
//	display_piles(r, &r->a, &r->b);
	int			i;
	int			value;

	i = -1;
	if (ALBD & GOOD)
	{
//		ft_printf("{magenta}{underline}ALBD & GOOD{eoc}\n");
		if (r->b_max > max && (rot = -1) && (i = -1))
		{
//			ft_printf("{yellow}r->b_max = %d > max{eoc}\n", r->b_max);
			while (++i < r->nb_b)
			{
				rot == -1 && BLNBR > max ? value = BLNBR : 0;
				rot == -1 && BLNBR > max ? rot = i : 0;
				rot > -1 && BLNBR > max && BLNBR < value ? value = BLNBR : 0;
				rot > -1 && BLNBR > max && BLNBR < value ? rot = i : 0;
				rotate(NULL, &r->b, 0);
			}
			if (rot <= r->nb_b / 2)
				while (rot-- > 0)
				{
					rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			else
				while (rot++ < r->nb_b)
				{
					r_rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			while (BLNBR > ALNBR && BLNBR > max)
			{
//				display_piles(r, &r->a, &r->b);
				simple_push(r, &r->b, &r->a, 'a');
				ALBD = GOOD;
//				display_piles(r, &r->a, &r->b);
				rotate(r, &r->a, 'a');
			}
		}
		if (r->b_min < min && (rot = -1) && (i = -1))
		{
//			ft_printf("{yellow}r->b_min = %d < min = %d{eoc}\n", r->b_min, min);
			while (++i < r->nb_b)
			{
				rot == -1 && BLNBR < min ? value = BLNBR : 0;
				rot == -1 && BLNBR < min ? rot = i : 0;
				rot > -1 && BLNBR < min && BLNBR < value ? rot = i : 0;
				rot > -1 && BLNBR < min && BLNBR < value ? value = BLNBR : 0;
				rotate(NULL, &r->b, 0);
			}
			if (rot <= r->nb_b / 2)
				while (rot-- > 0)
				{
					rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			else
				while (rot++ < r->nb_b)
				{
					r_rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			while (BLNBR < min && BLNBR < ALNBR)
			{
//				display_piles(r, &r->a, &r->b);
				simple_push(r, &r->b, &r->a, 'a');
				ALBD = GOOD;
//				display_piles(r, &r->a, &r->b);
				rotate(r, &r->a, 'a');
			}
			rotate(r, &r->a, 'a');
		}
	}
	else if (ATBD & GOOD)
	{
//		ft_printf("{magenta}{underline}ATBD & GOOD{eoc}\n");
		if (r->b_max > max && (rot = -1) && (i = -1))
		{
//			ft_printf("{yellow}r->b_max = %d > max{eoc}\n", r->b_max);
			while (++i < r->nb_b)
			{
				rot == -1 && BLNBR > max ? value = BLNBR : 0;
				rot == -1 && BLNBR > max ? rot = i : 0;
				rot > -1 && BLNBR > max && BLNBR < value ? value = BLNBR : 0;
				rot > -1 && BLNBR > max && BLNBR < value ? rot = i : 0;
				rotate(NULL, &r->b, 0);
			}
			if (rot <= r->nb_b / 2)
				while (rot-- > 0)
				{
					rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			else
				while (rot++ < r->nb_b)
				{
					r_rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			while (BLNBR > ALNBR && BLNBR > max)
			{
//				display_piles(r, &r->a, &r->b);
				simple_push(r, &r->b, &r->a, 'a');
				ALBD = GOOD;
//				display_piles(r, &r->a, &r->b);
				rotate(r, &r->a, 'a');
			}
		}
		if (r->b_min < min && (rot = -1) && (i = -1))
		{
//			ft_printf("{yellow}r->b_min = %d < min{eoc}\n", r->b_min);
			while (++i < r->nb_b)
			{
				rot == -1 && BLNBR < min ? value = BLNBR : 0;
				rot == -1 && BLNBR < min ? rot = i : 0;
				rot > -1 && BLNBR < min && BLNBR < value ? value = BLNBR : 0;
				rot > -1 && BLNBR < min && BLNBR < value ? rot = i : 0;
				rotate(NULL, &r->b, 0);
			}
			if (rot <= r->nb_b / 2)
				while (rot-- > 0)
				{
					rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			else
				while (rot++ < r->nb_b)
				{
					r_rotate(r, &r->b, 'b');
//					display_piles(r, &r->a, &r->b);
				}
			while (BLNBR < min && BLNBR < ALNBR)
			{
//				display_piles(r, &r->a, &r->b);
				simple_push(r, &r->b, &r->a, 'a');
				ALBD = GOOD;
//				display_piles(r, &r->a, &r->b);
				rotate(r, &r->a, 'a');
			}
		}
	}
//	display_piles(r, &r->a, &r->b);
//	ft_printf("{bold}{underline}{blue}END\tHARD{eoc}\n\n");
}

int			value_insert(t_roll *r, int *rt, int min, int max)
{
//	ft_printf("{bold}{underline}{green}IN\tVALUE INSERT min = %d max = %d\n{eoc}", min, max);
	int		i;
	int		test;

	i = -1;
	test = 0;
	while (++i < r->nb_b)
	{
		rt && min < max && !test && BLNBR > min && BLNBR < max ? *rt = i : 0;
		rt && min > max && !test && (BLNBR < min || BLNBR > max) ? *rt = i : 0;
		min < max && !test && BLNBR > min && BLNBR < max ? test = 1 : 0;
		min > max && !test && (BLNBR > min || BLNBR < max) ? test = 1 : 0;
		rotate(NULL, &r->b, 0);
	}
//	ft_printf("%s\n", test ? "VALUE" : "NO VALUE");
//	ft_printf("{bold}{underline}{green}END\tVALUE INSERT\n\n{eoc}");
	return (test);

}

int			b_push(t_roll *r, int min, int max)
{
//	ft_printf("{bold}{red}{underline}IN\tB_PUSH\t");
//	ft_printf("min = %d\tmax = %d{eoc}\n", min, max);
//	display_piles(r, &r->a, &r->b);
//	ft_printf("test 3\n");
	int		rot;
	int		test;

	rot = 0;
	test = value_insert(r, &rot, min, max);
//	display_piles(r, &r->a, &r->b);
	test && min < max ? easy_insert(r, rot, min, max) : 0;
	test && min > max ? hard_insert(r, -1, max, min) : 0;
//	display_piles(r, &r->a, &r->b);
//	!test ? ft_printf("{red}{bold}NO\n{eoc}") : ft_printf("{red}{bold}YES\n{eoc}");
//	ft_printf("test 3\n");
//	ft_printf("{bold}{red}{underline}END\tB_PUSH\t");
//	ft_printf("%s{eoc}\n\n", test ? "insertion" : "no value");
	return (test ? 1 : 0);
}
