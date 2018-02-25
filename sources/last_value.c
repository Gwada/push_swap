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
	ft_printf("\n{magenta}{bold}{underline}IN\tINIT PILE{eoc} size = %d\n", size);//
	int			fst;
	int			lst;
	int			start = 0;

	fst = r->nb_a;
	lst = 0;
	pile_sort(r, t, size, -1);
	find_best_combinaison(t, r, -1);
	find_best_rotation(r, size - r->b_rot, 0);
	ft_printf("indice dif la plus proche\tr->b_rot = %2d\tindice st %d\n", r->b_rot, size - r->b_rot);//
	i = -1;
	while (++i < size)
	{
		if (t[i] == r->a.LNBR)
		{
			if ((i == size - 1 && t[i - 1] == r->a.low->LNBR) || (i && t[i - 1] == r->a.low->LNBR))
				r->a.low->bd = SWAP;
			else
				r->a.low->bd = GOOD;
		}
		else
		{
			if ((t[i] == r->a.low->LNBR && i + 1 < size && t[i + 1] == r->a.LNBR)
			|| (i < size - 2 && t[i + 1] == r->a.low->LNBR && t[i + 2] == r->a.LNBR)
			|| (i == size -1 && t[0] == r->a.LNBR && r->a.low->LNBR == t[i]))
				r->a.low->bd = SWAP;
			else if ((i > 0 && r->a.LNBR == t[i - 1])
			|| (i > 1 && t[i - 1] == r->a.TNBR && t[i - 2] == r->a.LNBR)
			|| (i < size - 1 && t[i + 1] == r->a.LNBR)
			|| (i == size - 1 && ((t[0] == r->a.LNBR) || (t[i - 1] == r->a.LNBR)))
			|| (!i && ((t[size - 1] == r->a.LNBR) || (t[size - 1] == r->a.TNBR && r->a.LNBR == t[size - 2]))))
				r->a.low->bd = GOOD;
			else
				r->a.low->bd = PUSH;
		}
		if (r->a.LNBR == t[i] || i == r->nb_a - 1)
			i - start > 1 ? finition_sort(r, t, start, i) : 0;
		r->a.LNBR == t[i] ? start = i : 0;
		rotate(NULL, &r->a, 0);
	}
	i = -1;
	while (++i < size)
	{////////////////////////////////////////////////////////////////////////////
		ft_printf("t[%3d] = [{green}%10d{eoc}]\t", i, t[i]);/////////////////////
		ft_printf("r->a.LNBR = [{magenta}%10d{eoc}] {bold}", r->a.LNBR);/////////
		r->a.low->bd & SWAP ? ft_printf("{yellow}SWAP ") : 0;/////////////////////
		r->a.low->bd & GOOD ? ft_printf("{green}GOOD ") : 0;/////////////////////
		r->a.low->bd & PUSH ? ft_printf("{red}PUSH") : 0;////////////////////////
		r->a.low->bd & NO_CHECK ? ft_printf("{magenta}NO_CHECK") : 0;////////////////////////
		r->a.low->bd & CHECK ? ft_printf("{cyan}CHECK") : 0;////////////////////////////////////
		ft_printf("{eoc}\n");////////////////////////////////////////////////////
		last_and_first(r, &fst, &lst, i);
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("\nfirst dif = %3d\tlast dif = %3d\n", fst, lst);//////////////////
	find_best_rotation(r, r->b_rot, 0);
	r->b_rot = (size - (size - fst) <= size - lst) ? fst : lst;
	ft_printf("best rot = %3d\n", r->b_rot);/////////////////////////////////////
	ft_printf("{magenta}{bold}{underline}END\tINIT PILE{eoc}\n\n");//////////////
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

void			first_step(t_roll *r, int size)
{
//	ft_printf("{yellow}{bold}{underline}IN\tGO TO LAST VALUE{eoc} size = %d\n\n", size);//
	int			t[size];

/*
 * 1
 *
 * partionner la pile pour reduire le nombre de deplacements
*/
	init_pile(r, t, size, -1);
//	display_piles(r, &r->a, &r->b);

/*
 * 2
 *
 * retirer les elements incorects
 * trier les portions
 * inserer les elements de la pile b si il y en a
*/
//	if (find_next_dif(r, size))
//		return ;


/*
 * 3
 * aller a la fin ou repeter si necessaire
*/
//	if (r->a.low->bd & PUSH)
//		return (push(r, &r->a, &r->b, 'b'));
//	else if (r->a.low->bd & SWAP)
//		return (swap(r, &r->a, 'a'));

	ft_printf("\n{red}{bold}--------------------------------------------------\n");//////////
	ft_printf("{underline}\t\tEND OF FIRST STEP{runderline}\n");///////////////////////
	ft_printf("--------------------------------------------------{eoc}\n\n\n");////////////////
}
