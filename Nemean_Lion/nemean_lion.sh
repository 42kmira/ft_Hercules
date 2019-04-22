# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nemean_lion.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 16:12:59 by kmira             #+#    #+#              #
#    Updated: 2019/03/01 22:46:50 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash 

if [[ $EUID -ne 0 ]]; then
	exit 1
fi

PORT_NUM="57485"

apt-get install -y openssh-server
sed -i 's/#Port 22/Port $PORT_NUM' /etc/ssh/sshd_config
systemctl restart ssh.service
