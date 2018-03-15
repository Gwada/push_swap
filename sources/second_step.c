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

static	void	nearest_dif_finder(t_roll *r, int i, int fst, int lst)
{
//	ft_printf("{bold}{underline}{blue}IN\tNEAREST\tALNBR = %d{eoc}\n", ALNBR);
	while (++i < r->nb_a)
	{
		fst == r->nb_a && ALBD ^ GOOD ? fst = i : 0;
		rotate(NULL, &r->a, 0);
	}
	while (i-- > 0)
	{
		!lst && ALBD ^ GOOD ? lst = i + 1 : 0;
		r_rotate(NULL, &r->a, 0);
	}
	r->b_rot = (r->nb_a - (r->nb_a - fst) <= r->nb_a - lst) ? fst : lst;
	ALBD |= r->b_rot < r->nb_a / 2 ? ROT : R_ROT;
	i = ALNBR;
	if (ALBD & ROT)
	{
		ALBD &= ~ROT;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		fst = ATNBR;
		while (ALNBR != i)
			rotate(NULL, &r->a, 0);
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		lst = ALLNBR;
		while (ALNBR != i)
			r_rotate(NULL, &r->a, 0);
		if (ALLBD ^ GOOD
		&& ((ALLNBR > ALNBR && ((ALNBR < fst && ALLNBR > fst) || (ALNBR < fst && ALLNBR > fst)))
		|| (ALLNBR < ALNBR && ((ALNBR < fst && ALLNBR < fst) || (ALNBR > fst && ALLNBR > fst)))))
			return (swap(r, &r->a, 'a'));
		if (ATBD ^ GOOD
		&& ((ATNBR > ALNBR && ((ALNBR < lst && ATNBR < lst) || (ALNBR > lst && ATNBR > lst)))
		|| (ATNBR < ALNBR && ((ALNBR < lst && ATNBR > lst) || (ALNBR > lst && ATNBR < lst)))))
		{
				r_rotate(r, &r->a, 'a');
				return (swap(r, &r->a, 'a'));
		}
		if (ALNBR - fst != 1 && b_push(r, fst, ALNBR))
			return;
		return (rotate(r, &r->a, 'a'));
	}
	if (ALBD & R_ROT)
	{
		ALBD &= ~R_ROT;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		fst = ATNBR;
		while (ALBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		lst = ALLNBR;
		while (ALNBR != i)
			r_rotate(NULL, &r->a, 0);
		if (ALLBD ^ GOOD
		&& ((ALLNBR > ALNBR && ((ALNBR < fst && ALLNBR > fst) || (ALNBR < fst && ALLNBR > fst)))
		|| (ALLNBR < ALNBR && ((ALNBR < fst && ALLNBR < fst) || (ALNBR > fst && ALLNBR > fst)))))
			return (swap(r, &r->a, 'a'));
		if (ATBD ^ GOOD
		&& ((ATNBR > ALNBR && ((ALNBR < lst && ATNBR < lst) || (ALNBR > lst && ATNBR > lst)))
		|| (ATNBR < ALNBR && ((ALNBR < lst && ATNBR > lst) || (ALNBR > lst && ATNBR < lst)))))
		{
				r_rotate(r, &r->a, 'a');
				return (swap(r, &r->a, 'a'));
		}

		if (ALNBR - fst != 1 && b_push(r, fst, ALNBR))
			return;
		if (lst - ALNBR != 1 && value_insert(r, NULL, ALNBR, lst))
		{
			r_rotate(r, &r->a, 'a');
			b_push(r, ALNBR, lst);
			return ;
		}
		return (r_rotate(r, &r->a, 'a'));
	}
}

static	void	fixe_that(t_roll *r, int min, int max)
{
//	ft_printf("{bold}{underline}{magenta}IN\tFIXE{eoc}\tALNBR = %d\n", ALNBR);

	if (ALLBD ^ GOOD && ATBD ^ GOOD)
		return (push(r, &r->a, &r->b, 'b'));
	if (ALLBD & GOOD)
	{
		min = ALLNBR;
		while (ALLLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		max = ALLLNBR;
		while (ALLBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		if ((ALNBR < min && ALNBR < max && min > max)
		|| (ALNBR > min && ((ALNBR < max && min < max) || (ALNBR > max && min > max))))
			return (swap(r, &r->a, 'a'));
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		min = ATNBR;
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		if (ATBD & GOOD && ALLNBR - min != 1 && value_insert(r, NULL, min, ALLNBR))
		{
			b_push(r, min, ALLNBR);
			return ;
		}
	}
	if (ATBD & GOOD)
	{
		max = ATNBR;
		while (ATTBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		min = ATTNBR;
		while (ATBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		if ((ALNBR > max && (max < min && min < ALNBR))
		|| (ALNBR < max && ((max < min && ALNBR < min) || (min < max && min < ALNBR))))
		{
			r_rotate(r, &r->a, 'a');
			return (swap(r, &r->a, 'a'));
		}
		min = ATNBR;
		while (ALLBD ^ GOOD)
			rotate(NULL, &r->a, 0);
		max = ALLNBR;
		while (ATBD ^ GOOD)
			r_rotate(NULL, &r->a, 0);
		if (b_push(r, min, max))
			return ;
	}
	push(r, &r->a, &r->b, 'b');
}

void	second_step(t_roll *r)
{
	ft_printf("\n{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}IN SECOND STEP{runderline}\t\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");
//	int test = -1;
	while (error_checker(r, 0, -1)/* && ++test <= 100*/ && !(r->b_rot = 0))
	{
		ALBD & GOOD ? nearest_dif_finder(r, -1, r->nb_a, 0) : 0;
		ALBD ^ GOOD ? fixe_that(r, 0, 0) : 0;
	//	r->nb_b > r->nb_a / 4 ? ft_printf("{bold}{red}r->nb_b > r->nb_a / 5{eoc}\n") : 0;
//		ft_printf("-------------------------------------------------{eoc}\n");
	}
//	while (r->nb_b && BLNBR != r->b_max)
//		rotate(NULL, &r->b, 'b');
/*	int i = -1;
	while (++i < r->nb_b)
	{
		ft_printf("{bold}{green}BLNBR = %11d{eoc}\n", BLNBR);
		rotate(NULL, &r->b, 0);
	}
	ft_printf("{bold}{green}\n%s test = %d{eoc}\n\n", test >= 100 ? "test >= 100" : "ONLY GOOD", test);
	while (ALNBR != r->a_min)
		rotate(NULL, &r->a, 0);
	ft_printf("\n\n");
	i = -1;
	while (++i < r->nb_a)
	{
		ft_printf("{bold}{green}ALNBR = %11d{eoc}\n", ALNBR);
		rotate(NULL, &r->a, 0);
	}*/

	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}END OF SECOND STEP{runderline}\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n\n");
}
