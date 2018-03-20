#include "push_swap.h"

static	int		error_checker(t_roll *r, int checker)
{
	int			i;
	int			total;

	i = -1;
	total = 0;
	while (++i < r->nb_a)
	{
		ALBD & checker ? ++total : 0;
		rotate(NULL, &r->a, 0);
	}
//	ft_printf("in error_checker ret = %d\n", total);
	return (total);
}

static	void	fixe_that(t_roll *r, int min, int max)
{
//	ft_printf("{bold}{underline}{magenta}IN\tFIXE{eoc}\tALNBR = %d\n", ALNBR);

	if (ALLBD & GOOD && ((min = ALLNBR) || !(min = ALLNBR)))
	{
//		ft_printf("ALLBD & GOOD\n");
		while (ALLLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		max = ALLLNBR;
		while (ALLBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
//		ft_printf("min = %d max = %d\n", min, max);
		if ((min < max && ALNBR > min && ALNBR < max)
		|| (min > max && (ALNBR > min || ALNBR < max)))
		{
//			ft_printf("(min < max && ALNBR > min && ALNBR < max) ||");
//			ft_printf(" || (min > max && (ALNBR > min || ALNBR < max))");
//			ft_printf(" -> SWAP -> return\n");
			return (swap(r, &r->a, 'a'));
		}
	}
	if (ATBD & GOOD && ((max = ATNBR) || !(max = ATNBR)))
	{
//		ft_printf("ATBD & GOOD\n");
		while (ATTBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		min = ATTNBR;
		while (ATBD ^ GOOD)
			rotate(NULL, &r->a, 0);
//		ft_printf("min = %d max = %d\n", min, max);
		if ((min < max && ALNBR > min && ALNBR < max)
		|| (min > max && (ALNBR > min || ALNBR < max)))
		{
//			ft_printf("(min < max && ALNBR > min && ALNBR < max) ||");
//			ft_printf(" || (min > max && (ALNBR > min || ALNBR < max))");
//			ft_printf(" -> R_ROT -> SWAP -> return\n");
			r_rotate(r, &r->a, 'a');
			return (swap(r, &r->a, 'a'));
		}
		min = ATNBR;
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		max = ALLNBR;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
//		ft_printf("min = %d max = %d\n", min, max);
		if (max - min != 1 && b_push(r, min, max))
//		if (max - min != 1 && value_insert(r, NULL, min, max))
//		{
//			ft_printf("max - min != 1 && value_insert(r, NULL, min, max) -> B_PUSH -> return\n");
//			b_push(r, min, max);
			return ;
//		}
	}
//	ft_printf("{bold}{underline}{yellow}NO THINGS TO DO -> PUSH\n");
	push(r, &r->a, &r->b, 'b');
}

void	second_step(t_roll *r)
{
	ft_printf("\n{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{red}{underline}IN SECOND STEP{runderline}{yellow}\t\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");
	int	i;
	int	test;//
	int	sort[2];

	i = -1;
	test = 0;//
	sort[1] = NO_CHECK;
	sort[0] = CHECK;
	while (++i < 3)
	{
		i == 0 ? ft_printf("\n\n\ntest CHECK\n\n\n") : 0;
		i == 1 ? ft_printf("\n\n\ntest NO_CHECK\n\n\n") : 0;
		test = 0;
		while (error_checker(r, sort[i]) && ++test /*<= 40*/ && !(r->b_rot = 0))
		{
			ALBD ^ sort[i] ? nearest_rotation(r, sort[i], r->nb_a, 0) : 0;
			ALBD & sort[i] ? fixe_that(r, r->nb_a, 0) : 0;
		}
	}

	i = -1;
	while (++i < r->size)
	{
		if (i >= r->nb_a && i >= r->nb_b)
			break ;
		i < r->nb_a && ALNBR != r->a_min ? rotate(NULL, &r->a, 0) : 0;
		i < r->nb_b && BLNBR != r->b_min ? rotate(NULL, &r->b, 0) : 0;
	}
	i = -1;
	while (++i < r->size)
	{
		if (i >= r->nb_a && i >= r->nb_b)
			break ;
		i < r->nb_a ? ft_printf("{bold}{green}ALNBR = %12d{eoc}\t", ALNBR) : 0;
		i < r->nb_a ? rotate(NULL, &r->a, 0) : 0;
		i < r->nb_b ? ft_printf("{bold}{green}BLNBR = %12d{eoc}\t", BLNBR) : 0;
		i < r->nb_b ? rotate(NULL, &r->b, 0) : 0;
		ft_printf("\n");
	}
	ft_printf("{bold}{green}\n%s test = %d{eoc}\n\n", test >= 30 ? "test >= 30" : "ONLY GOOD", test);

	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{red}{underline}END OF SECOND STEP{runderline}{yellow}\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n\n");
}
