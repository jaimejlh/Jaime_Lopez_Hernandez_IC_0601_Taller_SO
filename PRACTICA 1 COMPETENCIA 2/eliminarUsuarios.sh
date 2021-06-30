#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a eliminar..."
   exit 1
fi

csv=agregar_usuarios.csv
	
while read linea;
do
	user=$(echo $linea | cut -d":" -f1)
	
	echo ""
	echo "Intentando eliminar usuario ${user}..."
		
	userdel "${user}"
		
	if [ $? -eq $SUCCESS ];
	then
		echo "Usuario ${user} eliminado exitosamente"
		echo ""
	else
		echo "Fallo al eliminar el usuario ${user}"
		echo ""
	fi
done < ${csv}
