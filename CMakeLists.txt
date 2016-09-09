PROJECT(ProyectoSO)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_INSTALL_PREFIX "")

ADD_SUBDIRECTORY(src) #Compilar componentes.
ADD_SUBDIRECTORY(root) #Copiar archivos de grub e include 
ADD_SUBDIRECTORY(iso) #Crear script para crear ISO
MESSAGE("make DESTDIR=proyectoSO install")
MESSAGE("./iso.sh")
