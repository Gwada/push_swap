#include "push_swap.h"

static	void	last_and_first(t_roll *r, int *fst, int *lst, int i)
{
	int			size;

	size = r->nb_a;
	if (r->a.low->bd & PUSH)
	{
		if (*fst == r->nb_a && !*lst)
		{
			*fst = (i < size - r->b_rot) ? r->b_rot + i : i - (size - r->b_rot);
			*lst = (i < size - r->b_rot) ? r->b_rot + i : i - (size - r->b_rot);
		}
		else
		{
			if (i < (size - r->b_rot) && (size - r->b_rot) - i < *fst)
				*fst = r->b_rot + i;
			else if (i >= (size - r->b_rot) && i - (size - r->b_rot) < *fst)
				*fst = i - (size - r->b_rot);
			if (i < (size - r->b_rot) && r->b_rot + i > *lst)
				*lst = r->b_rot + i;
			else if (i > (size - r->b_rot) && i - (size - r->b_rot) > *lst)
				*lst = i - (size - r->b_rot);
		}
	}
	rotate(NULL, &r->a, 0);
}

static	void	init_pile(t_roll *r, int *t, int size, int i)
{
//	ft_printf("\n{magenta}{bold}{underline}IN\tINIT PILE{eoc} size = %d\n", size);//
	int			fst;
	int			lst;
	int			start;

	fst = r->nb_a;
	lst = 0;
	start = 0;
	while (--i >= 0)
	{
		r->a.LBD & GOOD || r->a.LBD & CHECK ? ++start : 0;
		rotate(NULL, &r->a, 0);
	}
	section_sort_v2(r, start, (i = -1), 0);
	ft_qsort(t, size, 0, 0);
	while (++i < size)
//	{
	//	if (r->a.low->bd & GOOD || r->a.low->bd & CHECK || r->a.LBD & NO_CHECK)
	//	{
//			ft_printf("{bold}tab[%3d] = [%11d]\tr->a.LNBR\t= [%11d]\t", i, t[i], r->a.LNBR);//
//			r->a.low->bd & GOOD ? ft_printf("{green}%10s", "GOOD") : 0;//////////////////
//			r->a.low->bd & CHECK ? ft_printf("{cyan}%10s", "CHECK") : 0;/////////////////
//			r->a.low->bd & NO_CHECK ? ft_printf("{magenta}%10s", "NO_CHECK") : 0;////////
//			r->a.low->bd & PUSH ? ft_printf("{red}%10s", "PUSH") : 0;////////////////////
//			ft_printf("{eoc}\n");////////////////////////////////////////////////
	//	}
		last_and_first(r, &fst, &lst, i);
//	}
//	ft_printf("{magenta}{bold}{underline}END\tINIT PILE{eoc}\n\n");//////////////
	find_best_rotation(r, r->b_rot, 0);
	r->b_rot = (size - (size - fst) <= size - lst) ? fst : lst;

}

/*static	int		find_next_dif(t_roll *r, int size)
{
//	ft_printf("\n{magenta}{bold}{underline}IN\tFIND NEXT DIF{eoc}\n");///////////
	find_best_rotation(r, size - r->b_rot, 0);
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
//	for (int i = 0; i < size; ++i)///////////////////////////////////////////////
//	{////////////////////////////////////////////////////////////////////////////
//		r->a.low->bd & GOOD ? ft_printf("{green}[%d{eoc}", r->a.LNBR) : 0;///////
//		!(r->a.low->bd & GOOD) ? ft_printf("[%d", r->a.LNBR) : 0;////////////////
//		r->a.low->bd & ROT ? ft_printf("{magenta}(R){eoc}") : 0;/////////////////
//		r->a.low->bd & R_ROT ? ft_printf("{yellow}(R_R){eoc}") : 0;//////////////
//		r->a.low->bd & PUSH ? ft_printf("{red}(P){eoc}") : 0;////////////////////
//		r->a.low->bd & SWAP ? ft_printf("{blue}(S){eoc}") : 0;///////////////////
//		r->a.low->bd & GOOD ? ft_printf("{green}]{eoc} ") : ft_printf("] ");/////
//		rotate(NULL, &r->a, 0);//////////////////////////////////////////////////
//	}////////////////////////////////////////////////////////////////////////////
//	ft_printf("\n\ngo prochaine dif\n");/////////////////////////////////////////
	while (r->a.low->bd & (ROT | R_ROT))
	{
		if (r->a.low->bd & R_ROT)////////////////////////////////////////////////
		{////////////////////////////////////////////////////////////////////////
			if (r->a.low->bd & PUSH)/////////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				push(r, &r->a, &r->b, 'b');//////////////////////////////////////
//				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return (1);/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			else if (r->a.low->bd & SWAP)////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				swap(r, &r->a, 'a');/////////////////////////////////////////////
//				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return (0);/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			r_rotate(r, &r->a, 'a');/////////////////////////////////////////////
		}////////////////////////////////////////////////////////////////////////
		else if (r->a.low->bd & ROT)/////////////////////////////////////////////
		{////////////////////////////////////////////////////////////////////////
			if (r->a.low->bd & PUSH)/////////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				push(r, &r->a, &r->b, 'b');//////////////////////////////////////
//				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return (1);/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			else if (r->a.low->bd & SWAP)////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				swap(r, &r->a, 'a');/////////////////////////////////////////////
//				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return (0);/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			rotate(r, &r->a, 'a');///////////////////////////////////////////////
		}////////////////////////////////////////////////////////////////////////

	}
//	ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//////////
	return (0);
}*/

void			first_step(t_roll *r, int size, int i, int start)
{
//	ft_printf("{yellow}{bold}{underline}IN\tGO TO LAST VALUE{eoc} size = %d\n\n", size);//
	int			t[size];

/*
 * partionner la pile pour reduire le nombre de deplacements
*/
	pile_sort(r, t, size, -1);
	find_best_combinaison(t, r, -1);
	find_best_rotation(r, size - r->b_rot, 0);
	while (++i < size)
	{
		r->a.LBD = t[i] == r->a.LNBR ? GOOD : PUSH;
		if ((t[i] == r->a.LNBR || (i == r->nb_a - 1)) && i - start > 1)
		{
			section_sort(r, (i - start), t[start], t[i]);
			start = i;
		}
		rotate(NULL, &r->a, 0);
	}
	init_pile(r, t, size, i);
//	ft_printf("\n{red}{bold}--------------------------------------------------\n");//
//	ft_printf("{underline}\t\tEND OF FIRST STEP{runderline}\n");/////////////////
//	ft_printf("--------------------------------------------------{eoc}\n\n\n");//
}
