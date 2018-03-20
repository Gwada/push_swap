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
	ft_printf("{bold}{underline}{blue}IN\tNEXT INSERT\tdif dep = %d ALNBR = %d{eoc}\n", best_dif_dep, ALNBR);//
	display_piles(r, &r->a, &r->b);
	int			i;
//	int			min;
//	int			max;
	int			n_dep_fst;
	int			n_dep_lst;
	int			b_dep;

	i = -1;
	while (++i < r->nb_a)
	{
	/*	if (ATBD & GOOD && fst == r->nb_a)
		{
			min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			value_insert(r, NULL, min, max) ? fst = i : 0;
		}*/
		if (ATBD & GOOD && ALBD & GOOD && fst == r->nb_a)
			value_insert(r, NULL, ATNBR, ALNBR) ? fst = i : 0;
		rotate(NULL, &r->a, 0);
	}
	while (i-- > 0)
	{
	/*	if (ALBD & GOOD && !lst)
		{
			max = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			min = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
			value_insert(r, NULL, min, max) ? lst = i + 1 : 0;
		}*/
		if (ATBD & GOOD && ALBD & GOOD && !lst)
			value_insert(r, NULL, ATNBR, ALNBR) ? lst = i + 1 : 0;
		r_rotate(NULL, &r->a, 0);
	}
	fst == r->nb_a ? fst = r->nb_a / 2 : 0;
	!lst ? lst = r->nb_a / 2 : 0;
	ft_printf("fst = %d\tlst = %d\n", fst, lst);//

	n_dep_fst = r->nb_a - (r->nb_a - fst);
	n_dep_lst = r->nb_a - lst;
	ft_printf("n dep fst = %d n dep lst = %d\n", n_dep_fst, n_dep_lst);

	b_dep = n_dep_fst <= n_dep_lst ? n_dep_fst : n_dep_lst;
	ft_printf("best_dif_dep = %d b_dep = %d\n", best_dif_dep, b_dep);
	b_dep > best_dif_dep ? ft_printf("{magenta}prochaine dif{eoc}\n") : 0;
	if (b_dep < best_dif_dep)
	{
		ft_printf("{red}{bold}--------------------------------------------------------\n");
		ft_printf("\t\t{underline}VIDAGE PILE B{runderline}\n");
		ft_printf("--------------------------------------------------------{eoc}\n\n");
		r->b_rot = n_dep_fst <= n_dep_lst ? fst : lst;
	}
	display_piles(r, &r->a, &r->b);
	ft_printf("{bold}{underline}{blue}END\tNEXT INSERT\tALNBR = %d{eoc}\n\n", ALNBR);//
}

