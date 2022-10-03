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

static void	free_subtree(t_ft_bst_static_node *node)
{
	if (node->left)
		free_subtree(node->left);
	if (node->right)
		free_subtree(node->right);
	free(node);
}

void	ft_bst_static_free(t_ft_bst_static *self)
{
	free_subtree(self->root);
	free(self);
}
