/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 19:14:31 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "libft.h"
#include "ft_printf.h"

int				main(void)
{
	ft_printf("ret = %d\n", ft_printf("test\n"));
	return (0);
}
