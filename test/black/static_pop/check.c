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

#include "ft_bst.h"

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

bool	check(t_ft_bst_static *bst, bool full)
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
