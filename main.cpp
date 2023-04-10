#include <iostream>
#include <iomanip>
using namespace std;
//Programación modular, inclusión de librerías
#include "pacientes.h"
#include "citas.h"
#include "medicos.h"

const string TITULO = "\n\t\t\t\t\t\t\t\t\t\tHOSPITAL GENERAL DE ESPECIALIDADES \"EUGENIO ESPEJO\"";
//Encabezados pacientes
const string TITULOPACIENTES = "\n\t\t\t\t\t\t\t\t\t\t\t\t      PACIENTES";
const string TITULOPACIENTESBUSQUEDA = "\n\t\t\t\t\t\t\t\t\t\t\t\tBÚSQUEDA DE PACIENTES";
const string TITULOPACIENTESREGISTRO = "\n\t\t\t\t\t\t\t\t\t\t\t\tREGISTRO DE PACIENTES";
const string TITULOPACIENTESMODIFICACION = "\n\t\t\t\t\t\t\t\t\t\t\t\tMODIFICACION DE PACIENTES";
const string TITULOPACIENTESMODIFICACIONSUBMENU = "\n\t\t\t\t\t\t\t\t\t\t\tSUBMENU MODIFICACION DE PACIENTES";
const string TITULOPACIENTESELIMINACION = "\n\t\t\t\t\t\t\t\t\t\t\tELIMINACION DE PACIENTES";
//Encabezados médicos
const string TITULOMEDICOS = "\n\t\t\t\t\t\t\t\t\t\t\t\t      MÉDICOS";
const string TITULOMEDICOSBUSQUEDA = "\n\t\t\t\t\t\t\t\t\t\t\t\tBÚSQUEDA DE MÉDICOS";
const string TITULOMEDICOSREGISTRO = "\n\t\t\t\t\t\t\t\t\t\t\t\tREGISTRO DE MÉDICOS";
const string TITULOMEDICOSMODIFICACION = "\n\t\t\t\t\t\t\t\t\t\t\t\tMODIFICACION DE MÉDICOS";
const string TITULOMEDICOSMODIFICACIONSUBMENU = "\n\t\t\t\t\t\t\t\t\t\t\tSUBMENU MODIFICACION DE MÉDICOS";
const string TITULOMEDICOSELIMINACION = "\n\t\t\t\t\t\t\t\t\t\t\tELIMINACION DE MÉDICOS";
//Encabezados citas
const string TITULOCITAS = "\n\t\t\t\t\t\t\t\t\t\t\t\t      CITAS";
const string TITULOCITASREGISTRO = "\n\t\t\t\t\t\t\t\t\t\t\t\tREGISTRO DE CITAS";
const string TITULOCITASCAMBIOFECHA = "\n\t\t\t\t\t\t\t\t\t\t\t\tCAMBIO FECHA DE CITAS";
const string TITULOCITASCAMBIOHORA = "\n\t\t\t\t\t\t\t\t\t\t\t\tCAMBIO HORA DE CITAS";

//Prototipos de funciones
int mostrarMenuPrincipal();//Menú principal
void agregarCita(tListaCitas& citas, tListaPacientes& pacientes, int& posicionCIPaciente, tListaMedicos& medicos);

