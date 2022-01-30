#include <stdio.h>
#include <libft.h>

void	ft_print_list(t_list *lst)
{
	if (!lst)
	{
		puts("The list is empty");
		return ;
	}
	do {
		printf("%s\n", (char*) lst->data);
	} while ((lst = lst->next));
}

int main(void)
{
	t_list *lst = ft_lstnew("First");
	ft_lstadd_back(&lst, ft_lstnew("Second"));
	ft_lstadd_back(&lst, ft_lstnew("Fourth"));
	ft_lstadd_back(&lst, ft_lstnew("Fifth"));
	ft_lstadd_back(&lst, ft_lstnew("Sixth"));
	ft_lstadd_back(&lst, ft_lstnew("Seventh"));

	ft_print_list(lst);

	return 0;
}
