#include <string>
using namespace std;
const int MAXIMOPACIENTES = 100;

typedef struct {
	string ci;
	string nombres;
	string apellidos;
	string ubicacion;
	string tipoSangre;
	string email;
	char sexo;
	int edad;
	float peso;
	float altura;
}tPaciente;
typedef struct {
	tPaciente listaPacientes[MAXIMOPACIENTES];
	int contador;
}tListaPacientes;

int mostrarMenuPacientes();//Menú de pacientes
int mostrarMenuPacienteModificacion();//Menu para modificación de datos del paciente

//Carga los datos referentes a los pacientes del hospital
void cargarListaPacientes(tListaPacientes& pacientes);

//Imprime todos los pacientes registrados en el sistema
void imprimirListaPacientes(tListaPacientes& pacientes);

//Imprime bordes horizontales para una mejor visualizacion
void imprimirBordePaciente();

//Agrega un paciente al registro del sistema
void agregarPaciente(tListaPacientes& pacientes);

//Guarda en el archivo .txt los datos modificados o no modificados
void guardarInformacionPacientes(tListaPacientes& pacientes);

//Busca un paciente determinado por su número de cédula
void buscarPaciente(tListaPacientes& pacientes, int& posicionCIPaciente);

//Imprime solo un paciente determinado
void imprimirPaciente(tPaciente& persona);

//Elimina un paciente del sistema mediante su número de cédula
void eliminarPaciente(tListaPacientes& pacientes, int& posicionCIPaciente);

//Modifica algún dato a elección de un paciente registrado
void modificarPaciente(tListaPacientes& pacientes, int& posicionCIPaciente);

//Ordenar informacion por orden alafabetico por nombre
void ordenarPaciente(tListaPacientes& pacientes);