#include "push_swap.h"

static	void	init_t(t_roll *r, int *t, int size, int i)
{
	ft_printf("\n{magenta}{bold}{underline}IN\tINIT TAB{eoc}\n");///////////////////
	int			fst;
	int			lst;

	fst = 0;
	lst = 0;
	while (++i < size)
	{
		t[i] = r->a.LNBR;
		r->a.low->bd = 0;
		rotate(NULL, &r->a, 0);
	}
	ft_qsort(t, size, 0, 0);
	find_best_combinaison(t, r, -1);
	find_best_rotation(r, size - r->b_rot, 0);
	ft_printf("go trouver l'indice de la dif la plus proche\n");//////////////////////////////////////////
	i = -1;
	while (++i < size)
	{
		ft_printf("t[%3d] = [{green}%10d{eoc}]\tr->a.LNBR = [{magenta}%10d{eoc}] ", i, t[i], r->a.LNBR);//
		if (t[i] == r->a.LNBR)
		{
			r->a.low->bd |= GOOD;
			ft_printf("GOOD");
		}
		else if (t[i] == r->a.low->LNBR && i + 1 < size && t[i + 1] == r->a.LNBR)
		{
			r->a.low->bd |= SWAP;
			r->a.low->low->bd |= GOOD;
			ft_printf("SWAP");
		}
		else if (t[i] != r->a.LNBR)
		{
			if ((i > 0 && r->a.LNBR == t[i - 1]) || (t[i + 1] == r->a.LNBR) || (i == size - 1 && t[0] == r->a.LNBR))
			{
				r->a.low->bd |= GOOD;
				ft_printf("GOOD");
			}
			else if (!(r->a.low->bd & GOOD))
			{
				r->a.low->bd |= PUSH;
				ft_printf("PUSH");
			}
		}
		if (!fst && !lst && !(r->a.low->bd & GOOD))
		{
			fst = i;
			lst = i;
		}
		if (lst && i > lst && !(r->a.low->bd & GOOD))
			lst = i;
		ft_printf("\n");
		rotate(NULL, &r->a, 0);
	}
	ft_printf("\nfirst dif = %d\tlast dif = %d\n", fst, lst);/////////////////////////
	find_best_rotation(r, r->b_rot, 0);
	r->b_rot = (size - fst > size - lst) ? fst : lst;
	ft_printf("best rot = %d\n", r->b_rot);//////////////////////////////////////
	ft_printf("{magenta}{bold}{underline}END\tINIT TAB{eoc}\n");///////////////
}

