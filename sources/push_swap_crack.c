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

void		pile_sort(t_roll *r, int *t, int size, int i)
{
	while (++i < size)
	{
		t[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, size, 0, 0);
}

static	int		is_present(int *t, int n, int value)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (t[i] == value)
			return (1);
	}
	return (0);
}

static	void	finition_sort(t_roll *r, int *t, int size, int nb_cor)
{
	ft_printf("\n{cyan}{bold}IN\tFINITION\tsize = %d\tnb_cor = %d{eoc}\n\n", size, nb_cor);//
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	while (++i < size)
	{
		if (r->a.LBD & NO_CHECK && nb_cor && is_present(t, nb_cor, r->a.LNBR))
		{
			if (r->a.LNBR >= *t && r->a.LNBR <= t[j])
			{
				r->a.LBD = GOOD;
				while(*t < r->a.LNBR)
				{
					++t;
					--nb_cor;
				}
				j = 0;
				while (++j < nb_cor)
					t[j - 1] = t[j];
				j = 0;
			}
			else
			{
				k = 0;
				r->a.LBD = CHECK;
				while (t[k] < r->a.LNBR)
					++k;
				while (++k < nb_cor)
					t[k - 1] = t[k];
				++j;
			}
			--nb_cor;
		}
		rotate(NULL, &r->a, 0);
	}
	rotate(NULL, &r->a, 0);
	ft_printf("\n{cyan}{bold}END\tFINITION\tsize = %d{eoc}\n", size);///////////////
}

void		section_sort(t_roll *r, int size, int min, int max)
{
	ft_printf("{red}{bold}IN\tSECTION\tsize = %d{eoc}\n", size);////////////////
	ft_printf("{bold}{yellow}{underline}before{runderline}\n");//////////////////
	ft_printf("r->a.LNBR\t= %10d\n", r->a.LNBR);/////////////////////////////////
	int		i;
	int		nb_check;
	int		verif[size];

	i = -1;
	nb_check = 0;
	ft_printf("min\t\t= %10d\nmax\t\t= %10d{eoc}\n", min, max);///////////////////////
	while (++i < size)
	{
		r_rotate(NULL, &r->a, 0);
		if (r->a.LNBR >= min && r->a.LNBR <= max && r->a.low->bd ^ GOOD)
		{
			r->a.low->bd = NO_CHECK;
			verif[nb_check] = r->a.LNBR;
			++nb_check;
		}
	}
	nb_check > 1 ? ft_qsort(verif, nb_check, 0, 0) : 0;
	finition_sort(r, verif, size, nb_check);
	ft_printf("\n{bold}{yellow}{underline}after{runderline}\n");/////////////////
	ft_printf("r->a.LNBR\t= %10d\n", r->a.LNBR);/////////////////////////////////
	ft_printf("min\t\t= %10d\nmax\t\t= %10d\n", min, max);///////////////////////
	ft_printf("{bold}{red}END\tSECTION{eoc}\n\n");//////////////////////////////
}

void		find_best_sort(int *t, t_roll *r, int size, int i)
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
