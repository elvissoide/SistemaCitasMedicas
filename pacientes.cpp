#include "pacientes.h"
#include <fstream>
#include <iostream>
#include <iomanip>
//#include <cctype>
using namespace std;

int mostrarMenuPacientes() {
	int opcion;
	cout << "\n\t\t\t\t\t\t\t\t\t\t0. Salir" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t1. Mostrar todos los pacientes registrados." << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t2. Registrar paciente." << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t3. Buscar paciente por número de cédula" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t4. Modificar datos de un paciente" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t5. Eliminar paciente registrado" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t6. Ordenar por orden alfabético por nombres" << endl;
	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\tIngrese una opción: ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 6);
	return opcion;
}

int mostrarMenuPacienteModificacion() {
	int opcion;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t0. Salir" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t1. Cédula" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t2. Nombres" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t3. Apellidos" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t4. Sexo" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t5. Ubicación" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t6. Tipo de sangre" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t7. Email" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t8. Edad" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t9. Peso" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t10. Altura" << endl;
	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tIngrese una opción: ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 10);
	return opcion;
}

void cargarListaPacientes(tListaPacientes& pacientes) {
	ifstream archivo;
	tPaciente persona;
	archivo.open("pacientes.txt");
	if (!archivo.is_open()){
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t=== NO SE CARGÓ LOS DATOS===\n" << endl;
	} else {
		archivo >> persona.ci;
		while (persona.ci != "XXX" && pacientes.contador < MAXIMOPACIENTES) {
			//archivo.get();
			//getline(archivo, persona.nombres);
			archivo >> persona.nombres;
			//getline(archivo, persona.apellidos);
			archivo >> persona.apellidos;
			archivo >> persona.sexo;
			archivo.get();
			getline(archivo, persona.ubicacion);
			archivo >> persona.tipoSangre;
			archivo >> persona.email;
			archivo >> persona.edad;
			archivo >> persona.peso;
			archivo >> persona.altura;
			pacientes.listaPacientes[pacientes.contador] = persona;
			pacientes.contador++;
			archivo >> persona.ci;
		}
		archivo.close();
	}
}

void imprimirListaPacientes(tListaPacientes& pacientes) {
	imprimirBordePaciente();
	cout << "\t| " << left << setw(16) << "Cédula";
	cout << "| " << left << setw(25) << "Nombres";
	cout << "| " << left << setw(20) << "Apellidos";
	cout << "| " << left << setw(5) << "Sexo";
	cout << "| " << left << setw(41) << "Ubicación";
	cout << "| " << left << setw(17) << "Tipo de Sangre";
	cout << "| " << left << setw(25) << "Email";
	cout << "| " << left << setw(6) << "Edad";
	cout << "| " << left << setw(6) << "Peso";
	cout << "| " << left << setw(8) << "Altura" << "|" << endl;
	imprimirBordePaciente();
	for (int i = 0; i < pacientes.contador; i++){
		cout << "\t| " << left << setw(15) << pacientes.listaPacientes[i].ci;
		cout << "| " << left << setw(25) << pacientes.listaPacientes[i].nombres;
		cout << "| " << left << setw(20) << pacientes.listaPacientes[i].apellidos;
		cout << "| " << left << setw(5) << pacientes.listaPacientes[i].sexo;
		cout << "| " << left << setw(40) << pacientes.listaPacientes[i].ubicacion;
		cout << "| " << left << setw(17) << pacientes.listaPacientes[i].tipoSangre;
		cout << "| " << left << setw(25) << pacientes.listaPacientes[i].email;
		cout << "| " << left << setw(6) << pacientes.listaPacientes[i].edad;
		cout << "| " << left << setw(6) << pacientes.listaPacientes[i].peso;
		cout << "| " << left << setw(8) << pacientes.listaPacientes[i].altura << "|";
		cout << endl;
	}
	imprimirBordePaciente();
}

void imprimirBordePaciente() {
	cout << "\t--------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------";
	cout << "--------------------------" << endl;
}

