#include "push_swap.h"

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
//	ft_printf("min = %d\tmax = %d{eoc}\n", min, max);
//	display_piles(r, &r->a, &r->b);
//	ft_printf("test 3\n");
	int		rot;
	int		test;

	rot = 0;
	test = value_insert(r, &rot, min, max);
//	display_piles(r, &r->a, &r->b);
	if (test && min < max)
	{
		if (easy_insert(r, ALNBR, 2, -1) == 1)
			right_insert(r, rot, min, max);
		else
			left_insert(r, rot, min, max);
	}
	test && min > max ? hard_insert(r, -1, max, min) : 0;
//	display_piles(r, &r->a, &r->b);
//	!test ? ft_printf("{red}{bold}NO\n{eoc}") : ft_printf("{red}{bold}YES\n{eoc}");
//	ft_printf("test 3\n");
//	ft_printf("{bold}{red}{underline}END\tB_PUSH\t");
//	ft_printf("%s{eoc}\n\n", test ? "insertion" : "no value");
	return (test ? 1 : 0);
}
