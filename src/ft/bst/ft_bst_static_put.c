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

static t_ft_bst_static_node	*new_node(const t_ft_bst_static_context *context)
{
	t_ft_bst_static_node *const	result = malloc(sizeof(t_ft_bst_static_node)
			+ context->self->value_length + context->self->key_length);

	result->left = NULL;
	result->right = NULL;
	result->key = &result->value[context->self->value_length];
	memcpy(result->key, context->key, context->self->key_length);
	memcpy(result->value, context->value, context->self->value_length);
	return (result);
}

static t_err	put(
	const t_ft_bst_static_context *context,
	t_ft_bst_static_node **node
)
{
	int	comparison;

	if (!*node)
	{
		*node = new_node(context);
		return (!*node);
	}
	comparison = context->self->comparator((*node)->value, context->value);
	if (comparison < 0)
		return (put(context, &(*node)->right));
	if (comparison > 0)
		return (put(context, &(*node)->left));
	return (true);
}

t_err	ft_bst_static_put(
	t_ft_bst_static *self,
	void *key,
	void *value
)
{
	const t_ft_bst_static_context	context = {self, key, value};

	return (put(&context, &self->root));
}
