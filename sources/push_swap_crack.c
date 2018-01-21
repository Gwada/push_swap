#include "push_swap.h"

void		crack_that_shit(t_tab *t, t_roll *r, int val)
{
	ft_printf("{black}{bold}{underline}IN CRACKER{eoc}\n");
	int		i = -1;
	int		rot = -1;

	while (++i < r->size)
	{
		rotate(NULL, &r->a);
		//rot = find_best_combi(t, &r->a);
		display_pile(&r->a, 'a');
	}

	(void)rot;
	(void)t;
	(void)val;
	ft_printf("{black}{bold}{underline}END CRACKER{eoc}\n\n");
}
