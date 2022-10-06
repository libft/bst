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

static t_err	func(
	void *context,
	const void *key,
	void *value)
{
	size_t *const	i = context;

	(void)value;
	if (*((const size_t *)key) + 1 < *i + 1)
		return (true);
	*i = *((const size_t *)key);
	return (false);
}

static bool	check(t_ft_bst_static *bst, bool full)
{
	size_t	i;
	size_t	value;

	i = -1;
	if (full)
		while (++i < 7)
			if (!ft_bst_static_get(bst, &i, &value) || value != i)
				return (true);
	i = -1;
	return (ft_bst_static_iterate(bst, func, &i));
}

bool	test_leak(const void *context)
{
	const size_t *const	order = context;
	t_ft_bst_static		*bst;
	size_t				i;
	bool				result;

	leak_test_start();
	bst = new_ft_bst_static(
			sizeof(size_t), sizeof(size_t), size_t_comparator);
	if (!bst)
		return (false);
	i = -1;
	while (++i < 7)
	{
		if (ft_bst_static_put(bst, &order[i], &order[i]))
		{
			result = check(bst, false);
			ft_bst_static_free(bst);
			return (result);
		}
	}
	result = check(bst, true);
	ft_bst_static_free(bst);
	leak_test_end();
	return (result);
}
