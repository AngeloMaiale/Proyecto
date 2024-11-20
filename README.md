# ProyectoParte1

Esta primera parte del proyecto consiste en desarrollar un programa que le de la opción al usuario de poder modificar ciertos archivos csv que en este caso se clasifican por Vehciulos, Clientes y Repuestos. Las opciones que presenta este programa al ejecutarlo son las siguientes:
1.Borrar lineas de un archivo.
2.Modificar o Actualizar una linea (tanto completamente como parcialmente).
3.Insertar una linea nueva con datos nuevos.
4.Hacer consultas sobre que datos corresponden a cada Vehiculo, Cliente o Repuesto.
Y a parte de eso el programa funciona de manera continua, por lo que este solo se cierra o termina cuando el usuario lo indique, con la posibilidad de volver a viertas opciones, y de confirmar o no los cambios a realizar (borrando el archivo original por uno nuevo con los cambios). Los commits mas relevantes fueron los siguientes:

Nov 9, 2024
feat: Datos para el programa
Autor: AngeloMaiale
Descripción: primero se crearon 3 archivos csv con datos aleatorios para poder realizar las pruebas pertinentes

Nov 14, 2024
feat: Estructuras y primer switch de los archivos (Corrupto)
Autor: NicoleBs554
Descripción: se crearon las estructuras de los datos a guardar de cada archivo junto con las funciones de leerlos mediante un ciclo while y la base de los switchs para darle un cuerpo al programa. Desgracidamente este commit al luego de subirlo se corrompió con dos carpetas 

Nov 15, 2024
feat: funciones de borrado, insercion y actualizacion (Eliminado)
Autor: AngeloMaiale
Descripcion: en este commit se agregaron las funciones de borrar, insertar y modificar (completamente mas no parcialmente) lineas de cada archivo, estas funciones comparan datos dados por el usuario mismo, y segun el archivo se ejecuta una funcion diferente (a excepcion de la de borrado), y se amplio aun mas la estructura de los switches. Lamentablemente este commit fue borrado accidentalmente en un intento de organizar mejor el repositorio remoto, pero aun permanece en los repositorios locales

Nov 17, 2024
feat: funciones de escritura y muestra
Autor: NicoleBs554
Descripcion: un prototipo de las funciones de escritura y muestreo, pero que requería mejoras 

Nov 19, 2024
feat: funcion para actualizar una columna en una fila especifica y mejora en el sistema que mantiene al usuario en el programa hasta que este lo desee
Autor: AngeloMaiale
Descripción: funcion de actualizar parcialmente las lineas de un archivo csv agregada, funcion de consulta de datos incluida de mejor manera en las opciones del programa y un sistema ciclico de que mantiene al usuario dentro del programa y que este le pregunte si quiere confirmar o no los cambios.