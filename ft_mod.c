#include "ft_db.h"

char *ft_option(int option)
{
	if (option == 1)
		return ("First name");
	else if (option == 2)
		return ("Last name");
	else if (option == 3)
		return ("Year of birth");
	else if (option == 4)
		return ("Phone number");
	else if (option == 5)
		return ("Current project");
	return ("option");
}

void	ft_mod_option(t_data *a, FILE *fd)
{
	int option;

	option = 1;
	while (option)
	{
		printf("\n\t%sChoose a field to modify:%s\n\t 1: First name\n\t 2: Last name\n\t 3: Year of birth\n\t 4: Phone number\n\t 5: Current_project\n\t 0: Save\n\n", CYAN BOLD_ON, BOLD_OFF RESET);
		scanf("%d", &option);
		printf("\n%sEnter new %s:%s\n",BOLD_ON, ft_option(option), BOLD_OFF RESET);
		if (option < 0 || option > 5)
			continue ;
		if (option == 1)
			scanf("%s", a->first_name);
		else if (option == 2)
			scanf("%s", a->last_name);
		else if (option == 3)
			scanf("%s", a->birthyear);
		else if (option == 4)
			scanf("%s", a->phonenumber);
		else if (option == 5)
			scanf("%s", a->curr_proj);
		else 
			fwrite(a, sizeof(*a), 1, fd);
	}
}

void	ft_mod(FILE *fd)
{
	t_data a;
	int	found;
	char last_name[50];

	rewind(fd);
	printf("\n%sEnter Last name of the student to modify:%s\n",
					BOLD_ON, BOLD_OFF RESET);
	scanf("%s", last_name);
	while (fread(&a, sizeof(a), 1, fd) == 1)
	{
		found = 0;
		if (strcmp(last_name, a.last_name) == 0)
		{
			printf("\n\t%sData of the student you're modifying:%s\n",
					BOLD_ON, BOLD_OFF RESET);
			ft_view_one(a);
			fseek(fd, -sizeof(t_data), SEEK_CUR);
			found = 1;
			break ;
		}
	}
	if (found)
		ft_mod_option(&a, fd);
	else	
		printf ("There's no such student\n");
}
