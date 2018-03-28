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
	if (!total && r->nb_b > 0 && checker & NO_CHECK)
		while (i-- > 0)
		{
			if (ATBD & GOOD && ATNBR >= r->pvt)
			{
				while (ALBD ^ GOOD)
					rotate(NULL, &r->a, 0);
				if (ALNBR >= r->pvt)
					while (ATBD ^ GOOD)
					{
						r_rotate(NULL, &r->a, 0);
						ALBD ^ GOOD && ALNBR < r->pvt ? ALBD = checker : 0;
						ALBD ^ GOOD && ALNBR < r->pvt ? ++total : 0;
					}
				else
					while (ATBD ^ GOOD)
						r_rotate(NULL, &r->a, 0);
			}
			rotate(NULL, &r->a, 0);
		}
	return (total);
}

static	int		right_check(t_roll *r, int min, int max)
{
	while (ALLLBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	max = ALLLNBR;
	while (ALLBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
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
		r_rotate(NULL, &r->a, 0);
	min = ATTNBR;
	while (ATBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	if ((ALNBR > min && ALNBR < max)
	|| (min > max && (ALNBR > min || ALNBR < max)))
	{
		ft_printf("1 min %d max %d\n", min , max);
		r_rotate(r, &r->a, 'a');
		swap(r, &r->a, 'a');
		return (1);
	}
	min = ATNBR;
	while (ALLBD ^ GOOD)
		rotate(NULL, &r->a, 0);
	max = ALLNBR;
	while (ATBD ^ GOOD)
		r_rotate(NULL, &r->a, 0);
	if (max - min != 1 && b_push(r, min, max))
	{
		ft_printf("2 min %d max %d\n", min , max);
		return (1);
	}
	return (0);
}

static	void	fixe_that(t_roll *r)
{
	ft_printf("in fixe\n");//
	if (ALLBD & GOOD && right_check(r, ALLNBR, 0))
	{
		ft_printf("right end fixe\n");//
		return ;
	}
	if (ATBD & GOOD && left_check(r, 0, ATNBR))
	{
		ft_printf("left end fixe\n");//
		return ;
	}
	ft_printf("end fixe\n");//
	push(r, &r->a, &r->b, 'b');
}

void	second_step(t_roll *r, int i)
{
	ft_printf("\n{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{red}{underline}IN SECOND STEP{runderline}{yellow}\t\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");
	int	sort[2];

	sort[0] = NO_CHECK;
	sort[1] = CHECK;
	while (++i < 2)
	{
		i == 1 ? ft_printf("\n\n\n{bold}{cyan}test CHECK{eoc}\n") : 0;
		i == 0 ? ft_printf("\n\n\n{bold}{magenta}test NO_CHECK\n{eoc}") : 0;
		ft_printf("{bold}r->pvt = %d\n\n{eoc}", r->pvt);
		while (error_checker(r, sort[i]))
		{
			ALBD ^ sort[i] ? nearest_rotation(r, sort[i], r->nb_a, 0) : 0;
			ALBD & sort[i] ? fixe_that(r) : 0;

		}
	}
	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{red}{underline}END OF SECOND STEP{runderline}{yellow}\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n\n");
}
