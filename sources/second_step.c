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
	ALBD ^ GOOD ? r->b_rot = 0 : 0;
	if (ALBD & GOOD)
	{
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
		find_best_rotation(r, r->nb_a - r->b_rot, 0);
		find_best_rotation(r, r->b_rot, ROT | R_ROT);
		int value = 0;
		while (ALBD & ROT || ALBD & R_ROT)
		{
			if (ALBD & ROT)
			{
				rotate(r, &r->a, 'a');
			}
			else
			{
				if (ALLBD & GOOD && ATNBR > ALNBR && ATNBR < ALLNBR)
				{
					r_rotate(r, &r->a, 'a');
					return (swap(r, &r->a, 'a'));
				}
				if (ATBD & GOOD)
					value = ATNBR;
				else
				{
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
					value = ATNBR; 
					while (ALBD ^ GOOD)
						rotate(NULL, &r->a, 0);
				}
				r->nb_b ? b_push(r, value, ALNBR) : 0;
				r_rotate(r, &r->a, 'a');
			}
		}
	}
}

static	void	fixe_that(t_roll *r, int value, int min, int max)
{
	if (ALLBD & GOOD)
	{
		if (ALLLBD & GOOD)
		{
			if (ALNBR > ALLNBR && (ALNBR < ALLLNBR || ALLLNBR == r->a_min))
			{
				return (swap(r, &r->a, 'a'));
			}
			else
				ft_printf("test 1.1.2\n");
		}
	}
	if (ATBD & GOOD)
	{
		if (ALNBR < ATNBR && ATTBD ^ GOOD && r->nb_a > 2)
		{
			r_rotate(NULL, &r->a, 0);
			max = ALNBR;
			while (ATBD ^ GOOD && ATNBR != max)
				r_rotate(NULL, &r->a, 0);
			min = ATNBR;
			while (ALNBR != value)
				rotate(NULL, &r->a, 0);
			int test = 0;
			if ((min < max && ALNBR > min) || min > max)
			{
				r_rotate(r, &r->a, 'a');
				swap(r, &r->a, 'a');
				if (ALLLNBR - ALLNBR != 1 && value_insert(r, 0, ALLNBR, ALLLNBR))
				{
					rotate(r, &r->a, 'a');
					rotate(r, &r->a, 'a');
					return (b_push(r, ATNBR, ALNBR));
				}
				else if (ALLNBR - ALNBR != 1 && value_insert(r, &test, ALNBR, ALLNBR))
				{
					rotate(r, &r->a, 'a');
					return (b_push(r, ATNBR, ALNBR));
				}
				return ;
			}
		}
	}
	push(r, &r->a, &r->b, 'b');
}

void	second_step(t_roll *r)
{
	ft_printf("\n{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}IN SECOND STEP{runderline}\t\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");
	int test = -1;
	while (error_checker(r, 0, -1)/* && ++test <= 100*/)
	{
		nearest_dif_finder(r, -1, r->nb_a, 0);
		ALBD ^ GOOD ? fixe_that(r, ALNBR, 0, 0) : 0;
	}
	while (r->nb_b && BLNBR != r->b_max)
		rotate(NULL, &r->b, 'b');
	int i = -1;
	while (++i < r->nb_b)
	{
		ft_printf("{bold}{green}BLNBR = %11d{eoc}\n", BLNBR);
		rotate(NULL, &r->b, 0);
	}
	ft_printf("{bold}{green}\n%s{eoc}\n\n", test >= 100 ? "test >= 100" : "ONLY GOOD");
	while (ALNBR != r->a_min)
		rotate(NULL, &r->a, 0);
	ft_printf("\n\n");
	i = -1;
	while (++i < r->nb_a)
	{
		ft_printf("{bold}{green}ALNBR = %11d{eoc}\n", ALNBR);
		rotate(NULL, &r->a, 0);
	}

	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}END OF SECOND STEP{runderline}\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n\n");
}
