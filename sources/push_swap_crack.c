#include "push_swap.h"

void		pile_sort(t_roll *r, int *t, int size, int i)
{
	while (++i < size)
	{
		t[i] = r->a.LNBR;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, size, 0, 0);
}

void		find_best_rotation(t_roll *r, int rot, int state)
{
	//if (rot == r->nb_a)
	//	return ;
	!rot ? rot = 1 : 0;
	rot < 0 ? rot = -rot : 0;
	ft_printf("r->nb_a = %d rot = %d\n", r->nb_a, rot);
	if (rot > (int)r->nb_a / 2)
		while (rot++ < r->nb_a)
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
	display_piles(r, &r->a, &r->b);
}

void		fixe_best_rotate(t_roll *r, int min, int max, int i)
{
	int		j;

	j = 0;
	while (ATBD ^ GOOD && --r->b_rot)
		r_rotate(NULL, &r->a, 0);
	j = ALNBR;
	while (++i < r->nb_a)
	{
		if (ALBD & GOOD && max >= min && (max = ALNBR))
		{
			while (ALNBR != j)
				r_rotate(NULL, &r->a, 0);
			while (ALNBR != max)
			{
				ALNBR >= min && ALNBR <= max ? ALBD |= GOOD : 0;
				ALNBR >= min && ALNBR <= max ? min = ALNBR : 0;
				rotate(NULL, &r->a, 0);
			}
			j = ALNBR;
			min = ALNBR;
		}
		ALBD & GOOD && ALNBR < min ? ALBD = NO_CHECK : 0;
		rotate(NULL, &r->a, 0);
	}
	find_best_rotation(r, r->b_rot, 0);
}

void		find_best_combinaison(int *t, t_roll *r, int i)
{
	int		j;
	int		cor;
	t_pile	*tmp;

	r->b_rot = 0;
	r->cor = 0;
	while (++i < r->nb_a)
	{
		tmp = &r->a;
		j = -1;
		cor = 0;
		while (++j < r->nb_a)
		{
			tmp->LNBR == t[j] ? ++cor : 0;
			rotate(NULL, tmp, 0);
		}
		cor > r->cor ? r->b_rot = i : 0;
		cor > r->cor ? r->cor = cor : 0;
		rotate(NULL, &r->a, 0);
	}
}
