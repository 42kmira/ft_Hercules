/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:44:17 by kmira             #+#    #+#             */
/*   Updated: 2019/03/09 13:05:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HYDRA_SERVER_H
# define HYDRA_SERVER_H

/*
** <unistd.h>		-> write(2), read(2), sleep(3), close(2), fork(2), setsid(2)
** <sys/socket.h>	-> socket(2), listen(2), accept(2), bind(2)
** <stdlib.h>		-> exit(3)
** <arpa/inet.h>	-> struct sockaddr_in, htons(3), htonl(3), inet_addr(3)
** <string.h>		-> strncmp(3)
** <stdio.h>		-> printf(3), dprintf(3)
*/

# include <unistd.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdio.h>

# define STDOUT 1
# define PORT_NUM 6456
# define BACKLOG 5
# define BUFF_SIZE 20

int		hydra_socket_init(void);
void	hydra_socket_bind(int socket_fd, struct sockaddr_in *server_address);
void	hydra_listen(int socket_fd);
int		hydra_accept(int socket_fd, struct sockaddr_in *client);
void	hydra_handshake(int client_fd);

void	hydra_message(int client_cd);

int		run_as_daemon(char *flag);
void	hydra_daemon_init(void);

#endif
