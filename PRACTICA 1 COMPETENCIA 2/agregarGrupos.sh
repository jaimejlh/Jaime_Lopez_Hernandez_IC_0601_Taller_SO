#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Validez paa usuario root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   exit 1
fi

crearGrupo(){
	eval nombreGrupo="$1"
	
	echo ""
	echo "Intentando crear grupo ${nombreGrupo}...."

	groupadd "${nombreGrupo}"
	
	
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] agregado exitosamente"
		echo ""
	else
		echo "Fallo al crear el grupo [${nombreGrupo}]"
		echo ""
	fi
}

while IFS=: read -r f1
do
	crearGrupo "\${f1}"	
done < ${file}

exit 0
