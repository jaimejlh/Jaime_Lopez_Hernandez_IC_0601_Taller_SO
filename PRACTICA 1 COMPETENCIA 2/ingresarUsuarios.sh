#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course.
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi 

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con nombres de usuarios a eliminar..."
   exit 1
fi

main(){
csv=agregar_usuarios.csv
while read linea ;
do
	user=$(echo "$linea" | cut -d ":" -f1)
	contra=$(echo "$linea" | cut -d ":" -f2)
	idu=$(echo "$linea" | cut -d ":" -f3)
	idg=$(echo "$linea" | cut -d ":" -f4) 
	coment=$(echo "$linea" | cut -d ":" -f5)
	rutaD=$(echo "$linea" | cut -d ":" -f6)
	rutaC=$(echo "$linea" | cut -d ":" -f7)
	
	echo ""
	echo "Intentando crear usuario ${user}..."
	if grep -q $user /etc/passwd ;
		then
			
			echo "El ${user} YA se encuentra en el sistema ¡Imposible agregar!"
			echo ""
		else
			
			echo "El ${user} aun NO se encuentra en el sistema"
				if grep -q ${idg} /etc/group ;
				then
					echo "El grupo ${idg} para ${user} se encuentra existente"
					echo "Directorio principal: ${rutaD}"
					echo "Comand Shell: ${rutaC}"
					useradd -p ${contra} -u ${idu} -g ${idg} -c ${coment} -d ${rutaD} -s ${rutaC} ${user}
					echo "$user:$contra" | chpasswd --md5
					chage -d0 "${user}"
					echo "¡El usuario ${user} ha sido creado exitosamente!"
					echo ""
				else
					echo "El grupo ${idg} no existe en el sistema ¡Imposible agregar ${user}!" 
					echo ""
				fi
		fi
done < ${csv}
}

main #"\${f1}"
