#include "push_swap.h"

/*static	void	init_best(t_roll *r, int *best, int i)
{
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	while (++i < (int)r->nb_a)
	{
		best[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
}*/

void		pile_sort(t_roll *r, int *t, int size, int i)
{
	while (++i < size)
	{
		t[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, size, 0, 0);
}

/*void		find_best_sort(int *t, t_roll *r, int size, int i)
{
//	ft_printf("{blue}{bold}{underline}IN\tFIND BEST SORT{eoc}\n");///////////////
	int		best[size];
	int		start = 0;

	init_best(r, best, -1);
	while (++i < r->nb_a)
	{
	//	ft_printf("{green}t[%3d] =\t[%10d]\t{magenta}r->a.LNBR =\t[%10d]{eoc}\n", i, t[i], r->a.LNBR);//
		if (best[i] != t[i])
		{
			if (r->a.top->bd & SWAP)
				r->a.low->bd |= GOOD;
			else if ((best[i] == t[i + 1] && best[i + 1] == t[i]))
			{
				r->a.low->bd |= SWAP;
				rotate(NULL, &r->a, 0);
				r->a.low->bd |= GOOD;
				++i;
			}
			else if (i == r->nb_a - 1 && t[0] == best[0] && t[1] == best[i])
				r->a.low->bd |= SWAP;
			else if ((i < r->nb_a - 1 && t[i + 1] == best[i])
			|| (i == r->nb_a - 1 && t[0] == best[i])
			|| (i && t[i - 1] == best[i]) || (!i && t[r->nb_a - 1] == best[i]))
				r->a.low->bd |= GOOD;
			else
				r->a.low->bd |= PUSH;
		}
		else
		{
			if (i && i < r->nb_a - 1 && best[i - 1] == t[i + 1])
				r->a.top->bd = SWAP;
			else if (i && i < r->nb_a - 1 && best[i + 1] == t[i - 1])
				r->a.low->bd = SWAP;
			else
				r->a.low->bd |= GOOD;
		}
	//	if (r->a.low->bd & GOOD || i == r->nb_a - 1)
	//	{
	//		i - start > 1 ? finition_sort(r, t, start, i) : 0;
	//	}
		r->a.low->bd & GOOD ? start = i : 0;
		rotate(NULL, &r->a, 0);
//		ft_printf("{red}{bold}----------------------------------------------------------------------{eoc}\n");//
	}
	find_best_rotation(r, r->b_rot, 0);
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST SORT{eoc}\n");//////////////
}*/

void		find_best_rotation(t_roll *r, int rot, int state)
{
	if (rot > (int)r->nb_a / 2)
		while (rot++ < (int)r->nb_a)
		{
			rotate(NULL, &r->a, 0);
			state & R_ROT ? r->a.low->bd |= R_ROT : 0;
		}
	else
		while (rot-- > 0)
		{
			r_rotate(NULL, &r->a, 0);
			state & ROT ? r->a.low->bd |= ROT : 0;
		}
}

void			find_best_combinaison(int *t, t_roll *r, int i)
{
//	ft_printf("{blue}{bold}{underline}\nIN\tFIND BEST COMBINAISON{eoc}\n");//////
	int			j;
	int			cor;
	t_pile		*tmp;

	r->b_rot = 0;
	r->cor = 0;
	while (++i < (int)r->nb_a)
	{
		tmp = &r->a;
		j = -1;
		cor = 0;
		while (++j < (int)r->nb_a)
		{
			tmp->LNBR == t[j] ? ++cor : 0;
			rotate(NULL, tmp, 0);
		}
		cor > r->cor ? r->b_rot = i : 0;
		cor > r->cor ? r->cor = cor : 0;
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST COMBINAISON{eoc}\n\n");/////
}
