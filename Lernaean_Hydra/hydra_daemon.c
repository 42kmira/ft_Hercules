/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra_daemon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 09:37:06 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 17:25:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

int		run_as_daemon(char *flags)
{
	if (strncmp(flags, "-D", 2) == 0)
		return (1);
	return (0);
}

/*
** (pid < 0) will exit the program because of error.
** (pid > 0) will exit the program because it is the parent.
** fork(2) will set the pid of the child to 0 if successful.
** setsid(2) will make a new session without a terminal
** if and only if the pid is not a process group,
** fork(2) ensures that the child pid has its own process ID
** that doesn't match any existing group.
*/

void	hydra_daemon_init(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("I spooned instead of forked, sorry.\n");
		exit(0);
	}
	else if (pid > 0)
	{
		printf("Hello darkness my old friend...\n");
		exit(0);
	}
	pid = setsid();
	if (pid == -1)
	{
		printf("New session could not start.\n");
		exit(0);
	}
	close(STDOUT);
}
