#include "parser.h"

void	handle_in_pipe_state(t_parse_params *p)
{
	if (p->cat == CHAR_GENERAL)
	{
		p->next_state = STATE_IN_STRING;
		append_token(p, TYPE_SPECIAL, "|");
		p->i--;
		//TODO: append | to p->token list
	}
	else if (p->cat == CHAR_WHITE_SPACE)
	{
		p->next_state = STATE_PIPED;
		append_token(p, TYPE_SPECIAL, "|");
		p->i--;
		//TODO: append | to p->token list
	}
	else if (p->cat == CHAR_PIPE)
	{
		p->next_state = STATE_IN_OR;
	}
	else
	{
		p->next_state = STATE_SYNTAX_ERROR;
	}
}
