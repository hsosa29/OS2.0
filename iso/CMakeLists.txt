PROJECT(ProyectoSO-iso)

MESSAGE(STATUS "Generando ISO")
FILE(WRITE iso.sh "#!/bin/bash\n grub-mkrescue --compress=xz --product-name=ProyectoSO --product-version=2.0 -o ProyectoSO.iso proyectoSO")
INSTALL(PROGRAMS iso.sh DESTINATION ..)
