#!/bin/bash

# testing script programming and bash use
# general testing and commands to understand the bash running 
clear

echo "The script starts now."
echo "Hi, $USER!"

echo "Setting variables."
COLOUR="black"
VALUE="9"

echo "Colour value: $COLOUR"
echo "Number value: $VALUE"

echo "Making alias"

alias c='clear'
alias ls='ls -la'

echo "Testing opening a file with a script"
#leio o nome do file, atribui-o a uma variavel

NOME=$1
echo $NOME

# Remover files o
OUTPUText='.o'
OUTPUTNAME=$NOME$OUTPUText


if [  -e  "$OUTPUTNAME"  ]; then
	rm $OUTPUTNAME 
	rm a.out 
	echo "removed old files" 
fi

TEST="teste"
NOMEF=$NOME$TEST

# tenho de acrescentar o c ao nome

gcc -Wall $NOME

if [  $?  -eq  0  ]; then                   
	gcc  -o $NOMEF  $NOME 
	./$NOMEF $2 $3 
fi

