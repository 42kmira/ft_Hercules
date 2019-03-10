/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:57:11 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 17:02:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(void)
{
	int socket_fd;
	struct sockaddr_in server_address;

	socket_fd = client_init();
	client_connect(socket_fd, &server_address, ADDRESS);
	client_session(socket_fd);
	printf("Finished\n");
	return (1);
}
