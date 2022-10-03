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

t_ft_bst_static	*new_ft_bst_static(size_t key_length, size_t value_length)
{
	t_ft_bst_static *const	result = malloc(sizeof(t_ft_bst_static));

	if (!result)
		return (NULL);
	result->key_length = key_length;
	result->value_length = value_length;
	result->root = NULL;
	return (result);
}
