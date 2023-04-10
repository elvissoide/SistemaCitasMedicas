#include "medicos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int mostrarMenuMedicos() {
	int opcion;
	cout << "\n\t\t\t\t\t\t\t\t\t\t0. Salir" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t1. Mostrar todos los medicos registrados" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t2. Registrar medico" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t3. Buscar medico por numero de cedula" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t4. Modificar datos de un medico" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t5. Eliminar medico registrado" << endl;
	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\tIngrese una opción: ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 5);
	return opcion;
}

int mostrarMenuMedicosModificacion() {
	int opcion;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t0. Salir" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t1. Numero de cedula" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t2. Nombres" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t3. Apellidos" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t4. Especialidad" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t5. Ubicacion" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t6. Email" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t7. Celular" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t8. Edad" << endl;
	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tIngrese una opción: ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 8);
	return opcion;
}

void cargarListaMedicos(tListaMedicos& medicos) {
	ifstream archivo;
	tMedico doctor;
	archivo.open("medicos.txt");
	if (!archivo.is_open()){
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t=== NO SE CARGÓ LOS DATOS===\n" << endl;
	} else {
		archivo >> doctor.ci;
		while (doctor.ci != "XXX" && medicos.contador < MAXIMOMEDICOS) {
			archivo >> doctor.nombres;
			archivo >> doctor.apellidos;
			archivo.get();
			getline(archivo, doctor.especialidad);
			getline(archivo, doctor.ubicacion);
			archivo >> doctor.email;
			archivo >> doctor.celular;
			archivo >> doctor.edad;
			medicos.listaMedicos[medicos.contador] = doctor;
			medicos.contador++;
			archivo >> doctor.ci;
		}
		archivo.close();
	}
}

void imprimirListaMedicos(tListaMedicos& medicos) {
	imprimirBordeMedicos();
	cout << "\t| " << left << setw(17) << "Cédula";
	cout << "| " << left << setw(25) << "Nombres";
	cout << "| " << left << setw(20) << "Apellidos";
	cout << "| " << left << setw(25) << "Especialidad";
	cout << "| " << left << setw(42) << "Ubicación";
	cout << "| " << left << setw(25) << "Email";
	cout << "| " << left << setw(14) << "Celular";
	cout << "| " << left << setw(8) << "Edad" << "|" << endl;
	imprimirBordeMedicos();
	for (int i = 0; i < medicos.contador; i++) {
		cout << "\t| " << left << setw(16) << medicos.listaMedicos[i].ci;
		cout << "| " << left << setw(25) << medicos.listaMedicos[i].nombres;
		cout << "| " << left << setw(20) << medicos.listaMedicos[i].apellidos;
		cout << "| " << left << setw(25) << medicos.listaMedicos[i].especialidad;
		cout << "| " << left << setw(41) << medicos.listaMedicos[i].ubicacion;
		cout << "| " << left << setw(25) << medicos.listaMedicos[i].email;
		cout << "| " << left << setw(14) << medicos.listaMedicos[i].celular;
		cout << "| " << left << setw(8) << medicos.listaMedicos[i].edad << "|";
		cout << endl;
	}
	imprimirBordeMedicos();
}

void imprimirBordeMedicos() {
	cout << "\t--------------------------------------------------------------------------------";
	cout << "----------------------------------------------------------------------------------";
	cout << "-----------------------------" << endl;
}

void agregarMedico(tListaMedicos& medicos) {
	tMedico doctor;
	char aceptarRegistro;
	cout << "\n\tIngrese el número de cédula: ";
	cin >> doctor.ci;
	cout << "\n\tIngrese nombre: ";
	cin >> doctor.nombres;
	//getline(cin, doctor.nombres);
	cout << "\n\tIngrese apellido: ";
	cin >> doctor.apellidos;
	//getline(cin, doctor.apellidos);
	cout << "\n\tIngrese la especialidad: ";
	cin.ignore(80, '\n');
	getline(cin, doctor.especialidad);
	cout << "\n\tIngrese ubicación: ";
	getline(cin, doctor.ubicacion);
	cout << "\n\tIngrese email: ";
	cin >> doctor.email;
	cout << "\n\tIngrese celular: ";
	cin >> doctor.celular;
	cout << "\n\tIngrese edad: ";
	cin >> doctor.edad;
	imprimirMedico(doctor);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDesea registrar el médico? (Y/N): ";
	cin >> aceptarRegistro;
	aceptarRegistro = toupper(aceptarRegistro);
	system("cls");
	if (aceptarRegistro == 'Y') {
		medicos.listaMedicos[medicos.contador] = doctor;
		medicos.contador++;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === MÉDICO REGISTRADO ===\n" << endl;
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === MÉDICO NO REGISTRADO ===\n" << endl;
	}
}

