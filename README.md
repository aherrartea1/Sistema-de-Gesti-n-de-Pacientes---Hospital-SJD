Sistema de Gestión de Pacientes - Hospital SJD

Sistema de consola interactivo desarrollado en C++ para la gestión básica y control de pacientes del Hospital SJD. El programa implementa operaciones CRUD (Crear, Leer, Actualizar, Eliminar) utilizando arreglos dinámicos y persistencia de reportes en archivos de texto.

📌 Funcionalidades

📥 Registrar Pacientes: Ingreso de datos personales con verificación automática para evitar DPIs duplicados.

📝 Modificación Interactiva: Actualización específica por campos (Nombre, Edad, Teléfono, Diagnóstico, etc.).

🗑️ Eliminar Registros: Reorganización interna de los datos al remover a un paciente de la base activa.

📊 Reporte en Pantalla: Despliegue completo de la lista de pacientes registrados.

📄 Exportación a Fichero: Generación de un reporte estructurado en formato .txt listo para imprimir o guardar.

🛠️ Tecnologías

Lenguaje: C++

Bibliotecas Estándar: <iostream>, <string>, <fstream>, <limits>

Compatibilidad: Windows, macOS, Linux

🚀 Instalación y Ejecución

Requisitos previos

Tener instalado un compilador de C++ como g++, clang++ o un entorno como Visual Studio Code / Dev-C++.

Pasos

Clonar el repositorio:

git clone https://github.com/tu-usuario/hospital-sjd.git
cd hospital-sjd


Compilar el archivo C++:

g++ "proyecto de progra.cpp" -o HospitalSJD


Ejecutar el programa:

Windows:

HospitalSJD.exe


Linux / macOS:

./HospitalSJD


🖥️ Vista Previa del Sistema terminal

Bienvenidos al Hospital SJD
Menú de opciones:
1. Ingreso de Paciente
2. Modificación de Datos del Paciente
3. Eliminar Paciente
4. Reporte General de Todos los Pacientes
5. Generar Archivo de Impresión
6. Salir
Seleccione una opción:


📁 Archivos Generados

Al ejecutar la Opción 5, se creará un archivo llamado Reporte_Pacientes.txt con la siguiente estructura tabulada:

Hospital Xumg
|DPI|	|Nombre|	|Edad|	|Género|	|Dirección|	|Teléfono|	|Fecha de Ingreso|	|Diagnóstico|
------------------------------------------------------------------------
3012456780101	Carlos Pérez	45	Masculino	Zona 1	55551234	12/10/2026