//system("cls");	
int main() {
	int opcionMenuPrincipal, opcionMenuPaciente, opcionMenuPacienteModificacion;
	int opcionMenuMedico, opcionMenuMedicoModificacion;
	int opcionMenuCita, opcionMenuCitaModificacion;
	int posicionCIPaciente, posicionCIMedico, posicionCita;
	tListaPacientes pacientes;
	tListaMedicos medicos;
	tListaCitas citas;
	medicos.contador = 0;
	pacientes.contador = 0;
	citas.contador = 0;
	cargarListaPacientes(pacientes);
	cargarListaMedicos(medicos);
	cargarListaCitas(citas);

	do {
		opcionMenuPrincipal = mostrarMenuPrincipal();
		system("cls");
		//cout << TITULO << endl;
		switch (opcionMenuPrincipal) {
		case 0:
			cout << "SISTEMA FINALIZADO" << endl;
			break;
		case 1://Case para manipular información de pacientes
			//system("cls");
			do {
				cout << TITULO << endl;
				cout << TITULOPACIENTES << endl;
				opcionMenuPaciente = mostrarMenuPacientes();
				system("cls");
				switch (opcionMenuPaciente) {
				case 1:
					imprimirListaPacientes(pacientes);
					break;
				case 2:
					cout << TITULO << endl;
					cout << TITULOPACIENTESREGISTRO << endl;
					agregarPaciente(pacientes);
					break;
				case 3:
					cout << TITULO << endl;
					cout << TITULOPACIENTESBUSQUEDA << endl;
					posicionCIPaciente = -1;
					buscarPaciente(pacientes, posicionCIPaciente);
					break;
				case 4://Modificar datos
					cout << TITULO << endl;
					cout << TITULOPACIENTESMODIFICACION << endl;
					posicionCIPaciente = -1;
					buscarPaciente(pacientes, posicionCIPaciente);
					cout << TITULO << endl;
					cout << TITULOPACIENTESMODIFICACIONSUBMENU << endl;
					if (posicionCIPaciente == -1){
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE NO ENCONTRADO ===\n" << endl;
					} else {
						modificarPaciente(pacientes, posicionCIPaciente);
					}
					break;
				case 5:
					posicionCIPaciente = -1;
					cout << TITULO << endl;
					cout << TITULOPACIENTESELIMINACION << endl;
					buscarPaciente(pacientes, posicionCIPaciente);
					if (posicionCIPaciente == -1) {
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === PACIENTE NO ENCONTRADO ===\n" << endl;
					} else {
						eliminarPaciente(pacientes, posicionCIPaciente);
					}
					break;
				case 6:
					ordenarPaciente(pacientes);
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === LISTA ORDENADA ===\n" << endl;
					break;
				}
			} while (opcionMenuPaciente != 0);
			guardarInformacionPacientes(pacientes);
			break;
		case 2://Case para manipular informacion de medicos
			do{
				cout << TITULO << endl;
				cout << TITULOMEDICOS << endl;
				opcionMenuMedico = mostrarMenuMedicos();
				system("cls");
				switch (opcionMenuMedico){
				case 1:
					imprimirListaMedicos(medicos);
					break;
				case 2:
					cout << TITULO << endl;
					cout << TITULOMEDICOSREGISTRO << endl;
					agregarMedico(medicos);
					break;
				case 3:
					cout << TITULO << endl;
					cout << TITULOMEDICOSBUSQUEDA << endl;
					posicionCIMedico = -1;
					buscarMedico(medicos, posicionCIMedico);
					break;
				case 4:
					cout << TITULO << endl;
					cout << TITULOMEDICOSMODIFICACION << endl;
					posicionCIMedico = -1;
					buscarMedico(medicos, posicionCIMedico);
					cout << TITULO << endl;
					cout << TITULOMEDICOSMODIFICACION << endl;
					if (posicionCIMedico == -1){
						cout << "\nNo existe registro del medico buscado." << endl;
					} else {
						modificarMedico(medicos, posicionCIMedico);
					}
					break;
				case 5:
					posicionCIMedico = -1;
					cout << TITULO << endl;
					cout << TITULOMEDICOSELIMINACION << endl;
					buscarMedico(medicos, posicionCIMedico);
					if (posicionCIMedico == -1){
						cout << "\nEl medico no se encuentra registrado en el sistema" << endl;
					} else {
						eliminarMedico(medicos, posicionCIMedico);
					}
					break;
				}
			} while (opcionMenuMedico != 0);
			guardarInformacionMedicos(medicos);
			break;
		case 3:
			do{
				cout << TITULO << endl;
				opcionMenuCita = mostrarMenuCitas();
				system("cls");
				switch (opcionMenuCita){
				case 1:
					imprimirListaCitas(citas);
					break;
				case 2:
					cout << TITULO << endl;
					cout << TITULOCITASREGISTRO << endl;
					posicionCIPaciente = -1;
					buscarPaciente(pacientes, posicionCIPaciente);
					if (posicionCIPaciente == -1){
						cout << "No se ha encontrado al paciente";
						cout << "Ingrese a sección pacientes y registre sus datos." << endl;
					} else {
						agregarCita(citas, pacientes, posicionCIPaciente, medicos);
					}
					break;
				case 3:
					cout << TITULO << endl;
					cout << TITULOCITASCAMBIOHORA << endl;
					cambiarCitaHora(citas);
					break;
				case 4:
					cout << TITULO << endl;
					cout << TITULOCITASCAMBIOFECHA << endl;
					cambiarCitaFecha(citas);
					break;
				default:
					break;
				}
			} while (opcionMenuCita != 0);
			guardarInformacionCitas(citas);
			break;
		default:
			break;
		}
	} while (opcionMenuPrincipal != 0);
	return 0;
}

