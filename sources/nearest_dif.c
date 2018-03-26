#include "push_swap.h"

static	void	next_dif(t_roll *r, int checker, int *best_dif_dep)
{
	int			i;
	int			fst;
	int			lst;
	int			n_dep_fst;
	int			n_dep_lst;

	i = -1;
	fst = r->nb_a;
	lst = 0;
	while (++i < r->nb_a)
	{
		fst == r->nb_a && ALBD & checker ? fst = i : 0;
		rotate(NULL, &r->a, 0);
	}
	while (i-- > 0)
	{
		!lst && ALBD & checker ? lst = i + 1 : 0;
		r_rotate(NULL, &r->a, 0);
	}
	n_dep_fst = r->nb_a - (r->nb_a - fst);
	n_dep_lst = r->nb_a - lst;
	*best_dif_dep = n_dep_fst <= n_dep_lst ? n_dep_fst : n_dep_lst;
	r->b_rot = (r->nb_a - (r->nb_a - fst) <= r->nb_a - lst) ? fst : lst;
}

static	void	next_insert(t_roll *r, int best_dif_dep, int fst, int lst)
{
	int			i;
	int			n_dep_fst;
	int			n_dep_lst;
	int			b_dep;

	i = -1;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD && ALBD & GOOD && fst == r->nb_a)
			value_insert(r, NULL, ATNBR, ALNBR) ? fst = i : 0;
		rotate(NULL, &r->a, 0);
	}
	while (i-- > 0)
	{
		if (ATBD & GOOD && ALBD & GOOD && !lst)
			value_insert(r, NULL, ATNBR, ALNBR) ? lst = i + 1 : 0;
		r_rotate(NULL, &r->a, 0);
	}
	fst == r->nb_a ? fst = r->nb_a / 2 : 0;
	!lst ? lst = r->nb_a / 2 : 0;
	n_dep_fst = r->nb_a - (r->nb_a - fst);
	n_dep_lst = r->nb_a - lst;
	b_dep = n_dep_fst <= n_dep_lst ? n_dep_fst : n_dep_lst;
	if (b_dep < best_dif_dep)
		r->b_rot = n_dep_fst <= n_dep_lst ? fst : lst;
}

void			nearest_rotation(t_roll *r, int checker, int fst, int lst)
{
	int			best_dif_dep;

	next_dif(r, checker, &best_dif_dep);
	next_insert(r, best_dif_dep, fst, lst);
	ALBD |= r->b_rot < r->nb_a / 2 ? ROT : R_ROT;
	if (ALBD & ROT)
	{
		ALBD &= ~ROT;
		if (nearest_checker(r, fst, lst))
			return ;
		return (rotate(r, &r->a, 'a'));
	}
	if (ALBD & R_ROT)
	{
		ALBD &= ~R_ROT;
		if (nearest_checker(r, fst, lst))
			return ;
		return (r_rotate(r, &r->a, 'a'));
	}
}
