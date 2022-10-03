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

#include "ft_bst.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft/leak_test.h"

static int	size_t_comparator(const void *a, const void *b)
{
	if (*((const size_t *)a) > *((const size_t *)b))
		return (1);
	if (*((const size_t *)a) < *((const size_t *)b))
		return (-1);
	return (0);
}

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

static bool	test_leak(const void *context)
{
	const size_t *const	order = context;
	t_ft_bst_static		*bst;
	size_t				i;

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
			ft_bst_static_free(bst);
			return (false);
		}
	}
	ft_bst_static_free(bst);
	leak_test_end();
	return (false);
}

static void	test(size_t skip[6])
{
	bool			inserted[7];
	size_t			i;
	size_t			order[7];
	t_ft_bst_static	*bst;
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
		printf("leak_test: %s\n", leak_test_error(errno));
	bst = new_ft_bst_static(
			sizeof(size_t), sizeof(size_t), size_t_comparator);
	if (!bst)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < 7)
		if (ft_bst_static_put(bst, &order[i], &order[i]))
			exit(EXIT_FAILURE);
	ft_bst_static_free(bst);
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
