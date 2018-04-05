# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    analyser.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 18:08:32 by aroulin           #+#    #+#              #
#    Updated: 2017/07/26 18:28:17 by aroulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

##
##		Need to have ./checker and ./push_swap
##
##		first request is the range of number with the smallest and biggest
##
##		second request is total loops that the program will perfom
##
##		third request is for know how many loops are above and below




echo "--- [ ANALYSING PUSH_SWAP] ---";

read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
read -p "How many loop : " TRY
read -p "Mediane for test : " MED
NBR=$(($NBRTOP - $NBRBOT))
NBR=$(( $NBR + 1 ));
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

printf "[ NBR == $NBR && TRY == $TRY && MED == $MED ]\n"

echo "Analyse in progress ...\n\n";
while [ $IND -gt 0 ];
do
	ARG=`ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')"`
	NBRCOUP=$(./push_swap $ARG | wc -l);
	TEST=$(./push_swap $ARG | ./checker $ARG);
	if [ $TEST = "OK" ]
	then
		printf "\033[0;32m▓\033[0;0m"
		WELL=$(( $WELL + 1 ));
	else
		printf "\033[0;31m▓\033[0;0m"
	fi;

	if [ $MAX -lt $NBRCOUP ]
	then 
		MAX=$NBRCOUP; 
		ACTMAX=$ARG; 
	fi;
	if [ $MIN -eq "-1" ];
	then 
		MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	if [ $NBRCOUP -lt $MIN ]
	then MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	MOY=$(( $MOY + $NBRCOUP ));
	IND=$(( $IND - 1 ));
	if [ $NBRCOUP -gt $MED ]
	then 
		MORE=$(( $MORE + 1 ));
	else
		LESS=$(( $LESS + 1 ));
	fi;
done;
MOY=$(( $MOY / $TRY ));
echo "\nThere is $WELL/$TRY correct answer"
echo "There is $MORE more than $MED"
echo "There is $LESS less than $MED"
echo "The biggest  is :\t$MAX"
echo "The average is :\t$MOY"
echo "The smallest is :\t$MIN"
echo "The worst list :\t$ACTMAX"
echo "The best list :\t\t$ACTMIN"