void imprimirMedico(tMedico& doctor) {
	cout << "\n";
	imprimirBordeMedicos();
	cout << "\t| " << left << setw(17) << "Cédula";
	cout << "| " << left << setw(25) << "Nombres";
	cout << "| " << left << setw(20) << "Apellidos";
	cout << "| " << left << setw(25) << "Especialidad";
	cout << "| " << left << setw(42) << "Ubicación";
	cout << "| " << left << setw(25) << "Email";
	cout << "| " << left << setw(14) << "Celular";
	cout << "| " << left << setw(8) << "Edad" << "|" << endl;
	imprimirBordeMedicos();
	cout << "\t| " << left << setw(16) << doctor.ci;
	cout << "| " << left << setw(25) << doctor.nombres;
	cout << "| " << left << setw(20) << doctor.apellidos;
	cout << "| " << left << setw(25) << doctor.especialidad;
	cout << "| " << left << setw(41) << doctor.ubicacion;
	cout << "| " << left << setw(25) << doctor.email;
	cout << "| " << left << setw(14) << doctor.celular;
	cout << "| " << left << setw(8) << doctor.edad << "|";
	cout << endl;
	imprimirBordeMedicos();
}

void guardarInformacionMedicos(tListaMedicos& medicos) {
	ofstream archivo;
	archivo.open("medicos.txt");
	for (int i = 0; i < medicos.contador; i++) {
		archivo << medicos.listaMedicos[i].ci << endl;
		archivo << medicos.listaMedicos[i].nombres << endl;
		archivo << medicos.listaMedicos[i].apellidos << endl;
		archivo << medicos.listaMedicos[i].especialidad << endl;
		archivo << medicos.listaMedicos[i].ubicacion << endl;
		archivo << medicos.listaMedicos[i].email << endl;
		archivo << medicos.listaMedicos[i].celular << endl;
		archivo << medicos.listaMedicos[i].edad << endl;
	}
	archivo << "XXX" << endl;
	archivo.close();
}

void buscarMedico(tListaMedicos& medicos, int& posicionCIMedico) {
	string cedula;
	bool encontrado = false;
	tMedico doctor;
	cout << "\n\tIngrese el número de cédula: ";
	cin >> cedula;
	system("cls");
	for (int i = 0; i < medicos.contador; i++){
		if (medicos.listaMedicos[i].ci == cedula) {
			encontrado = true;
			posicionCIMedico = i;
		}
	}
	if (encontrado){
		doctor = medicos.listaMedicos[posicionCIMedico];
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === MÉDICO ENCONTRADO ===\n" << endl;
		imprimirMedico(doctor);
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === MÉDICO NO ENCONTRADO ===\n" << endl;
	}
}

void modificarMedico(tListaMedicos& medicos, int& posicionCIMedico) {
	int opcion;
	do{
		opcion = mostrarMenuMedicosModificacion();
		switch (opcion){
		case 1:
			cout << "\n\tIngrese el número de cédula: ";
			cin >> medicos.listaMedicos[posicionCIMedico].ci;
			break;
		case 2:
			cout << "\n\tIngrese nombre: ";
			//cin.ignore(80, '\n');
			//getline(cin, medicos.listaMedicos[posicionCIMedico].nombres);
			cin >> medicos.listaMedicos[posicionCIMedico].nombres;
			break;
		case 3:
			cout << "\n\tIngrese apellido: ";
			//cin.ignore(80, '\n');
			//getline(cin, medicos.listaMedicos[posicionCIMedico].apellidos);
			cin >> medicos.listaMedicos[posicionCIMedico].apellidos;
			break;
		case 4:
			cout << "\n\tIngrese especialidad: ";
			cin.ignore(80, '\n');
			getline(cin, medicos.listaMedicos[posicionCIMedico].especialidad);
			break;
		case 5:
			cout << "\n\tIngrese ubicacion: ";
			cin.ignore(80, '\n');
			getline(cin, medicos.listaMedicos[posicionCIMedico].ubicacion);
			break;
		case 6:
			cout << "\n\tIngrese email: ";
			cin >> medicos.listaMedicos[posicionCIMedico].email;
			break;
		case 7:
			cout << "\n\tIngrese celular: ";
			cin >> medicos.listaMedicos[posicionCIMedico].celular;
			break;
		case 8:
			cout << "\n\tIngrese edad: ";
			cin >> medicos.listaMedicos[posicionCIMedico].edad;
			break;
		}
		system("cls");
		imprimirMedico(medicos.listaMedicos[posicionCIMedico]);
	} while (opcion != 0);
	system("cls");
}

void eliminarMedico(tListaMedicos& medicos, int& posicionCIMedico) {
	char eliminar;
	cout << "\n\n\t\t\t\t\t\t\t\t\tDesea eliminar el registro del médico mostrado? (y/n): ";
	cin >> eliminar;
	eliminar = tolower(eliminar);
	system("cls");
	if (eliminar == 'y') {
		for (int i = posicionCIMedico; i < medicos.contador; i++) {
			medicos.listaMedicos[i] = medicos.listaMedicos[i + 1];
		}
		medicos.contador--;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === MÉDICO ELIMINADO ===\n" << endl;
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === MÉDICO NO ELIMINADO ===\n" << endl;
	}
}

/*
void listarPorEspecialidad(tListaMedicos& medicos) {
	tListaMedicos listaAuxiliar;
	listaAuxiliar.contador = 0;
	string especialidad;
	cout << "Ingrese la especialidad: ";
	cin >> especialidad;
	for (int i = 0; i < medicos.contador; i++){
		if (medicos.listaMedicos[i].especialidad == especialidad) {
			listaAuxiliar.listaMedicos[listaAuxiliar.contador] = medicos.listaMedicos[i];
			listaAuxiliar.contador++;
		}
	}

}
*/