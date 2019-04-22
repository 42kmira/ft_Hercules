# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    backup.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 13:00:10 by kmira             #+#    #+#              #
#    Updated: 2019/04/21 13:14:03 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

kill -s KILL $(pgrep crap lampon ruins xanthos yes)
kill -s KILL $(top -l 1 | grep manger | awk '{print $1}')
pkill -1 podargos ruins lampon xanthos yes crap -bash eurystheus

rm -rf *.poo
rm -rf *.dummy