void agregarPaciente(tListaPacientes& pacientes) {
	tPaciente persona;
	char aceptarRegistro;
	cout << "\n\tIngrese el numero de cedula del paciente: ";
	cin >> persona.ci;
	cout << "\n\tIngrese el nombre del paciente: ";
	//cin.ignore(80, '\n');
	//getline(cin, persona.nombres);
	cin >> persona.nombres;
	cout << "\n\tIngrese el apellido del paciente: ";
	//getline(cin, persona.apellidos);
	cin >> persona.apellidos;
	cout << "\n\tIngrese el sexo del paciente (M/F): ";	
	cin >> persona.sexo;
	persona.sexo = toupper(persona.sexo);
	cout << "\n\tIngrese dirección de domicilio: ";
	cin.ignore(80, '\n');
	getline(cin, persona.ubicacion);
	cout << "\n\tIngrese tipo de sangre: ";
	cin >> persona.tipoSangre;
	//persona.tipoSangre = toupper(persona.tipoSangre);
	cout << "\n\tIngrese el email: ";
	cin >> persona.email;
	cout << "\n\tIngrese la edad: ";
	cin >> persona.edad;
	cout << "\n\tIngrese el peso (en kilogramos, usar punto): ";
	cin >> persona.peso;
	cout << "\n\tIngrese la altura (en metros, usar punto): ";
	cin >> persona.altura;
	imprimirPaciente(persona);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDesea registrar el paciente? (Y/N): ";
	cin >> aceptarRegistro;
	aceptarRegistro = toupper(aceptarRegistro);
	system("cls");
	if (aceptarRegistro == 'Y') {
		pacientes.listaPacientes[pacientes.contador] = persona;
		pacientes.contador++;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE REGISTRADO ===\n" << endl;
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE NO REGISTRADO ===\n" << endl;
	}
}

void imprimirPaciente(tPaciente& persona) {
	cout << "\n";
	imprimirBordePaciente();
	cout << "\t| " << left << setw(16) << "Cédula";
	cout << "| " << left << setw(25) << "Nombres";
	cout << "| " << left << setw(20) << "Apellidos";
	cout << "| " << left << setw(5) << "Sexo";
	cout << "| " << left << setw(41) << "Ubicación";
	cout << "| " << left << setw(17) << "Tipo de Sangre";
	cout << "| " << left << setw(25) << "Email";
	cout << "| " << left << setw(6) << "Edad";
	cout << "| " << left << setw(6) << "Peso";
	cout << "| " << left << setw(8) << "Altura" << "|" << endl;
	imprimirBordePaciente();
	cout << "\t| " << left << setw(15) << persona.ci;
	cout << "| " << left << setw(25) << persona.nombres;
	cout << "| " << left << setw(20) << persona.apellidos;
	cout << "| " << left << setw(5) << persona.sexo;
	cout << "| " << left << setw(40) << persona.ubicacion;
	cout << "| " << left << setw(17) << persona.tipoSangre;
	cout << "| " << left << setw(25) << persona.email;
	cout << "| " << left << setw(6) << persona.edad;
	cout << "| " << left << setw(6) << persona.peso;
	cout << "| " << left << setw(8) << persona.altura << "|";
	cout << endl;
	imprimirBordePaciente();
}

void guardarInformacionPacientes(tListaPacientes& pacientes) {
	ofstream archivo;
	archivo.open("pacientes.txt");
	for (int i = 0; i < pacientes.contador; i++){
		archivo << pacientes.listaPacientes[i].ci << endl;
		archivo << pacientes.listaPacientes[i].nombres << endl;
		archivo << pacientes.listaPacientes[i].apellidos << endl;
		archivo << pacientes.listaPacientes[i].sexo << endl;
		archivo << pacientes.listaPacientes[i].ubicacion << endl;
		archivo << pacientes.listaPacientes[i].tipoSangre << endl;
		archivo << pacientes.listaPacientes[i].email << endl;
		archivo << pacientes.listaPacientes[i].edad << endl;
		archivo << pacientes.listaPacientes[i].peso << endl;
		archivo << pacientes.listaPacientes[i].altura << endl;
	}
	archivo << "XXX" << endl;
	archivo.close();
}

