#include "push_swap.h"

void			nearest_dif_finder(t_roll *r, int i, int fst, int lst)
{
	while (++i < r->nb_a)
	{
		fst == r->nb_a && ALBD ^ GOOD ? fst = i: 0;
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
	while (ALBD & ROT || ALBD & R_ROT)
		ALBD & ROT ? rotate(r, &r->a, 'a') : r_rotate(r, &r->a, 'a');
}
