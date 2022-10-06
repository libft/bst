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

#include "ft_bst_internal.h"

static t_err	iterate(
	t_ft_bst_static *self,
	t_ft_bst_static_node *node,
	t_ft_bst_static_iterate_func func,
	void *context
)
{
	if (!node)
		return (false);
	if (iterate(self, node->left, func, context))
		return (true);
	if (func(context, node->key, node->value))
		return (true);
	if (iterate(self, node->right, func, context))
		return (true);
	return (false);
}

t_err	ft_bst_static_iterate(
	t_ft_bst_static *self,
	t_ft_bst_static_iterate_func func,
	void *context
)
{
	return (iterate(self, self->root, func, context));
}
