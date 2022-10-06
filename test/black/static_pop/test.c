/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#include <stdio.h>
#include <stdlib.h>

#include "ft/leak_test.h"
#include "ft_bst.h"

static int	size_t_comparator(const void *a, const void *b)
{
	if (*((const size_t *)a) > *((const size_t *)b))
		return (1);
	if (*((const size_t *)a) < *((const size_t *)b))
		return (-1);
	return (0);
}

static t_err	put(t_ft_bst_static *bst, size_t order[6])
{
	size_t	i;

	i = -1;
	while (++i < 6)
		if (ft_bst_static_put(bst, &order[i], &order[i]))
			return (true);
	return (false);
}

static t_err	pop(t_ft_bst_static *bst, size_t order[6])
{
	size_t	i;
	size_t	value;

	i = -1;
	while (++i < 6)
		if (ft_bst_static_pop(bst, &order[i], &value))
			if (order[i] != value || check(bst, false))
				return (true);
	return (false);
}

static bool	test_leak(const void *context)
{
	const t_test_orders *const	orders = context;
	t_ft_bst_static				*bst;
	bool						result;

	leak_test_start();
	bst = new_ft_bst_static(
			sizeof(size_t), sizeof(size_t), size_t_comparator);
	if (!bst)
		return (false);
	if (put(bst, orders->order1))
	{
		ft_bst_static_free(bst);
		return (false);
	}
	result = pop(bst, orders->order2);
	ft_bst_static_free(bst);
	leak_test_end();
	return (result);
}

void	test(size_t order1[6], size_t order2[6])
{
	const t_test_orders	orders = {order1, order2};
	const int			errno = leak_test(test_leak, &orders, NULL);

	if (errno)
	{
		printf("%s\n", leak_test_error(errno));
		exit(EXIT_FAILURE);
	}
}
