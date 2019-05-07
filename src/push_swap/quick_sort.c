/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaiel <anaiel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:54:37 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/06 10:45:13 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		quick_sort_a(t_piles *piles, t_fun *fun_list, int len, t_opt opt)
{
	int		mediane;
	int		nb_elem;
	int		pushed_under;

	if (is_sorted(piles->a, len, ASCENDING))
		return (1);
	if ((nb_elem = len) && len <= 3)
	{
		sort_3(piles, fun_list, len, opt);
		return (1);
	}
	if (!(pushed_under = 0) && !get_mediane(&mediane, piles->a, len))
		return (0);
	while (len != nb_elem / 2 + nb_elem % 2)
		if (piles->a[0] < mediane && (len--))
			pb(piles, opt);
		else if ((++pushed_under))
			ra(piles, opt);
	while (nb_elem / 2 + nb_elem % 2 != piles->alen && pushed_under--)
		rra(piles, opt);
	return (quick_sort_a(piles, fun_list, nb_elem / 2 + nb_elem % 2, opt)
		&& quick_sort_b(piles, fun_list, nb_elem / 2, opt));
	return (1);
}

int		quick_sort_b(t_piles *piles, t_fun *fun_list, int len, t_opt opt)
{
	int		mediane;
	int		nb_elem;
	int		pushed_under;

	if (!(pushed_under = 0) && is_sorted(piles->b, len, DESCENDING))
		while (len--)
			pa(piles, opt);
	if (len <= 3)
	{
		push_sort_3(piles, fun_list, len, opt);
		return (1);
	}
	if ((nb_elem = len) && !get_mediane(&mediane, piles->b, len))
		return (0);
	while (len != nb_elem / 2)
		if (piles->b[0] >= mediane && len--)
			pa(piles, opt);
		else if (++pushed_under)
			rb(piles, opt);
	while (nb_elem / 2 != piles->blen && pushed_under--)
		rrb(piles, opt);
	return (quick_sort_a(piles, fun_list, nb_elem / 2 + nb_elem % 2, opt)
		&& quick_sort_b(piles, fun_list, nb_elem / 2, opt));
}
