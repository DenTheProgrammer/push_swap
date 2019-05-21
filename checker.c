//
// Created by den on 17.05.19.
//
//todo how to give array?

#include "push_swap.h"

void	execute_operation(char *op, t_stack *a, t_stack *b)
{
//	static char *nul = NULL;

	if (ft_strequ(op, "pb") || ft_strequ(op, "pa"))
		ft_strequ(op, "pb") ? push(a, b, NULL) : push(b, a, NULL);
	else if (ft_strequ(op, "sb") || ft_strequ(op, "sa"))
		ft_strequ(op, "sb") ? swap(b, NULL) : swap(a, NULL);
	else if (ft_strequ(op, "rb") || ft_strequ(op, "ra"))
		ft_strequ(op, "rb") ? rotate(b, NULL) : rotate(a, NULL);
	else if (ft_strequ(op, "rrb") || ft_strequ(op, "rra"))
		ft_strequ(op, "rrb") ? rev_rotate(b, NULL) : rev_rotate(a, NULL);
	else if (ft_strequ(op, "rr") || ft_strequ(op, "rrr"))
		ft_strequ(op, "rr") ? rot_both(a, b, NULL) : rev_rot_both(a, b, NULL);
	else if (ft_strequ(op, "ss"))
		swap_both(a, b, NULL);
	else
		printf("Unknown operation: %s\n", op);
}

void	read_ops(t_stack *a, t_stack *b)
{
//	print_stacks(a, b);
	char	*line;
	while (get_next_line(0, &line) > 0)
	{
		execute_operation(line, a, b);
//		print_stacks(a, b);
	}
}

//int main(int argc, char **argv)
//{
//	int *input;
//	int B[] = {};
//
//	input = parse_input(argc, argv);
//	t_stack *a = create_stack(input, argc - 1, NULL, ft_strnew(0));
//	t_stack *b = create_stack(B, 0, NULL, ft_strnew(0));
//	read_ops(a, b);
//	return (printf("%s\n", is_sorted_asc(a) && (a->size == argc - 1) ? "OK" : "KO"));
//}