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

#ifndef FT_BST_H
# define FT_BST_H

# include "ft_bst_types.h"

# include "ft_types.h"

typedef t_err	(*t_ft_bst_static_iterate_param)(
					void *context,
					const void *key,
					void *value);

t_ft_bst_static		*new_ft_bst_static(
						size_t key_length,
						size_t value_length,
						t_ft_bst_static_comparator comparator);
bool				ft_bst_static_get(
						t_ft_bst_static *self,
						const void *key,
						void *value);
t_err				ft_bst_static_put(
						t_ft_bst_static *self,
						const void *key,
						const void *value);
bool				ft_bst_static_pop(
						t_ft_bst_static *self,
						const void *key,
						void *value);
t_err				ft_bst_static_iterate(
						t_ft_bst_static *self,
						void *t_ft_bst_static_iterate_param,
						void *context);
void				ft_bst_static_free(
						t_ft_bst_static *self);

#endif
