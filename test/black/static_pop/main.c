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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft/leak_test.h"
#include "ft_bst.h"

static size_t	skipped(bool inserted[6], size_t skip)
{
	size_t	result;

	result = 0;
	while (inserted[result])
		result++;
	while (skip--)
	{
		result++;
		while (inserted[result])
			result++;
	}
	inserted[result] = true;
	return (result);
}

static void	main4(size_t order1[6], size_t skip[5])
{
	bool			inserted[6];
	size_t			i;
	size_t			order2[6];

	i = -1;
	while (++i < 6)
		inserted[i] = 0;
	i = -1;
	while (++i < 5)
		order2[i] = skipped(inserted, skip[i]);
	order2[i] = skipped(inserted, 0);
	test(order1, order2);
}

static void	main3(size_t order[6])
{
	size_t	skip[5];

	skip[0] = -1;
	while (++skip[0] < 6)
	{
		skip[1] = -1;
		while (++skip[1] < 5)
		{
			skip[2] = -1;
			while (++skip[2] < 4)
			{
				skip[3] = -1;
				while (++skip[3] < 3)
				{
					skip[4] = -1;
					while (++skip[4] < 2)
						main4(order, skip);
				}
			}
		}
	}
}

static void	main2(size_t skip[5])
{
	bool			inserted[6];
	size_t			i;
	size_t			order[6];

	i = -1;
	while (++i < 6)
		inserted[i] = 0;
	i = -1;
	while (++i < 5)
		order[i] = skipped(inserted, skip[i]);
	order[i] = skipped(inserted, 0);
	main3(order);
}

int	main(void)
{
	size_t	skip[5];

	skip[0] = -1;
	while (++skip[0] < 6)
	{
		skip[1] = -1;
		while (++skip[1] < 5)
		{
			skip[2] = -1;
			while (++skip[2] < 4)
			{
				skip[3] = -1;
				while (++skip[3] < 3)
				{
					skip[4] = -1;
					while (++skip[4] < 2)
						main2(skip);
				}
			}
		}
	}
}
