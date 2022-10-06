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

#ifndef TEST_H
# define TEST_H

# include <stdbool.h>
# include <stddef.h>

# include "ft_bst.h"

typedef struct s_test_orders
{
	size_t	*order1;
	size_t	*order2;
}	t_test_orders;

bool	check(t_ft_bst_static *bst, bool full);
void	test(size_t order1[6], size_t order2[6]);

#endif
