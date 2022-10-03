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

#ifndef FT_BST_TYPES_H
# define FT_BST_TYPES_H

# include <stddef.h>

typedef struct s_ft_bst_static_node
{
	struct s_ft_bst_static_node	*left;
	struct s_ft_bst_static_node	*right;
	void						*key;
	unsigned char				value[];
}	t_ft_bst_static_node;

typedef struct s_ft_bst_static
{
	size_t					key_length;
	size_t					value_length;
	t_ft_bst_static_node	*root;
}	t_ft_bst_static;

#endif
