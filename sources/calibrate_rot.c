#include "push_swap.h"

static	int		push_calibrate(t_roll *r, int rot, int i)
{
	ft_printf("{bold}{cyan}{underline}IN\tPUSH_CALIBRATE{eoc}\n");
	int			ret;
	int			rot_b;

	ret = 0;
	while (++i < r->nb_b)
	{
		if ((ALNBR > BTNBR && ALNBR < BLNBR)
		|| (BTNBR > BLNBR && (ALNBR > BTNBR || ALNBR < BLNBR)))
			rot_b = i;
		rotate(NULL, &r->b, 0);
	}
	if (!rot_b)
		return (0);
	if (rot >= r->nb_b)
		return (1);
	if (rot <= r->nb_a / 2)
	{
		if ((rot_b <= r->nb_b / 2) || (rot < r->nb_b && r->nb_b - rot <= rot_b))
			ret = 1;
	}
	else
	{
		if ((rot_b > r->nb_b / 2) || (r->nb_a - rot >= r->nb_b - rot_b))
			ret = 1;
	}
	ft_printf("{bold}{cyan}{underline}END\tPUSH_CALIBRATE{eoc}\n");
	return (ret);
}

int			calibrate_rot(t_roll *r, int rot, int i)
{
	ft_printf("{bold}{underline}\nIN\tCALIBRATE_ROT{eoc}\n");
	ft_printf("r->nb_a = %d r->b_rot = %d rot = %d\n", r->nb_a, r->b_rot, rot);
	int		ret;

	ret = 0;
	if (rot <= r->nb_a / 2)
	{
		while (++i < rot)
			rotate(NULL, &r->a, 0);
		ALBD ^ GOOD ? ret = push_calibrate(r, rot, -1) : 0;
		while (i-- > 0)
			r_rotate(NULL, &r->a, 0);
	}
	else
	{
		i = r->nb_a;
		while (i-- > rot)
			r_rotate(NULL, &r->a, 0);
		ALBD ^ GOOD ? ret = push_calibrate(r, rot, -1) : 0;
		while (++i < r->nb_a)
			rotate(NULL, &r->a, 0);
	}
	(void)r;
	(void)rot;
	ft_printf("{bold}{underline}END\tCALIBRATE_ROT{eoc}\n");
	return (ret);
}
