#include <iostream>//biblotteca saida y entrada de datos
#include <string>//biblioteca para los datos
#include <limits>//para limites de datos 
#include <fstream>//para operaciones de archivos
#include <iostream>


using namespace std;

// Constantes
const int MAX_PACIENTES = 100000;
const int CAMPOS_PACIENTE = 8; // Numero de campos por p
string pacientes[MAX_PACIENTES][CAMPOS_PACIENTE];


// Declaraci�n de funciones
void IngresoPaciente();
void ModificarDatosPaciente();
void EliminarPaciente();
void ReporteGeneral();
void GenerarArchivoImpresion();
void LimpiarPantalla();
void EsperarTecla();

// Variables globales para almacenar los datos de los pacientes
string dpis[MAX_PACIENTES];
string nombres[MAX_PACIENTES];
int edades[MAX_PACIENTES];
string generos[MAX_PACIENTES];
string direcciones[MAX_PACIENTES];
string telefonos[MAX_PACIENTES];
string fechasIngreso[MAX_PACIENTES];
string diagnosticos[MAX_PACIENTES];
int cantidadPacientes = 0;

int main() {
	int opcion;
	
	// Ciclo para mostrar el men� hasta que se decida salir
	do {
		LimpiarPantalla();
		cout << "Bienvenidos al Hospital SJD" << endl;
		cout << "Men� de opciones:" << endl;
		cout << "1. Ingreso de Paciente" << endl;
		cout << "2. Modificaci�n de Datos del Paciente" << endl;
		cout << "3. Eliminar Paciente" << endl;
		cout << "4. Reporte General de Todos los Pacientes" << endl;
		cout << "5. Generar Archivo de Impresi�n" << endl;
		cout << "6. Salir" << endl;
		cout << "Seleccione una opci�n: ";
		cin >> opcion;
		
		// Validar la entrada
		if (cin.fail()) {
			cin.clear(); //LEEDE
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //IG
			opcion = -1; //AUVIPMLEDI
		}
		//Procesa la opci�n 
		switch (opcion) {
		case 1:
			IngresoPaciente();
			break;
		case 2:
			ModificarDatosPaciente();
			break;
		case 3:
			EliminarPaciente();
			break;
		case 4:
			ReporteGeneral();
			break;
		case 5:
			GenerarArchivoImpresion();
			break;
		case 6:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opci�n inv�lida, por favor seleccione una opci�n v�lida." << endl;
			EsperarTecla();
			break;
		}
	} while (opcion != 6); //REP
	
	return 0; //FinCor
}

// F
void IngresoPaciente() {
	if (cantidadPacientes >= MAX_PACIENTES) {
		cout << "No se pueden ingresar m�s pacientes." << endl;
		EsperarTecla();
		return;
	}
	
	string dpi, nombre, genero, direccion, telefono, fechaIngreso, diagnostico; //DDVPGIT
	int edad; //N
	
	// Ingreso del DPI y validaci�n de u
	do {
		cout << "Ingrese el DPI (N�mero de Identificaci�n): ";
		cin.ignore(); // Limpiar el buffer 
		getline(cin, dpi); //LDPI
	} while (dpi.empty());//RhDPIv
	
	// Validar que el DPI no se repita
	for (int i = 0; i < cantidadPacientes; i++) {//Ba1a
		if (dpis[i] == dpi) {
			cout << "El DPI ya est� registrado." << endl;
			EsperarTecla();
			return;
		}
	}
	
	// Ingreso de Nombre
	do {
		cout << "Ingrese el nombre completo: ";
		getline(cin, nombre);
	} while (nombre.empty());
	
	
	do {
		cout << "Ingrese la edad: ";
		cin >> edad;
	} while (edad <= 0);
	
	cin.ignore(); // Limpiar el buffer
	
	
	cout << "Ingrese el g�nero: ";
	getline(cin, genero);
	
	
	cout << "Ingrese la direcci�n: ";
	getline(cin, direccion);
	
	
	cout << "Ingrese el n�mero de tel�fono: ";
	getline(cin, telefono);
	
	
	cout << "Ingrese la fecha de ingreso: ";
	getline(cin, fechaIngreso);
	
	
	cout << "Ingrese el diagn�stico principal: ";
	getline(cin, diagnostico);
	
	// Guardar los datos del paciente en su esapcio corrspondiente 
	dpis[cantidadPacientes] = dpi;
	nombres[cantidadPacientes] = nombre;
	edades[cantidadPacientes] = edad;
	generos[cantidadPacientes] = genero;
	direcciones[cantidadPacientes] = direccion;
	telefonos[cantidadPacientes] = telefono;
	fechasIngreso[cantidadPacientes] = fechaIngreso;
	diagnosticos[cantidadPacientes] = diagnostico;
	cantidadPacientes++; //se asegura de utilizar la sigueinte posicion 
	
	cout << "Paciente ingresado con �xito." << endl;
	EsperarTecla();
}

