#include "push_swap.h"

static	void	easy_insert(t_roll *r, int rot, int min, int max)
{
	int			i;
	int			value;

	i = -1;
	value = BLNBR;
	if (!rot && (rot = r->nb_b))
		while (++i < r->nb_b)
		{
			r_rotate(NULL, &r->b, 0);
			BLNBR > min && BLNBR < max && BLNBR > value ? --rot : 0;
		}
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (BLNBR > min && BLNBR < max)
		simple_push(r, &r->b, &r->a, 'a');
}

static	void	hard_insert(t_roll *r, int rot, int min, int max)
{
	int			i;

	i = r->nb_b;
	while (i > 0)
	{
		rot == -1 && BLNBR == r->b_min ? rot = i : 0;
		rot != -1 && BLNBR > r->b_min && BLNBR < min ? rot = i : 0;
		r_rotate(NULL, &r->b, 0);
		--i;
	}
	if (rot <= r->nb_b / 2)
		while (rot-- > 0)
			rotate(r, &r->b, 'b');
	else
		while (rot++ < r->nb_b)
			r_rotate(r, &r->b, 'b');
	while (BLNBR != r->b_max && BLNBR < min)
		simple_push(r, &r->b, &r->a, 'a');
	while (BLNBR > max)
		simple_push(r, &r->b, &r->a, 'a');
}

int			value_insert(t_roll *r, int *rt, int min, int max)
{
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
	return (test);

}

int			b_push(t_roll *r, int min, int max)
{
//	ft_printf("{bold}{red}{underline}IN\tB_PUSH\t");
//	ft_printf("min = %d\tmax = %d\ti = %d{eoc}\n", min, max, i);
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
	return (test ? 1 : 0);
}
