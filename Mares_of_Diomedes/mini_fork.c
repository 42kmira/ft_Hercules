/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:08:58 by kmira             #+#    #+#             */
/*   Updated: 2019/04/21 15:29:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	printf("Parent %d\n", getpid());
	printf("Forking\n");
	fork();

	printf("Forking again!");
	fork();

	while (1)
	{
		printf("%d\n", getpid());
		sleep(2);
	}
	return (0);
}
