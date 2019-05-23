//
// Created by Maybell Debbi on 2019-05-22.
//

#include "../push_swap.h"

void	execute_operation(char *op, t_stack *a, t_stack *b)
{
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
		throw_error("Error\n");
}

void	read_ops(t_stack *a, t_stack *b, int v)
{
	char	*line;

	line = NULL;
	if (v)
		print_stacks(a, b);
	while (get_next_line(0, &line) > 0)
	{
		execute_operation(line, a, b);
		if (v)
			print_stacks(a, b);
	}
	free(line);
}

int main(int argc, char **argv)
{
	int *input;
	int B[] = {};
	int sorted;
	int visual;

	visual = ft_strequ(argv[1], "-v");
	if (argc < 2)
		return (0);
	if (!is_valid_input(argv + 1 + visual, argc - 1 - visual))
		throw_error("Error\n");
	input = parse_input(argc - 1 - visual, argv + 1 + visual);
	t_stack *a = create_stack(input, argc - 1 - visual, NULL);
	t_stack *b = create_stack(B, 0, NULL);
	free(input);
	read_ops(a, b, visual);
	sorted = is_sorted_asc(a) && (a->size == argc - 1 - visual);
	free_stack(a);
	free_stack(b);
	return (printf("%s\n", sorted ? "OK" : "KO"));
}