static	void	find_next_dif(t_roll *r, int size)
{
	ft_printf("\n{magenta}{bold}{underline}IN\tFIND NEXT DIF{eoc}\n");///////////
	find_best_rotation(r, size - r->b_rot, 0);
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
	for (int i = 0; i < size; ++i)///////////////////////////////////////////////
	{////////////////////////////////////////////////////////////////////////////
		r->a.low->bd & GOOD ? ft_printf("{green}[%d{eoc}", r->a.LNBR) : 0;///////
		!(r->a.low->bd & GOOD) ? ft_printf("[%d", r->a.LNBR) : 0;////////////////
		r->a.low->bd & ROT ? ft_printf("{magenta}(R){eoc}") : 0;/////////////////
		r->a.low->bd & R_ROT ? ft_printf("{yellow}(R_R){eoc}") : 0;//////////////
		r->a.low->bd & PUSH ? ft_printf("{red}(P){eoc}") : 0;////////////////////
		r->a.low->bd & SWAP ? ft_printf("{blue}(S){eoc}") : 0;///////////////////
		r->a.low->bd & GOOD ? ft_printf("{green}]{eoc} ") : ft_printf("] ");/////
		rotate(NULL, &r->a, 0);//////////////////////////////////////////////////
	}////////////////////////////////////////////////////////////////////////////
	ft_printf("\n\ngo prochaine dif\n");/////////////////////////////////////////
	while (r->a.low->bd & (ROT | R_ROT))
	{
		if (r->a.low->bd & R_ROT)////////////////////////////////////////////////
		{////////////////////////////////////////////////////////////////////////
			if (r->a.low->bd & PUSH)/////////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				push(r, &r->a, &r->b, 'b');//////////////////////////////////////
				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return ;/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			else if (r->a.low->bd & SWAP)////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				swap(r, &r->a, 'a');/////////////////////////////////////////////
				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return ;/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			r_rotate(r, &r->a, 'a');/////////////////////////////////////////////
		}////////////////////////////////////////////////////////////////////////
		else if (r->a.low->bd & ROT)/////////////////////////////////////////////
		{////////////////////////////////////////////////////////////////////////
			if (r->a.low->bd & PUSH)/////////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				push(r, &r->a, &r->b, 'b');//////////////////////////////////////
				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return ;/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			else if (r->a.low->bd & SWAP)////////////////////////////////////////
			{////////////////////////////////////////////////////////////////////
				swap(r, &r->a, 'a');/////////////////////////////////////////////
				ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//
				return ;/////////////////////////////////////////////////////////
			}////////////////////////////////////////////////////////////////////
			rotate(r, &r->a, 'a');///////////////////////////////////////////////
		}////////////////////////////////////////////////////////////////////////

/*
**								CODE FINAL

		if (r->a.low->bd & PUSH)
			return (push(r, &r->a, &r->b, 'b'));
		else if (r->a.low->bd & SWAP)
			return (swap(r, &r->a, 'a'));
		else if (r->a.low->bd & R_ROT)
			r_rotate(r, &r->a, 'a');
		if (r->a.low->bd & ROT)
			rotate(r, &r->a, 'a');
*/
	}
	ft_printf("{magenta}{bold}{underline}END\tFIND NEXT DIF{eoc}\n\n");//////////
}

void			go_to_last_value(t_roll *r, int size)
{
	ft_printf("{yellow}{bold}{underline}IN\tGO TO LAST VALUE{eoc} size = %d\n\n", size);//
//	display_pile(r, &r->a, 'a');/////////////////////////////////////////////////
	int			t[size];

	//1. trouver lindice de la 1ere et derniere difference///////////////////////
	init_t(r, t, size, -1);
	//2. aller a cet element en optimisant les deplacement///////////////////////
	find_next_dif(r, size);
	//3. aller a la fin ou repeter si necessaire/////////////////////////////////
//	ft_printf("go dernier element\n");///////////////////////////////////////////
		if (r->a.low->bd & PUSH)
	//	{////////////////////////////////////////////////////////////////////////
	//		push(r, &r->a, &r->b, 'b');//////////////////////////////////////////
	//		i = -1;//////////////////////////////////////////////////////////////
	//		while (++i < (int)r->nb_a)///////////////////////////////////////////
	//		{////////////////////////////////////////////////////////////////////
	//			r->a.low->bd = 0;////////////////////////////////////////////////
	//			rotate(NULL, &r->a, 0);//////////////////////////////////////////
	//		}////////////////////////////////////////////////////////////////////
	//		return ;/////////////////////////////////////////////////////////////
			return (push(r, &r->a, &r->b, 'b'));
	//	}////////////////////////////////////////////////////////////////////////
		else if (r->a.low->bd & SWAP)
	//	{////////////////////////////////////////////////////////////////////////
	//		swap(r, &r->a, 'a');/////////////////////////////////////////////////
	//		rotate(r, &r->a, 'a');///////////////////////////////////////////////
	//		rotate(r, &r->a, 'a');///////////////////////////////////////////////
	//		return ;/////////////////////////////////////////////////////////////
			return (swap(r, &r->a, 'a'));
	//	}////////////////////////////////////////////////////////////////////////
	ft_printf("{yellow}{bold}{underline}END\tGO TO LAST VALUE{eoc}\n");//////////
}
