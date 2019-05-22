
FLAGS = -Wall -Wextra -Werror -g

all:
	make -C libft
	make checker
	make push_swap

push_swap:
	gcc $(FLAGS) push-swap/push_swap.c radix_sort.c mdebbis_sort.c list\&stack.c push\&swap.c rotate.c smarter.c trimmer.c bubble_sort.c is_sorted.c parse_input.c libft/libft.a -o push_swap

checker:
	gcc $(FLAGS) print_stacks.c check/checker.c push\&swap.c rotate.c list\&stack.c is_sorted.c parse_input.c libft/libft.a -o checker

clean:
	rm -rf push_swap checker
	make clean -C libft

fclean: clean
	make fclean -C libft

re: fclean
	make re -C libft
	make all