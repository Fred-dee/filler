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

#/bin/sh
cd ../ && make re && cd ./resources
./filler_vm -f ./maps/map00 -p1 ./players/mdilapi.filler -p2 ./players/abanlin.filler