int mostrarMenuPrincipal() {
	int opcion = 0;
	cout << TITULO << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Salir" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. Información sobre pacientes" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. Información sobre medicos" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t3. Información sobre citas" << endl;
	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tIngrese una opción: ";
		cin >> opcion;
	} while (opcion < 0 || opcion > 3);
	return opcion;
}

void agregarCita(tListaCitas& citas, tListaPacientes& pacientes, int& posicionCIPaciente, tListaMedicos& medicos) {
	tCita citacion;
	tPaciente persona;
	string especialidad;
	char aceptarRegistro;
	bool encontradoEspecialidad = false;
	citacion.ci = pacientes.listaPacientes[posicionCIPaciente].ci;
	citacion.nombrePaciente[0] = pacientes.listaPacientes[posicionCIPaciente].nombres;
	citacion.nombrePaciente[1] = pacientes.listaPacientes[posicionCIPaciente].apellidos;
	cout << "\n\tIngrese la especialidad a tomar cita: ";
	cin.ignore(80, '\n');
	getline(cin, especialidad);
	for (int i = 0; i < medicos.contador; i++) {
		if (medicos.listaMedicos[i].especialidad == especialidad) {
			citacion.especialidad = medicos.listaMedicos[i].especialidad;
			citacion.nombreDoctor[0] = medicos.listaMedicos[i].nombres;
			citacion.nombreDoctor[1] = medicos.listaMedicos[i].apellidos;
			encontradoEspecialidad = true;
		}
	}
	if (encontradoEspecialidad){
		cout << "\n\tIngrese la fecha (formato DD/MM/AAAA): ";
		cin >> citacion.fecha[0];
		cin.ignore();
		cin >> citacion.fecha[1];
		cin.ignore();
		cin >> citacion.fecha[2];
		//do{
			cout << "\n\tHorario de atencion de 08h00 a 17h00. Solo se aceptan citas en intervalos de 30min.";
			cout << "\n\tIngrese la hora en formato 24 horas (HH:MM): ";
			cin >> citacion.hora[0];
			cin.ignore();
			cin >> citacion.hora[1];
		//} while ((citacion.hora[0] < 8 || citacion.hora[0] > 17) || (citacion.hora[1] != 0 || citacion.hora[1] != 30));
		imprimirCita(citacion);
		cout << "\n\n\t\t\t\t\t\t\t\t\tDesea registrar la cita? (Y/N): ";
		cin >> aceptarRegistro;
		aceptarRegistro = toupper(aceptarRegistro);
		system("cls");
		if (aceptarRegistro == 'Y') {
			citas.listaCitas[citas.contador] = citacion;
			citas.contador++;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === CITA REGISTRADA ===\n" << endl;
		}
		else {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t      === CITA NO REGISTRADA ===\n" << endl;
		}
	} else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t    === ESPECIALIDAD NO DISPONIBLE ===\n" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t=== VER LAS ESPECIALIDADES DISPONIBLES EN SECCION MEDICOS ===\n" << endl;
	}

}