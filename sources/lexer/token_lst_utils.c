/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 05:39:48 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/14 10:49:04 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token_lst(char *content, char *content_copy, int type, int qs)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token) * 1);
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->cc = content_copy;
	new_node->is_var = false;
	new_node->type = type;
	new_node->q_status = qs;
	new_node->has_quotes = false;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_back_tok_lst(t_token **lst, t_token *new_node)
{
	t_token	*start;

	start = *lst;
	if (!start)
	{
		*lst = new_node;
		return ;
	}
	if (lst && *lst && new_node)
	{
		while (start->next)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}
}

void	lstdelone_token(t_token *lst, void (*del)(void *))
{
	if (del && lst && lst->content)
	{	
		(*del)(lst->content);
		lst->content = NULL;
	}
	if (del && lst && lst->cc)
	{	
		(*del)(lst->cc);
		lst->cc = NULL;
	}
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free_ptr(lst);
}

void	lstclear_token(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		lstdelone_token(*lst, del);
		*lst = tmp;
	}
}