void buscarPaciente(tListaPacientes& pacientes, int& posicionCIPaciente) {
	//system("cls");
	string cedula;
	bool encontrado = false;
	tPaciente persona;
	cout << "\n\tIngrese el número de cédula del paciente: ";
	cin >> cedula;
	system("cls");
	for (int i = 0; i < pacientes.contador; i++){
		if (pacientes.listaPacientes[i].ci == cedula) {
			encontrado = true;
			posicionCIPaciente = i;
		}
	}
	if (encontrado){
		persona = pacientes.listaPacientes[posicionCIPaciente];
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE ENCONTRADO ===\n" << endl;
		imprimirPaciente(persona);
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE NO ENCONTRADO ===\n" << endl;
	}
}


void modificarPaciente(tListaPacientes& pacientes, int& posicionCIPaciente) {
	int opcion;
	do{
		opcion = mostrarMenuPacienteModificacion();
		switch (opcion){
		case 1:
			cout << "\n\tIngrese el numero de cedula del paciente: ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].ci;
			break;
		case 2:
			cout << "\n\tIngrese nombre del paciente: ";
			//cin.ignore(80, '\n');
			//getline(cin, pacientes.listaPacientes[posicionCIPaciente].nombres);
			cin >> pacientes.listaPacientes[posicionCIPaciente].nombres;
			break;
		case 3:
			cout << "\n\tIngrese apellido del paciente: ";
			//cin.ignore(80, '\n');
			//getline(cin, pacientes.listaPacientes[posicionCIPaciente].apellidos);
			cin >> pacientes.listaPacientes[posicionCIPaciente].apellidos;
			break;
		case 4:
			cout << "\n\tIngrese el sexo del paciente (M/F): ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].sexo;
			pacientes.listaPacientes[posicionCIPaciente].sexo = toupper(pacientes.listaPacientes[posicionCIPaciente].sexo);
			break;
		case 5:
			cout << "\n\tIngrese dirección de domicilio: ";
			cin.ignore(80, '\n');
			getline(cin, pacientes.listaPacientes[posicionCIPaciente].ubicacion);
			break;
		case 6:
			cout << "\n\tIngrese tipo de sangre: ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].tipoSangre;
			break;
		case 7:
			cout << "\n\tIngrese el email: ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].email;
			break;
		case 8:
			cout << "\n\tIngrese la edad: ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].edad;
			break;
		case 9:
			cout << "\n\tIngrese el peso (en kilogramos, usar punto): ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].peso;
			break;
		case 10:
			cout << "\n\tIngrese la altura (en metros, usar punto): ";
			cin >> pacientes.listaPacientes[posicionCIPaciente].altura;
			break;
		}
		system("cls");
		imprimirPaciente(pacientes.listaPacientes[posicionCIPaciente]);
	} while (opcion != 0);
	system("cls");
}

void eliminarPaciente(tListaPacientes& pacientes, int& posicionCIPaciente) {
	char eliminar;
	cout << "\n\n\t\t\t\t\t\t\t\t\tDesea eliminar el registro del paciente mostrado? (y/n): ";
	cin >> eliminar;
	eliminar = tolower(eliminar);
	system("cls");
	if (eliminar == 'y') {
		for (int i = posicionCIPaciente; i < pacientes.contador; i++){
			pacientes.listaPacientes[i] = pacientes.listaPacientes[i + 1];
		}
		pacientes.contador--;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE ELIMINADO ===\n" << endl;
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE NO ELIMINADO ===\n" << endl;
	}
}

void ordenarPaciente(tListaPacientes& pacientes) {
	int contador = 0;
	tPaciente persona;
	do{
		for (int i = 0; i < pacientes.contador - 1; i++) {
			if (pacientes.listaPacientes[i].nombres[i] > pacientes.listaPacientes[i].nombres[i+1]) {
				contador++;
				persona = pacientes.listaPacientes[i];
				pacientes.listaPacientes[i] = pacientes.listaPacientes[i + 1];
				pacientes.listaPacientes[i + 1] = persona;
			} else {
				contador = 0;
			}
		}
	} while (contador != 0);
}