# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 13:54:07 by mdilapi           #+#    #+#              #
#    Updated: 2018/06/12 13:54:08 by mdilapi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
if [ "$1" == "make" ]
then
	cd ../ && make re && cd ./resources
fi
if [ "$2" == "p1" ] || [ "$1" == "p1" ]
then
	./filler_vm -f ./maps/map01 -p1 ./players/mdilapi.filler -p2 ./players/superjeannot.filler
fi
if [ "$2" == "p2" ] || [ "$1" == "p2" ]
then
	./filler_vm -f ./maps/map01 -p1 ./players/superjeannot.filler -p2 ./players/mdilapi.filler
fi


