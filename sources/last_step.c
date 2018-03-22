#include "push_swap.h"

static	void	fixe_fst(t_roll *r, int *fst, int *l_min, int *l_max)
{
	int			i;

	i = -1;
	*fst = r->nb_a;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD && *fst == r->nb_a)
		{
			*l_min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			*l_max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			value_insert(r, NULL, *l_min, *l_max) ? *fst = i : 0;
		}
		rotate(NULL, &r->a, 0);
	}
}

static	void	fixe_lst(t_roll *r, int *lst, int *t_min, int *t_max)
{
	int			i;

	i = r->nb_a;
	*lst = 0;
	while (i-- > 0)
	{
		if (ALBD & GOOD && !lst)
		{
			*t_max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			*t_min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			value_insert(r, NULL, *t_min, *t_max) ? *lst = i + 1 : 0;
		}
		r_rotate(NULL, &r->a, 0);
	}
}

static	void	clean_b(t_roll *r, int fst, int lst, int value)
{
	ft_printf ("{green}{bold}{underline}IN CLEAN{eoc}\n");
	int			l_min;
	int			l_max;
	int			t_min;
	int			t_max;

	while (r->nb_b > 0)
	{
		fixe_fst(r, &fst, &l_min, &l_max);
		fixe_lst(r, &lst, &t_min, &t_max);
		r->b_rot = r->nb_a - (r->nb_a - fst) <= r->nb_a - lst ? fst : lst;
		value = r->b_rot;
		if (r->b_rot <= r->nb_a / 2)
			while (r->b_rot-- > 0)
				rotate(r, &r->a, 'a');
		else
			while (r->b_rot++ < r->nb_a)
				r_rotate(r, &r->a, 'a');
		value == fst ? b_push(r, l_min, l_max) : b_push(r, t_min, t_max);
	}
	ft_printf ("{green}{bold}{underline}END CLEAN{eoc}\n");
}

void			last_step(t_roll *r, int i)
{
	clean_b(r, r->nb_a, 0, 0);
	while (++i < r->nb_a)
	{
		ALNBR == r->a_min ? r->b_rot = i : 0;
		rotate(NULL, &r->a, 0);
	}
	if (r->b_rot <= r->nb_a / 2)
		while (r->b_rot-- > 0)
			rotate(r, &r->a, 'a');
	else
		while (r->b_rot++ < r->nb_a)
			r_rotate(r, &r->a, 'a');
}

