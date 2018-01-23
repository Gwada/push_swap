#include "push_swap.h"

static int	find_best_comb(t_tab *t, t_roll *r, int good, int i)
{
	ft_printf("\n{red}in best comb{eoc}\n");//
	t_pile	*tmp;

	tmp = r->a.low;
//	display_pile(&r->a, 'A');//
	while (++i < r->size && !tmp->root)
	{
		tmp->nbr == (int)t[i].n ? ++good : 0;
		tmp = tmp->low;
	}
	ft_printf("{red}end best comb{eoc}\n\n");//
	return (good);
}

static void	find_best_rot(t_roll *r)
{
	ft_printf("\n{red}in best rot{eoc}\n");//
//	r->cor ? ft_printf("r->cor\t= %d\n", r->cor) : 0;//
//	r->b_rot ? ft_printf("b_rot\t= %d\n", r->b_rot) : 0;//
//	display_pile(&r->a, 'A');///
	if (r->b_rot > r->size / 2)
	{
	//	ft_printf ("best rot > size / 2 (rotate)\n");//
		while (r->b_rot++ < r->size)
		{
			rotate(NULL, &r->a);
			r->a.low->bd |= R_ROT;
		}
	}
	else
	{
	//	ft_printf ("best rot <= size / 2 (r_rotate)\n");//
		while (r->b_rot--)
		{
			r_rotate(NULL, &r->a);
			r->a.low->bd |= ROT;
		}
	}
//	display_pile(&r->a, 'A');///
	ft_printf("{red}end best rot{eoc}\n\n");//
}

static void	find_best_sort(t_tab *t, t_roll *r)
{
	(void)r;
	(void)t;
	ft_printf("in best sort\n");
}

void		crack_that_shit(t_tab *t, t_roll *r, int rot)
{
	ft_printf("{black}{bold}{underline}IN CRACKER{eoc}\n");//
	int		i = 0;

	while (++i <= r->size && r->cor != r->size)
	{
		rotate(NULL, &r->a);
		rot = find_best_comb(t, r, 0, -1);
		rot > r->cor ? r->b_rot = i : 0;
		rot > r->cor ? r->cor = rot : 0;
	}
	r->cor == r->size ? find_best_rot(r) : find_best_sort(t, r);


	r->cor == r->size ? ft_printf("{green}{underline}ONLY ROTATE{eoc}\n") : 0;//
	r->cor != r->size ? ft_printf("{red}{underline}NEED MORE{eoc}\n") : 0;//
//	display_pile(&r->a, 'A');///
	ft_printf("{black}{bold}{underline}END CRACKER{eoc}\n\n");//
}
