/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:19:58 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 17:25:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		client_init(void)
{
	int socket_fd;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
	{
		printf("Socket unsecessfully created\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	return (socket_fd);
}

void	client_connect(int socket_fd, struct sockaddr_in *server_address, char *address)
{
	bzero(server_address, sizeof(*server_address));
	server_address->sin_family = AF_INET;
	server_address->sin_addr.s_addr = inet_addr(address);
	server_address->sin_port = htons(PORT_NUM);
	if (connect(socket_fd, (struct sockaddr *)server_address, sizeof(*server_address)))
	{
		printf("The glue did not hold.\n");
		exit(0);
	}
	else
		printf("Server is connected\n");
}

void	client_session(int socket_fd)
{
	char buffer[BUFF_SIZE + 1];
	int n;

	bzero(buffer, BUFF_SIZE + 1);
	printf("I am starting your session with %s on port %d\n", ADDRESS, PORT_NUM);
	printf("Please wait...\n");
	sleep(2);
	printf("Starto!\n");
	read(socket_fd, buffer, BUFF_SIZE);
	if (buffer[0] != '\0' || buffer[0] != '\n')
		printf("%s", buffer);
	while (1)
	{
		printf("\033[1;37mEnter your string: \033[1;35m");
		bzero(buffer, BUFF_SIZE + 1);
		n = 0;
		while ((buffer[n] = getchar()) != '\n')
			n++;
		dprintf(socket_fd, "%s", buffer);
		bzero(buffer, BUFF_SIZE);
		sleep(1);
		read(socket_fd, buffer, BUFF_SIZE);
		if (buffer[0] == 'H')
			printf("%s", &buffer[1]);
	}
}
