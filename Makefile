
FLAGS = -Wall -Wextra -Werror

all:
	make checker
	make push_swap

push_swap:
	gcc $(FLAGS) min_sort.c min_sort_additional.c is_need_swap.c is_cyclesorted.c find_min_max.c one_line_fix.c push-swap/push_swap.c radix_sort.c mdebbis_sort.c listandstack.c pushandswap.c rotate.c smarter.c trimmer.c bubble_sort.c is_sorted.c parse_input.c validation.c libft.a libftprintf.a -o push_swap

checker:
	gcc $(FLAGS) one_line_fix.c print_stacks.c check/checker.c pushandswap.c rotate.c validation.c listandstack.c is_sorted.c parse_input.c libft.a libftprintf.a -o checker

clean:
	rm -rf push_swap checker

re: clean
	make all