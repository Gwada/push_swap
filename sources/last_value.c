#include "push_swap.h"

static	void	easy_insert(t_roll *r, int rot, int min, int max)
{
//	ft_printf("{bold}{cyan}{underline}IN\tEASY\n");
//	display_piles(r, &r->a, &r->b);
	int			i;
	int			value;

	i = -1;
	value = BLNBR;
	if (!rot && (rot = r->nb_b))
	{
		while (++i < r->nb_b)
		{
			r_rotate(NULL, &r->b, 0);
			BLNBR > min && BLNBR < max && BLNBR > value ? --rot : 0;
		}
	}
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (BLNBR > min && BLNBR < max)
		simple_push(r, &r->b, &r->a, 'a');
//	display_piles(r, &r->a, &r->b);
//	ft_printf("{bold}{cyan}{underline}END\tEASY\n");
}

static	void	hard_insert(t_roll *r, int min, int max)
{
//	ft_printf("{bold}{green}{underline}IN\tHARD\n");
//	display_piles(r, &r->a, &r->b);
	int			i;
	int			rot;

	i = -1;
	rot = 0;
	while (r->b_min < min && ++i < r->nb_b)
	{
		BLNBR == r->b_min ? rot = i : 0;
		rotate(NULL, &r->b, 0);
	}
	while (r->b_min > min && r->b_max > max && ++i < r->nb_b)
	{
		BLNBR == r->b_max ? rot = i : 0;
		rotate(NULL, &r->b, 0);
	}
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	r->b_min < min ? simple_push(r, &r->b, &r->a, 'a') : 0;
	while (BTNBR < min)
	{
		r_rotate(r, &r->b, 'b');
		simple_push(r, &r->b, &r->a, 'a');
	}
	while (BLNBR > max)
		simple_push(r, &r->b, &r->a, 'a');
//	display_piles(r, &r->a, &r->b);
//	ft_printf("{bold}{green}{underline}END\tHARD\n");
}

int			value_insert(t_roll *r, int *rot, int min, int max)
{
//	ft_printf("min = %d\tmax = %d\t{eoc}\n", min, max);
	int		i;
	int		test;

	i = -1;
	test = 0;
	while (++i < r->nb_b)
	{
		min < max && !test && BLNBR > min && BLNBR < max ? *rot = i : 0;
		min < max && !test && BLNBR > min && BLNBR < max ? test = 1 : 0;
		min > max && !test && (BLNBR < min || BLNBR > max) ? *rot = i : 0;
		min > max && !test && (BLNBR > min || BLNBR > max) ? test = 1 : 0;
		rotate(NULL, &r->b, 0);
	}
	return (test);
}

void			b_push(t_roll *r, int min, int max)
{
//	ft_printf("{bold}{red}{underline}IN\tB_PUSH\t");
//	ft_printf("min = %d\tmax = %d\ti = %d{eoc}\n", min, max, i);
//	display_piles(r, &r->a, &r->b);
	int		rot;
	int		test;

	rot = 0;
	test = value_insert(r, &rot, min, max);
	display_piles(r, &r->a, &r->b);
	test && min < max ? easy_insert(r, rot, min, max) : 0;
	test && min > max ? hard_insert(r, max, min) : 0;
//	display_piles(r, &r->a, &r->b);
//	!test ? ft_printf("{red}{bold}NO\n{eoc}") : ft_printf("{red}{bold}YES\n{eoc}");
}
