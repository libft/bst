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

static inline void	memcpy(void *dest, const void *source, size_t length)
{
	unsigned char *const		d = dest;
	const unsigned char *const	s = source;
	size_t						i;

	i = -1;
	while (++i < length)
		d[i] = s[i];
}

static bool	get(
	const t_ft_bst_static_context_w *context,
	t_ft_bst_static_node *node
)
{
	int	comparison;

	if (!node)
		return (false);
	comparison = context->self->comparator(node->key, context->key);
	if (comparison < 0)
		return (get(context, node->right));
	if (comparison > 0)
		return (get(context, node->left));
	memcpy(context->value, node->value, context->self->value_length);
	return (true);
}

bool	ft_bst_static_get(
	t_ft_bst_static *self,
	const void *key,
	void *value
)
{
	const t_ft_bst_static_context_w	context = {self, key, value};

	return (get(&context, self->root));
}
