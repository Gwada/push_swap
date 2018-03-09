#include "push_swap.h"

/*static	void	last_and_first(t_roll *r, int *fst, int *lst, int i)
{
	int			size;

	size = r->nb_a;
	if (ALBD & PUSH)
	{
		if (*fst == r->nb_a && !*lst)
		{
			*fst = (i < size - r->b_rot) ? r->b_rot + i : i - (size - r->b_rot);
			*lst = (i < size - r->b_rot) ? r->b_rot + i : i - (size - r->b_rot);
		}
		else
		{
			if (i < (size - r->b_rot) && (size - r->b_rot) - i < *fst)
				*fst = r->b_rot + i;
			else if (i >= (size - r->b_rot) && i - (size - r->b_rot) < *fst)
				*fst = i - (size - r->b_rot);
			if (i < (size - r->b_rot) && r->b_rot + i > *lst)
				*lst = r->b_rot + i;
			else if (i > (size - r->b_rot) && i - (size - r->b_rot) > *lst)
				*lst = i - (size - r->b_rot);
		}
	}
	rotate(NULL, &r->a, 0);
}*/

/*static	void	init_pile(t_roll *r, int *t, int size, int i)
{
	while (++i < size)
		last_and_first(r, &fst, &lst, i);
}*/
