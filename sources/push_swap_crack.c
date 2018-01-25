#include "push_swap.h"

int			find_best_comb(t_tab *t, t_roll *r, int good, int i)
{
//	ft_printf("\n{red}in best comb{eoc}\n");//
	t_pile	*tmp;

	tmp = r->a.low;
//	display_pile(&r->a, 'A');//
	while (++i < r->size && !tmp->root)
	{
		tmp->nbr == (int)t[i].n ? ++good : 0;
		tmp = tmp->low;
	}
//	ft_printf("{red}end best comb{eoc}\n\n");//
	return (good);
}

void		find_best_rot(t_roll *r, int rot)
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
			r_rotate(NULL, NULL, &r->a, 0);
//		display_pile(&r->a, 'A');///
			r->a.low->bd |= ROT;
		}
	}
//	display_pile(&r->a, 'A');///
//	ft_printf("{red}end best rot{eoc}\n\n");//
}

void		find_best_sort(t_tab *t, t_roll *r, int size, int i)
{
	int		j;
	int		best[size];

//	ft_printf("{blue}{bold}{underline}IN BEST SORT{eoc}\n\n");//
	j = -1;
	find_best_rot(r, r->size - r->b_rot);

//	display_pile(r, &r->a, 'A');///

//	ft_printf("\n1\n\n");//
	while (++i < r->size)
	{
		best[i] = r->a.low->nbr;
//		ft_printf("best[%d] = %d\tt[%d].n = %d\n", i, best[i], i, t[i].n);
		rotate(NULL, NULL, &r->a, 0);
	}
//	ft_printf("\n2\n\n");//
	find_best_rot(r, r->b_rot);
//	display_pile(r, &r->a, 'A');///
//	ft_printf("\n3\n\n");//
	i = 0;
	while (best[i] != r->a.low->nbr)
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
	}
//	ft_printf("{blue}{bold}{underline}END BEST SORT{eoc}\n\n");//
}

void		crack_that_shit(t_tab *t, t_roll *r, int rot, int i)
{
//	ft_printf("{black}{bold}{underline}IN CRACKER{eoc}\n");//
//	display_piles(r, &r->a, &r->b);///
	while (++i <= r->size && r->cor != r->size)
	{
		rotate(NULL, NULL, &r->a, 0);
		rot = find_best_comb(t, r, 0, -1);
		rot > r->cor ? r->b_rot = i : 0;
		rot > r->cor ? r->cor = rot : 0;
	}
	r->a.bd |= (r->cor == r->size) ? ONLY_R : MORE;
	r->cor == r->size ? find_best_rot(r, r->b_rot) : find_best_sort(t, r, r->size, -1);
//	r->cor == r->size ? ft_printf("{green}{underline}ONLY ROTATE{eoc}\n") : ft_printf("{red}{underline}NEED MORE{eoc}\n");//
//	display_piles(r, &r->a, &r->b);///
//	ft_printf("{black}{bold}{underline}END CRACKER{eoc}\n\n");//
}
