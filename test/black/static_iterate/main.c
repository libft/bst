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

static size_t	skipped(bool inserted[7], size_t skip)
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

static void	test(size_t skip[6])
{
	bool			inserted[7];
	size_t			i;
	size_t			order[7];
	int				errno;

	i = -1;
	while (++i < 7)
		inserted[i] = 0;
	i = -1;
	while (++i < 6)
		order[i] = skipped(inserted, skip[i]);
	order[i] = skipped(inserted, 0);
	errno = leak_test(test_leak, order, NULL);
	if (errno)
	{
		printf("leak_test: %s\n", leak_test_error(errno));
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	size_t	skip[6];

	skip[0] = -1;
	while (++skip[0] < 7)
	{
		skip[1] = -1;
		while (++skip[1] < 6)
		{
			skip[2] = -1;
			while (++skip[2] < 5)
			{
				skip[3] = -1;
				while (++skip[3] < 4)
				{
					skip[4] = -1;
					while (++skip[4] < 3)
					{
						skip[5] = -1;
						while (++skip[5] < 2)
							test(skip);
					}
				}
			}
		}
	}
}
