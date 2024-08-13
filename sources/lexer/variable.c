#include "minishell.h"

static void	assign_var_type(t_token **node)
{
	int	i;

	i = 0;
	while ((*node)->content[i])
	{
		if ((*node)->content[i] == '$')
		{	
			if ((*node)->prev && (*node)->prev->type == HEREDOC)
				break ;
			(*node)->type = VAR;
			return ;
		}
		i++;
	}
}

int	check_variable(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		assign_var_type(&tmp);
		tmp = tmp->next;
	}
	return (OK);
}
