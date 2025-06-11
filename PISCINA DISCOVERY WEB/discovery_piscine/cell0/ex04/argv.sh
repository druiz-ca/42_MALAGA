#! /bin/bash
# Condición SI no hay (-z) argumentos ("$1")
if [ -z "$1" ]
then
	# imprime la cadena siguiente
	echo "No has proporcionado ningún argumento";
fi
# Condición SI hay (-n) argumentos ("$1")
if [ -n "$1" ]
then
	# imprime el argumento dado ($1)
	echo $1
fi
if [ -n "$2" ]
then
	echo $2
fi
if [ -n "$3" ]
then
	echo $3
fi
