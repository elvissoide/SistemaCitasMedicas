#include "citas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int mostrarMenuCitas() {
	int opcion;
	cout << "\n\t\t\t\t\t\t\t\t\t\t0. Salir" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t1. Mostrar todas las citas registradas" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t2. Registrar cita" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t3. Cambiar hora de la cita" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t4. Cambiar fecha de la cita" << endl;
	do{
		cout << "\n\t\t\t\t\t\t\t\t\t\tIngresar una opcion: ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 4);
	return opcion;
}

void cargarListaCitas(tListaCitas& citas) {
	ifstream archivo;
	tCita citacion;
	archivo.open("citas.txt");
	if (!archivo.is_open()){
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t=== NO SE CARGÓ LOS DATOS===\n" << endl;
	} else {
		archivo >> citacion.ci;
		while (citacion.ci != "XXX" && citas.contador < MAXIMOCITAS) {
			archivo >> citacion.nombrePaciente[0];
			archivo >> citacion.nombrePaciente[1];
			archivo >> citacion.nombreDoctor[0];
			archivo >> citacion.nombreDoctor[1];
			archivo.get();
			getline(archivo, citacion.especialidad);
			archivo >> citacion.fecha[0];
			archivo >> citacion.fecha[1];
			archivo >> citacion.fecha[2];
			archivo >> citacion.hora[0];
			archivo >> citacion.hora[1];
			citas.listaCitas[citas.contador] = citacion;
			citas.contador++;
			archivo >> citacion.ci;
		}
		archivo.close();
	}
}

void imprimirListaCitas(tListaCitas& citas) {
	string concatenado;
	imprimirBordeCitas();
	cout << "\t\t\t\t\t\t| " << left << setw(14) << "Cédula";
	cout << "| " << left << setw(25) << "Nombre del paciente";
	cout << "| " << left << setw(25) << "Especialista";
	cout << "| " << left << setw(26) << "Área de especialidad";
	cout << "| " << left << setw(10) << "Fecha";
	cout << "| " << left << setw(7) << "Hora" << "|" << endl;
	imprimirBordeCitas();
	for (int i = 0; i < citas.contador; i++){
		cout << "\t\t\t\t\t\t| " << left << setw(13) << citas.listaCitas[i].ci;
		concatenado = citas.listaCitas[i].nombrePaciente[0] + " " + citas.listaCitas[i].nombrePaciente[1];
		cout << "| " << left << setw(25) << concatenado;
		concatenado = citas.listaCitas[i].nombreDoctor[0] + " " + citas.listaCitas[i].nombreDoctor[1];
		cout << "| " << left << setw(25) << concatenado;
		cout << "| " << left << setw(25) << citas.listaCitas[i].especialidad;
		concatenado = to_string(citas.listaCitas[i].fecha[0]) + '/' + to_string(citas.listaCitas[i].fecha[1]) + '/' + to_string(citas.listaCitas[i].fecha[2]);
		cout << "| " << left << setw(10) << concatenado;
		concatenado = to_string(citas.listaCitas[i].hora[0]) + 'h' + to_string(citas.listaCitas[i].hora[1]);
		cout << "| " << left << setw(7) << concatenado << "|";
		cout << endl;
	}
	imprimirBordeCitas();
}

void imprimirBordeCitas() {
	cout << "\t\t\t\t\t\t------------------------------------------------------------";
	cout << "----------------------------------------------------------" << endl;
}

void imprimirCita(tCita& citacion) {
	string concatenado;
	imprimirBordeCitas();
	cout << "\t\t\t\t\t\t| " << left << setw(13) << "Cédula";
	cout << "| " << left << setw(25) << "Nombre del paciente";
	cout << "| " << left << setw(25) << "Especialista";
	cout << "| " << left << setw(26) << "Área de especialidad";
	cout << "| " << left << setw(10) << "Fecha";
	cout << "| " << left << setw(7) << "Hora" << "|" << endl;
	imprimirBordeCitas();
	cout << "\t\t\t\t\t\t| " << left << setw(13) << citacion.ci;
	concatenado = citacion.nombrePaciente[0] + " " + citacion.nombrePaciente[1];
	cout << "| " << left << setw(25) << concatenado;
	concatenado = citacion.nombreDoctor[0] + " " + citacion.nombreDoctor[1];
	cout << "| " << left << setw(25) << concatenado;
	cout << "| " << left << setw(25) << citacion.especialidad;
	concatenado = to_string(citacion.fecha[0]) + '/' + to_string(citacion.fecha[1]) + '/' + to_string(citacion.fecha[2]);
	cout << "| " << left << setw(10) << concatenado;
	concatenado = to_string(citacion.hora[0]) + 'h' + to_string(citacion.hora[1]);
	cout << "| " << left << setw(7) << concatenado << "|";
	cout << endl;
	imprimirBordeCitas();
}

void guardarInformacionCitas(tListaCitas& citas) {
	ofstream archivo;
	archivo.open("citas.txt");
	for (int i = 0; i < citas.contador; i++){
		archivo << citas.listaCitas[i].ci << endl;
		archivo << citas.listaCitas[i].nombrePaciente[0] << endl;
		archivo << citas.listaCitas[i].nombrePaciente[1] << endl;
		archivo << citas.listaCitas[i].nombreDoctor[0] << endl;
		archivo << citas.listaCitas[i].nombreDoctor[1] << endl;
		archivo << citas.listaCitas[i].especialidad << endl;
		archivo << citas.listaCitas[i].fecha[0] << endl;
		archivo << citas.listaCitas[i].fecha[1] << endl;
		archivo << citas.listaCitas[i].fecha[2] << endl;
		archivo << citas.listaCitas[i].hora[0] << endl;
		archivo << citas.listaCitas[i].hora[1] << endl;
	}
	archivo << "XXX" << endl;
	archivo.close();
}

void cambiarCitaHora(tListaCitas& citas) {
	string cedula;
	int posicion = -1;
	cout << "\n\tIngrese la cedula del paciente: ";
	cin >> cedula;
	for (int i = 0; i < citas.contador; i++){
		if (citas.listaCitas[i].ci == cedula) {
			posicion = i;
		}
	}
	if (posicion == -1){
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE SIN CITA ===\n" << endl;
	} else {
		imprimirCita(citas.listaCitas[posicion]);
		cout << "\n\tHorario de atencion de 08h00 a 17h00. Solo se aceptan citas en intervalos de 30min.";
		cout << "\n\tIngrese la hora en formato 24 horas (HH:MM): ";
		cin >> citas.listaCitas[posicion].hora[0];
		cin.ignore();
		cin >> citas.listaCitas[posicion].hora[1];
		imprimirCita(citas.listaCitas[posicion]);
	}
}

void cambiarCitaFecha(tListaCitas& citas) {
	string cedula;
	int posicion = -1;
	cout << "\n\tIngrese la cedula del paciente: ";
	cin >> cedula;
	for (int i = 0; i < citas.contador; i++) {
		if (citas.listaCitas[i].ci == cedula) {
			posicion = i;
		}
	}
	if (posicion == -1) {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE SIN CITA ===\n" << endl;
	}
	else {
		imprimirCita(citas.listaCitas[posicion]);
		cout << "\n\tIngrese la fecha (formato DD/MM/AAAA): ";
		cin >> citas.listaCitas[posicion].fecha[0];
		cin.ignore();
		cin >> citas.listaCitas[posicion].fecha[1];
		cin.ignore();
		cin >> citas.listaCitas[posicion].fecha[2];
		imprimirCita(citas.listaCitas[posicion]);
	}
}