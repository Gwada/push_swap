#include "push_swap.h"

static	void	init_best(t_roll *r, int *best, int i)
{
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	while (++i < (int)r->nb_a)
	{
		best[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
}

void		finition_sort(t_roll *r, int *t, int start, int end)
{
//	ft_printf("{red}{bold}IN\tFINITION{eoc}\n");/////////////////////////////////
//	ft_printf("before\t: r->a.LNBR %d\n", r->a.LNBR);////////////////////////////
	int		min = t[start];
	int		max = t[end];
	int		i = 0;

//	ft_printf("{bold}{yellow}indice : start\t= [%2d] end = [%2d]\n", start, end);//
//	ft_printf("valeur : min\t= [%2d] max = [%2d]{eoc}\n", min, max);/////////////
	while (++i < end - start)
		r_rotate(NULL, &r->a, 0);
	i = -1;
	while (++i < end - start - 1)
	{
//		ft_printf("t[%3d] = {green}[%10d]{eoc}\t", start + i, t[start + i]);/////
//		ft_printf("r->a.LNBR = {red}[%10d]{eoc}\t", r->a.LNBR);//////////////////
		if (r->a.LNBR >= min && r->a.LNBR <= max)
		{
			r->a.low->bd &= ~PUSH;
			r->a.low->bd |= GOOD;
//			ft_printf("{green}{bold}GOOD\t");////////////////////////////////////
//			ft_printf("min <= r->a.LNBR <= max{eoc}\n");/////////////////////////
		}
//		else/////////////////////////////////////////////////////////////////////
//			ft_printf("{red}{bold}PUSH{eoc}\n");/////////////////////////////////
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("\n");/////////////////////////////////////////////////////////////
//	ft_printf("\nafter\t: r->a.LNBR %d\n", r->a.LNBR);///////////////////////////
//	ft_printf("{bold}{red}END\tFINITION{eoc}\n\n");//////////////////////////////
}

void		find_best_sort(int *t, t_roll *r, int size, int i)
{
//	ft_printf("{blue}{bold}{underline}IN\tFIND BEST SORT{eoc}\n");///////////////
	int		best[size];
	int		start = 0;

	init_best(r, best, -1);
	while (++i < r->nb_a)
	{
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
		if (r->a.low->bd & GOOD || i == r->nb_a - 1)
		{
			i - start > 1 ? finition_sort(r, t, start, i) : 0;
		}
		r->a.low->bd & GOOD ? start = i : 0;
		rotate(NULL, &r->a, 0);
//		ft_printf("{red}{bold}----------------------------------------------------------------------{eoc}\n");//
	}
	find_best_rotation(r, r->b_rot, 0);
//	ft_printf("{blue}{bold}{underline}END\tFIND BEST SORT{eoc}\n");//////////////
}

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