void			nearest_rotation(t_roll *r, int checker, int fst, int lst)
{
//	ft_printf("{bold}{underline}{blue}IN\tNEAREST ROTATION\tALNBR = %d{eoc}\n", ALNBR);//
	int			best_dif_dep;

	next_dif(r, checker, &best_dif_dep);
	next_insert(r, best_dif_dep, fst, lst);
	ALBD |= r->b_rot < r->nb_a / 2 ? ROT : R_ROT;
	if (ALBD & ROT)
	{
//		ft_printf("ALBD & ROT\n");//////////////////////////////////////////////
		ALBD &= ~ROT;
		if (ALBD & GOOD)
		{
//			ft_printf("ALBD & GOOD\n");//////////////////////////////////////////////
			lst = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			fst = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
//			ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////////
			if (ALLBD ^ GOOD && ((fst < lst && ALLNBR > fst && ALLNBR < lst) || (fst > lst && (ALLNBR > fst || ALLNBR < lst))))
			{
//				ft_printf("ALLBD ^ GOOD && (fst < lst && ALLNBR > fst && ALLNBR < lst) || (fst > lst && (ALLNBR > fst || ALLNBR < lst)) -> SWAP\n");//
				return (swap(r, &r->a, 'a'));
			}
			if (ATBD ^ GOOD)
			{
//				ft_printf("ATBD ^ GOOD\n");//////////////////////////////////////////
				fst = ALNBR;
				while (ALLBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				lst = ALLNBR;
				while (ALBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
				if ((fst < lst && ATNBR > fst && ATNBR < lst) || (fst > lst && (ATNBR > fst || ATNBR < lst)))
				{
//					ft_printf("(fst < lst && ATNBR > fst && ATNBR < lst) || (fst > lst && (ATNBR > fst || ATNBR < lst)) -> R_ROT -> SWAP\n");//
					r_rotate(r, &r->a, 'a');
					return (swap(r, &r->a, 'a'));
				}
				if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
				{
//					ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
					rotate(r, &r->a, 'a');
					b_push(r, fst, lst);
					return ;
				}
				lst = ALNBR;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
				fst = ATNBR;
				while (ALBD ^ GOOD)
					rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
			}
			if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
			{
//				ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
				b_push(r, fst, lst);
				return ;
			}
		}
		else
		{
//			ft_printf("ALBD ^ GOOD\n");//////////////////////////////////////////////
			if (ALLBD & GOOD)
			{
//				ft_printf("ALLBD & GOOD\n");/////////////////////////////////////////
				fst = ALLNBR;
				while (ALLLBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				lst = ALLLNBR;
				while (ALLBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
				if ((fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)))
				{
//					ft_printf("(fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)) -> SWAP\n");//
					return (swap(r, &r->a, 'a'));
				}
				if (ATBD ^ GOOD)
				{
//					ft_printf("ATBD ^ GOOD\n");//////////////////////////////////////
					lst = ALLNBR;
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
					fst = ATNBR;
					while (ALLBD ^ GOOD)
						rotate(NULL, &r->a, 0);
//					ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////
					if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
					{
//						ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
						rotate(r, &r->a, 'a');
						b_push(r, fst, lst);
						return ;
					}
				}
			}
			if (ATBD & GOOD)
			{
//				ft_printf("ATBD & GOOD\n");//////////////////////////////////////////
				lst = ATNBR;
				while (ATTBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				fst = ATTNBR;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
				if ((fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)))
				{
//					ft_printf("(fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)) -> R_ROT -> SWAP\n");//
					r_rotate(r, &r->a, 'a');
					return (swap(r, &r->a, 'a'));
				}
				if (ALLBD ^ GOOD)
				{
//					ft_printf("ALLBD ^ GOOD\n");/////////////////////////////////////
					fst = ATNBR;
					while (ALLBD ^ GOOD)
						rotate(NULL, &r->a, 0);
					lst = ALLNBR;
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
//					ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////
					if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
					{
//						ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
						b_push(r, fst, lst);
						return;
					}
				}
			}
		}
		return (rotate(r, &r->a, 'a'));
	}
	if (ALBD & R_ROT)
	{
//		ft_printf("ALBD & R_R\n");//////////////////////////////////////////////
		ALBD &= ~R_ROT;
		if (ALBD & GOOD)
		{
//			ft_printf("ALBD & GOOD\n");//////////////////////////////////////////////
			lst = ALNBR;
			while (ATBD ^ GOOD)
				r_rotate(NULL, &r->a, 0);
			fst = ATNBR;
			while (ALBD ^ GOOD)
				rotate(NULL, &r->a, 0);
//			ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////////
			if (ALLBD ^ GOOD && ((fst < lst && ALLNBR > fst && ALLNBR < lst) || (fst > lst && (ALLNBR > fst || ALLNBR < lst))))
			{
//				ft_printf("ALLBD ^ GOOD && (fst < lst && ALLNBR > fst && ALLNBR < lst) || (fst > lst && (ALLNBR > fst || ALLNBR < lst)) -> SWAP\n");//
				return (swap(r, &r->a, 'a'));
			}
			if (ATBD ^ GOOD)
			{
//				ft_printf("ATBD ^ GOOD\n");//////////////////////////////////////////
				fst = ALNBR;
				while (ALLBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				lst = ALLNBR;
				while (ALBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
				if ((fst < lst && ATNBR > fst && ATNBR < lst) || (fst > lst && (ATNBR > fst || ATNBR < lst)))
				{
//					ft_printf("(fst < lst && ATNBR > fst && ATNBR < lst) || (fst > lst && (ATNBR > fst || ATNBR < lst)) -> R_ROT -> SWAP\n");//
					r_rotate(r, &r->a, 'a');
					return (swap(r, &r->a, 'a'));
				}
				if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
				{
//					ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
					rotate(r, &r->a, 'a');
					b_push(r, fst, lst);
					return ;
				}
				lst = ALNBR;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
				fst = ATNBR;
				while (ALBD ^ GOOD)
					rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
			}
			if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
			{
//				ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
				b_push(r, fst, lst);
				return ;
			}
		}
		else
		{
//			ft_printf("ALBD ^ GOOD\n");//////////////////////////////////////////////
			if (ALLBD & GOOD)
			{
//				ft_printf("ALLBD & GOOD\n");/////////////////////////////////////////
				fst = ALLNBR;
				while (ALLLBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				lst = ALLLNBR;
				while (ALLBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
				if ((fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)))
				{
//					ft_printf("(fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)) -> SWAP\n");//
					return (swap(r, &r->a, 'a'));
				}
				if (ATBD ^ GOOD)
				{
//					ft_printf("ATBD ^ GOOD\n");//////////////////////////////////////
					lst = ALLNBR;
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
					fst = ATNBR;
					while (ALLBD ^ GOOD)
						rotate(NULL, &r->a, 0);
//					ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////
					if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
					{
//						ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
						rotate(r, &r->a, 'a');
						b_push(r, fst, lst);
						return ;
					}
				}
			}
			if (ATBD & GOOD)
			{
//				ft_printf("ATBD & GOOD\n");//////////////////////////////////////////
				lst = ATNBR;
				while (ATTBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				fst = ATTNBR;
				while (ATBD ^ GOOD)
					r_rotate(NULL, &r->a, 0);
//				ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////////
				if ((fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)))
				{
//					ft_printf("(fst < lst && ALNBR > fst && ALNBR < lst) || (fst > lst && (ALNBR > fst || ALNBR < lst)) -> R_ROT -> SWAP\n");//
					r_rotate(r, &r->a, 'a');
					return (swap(r, &r->a, 'a'));
				}
				if (ALLBD ^ GOOD)
				{
//					ft_printf("ALLBD ^ GOOD\n");/////////////////////////////////////
					fst = ATNBR;
					while (ALLBD ^ GOOD)
						rotate(NULL, &r->a, 0);
					lst = ALLNBR;
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
//					ft_printf("fst = %d lst = %d\n", fst, lst);//////////////////////
					if (fst - lst != 1 && value_insert(r, NULL, fst, lst))
					{
//						ft_printf("lst - fst != 1 && value_insert(r, NULL, %d, %d) -> ROT -> B_PUSH\n", fst, lst);//
						b_push(r, fst, lst);
						return;
					}
				}
			}
		}
		return (r_rotate(r, &r->a, 'a'));
	}
}
