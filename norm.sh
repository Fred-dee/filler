# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    norm.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 12:09:37 by mdilapi           #+#    #+#              #
#    Updated: 2018/08/01 12:09:39 by mdilapi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/sh
norminette -R CheckForbiddenSourceHeader ./includes/*.h
norminette -R CheckForbiddenSourceHeader ./src/*.c
