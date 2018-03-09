#include "push_swap.h"

void	second_step(t_roll *r, int size, int i, int j)
{
	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}IN SECOND STEP{runderline}\t\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");

	find_best_rotation(r, size - r->b_rot, 0);
	display_piles(r, &r->a, &r->b);
	(void)size;
	(void)i;
	(void)j;
	find_best_rotation(r, r->b_rot, 0);
	display_piles(r, &r->a, &r->b);

	ft_printf("{yellow}{bold}-------------------------------------------------\n");
	ft_printf("|\t\t{underline}END OF SECOND STEP{runderline}\t\t|\n");
	ft_printf("-------------------------------------------------{eoc}\n");
}
