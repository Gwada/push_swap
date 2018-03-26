# include "push_swap.h"

static	int		is_present(int *t, int n, int value)
{
	int			i;

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
	int			i;
	int			j;

	i = 0;
	while (--size >= 0)
	{
		if (ALBD == NO_CHECK && is_present(t, nb_cor, ALNBR) && !(j = 0))
		{
			if (ALNBR >= *t && ALNBR <= t[i] && (ALBD = GOOD))
				while(*t < ALNBR && !(i = 0))
				{
					++t;
					--nb_cor;
				}
			else if (++i)
				while (t[j] < ALNBR && (ALBD = CHECK))
					++j;
			while (++j < nb_cor)
				t[j - 1] = t[j];
			--nb_cor;
		}
		rotate(NULL, &r->a, 0);
	}
}

static	void	section_sort(t_roll *r, int size, int min, int max)
{
	int			i;
	int			nb_check;
	int			verif[size];

	i = -1;
	nb_check = 0;
	while (++i < size)
	{
		r_rotate(NULL, &r->a, 0);
		if (ALNBR >= min && ALNBR <= max && ALBD ^ GOOD)
		{
			ALBD = NO_CHECK;
			verif[nb_check++] = ALNBR;
		}
	}
	nb_check > 1 ? ft_qsort(verif, nb_check, 0, 0) : 0;
	finition_sort(r, verif, size, nb_check);
}

static	void	section_sort_v2(t_roll *r, int size, int i, int j)
{
	int			min;
	int			verif[size];

	while (++i < r->nb_a)
	{
		ALBD & GOOD ? verif[j++] = r->a.LNBR : 0;
		rotate(NULL, &r->a, 0);
	}
	j = 0;
	min = *verif;
	while (--i >= 0)
	{
		ALBD & GOOD && ++j ? min = verif[j - 1] : 0;
		if ((ALBD & CHECK || ALBD & NO_CHECK) && ALNBR < verif[j]
		&& ALNBR > min && (min = ALNBR))
			ALBD = GOOD;
		rotate(NULL, &r->a, 0);
	}
}

void			first_step(t_roll *r, t_tab *t, int i, int start)
{
	int			cor;

	cor = 0;
	find_best_rotation(r, r->nb_a - r->b_rot, 0);
	while (++i < r->nb_a)
	{
		ALBD = (int)t[i].n == ALNBR ? GOOD : PUSH;
		(int)t[i].n == ALNBR ? ++cor : 0;
		if (((int)t[i].n == ALNBR) || (cor && i == r->nb_a - 1))
			section_sort(r, i - start, (int)t[start].n, (int)t[i].n);
		(int)t[i].n == ALNBR ? start = i : 0;
		rotate(NULL, &r->a, 0);
	}
	if (cor)
	{
		start = 0;
		while (--i >= 0)
		{
			(ALBD & GOOD || ALBD & CHECK) ? ++start : 0;
			rotate(NULL, &r->a, 0);
		}
		section_sort_v2(r, start, -1, 0);
	}
	find_best_rotation(r, r->b_rot, 0);
	cor > 0 ? check_limits(r, -1, 0, 0) : 0;
}
