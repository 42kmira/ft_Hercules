# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Hercules.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 15:55:56 by kmira             #+#    #+#              #
#    Updated: 2019/04/22 12:28:21 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME="manger"

./${NAME} &

sleep 10

# if you run the command "hexdump -C manger", you can see that
# manger has the pre-defined names.
# also nm -j manger can get you the names

pkill -1 podargos ruins lampon xanthos yes crap -bash
echo "Steeds have been killed."
# kill -s KILL $(top -l 1 | grep ${NAME} | awk '{print "-" $1}' | xargs)
# kill -s -9
# That would also kill the process. Also sending some other signals like interupt
# This will end the processes that the user has. Like a soft-reboot
# killall -KILL -u $USER
pkill -KILL ${NAME}
echo "Manger has been killed."


echo "Cleaning the crap."
rm -Rf *.poo

echo "\033[1;32m""[DONE]"
