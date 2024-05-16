/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:07:13 by hbouchel          #+#    #+#             */
/*   Updated: 2024/05/16 15:41:00 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					swap(t_stack **stack);
int					push(t_stack **stack_to, t_stack **stack_from);
int					rotate(t_stack **stack);
int					reverse_rotate(t_stack **stack);

int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_b, t_stack **stack_a);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);
void				init_stack(t_stack **stack, int ac, char **av);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					get_max_bits(t_stack **stack);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					get_min(t_stack **stack, int val);
// void				sort_3(t_stack **stack_a);
void				tri(t_stack *head, int min, int next_min,
						t_stack **stack_a);
void				sort_4(t_stack **stack_a, t_stack **stack_b);
void				sort_5(t_stack **stack_a, t_stack **stack_b);
void				simple_sort(t_stack **stack_a, t_stack **stack_b);
int					ft_contains(int num, char **av, int i);
int					ft_isnum(char *num);
void				ft_error(char *msg);
void				ft_free(char **str);
int					is_sorted(t_stack **stack);
int					get_distance(t_stack **stack, int index);
t_stack				*ft_lstnew(int value);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
void				ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_lstlast(t_stack *head);
t_stack				*get_next_min(t_stack **stack);
void				index_stack(t_stack **stack);
int					ft_lstsize(t_stack *head);
void				ft_check_args(int ac, char **av);
void				free_stack(t_stack **stack);
void				make_top(t_stack **stack, int distance);
void				sort_3(t_stack **stack);
void				free_error(char **args, int ac);
void				sort4_5(t_stack **stack_a, t_stack **stack_b);

#endif