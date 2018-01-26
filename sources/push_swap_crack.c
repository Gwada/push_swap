#include "push_swap.h"

/*void		find_best_rot(t_roll *r, int rot)
{
//	ft_printf("\n{red}in best rot{eoc}\n");//
//	r->cor ? ft_printf("r->cor\t= %d\n", r->cor) : 0;//
//	r->b_rot ? ft_printf("b_rot\t= %d\n", r->b_rot) : 0;//
//	display_pile(&r->a, 'A');///
	if (rot > r->size / 2)
	{
	//	ft_printf ("best rot > size / 2 (rotate)\n");//
		while (rot++ < r->size)
		{
			rotate(NULL, NULL, &r->a, 0);
	//	display_pile(&r->a, 'A');///
			r->a.low->bd |= R_ROT;

		}
	}
	else
	{
	//	ft_printf ("best rot <= size / 2 (r_rotate)\n");//
		while (rot-- > 0)
		{
			r->a.low->bd &= ~R_ROT;
			r_rotate(NULL, NULL, &r->a, 0);
//		display_pile(&r->a, 'A');///
		}
	}
//	display_pile(&r->a, 'A');///
//	ft_printf("{red}end best rot{eoc}\n\n");//
}
*/
void		find_best_sort(t_tab *t, t_roll *r, int size, int i)
{
	ft_printf("{blue}{bold}{underline}IN BEST SORT{eoc}\n\n");///////////////
	int		j;
	int		best[size];

	j = -1;
	display_pile(r, &r->a, 'A');////////////////
	find_best_rotation(r, r->size - r->b_rot, 0);
	display_pile(r, &r->a, 'A');//////////////////
	ft_printf("\n");/////////////////////
	while (++j < r->size)
	{
		best[j] = r->a.low->nbr;
		ft_printf("best[%d] = %d\tt[%d].n = %d\n", j, best[j], j, t[j].n);////////////////
		rotate(NULL, NULL, &r->a, 0);
	}
//	find_best_rotation(r, r->b_rot, 0);////////////////
	ft_printf("\n");/////////////////////
	display_pile(r, &r->a, 'A');///
	j = -1;
	i = 0;
/*	while (best[i] != r->a.low->nbr)
		i++;
	while (++j < r->size)
	{
//		display_pile(r, &r->a, 'A');///
		i + j == r->size ? i = -j : 0;
//		ft_printf("-> i + j = %d\t", i + j);
//		ft_printf("best[%d] = %d\t", i+j, best[i + j]);
//		ft_printf("t[%d].n = %d\t", i + j, t[i + j].n);
		if (best[i + j] != t[i + j].n)
		{
//			ft_printf("{red}{underline}best[i + j] != t[i + j].n){eoc}\t");
			if (i + j + 1 <= r->size)
			{
//				ft_printf("{green}{underline}i + j <= r->size{eoc}\n");
				if (best[i + j] == t[i + j + 1].n && best[i + j + 1] == t[i + j].n)
				{
//					ft_printf("{green}SWAP : best[i + j] == t[i + j + 1] && best[i + j + 1] == t[i + j]{eoc}\ntest\n");
//					display_pile(r, &r->a, 'A');///
					r->a.low->bd |= SWAP;
					r->a.low->bd |= ROT;
					rotate(NULL, NULL, &r->a, 0);
//					display_pile(r, &r->a, 'A');///
					//r->a.low->bd &= ~R_ROT;
					r->a.low->bd |= ROT;
					j++;
				}
				else
				{
//					ft_printf("{red}PUSH : best[i + j] != t[i + j + 1] || best[i + j + 1] != t[i + j]{eoc}\n");
					r->a.low->bd |= PUSH;
				}
			}
			else
			{
//				ft_printf("{red}{underline}i + j > r->size -> pushb{eoc}\n");
				r->a.low->bd |= PUSH;
			}
		}
		else
		{
		//	ft_printf("{green}best[i + j] == t[i + j].n)\t{eoc}");
			//ft_printf("{blue}{bold}r->a.low->bd |= ROT{eoc}\n");
			//r->a.low->bd |= GOOD;
			r->a.low->bd |= ROT;
			r->a.low->bd &= ~R_ROT;
		}
		rotate(NULL, NULL, &r->a, 0);
//		ft_printf("\n");//
	}*/
//	ft_printf("\n");//
	display_pile(r, &r->a, 'A');///
	find_best_rotation(r, r->b_rot, ROT | R_ROT);
	//display_pile(r, &r->a, 'A');///
	ft_printf("{blue}{bold}{underline}\nEND BEST SORT{eoc}\n");//
}

void		find_best_rotation(t_roll *r, int rot, int state)
{
//	ft_printf("{red}in best rot{eoc}\n");//

	if (rot > r->size / 2)
	{
//		ft_printf ("best rot > size / 2 (rotate)\n");//
		while (rot++ < r->size)
		{
			rotate(NULL, NULL, &r->a, 0);
//			display_pile(r, &r->a, 'T');//
			state & R_ROT ? r->a.low->bd |= R_ROT : 0;
		}
	}
	else
	{
//		ft_printf ("best rot <= size / 2 (r_rotate)\n");//
		while (rot-- > 0)
		{
			r_rotate(NULL, NULL, &r->a, 0);
//			display_pile(r, &r->a, 'T');///
			state & ROT ? r->a.low->bd |= ROT : 0;
		}
	}
//	display_pile(r, &r->a, 'A');///
	(void)state;
	ft_printf("{red}{bold}END BEST ROT{eoc}\n");//
}

void		find_best_combinaison(t_tab *t, t_roll *r, int i)
{
//	ft_printf("\n{red}in best comb{eoc}\n");//
	int		j;
	int		cor;
	t_pile	*tmp1;
	t_pile	*tmp2;

	tmp1 = &r->a;
	while (++i <= r->size)
	{
		rotate(NULL, NULL, tmp1, 0);
		tmp2 = tmp1->low;
//		display_pile(r, tmp1, 'T');//
		j = -1;
		cor = 0;
		while (++j < r->size && !tmp2->root)
		{
			tmp2->nbr == (int)t[j].n ? ++cor : 0;
			tmp2 = tmp2->low;
		}
//		ft_printf("correspondance = %d\n\n", cor);//
		cor > r->cor ? r->b_rot = i : 0;
		cor > r->cor ? r->cor = cor : 0;
	}
	r->cor == r->size ? ft_printf("(tris relatif!!!) ") : 0;//
//	ft_printf("{red}end best comb{eoc}\n\n");//
}

void		crack_that_shit(t_tab *t, t_roll *r)
{
	ft_printf("{black}{bold}{underline}IN CRACKER{eoc}\n");//
//	display_piles(r, &r->a, &r->b);///
//	find_best_rotation(r, r->b_rot);
	find_best_sort(t, r, r->size, -1);
//	r->a.bd |= (r->cor == r->size) ? ONLY_R : MORE;
//	r->cor == r->size ? find_best_rot(r, r->b_rot) : find_best_sort(t, r, r->size, -1);
//	r->cor == r->size ? ft_printf("{green}{underline}ONLY ROTATE{eoc}\n") : ft_printf("{red}{underline}NEED MORE{eoc}\n");//
//	display_piles(r, &r->a, &r->b);///
	ft_printf("{black}{bold}{underline}END CRACKER{eoc}\n");//
	(void)t;
}
