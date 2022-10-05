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

#include <stdlib.h>

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

static t_ft_bst_static_node	*pop_right_node(
	t_ft_bst_static_node **node
)
{
	t_ft_bst_static_node	*result;

	if ((*node)->right)
		return (pop_right_node(&(*node)->right));
	result = *node;
	*node = (*node)->left;
	return (result);
}

static void	delete_node(
	t_ft_bst_static_node **node
)
{
	t_ft_bst_static_node	*replacement;

	if (!(*node)->left && !(*node)->right)
		replacement = NULL;
	else if (!(*node)->left)
		replacement = (*node)->left;
	else if (!(*node)->right)
		replacement = (*node)->right;
	else
	{
		replacement = pop_right_node(&(*node)->left);
		replacement->left = (*node)->left;
		replacement->right = (*node)->right;
	}
	free(*node);
	*node = replacement;
}

static bool	pop(
	const t_ft_bst_static_context_w *context,
	t_ft_bst_static_node **node
)
{
	int	comparison;

	if (!*node)
		return (false);
	comparison = context->self->comparator((*node)->key, context->key);
	if (comparison < 0)
		return (pop(context, &(*node)->right));
	if (comparison > 0)
		return (pop(context, &(*node)->left));
	memcpy(context->value, (*node)->value, context->self->value_length);
	delete_node(node);
	return (true);
}

bool	ft_bst_static_pop(
	t_ft_bst_static *self,
	const void *key,
	void *value
)
{
	const t_ft_bst_static_context_w	context = {self, key, value};

	return (pop(&context, &self->root));
}
