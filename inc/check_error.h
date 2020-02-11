typedef struct		s_check_bad_order
{
	int				tube_pars;
	int				start;
	int				end;
}					t_check_bad_order;

int			read_error(t_read_room *pars);
int			free_temp_line(char *temp, char *line, int ret);
int			count_space(char *line);
int			check_definition(t_read_room *pars, t_check_bad_order *order, int index);
int			check_room(char *line, int tube_pars);
int			check_tubes(char *line);


