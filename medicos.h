//#define medicos_h
//#define medicos_h

#include <string>
using namespace std;
const int MAXIMOMEDICOS = 100;

typedef struct {
	string ci;
	string nombres;
	string apellidos;
	string especialidad;
	string ubicacion;
	string email;
	int celular;
	int edad;
}tMedico;
typedef struct {
	tMedico listaMedicos[MAXIMOMEDICOS];
	int contador;
}tListaMedicos;

int mostrarMenuMedicos();//Menú de médicos
int mostrarMenuMedicosModificacion();//Menu para modificación de datos del médico

//Carga los datos referentes a los médicos desde un archivo txt
void cargarListaMedicos(tListaMedicos& medicos);

//Imprime los datos cargados desde el archivo txt
void imprimirListaMedicos(tListaMedicos& medicos);

//Imprime los bordes horizontales para una mejor presentación
void imprimirBordeMedicos();

//Agrega un médico al registro del sistema
void agregarMedico(tListaMedicos& medicos);

//Guarda en el archivo .txt los datos modificados o no modificados
void guardarInformacionMedicos(tListaMedicos& medicos);

//Busca un médico determinado por su número de cédula
void buscarMedico(tListaMedicos& medicos, int& posicionCIMedico);

//Imprime solo un médico determinado
void imprimirMedico(tMedico& doctor);

//Modifica algún dato a elección de un médico registrado
void modificarMedico(tListaMedicos& medicos, int& posicionCIMedico);

//Elimina un médico del sistema mediante su número de cédula
void eliminarMedico(tListaMedicos& medicos, int& posicionCIMedico);