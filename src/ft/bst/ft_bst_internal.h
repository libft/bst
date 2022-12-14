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

#ifndef FT_BST_INTERNAL_H
# define FT_BST_INTERNAL_H

# include "ft_bst_types.h"

typedef struct s_ft_bst_static_context_r
{
	t_ft_bst_static	*self;
	const void		*key;
	const void		*value;
}	t_ft_bst_static_context_r;

typedef struct s_ft_bst_static_context_w
{
	t_ft_bst_static	*self;
	const void		*key;
	void			*value;
}	t_ft_bst_static_context_w;

#endif
