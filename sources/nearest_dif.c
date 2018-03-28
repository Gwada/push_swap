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
	ft_printf("{bold}{yellow}{underline}IN\tNEXT_INSERT{eoc}\n");
	int			i;
	int			n_dep_fst;
	int			n_dep_lst;
	int			b_dep;
	int			max;

	i = -1;
	while (++i < r->nb_a)
	{
		if (ATBD & GOOD && fst == -1)
		{
			lst = r->nb_a - i;
			while (ALBD ^ GOOD && --lst != r->nb_a + 1)
				rotate(NULL, &r->a, 0);
			max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			value_insert(r, NULL, ATNBR, max) ? fst = i : 0;
		}
		rotate(NULL, &r->a, 0);
	}
	ft_printf("1. fst = %d lst = %d\n", fst, lst);
	if (fst != -1)
	{
	//	fst == r->nb_a ? fst = r->nb_a / 2 : 0;
	//	!lst ? lst = r->nb_a / 2 : 0;
	//	ft_printf("2. fst = %d lst = %d\n", fst, lst);
		n_dep_fst = r->nb_a - (r->nb_a - fst);
		n_dep_lst = r->nb_a - lst;
		b_dep = n_dep_fst <= n_dep_lst ? n_dep_fst : n_dep_lst;
		ft_printf("3. n_dep_fst = %d\n", n_dep_fst);
		ft_printf("3. n_dep_lst = %d\n", n_dep_lst);
		ft_printf("%d deplacements pour l'insertion la plus proche ", b_dep);
		ft_printf("et %d pour lelement a trier le plus proche\n", best_dif_dep);
		if (b_dep <= best_dif_dep)
		{
			r->b_rot = n_dep_fst <= n_dep_lst ? fst : lst;
			ft_printf("{bold}{yellow}la prochaine etape est une insertion b -> a\n{eoc}");
			ft_printf("{bold}{yellow}r->b_rot = %d\n{eoc}", r->b_rot);
		}
	}
	ft_printf("{bold}{yellow}{underline}END\tNEXT_INSERT{eoc}\n");
}

void			nearest_rotation(t_roll *r, int checker, int fst, int lst)
{
	ft_printf("{yellow}{bold}IN\tNEAREST_ROTATION\n{eoc}");
	int			best_dif_dep;

	next_dif(r, checker, &best_dif_dep);
//	checker ^ CHECK && r->nb_b > 0 ? next_insert(r, best_dif_dep, fst, lst) : 0;
	r->nb_b > 0 ? next_insert(r, best_dif_dep, -1, lst) : 0;
	ALBD |= r->b_rot < r->nb_a / 2 ? ROT : R_ROT;
	if (ALBD & ROT)
	{
		ALBD &= ~ROT;
		if (nearest_checker(r, fst, lst))
		{
			ft_printf("{yellow}{bold}END\tNEAREST_ROTATION CHECKER\n{eoc}");
			return ;
		}
		ft_printf("{yellow}{bold}END\tNEAREST_ROTATION\n{eoc}");
		return (rotate(r, &r->a, 'a'));
	}
	if (ALBD & R_ROT)
	{
		ALBD &= ~R_ROT;
		if (nearest_checker(r, fst, lst))
		{
			ft_printf("{yellow}{bold}END\tNEAREST_ROTATION CHECKER\n{eoc}");
			return ;
		}
		ft_printf("{yellow}{bold}END\tNEAREST_ROTATION\n{eoc}");
		return (r_rotate(r, &r->a, 'a'));
	}
}