// Funci�n para modificar los datos de un paciente
void ModificarDatosPaciente() {
	string dpi;
	int indice = -1; //VQAPEI hasta que se cambie el valor lo encuentra 
	
	// Solicitar DPI del paciente a modificar
	cout << "Ingrese el DPI del paciente que desea modificar: ";
	cin.ignore();
	getline(cin, dpi); //AQSLATE
	
	// Busca
	for (int i = 0; i < cantidadPacientes; i++) {//BHQ i=c
		if (dpis[i] == dpi) {
			indice = i;
			break;
		}
	}
	
	// Si el paciente no existe, mostrar mensaje y salir
	if (indice == -1) {//I-1
		cout << "Paciente no encontrado." << endl;
		EsperarTecla();
		return;
	}
	
	int opcionMod;
	bool continuar = true;
	
	// Bucle para modificar los campos seleccionados por el usuario
	while (continuar) {
		LimpiarPantalla();
		cout << "Modificaci�n de datos del paciente (DPI: " << dpis[indice] << ")" << endl;
		cout << "Seleccione el campo a modificar:" << endl;
		cout << "1. Nombre completo (Actual: " << nombres[indice] << ")" << endl;
		cout << "2. Edad (Actual: " << edades[indice] << ")" << endl;
		cout << "3. G�nero (Actual: " << generos[indice] << ")" << endl;
		cout << "4. Direcci�n (Actual: " << direcciones[indice] << ")" << endl;
		cout << "5. Tel�fono (Actual: " << telefonos[indice] << ")" << endl;
		cout << "6. Fecha de Ingreso (Actual: " << fechasIngreso[indice] << ")" << endl;
		cout << "7. Diagn�stico (Actual: " << diagnosticos[indice] << ")" << endl;
		cout << "8. Finalizar modificaci�n" << endl;
		cout << "Seleccione una opci�n: ";
		cin >> opcionMod;
		
		cin.ignore(); // Limpiar buffer de entrada
		
		switch (opcionMod) {
		case 1: {
			string nuevoNombre;
			do {
				cout << "Ingrese el nuevo nombre completo: ";
				getline(cin, nuevoNombre);
				if (nuevoNombre.empty()) {
					cout << "El nombre no puede estar vac�o." << endl;
				}
			} while (nuevoNombre.empty());
			nombres[indice] = nuevoNombre;
			break;
		}
		case 2: {
			int nuevaEdad;
			do {
				cout << "Ingrese la nueva edad: ";
				cin >> nuevaEdad;
				if (nuevaEdad <= 0) {
					cout << "La edad debe ser un n�mero positivo." << endl;
				}
			} while (nuevaEdad <= 0);
			edades[indice] = nuevaEdad;
			cin.ignore(); // Limpiar buffer de entrada
			break;
		}
		case 3: {
			string nuevoGenero;
			cout << "Ingrese el nuevo g�nero: ";
			getline(cin, nuevoGenero);
			generos[indice] = nuevoGenero;
			break;
		}
		case 4: {
			string nuevaDireccion;
			cout << "Ingrese la nueva direcci�n: ";
			getline(cin, nuevaDireccion);
			direcciones[indice] = nuevaDireccion;
			break;
		}
		case 5: {
			string nuevoTelefono;
			cout << "Ingrese el nuevo n�mero de tel�fono: ";
			getline(cin, nuevoTelefono);
			telefonos[indice] = nuevoTelefono;
			break;
		}
		case 6: {
			string nuevaFechaIngreso;
			cout << "Ingrese la nueva fecha de ingreso: ";
			getline(cin, nuevaFechaIngreso);
			fechasIngreso[indice] = nuevaFechaIngreso;
			break;
		}
		case 7: {
			string nuevoDiagnostico;
			cout << "Ingrese el nuevo diagn�stico: ";
			getline(cin, nuevoDiagnostico);
			diagnosticos[indice] = nuevoDiagnostico;
			break;
		}
		case 8:
			continuar = false;
			cout << "Modificaci�n finalizada." << endl;
			break;
		default:
			cout << "Opci�n inv�lida, por favor seleccione una opci�n v�lida." << endl;
			break;
		}
		EsperarTecla();
	}
}

