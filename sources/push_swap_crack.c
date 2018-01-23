#include "push_swap.h"

static int	find_best_comb(t_tab *t, t_roll *r, int good, int i)
{
	t_pile	*tmp;

	tmp = r->a.low;
	display_pile(&r->a, 'A');///
	while (++i < r->size && !tmp->root)
	{
		tmp->nbr == (int)t[i].n ? ++good : 0;
		tmp = tmp->low;
	}
	return (good);
}

void		crack_that_shit(t_tab *t, t_roll *r, int val)
{
	ft_printf("{black}{bold}{underline}IN CRACKER{eoc}\n");
	int		i = -1;
	int		rot;

	while (++i < r->size)
	{
		rotate(NULL, &r->a);
		rot = find_best_comb(t, r, 0, -1);
		rot > r->cor ? val = i : 0;
		rot > r->cor ? r->cor = rot : 0;
	//	ft_printf("good = %d\n", rot);//
	//	ft_printf("cor = %d\n", r->cor);//
	//	ft_printf("val = %d\n", val);//
	}
	r->cor == r->size ? ft_printf("{green}{underline}ONLY ROTATE{eoc}\n") : 0;
	r->cor != r->size ? ft_printf("{red}{underline}NEED MORE{eoc}\n") : 0;
	ft_printf("{black}{bold}{underline}END CRACKER{eoc}\n\n");
}
