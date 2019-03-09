/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:40:39 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 11:19:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

int		main(int aa, char **args)
{
	struct sockaddr_in	server;
	struct sockaddr_in	client;
	int	server_fd;
	int	client_fd;

	if (aa > 2)
		printf("Invalid combination of options");
	else if (aa == 2)
	{
		if (run_as_daemon(args[aa - 1]))
			hydra_daemon_init();
		else
			printf("Running as server, your arguement is wrong");
	}
	server_fd = hydra_socket_init();
	hydra_socket_bind(server_fd, &server);
	hydra_listen(server_fd);
	client_fd = hydra_accept(server_fd, &client);
	hydra_handshake(client_fd);
	close(server_fd);
	close(client_fd);
	return (0);
}