// Funci�n PA ELIMIAR 
void EliminarPaciente() {
	string dpi;
	int indice = -1;
	
	cout << "Ingrese el DPI del paciente que desea eliminar: ";
	cin.ignore();
	getline(cin, dpi);
	
	// Buscar al paciente por su DPI
	for (int i = 0; i < cantidadPacientes; i++) {
		if (dpis[i] == dpi) {
			indice = i;
			break;
		}
	}
	
	// Si el paciente no existe, mostrar mensaje y salir
	if (indice == -1) {
		cout << "Paciente no encontrado." << endl;
		EsperarTecla();
		return;
	}
	
	// Eliminar paciente moviendo todos los pacientes hacia atr�s
	for (int i = indice; i < cantidadPacientes - 1; i++) {
		dpis[i] = dpis[i + 1];
		nombres[i] = nombres[i + 1];
		edades[i] = edades[i + 1];
		generos[i] = generos[i + 1];
		direcciones[i] = direcciones[i + 1];
		telefonos[i] = telefonos[i + 1];
		fechasIngreso[i] = fechasIngreso[i + 1];
		diagnosticos[i] = diagnosticos[i + 1];
	}
	cantidadPacientes--;
	cout << "Paciente eliminado con �xito." << endl;
	EsperarTecla();
}

// Funci�n para generar un reporte general
void ReporteGeneral() {
	if (cantidadPacientes == 0) {
		cout << "No hay pacientes registrados." << endl;
		EsperarTecla();
		return;
	}
	
	cout << "Reporte General de Pacientes:" << endl;
	for (int i = 0; i < cantidadPacientes; i++) {
		cout << "DPI: " << dpis[i] << endl;
		cout << "Nombre: " << nombres[i] << endl;
		cout << "Edad: " << edades[i] << endl;
		cout << "G�nero: " << generos[i] << endl;
		cout << "Direcci�n: " << direcciones[i] << endl;
		cout << "Tel�fono: " << telefonos[i] << endl;
		cout << "Fecha de Ingreso: " << fechasIngreso[i] << endl;
		cout << "Diagn�stico: " << diagnosticos[i] << endl;
		cout << "--------------------------" << endl;
	}
	EsperarTecla();
}


// Funci�n para limpiar la pantalla
void LimpiarPantalla() {

	system("cls");

	system("clear");

}

// Funci�n para esperar a que el usuario presione una tecla
void EsperarTecla() {
	cout << "Presione una tecla para continuar..." << endl;
	cin.ignore();
	cin.get();
}
void GenerarArchivoImpresion() {
	// Ruta donde se guardar� el archivo
	string rutaArchivo = "./Reporte_Pacientes.txt";
	
	// Crear y abrir el archivo 
ofstream archivo(rutaArchivo);
if (!archivo.is_open()) {//verifica
    cout << "Error al abrir el archivo." << endl;
    return;
}

	
	// Escribir la cabecera
	archivo << "Hospital Xumg" << endl;
	
	// Obtener la fecha actual
	
	// Escribir encabezados de columnas
    archivo << "|DPI|\t|Nombre|\t|Edad|\t|G�nero|\t|Direcci�n|\t|Tel�fono|\t|Fecha de Ingreso|\t|Diagn�stico|" << endl;
	archivo << "------------------------------------------------------------------------" << endl;
	
	// Escribir los datos de los pacientes
	for (int i = 0; i < cantidadPacientes; i++) {
		archivo << dpis[i] << "\t"
			<< nombres[i] << "\t"
			<< edades[i] << "\t"
			<< generos[i] << "\t"
			<< direcciones[i] << "\t"
			<< telefonos[i] << "\t"
			<< fechasIngreso[i] << "\t"
			<< diagnosticos[i] << endl;
	}
	
	// Cerrar el archivo
	archivo.close();
	
	cout << "Archivo de texto generado correctamente en: " << rutaArchivo << endl;
}
