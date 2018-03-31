#include "push_swap.h"

static	int		error_checker(t_roll *r)
{
	int			i;
	int			total;

	i = -1;
	total = 0;
	while (++i < r->nb_a)
	{
		ALBD & NO_CHECK ? ++total : 0;
		rotate(NULL, &r->a, 0, 0);
	}
	return (total);
}

static	int		right_check(t_roll *r, int min, int max)
{
	while (ALLLBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	max = ALLLNBR;
	while (ALLBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	if ((ALNBR > min && ALNBR < max)
	|| (min > max && (ALNBR > min || ALNBR < max)))
	{
		swap(r, &r->a, 'a');
		return (1);
	}
	return (0);
}

static	int		left_check(t_roll *r, int min, int max)
{
	while (ATTBD ^ GOOD)
		r_rotate(NULL, &r->a, 0, 0);
	min = ATTNBR;
	while (ATBD ^ GOOD)
		rotate(NULL, &r->a, 0, 0);
	if ((ALNBR > min && ALNBR < max)
	|| (min > max && (ALNBR > min || ALNBR < max)))
	{
		r_rotate(r, &r->a, 'a', GOOD);
		swap(r, &r->a, 'a');
		return (1);
	}
	return (0);
}

static	void	fixe_that(t_roll *r)
{
	if (ALLBD & GOOD && right_check(r, ALLNBR, 0))
		return ;
	if (ATBD & GOOD && left_check(r, 0, ATNBR))
		return ;
	push(r, &r->a, &r->b, 'b');
}

void			second_step(t_roll *r, t_tab *t, int i)
{
//	ft_printf("\n{yellow}{bold}-------------------------------------------------\n");
//	ft_printf("|\t\t{red}{underline}IN SECOND STEP{runderline}{yellow}\t\t\t|\n");
//	ft_printf("-------------------------------------------------{eoc}\n");
	while (++i < 9)
	{
		fixe_push(r, t, i);
		while (error_checker(r)/* && r->nb_b < 12*/)
		{
			ALBD ^ NO_CHECK ? nearest_rotation(r, NO_CHECK, r->nb_a, 0) : 0;
			ALBD & NO_CHECK ? fixe_that(r) : 0;
		}
		//return ;
	}
//	ft_printf("{yellow}{bold}-------------------------------------------------\n");
//	ft_printf("|\t\t{red}{underline}END OF SECOND STEP{runderline}{yellow}\t\t|\n");
//	ft_printf("-------------------------------------------------{eoc}\n\n");
}
