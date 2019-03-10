/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:13:05 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 17:05:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT_NUM 6456
#define ADDRESS "10.112.5.16"
#define BUFF_SIZE 100

int		client_init(void);
void	client_connect(int socket_fd, struct sockaddr_in *server, char *address);
void	client_session(int socket_fd);

#endif
