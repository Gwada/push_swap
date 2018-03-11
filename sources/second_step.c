#include "push_swap.h"

static	int		error_checker(t_roll *r, int total, int i)
{
	while (++i < r->nb_a)
	{
		ALBD ^ GOOD ? ++total : 0;
		rotate(NULL, &r->a, 0);
	}
	return (total);
}

void	second_step(t_roll *r, int size, int i, int j)
{
	ft_printf("\n{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}IN SECOND STEP{runderline}\t\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");

	while (error_checker(r, 0, -1) && ++j <= 100)
	{
		nearest_dif_finder(r, -1, r->nb_a, 0);
		ALBD ^ GOOD ? push(r, &r->a, &r->b, 'b') : 0;
		if (ALBD & GOOD && ATBD & GOOD && ALNBR - ATNBR != 1)
		{
			ft_printf("{red}{bold}insertion valeur > %d && < %d{eoc}\n", ATNBR, ALNBR);
		}
	}
	while (BLNBR != r->b_max)
		rotate(NULL, &r->b, 0);
	i = -1;
	while (++i < r->nb_b)
	{
		ft_printf("{bold}{green}BLNBR = %10d{eoc}\n", BLNBR);
		rotate(NULL, &r->b, 0);
	}
	ft_printf("{bold}{green}\n%s{eoc}\n\n", j > 100 ? "j > 20" : "ONLY GOOD");
	display_piles(r, &r->a, &r->b);
	i = -1;
	while (++i < r->nb_a)
	{
		ALBD & ROT || ALBD & R_ROT ? ft_printf("ROT || R_ROT\n") : 0;
		rotate(NULL, &r->b, 0);
	}
	(void)size;
	(void)i;
	(void)j;

	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}END OF SECOND STEP{runderline}\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n\n");
}
