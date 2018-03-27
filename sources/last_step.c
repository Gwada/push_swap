#include "push_swap.h"

static	void	fixe_low(t_roll *r, int *fst, int *l_min, int *l_max)
{
	int			i;

	i = -1;
	*fst = -1;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD && *fst == -1)
		{
			*l_min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			*l_max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			if (value_insert(r, NULL, *l_min, *l_max))
			{
				*fst = i;
				ft_printf("fst = %d l_min = %d l_max = %d\n", *fst, *l_min, *l_max);
			}
		}
		rotate(NULL, &r->a, 0);
	}
}

static	void	fixe_top(t_roll *r, int *lst, int *t_min, int *t_max)
{
	ft_printf("{bold}{yellow}IN\tFIXE_TOP{eoc}\n");
	int			i;

	i = r->nb_a + 1;
	*lst = -1;
	while (--i > 0)
	{
		if (ALBD & GOOD && *lst == -1)
		{
			*t_max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			*t_min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			if (value_insert(r, NULL, *t_min, *t_max))
			{
				*lst = i;
				ft_printf("lst = %d t_min = %d t_max = %d\n", *lst, *t_min, *t_max);
			}
		}
		r_rotate(NULL, &r->a, 0);
	}
	ft_printf("{bold}{yellow}END\tFIXE_TOP{eoc}\n");
}

void			clean_b(t_roll *r, int fst, int lst, int value)
{
	ft_printf ("{green}{bold}{underline}IN CLEAN{eoc}\n");
	int			l_min;
	int			l_max;
	int			t_min;
	int			t_max;

	while (r->nb_b > 0)
	{
		fixe_low(r, &fst, &l_min, &l_max);
		fixe_top(r, &lst, &t_min, &t_max);
		r->b_rot = r->nb_a - (r->nb_a - fst) <= r->nb_a - lst ? fst : lst;
		value = r->b_rot;
		ft_printf("r->b_rot = %d fst = %d lst = %d\n", r->b_rot, fst, lst);
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

