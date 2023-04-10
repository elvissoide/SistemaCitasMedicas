#include <string>
using namespace std;
const int MAXIMOCITAS = 100;

typedef struct {
	string ci;
	string nombrePaciente[2];
	string nombreDoctor[2];
	string especialidad;
	int fecha[3];
	int hora[2];

}tCita;
typedef struct {
	tCita listaCitas[MAXIMOCITAS];
	int contador;
}tListaCitas;

int mostrarMenuCitas();//Menu de citas

//Carga los datos referentes a las citas desde un archivo txt
void cargarListaCitas(tListaCitas& citas);

//Imprime los datos cargados desde el archivo txt
void imprimirListaCitas(tListaCitas& citas);

//Imprime los bordes horizontales para una mejor presentación
void imprimirBordeCitas();

//Guarda en el archivo .txt los datos modificados o no modificados
void guardarInformacionCitas(tListaCitas& citas);

//Imprime solo una cita determinada
void imprimirCita(tCita& citacion);

//Cambia la hora de una cita determinada
void cambiarCitaHora(tListaCitas& citas);

//Cambia la fecha de una cita determinada
void cambiarCitaFecha(tListaCitas& citas);