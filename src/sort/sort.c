/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:08:44 by hbouchel          #+#    #+#             */
/*   Updated: 2024/05/15 23:05:23 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*middle;

	bottom = (*stack)->next->next;
	middle = (*stack)->next;
	if (is_sorted(stack))
		return ;
	if ((*stack)->value < middle->value && middle->value > bottom->value
		&& bottom->value > (*stack)->value)
	{
		sa(stack);
		ra(stack);
	}
	else if ((*stack)->value > middle->value && middle->value > bottom->value)
	{
		sa(stack);
		rra(stack);
	}
	else if (middle->value < bottom->value && (*stack)->value < bottom->value)
		sa(stack);
	else if (middle->value > bottom->value && (*stack)->value < middle->value)
		rra(stack);
	else if (middle->value < bottom->value && (*stack)->value > bottom->value)
		ra(stack);
	return ;
}

// void	sort_4(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	distance;

// 	if (is_sorted(stack_a))
// 		return ;
// 	distance = get_distance(stack_a, get_min(stack_a, -1));
// 	if (distance == 1)
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 	{
// 		rra(stack_a);
// 		rra(stack_a);
// 	}
// 	else if (distance == 4)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b);
// 	sort_3(stack_a);
// 	pa(stack_a, stack_b);
// }

// void	sort_5(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	distance;

// 	distance = get_distance(stack_a, get_min(stack_a, -1));
// 	if (distance == 1)
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 	{
// 		rra(stack_a);
// 		rra(stack_a);
// 	}
// 	else if (distance == 4)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b);
// 	sort_4(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// }

 void	sort4_5(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack_a;
	while (!is_sorted(stack_a))
	{
		tmp = *stack_a;
		min = get_min(stack_a, -1);
		if (tmp->index == min)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_a) == 3)
				break ;
		}
		else if (tmp->next->index == min)
			ra(stack_a);
		else
			rra(stack_a);
	}
	if (!is_sorted(stack_a))
		sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}