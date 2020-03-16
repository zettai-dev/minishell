#include "parser.h"

void	handle_in_and_state(t_parse_params *p)
{
	if (p->cat == CHAR_GENERAL)
	{
		p->next_state = STATE_IN_STRING;
		append_token(p, TYPE_SPECIAL, "&&");
		//TODO: append && to p->token list
		p->i--;
	}
	else if (p->cat == CHAR_WHITE_SPACE)
	{
		p->next_state = STATE_IN_AND;
		//TODO: append && to p->token list
	}
	else
	{
		p->next_state = STATE_SYNTAX_ERROR;
	}
}
