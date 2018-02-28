# include "push_swap.h"

static	int		is_present(int *t, int n, int value)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (t[i] == value)
			return (1);
	}
	return (0);
}

static	void	finition_sort(t_roll *r, int *t, int size, int nb_cor)
{
//	ft_printf("\n{cyan}{bold}IN\tFINITION\tsize = %d\tnb_cor = %d{eoc}\n\n", size, nb_cor);//
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	while (++i < size)
	{
		if (r->a.LBD & NO_CHECK && nb_cor && is_present(t, nb_cor, r->a.LNBR))
		{
			k = 0;
			if (r->a.LNBR >= *t && r->a.LNBR <= t[j])
			{
				r->a.LBD = GOOD;
				while(*t < r->a.LNBR)
				{
					++t;
					--nb_cor;
				}
				while (++k < nb_cor)
					t[k - 1] = t[k];
				j = 0;
			}
			else
			{
				r->a.LBD = CHECK;
				while (t[k] < r->a.LNBR)
					++k;
				while (++k < nb_cor)
					t[k - 1] = t[k];
				++j;
			}
			--nb_cor;
		}
		rotate(NULL, &r->a, 0);
	}
	rotate(NULL, &r->a, 0);
//	ft_printf("\n{cyan}{bold}END\tFINITION\tsize = %d{eoc}\n", size);///////////////
}

void		section_sort(t_roll *r, int size, int min, int max)
{
//	ft_printf("{red}{bold}IN\tSECTION\tsize = %d{eoc}\n", size);////////////////
//	ft_printf("{bold}{yellow}{underline}before{runderline}\n");//////////////////
//	ft_printf("r->a.LNBR\t= %10d\n", r->a.LNBR);/////////////////////////////////
	int		i;
	int		nb_check;
	int		verif[size];

	i = -1;
	nb_check = 0;
//	ft_printf("min\t\t= %10d\nmax\t\t= %10d{eoc}\n", min, max);///////////////////////
	while (++i < size)
	{
		r_rotate(NULL, &r->a, 0);
		if (r->a.LNBR >= min && r->a.LNBR <= max && r->a.low->bd ^ GOOD)
		{
			r->a.low->bd = NO_CHECK;
			verif[nb_check] = r->a.LNBR;
			++nb_check;
		}
	}
	nb_check > 1 ? ft_qsort(verif, nb_check, 0, 0) : 0;
	finition_sort(r, verif, size, nb_check);
//	ft_printf("\n{bold}{yellow}{underline}after{runderline}\n");/////////////////
//	ft_printf("r->a.LNBR\t= %10d\n", r->a.LNBR);/////////////////////////////////
//	ft_printf("min\t\t= %10d\nmax\t\t= %10d\n", min, max);///////////////////////
//	ft_printf("{bold}{red}END\tSECTION{eoc}\n\n");//////////////////////////////
}

void		section_sort_v2(t_roll *r, int size, int i, int j)
{
//	ft_printf("{red}{bold}IN\tSECTION_V2\tsize = %d{eoc}\n", size);////////////////
//	ft_printf("{bold}{yellow}{underline}before{runderline}{eoc}\n");//////////////////
//	ft_printf("{bold}r->a.LNBR\t= %10d\n\n", r->a.LNBR);/////////////////////////////////
	int		min;
	int		verif[size];

	while (++i < r->nb_a)
	{
		r->a.LBD & GOOD ? verif[j] = r->a.LNBR : 0;
		r->a.LBD & GOOD ? ++j : 0;
		rotate(NULL, &r->a, 0);
	}
	j = 0;
	min = verif[j];
	while (--i >= 0)
	{
		if(r->a.LBD & GOOD && ++j)
			min = verif[j - 1];
		if (r->a.LBD & CHECK && r->a.LNBR < verif[j] && r->a.LNBR > min && (min = r->a.LNBR))
			r->a.LBD = GOOD;
		//r->a.LBD & NO_CHECK && j == nb_good && r->a.LNBR > verif[j - 1] ? r->a.LBD = GOOD : 0;
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("\n{bold}{yellow}{underline}after{runderline}\n");/////////////////
//	ft_printf("r->a.LNBR\t= %10d\n", r->a.LNBR);/////////////////////////////////
//	ft_printf("{bold}{red}END\tSECTION_V2{eoc}\n\n");//////////////////////////////
}
