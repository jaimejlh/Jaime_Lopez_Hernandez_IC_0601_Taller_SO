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
   echo "Debe indicar el archivo del listado con nombres de grupos a eliminar..."
   exit 1
fi

eliminarGrupo(){
	eval nombreGrupo="$1"
	
	echo ""
	echo "Intenando eliminar grupo ${nombreGrupo}"

	groupdel "${nombreGrupo}"
	
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] eliminado exitosamente"
		echo ""
	else
		echo "Fallo al elimnar el grupo [${nombreGrupo}]"
		echo ""
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}

exit 0
