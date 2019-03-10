/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra_server_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:32:11 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 17:26:46 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

/*
** Creates a socket and returns the file descriptor (socket_fd) to access it.
** Exits the program is socket was unable to be made.
** AF_INET is the most used type of family.
** SOCK_STREAM will allow a 'reliable' two-way communication.
** 0 will be assign protocal 0 to the socket which will automatically
** use TCP or UDP according to the curcumstances. In most cases it will be TCP.
*/

int		hydra_socket_init(void)
{
	int socket_fd;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
	{
		write(STDOUT, "The socket was unsuccessfully created.\n", 39);
		exit(0);
	}
	else
		write(STDOUT, "The socket is ready to rock it.\n", 32);
	return (socket_fd);
}

/*
** Binds the socket located at socket_fd.
** Makes the socket at socket_fd a AF_NET class of socket.
** Makes the address of the socket able to listen to all 'interfaces' and
** when sending uses the lowest possible one. (INADDR_ANY)
** Makes the port of the socket the designated port number.
** htonl and htons are used because internet protocal for
** addresses are 'reversed'.
*/

void	hydra_socket_bind(int socket_fd, struct sockaddr_in *server_address)
{
	server_address->sin_family = AF_INET;
	server_address->sin_addr.s_addr = htonl(INADDR_ANY);
	server_address->sin_port = htons(PORT_NUM);
	if (bind(socket_fd, (struct sockaddr *)server_address, \
					(socklen_t)(sizeof(*server_address))))
	{
		write(STDOUT, "The glue did not hold.\n", 23);
		exit(0);
	}
	else
		write(STDOUT, "Binding was successful.\n", 24);
}

/*
** listen(2) requires the socket created to be SOCK_STREAM or SOCK_SEPACKET
** Usual max is 5
*/

void	hydra_listen(int socket_fd)
{
	if (listen(socket_fd, BACKLOG))
		write(STDOUT, "Server failed to listen\n", 40);
	else
		write(STDOUT, "Server is listening...\n", 23);
}

/*
** Creates a fd for the client.
*/

int		hydra_accept(int server_fd, struct sockaddr_in *client)
{
	int client_fd;
	int client_size;

	client_size = sizeof(client);
	if ((client_fd = accept(server_fd, (struct sockaddr *)client, \
									(socklen_t *)client)) == -1)
	{
		write(STDOUT, "Did not accept the message please try again.\n", 45);
		exit(0);
	}
	else
	{
		dprintf(client_fd, \
			"\033[1;36;40m[HYDRA]\033[0;37;40m: Server is ready to chat.\n");
		printf("\033[1;36;40m[HYDRA]\033[0;37;40m:Server is ready to chat.\n");
	}
	return (client_fd);
}

/*
** Verifies if the password is right ten send the secret to the sender.
*/

void	hydra_handshake(int client_fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		size;

	size = 0;
	while (size >= 0)
	{
		bzero(buffer, BUFF_SIZE + 1);
		size = read(client_fd, buffer, BUFF_SIZE);
		printf("\033[1;36;40m[HYDRA]\033[0;37;40m:\033[0;92;40mSERVER BUFF");
		printf("\033[0;37;40m %s", buffer);
		dprintf(client_fd, "H");
		if (strncmp(buffer, "ping", 4) == 0)
			hydra_message(client_fd);
		else if (strncmp(buffer, "exit", 4) == 0)
		{
			dprintf(client_fd, \
					"\033[1;31mConncetion is Terminated\033[0;37m\n");
			printf("\033[1;31mConncetion is Terminated\033[0;37m\n");
			exit(0);
		}
	}
	printf("\033[1;31mConncetion is Terminated\033[0;37m\n");
	exit(0);
}
