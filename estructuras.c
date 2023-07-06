#ifndef ESTRUCTURAS_C
#define ESTRUCTURAS_C

typedef struct {
  char nombreMateria[41];
  int creditos;
  int paralelo;
} materia;

typedef struct {
  char nombre[21];
  int nivel;
  char carrera[41];
  int n_materia;
  materia materia[7];
} estudiante;

typedef struct {
  char nombre[20];
  char carrera[20];
  int n_materia;
  materia materia[3];
} profesor;

profesor crearProfesor(char nombre[20], char c[20], int n_materia,
                       materia materia[3]);
estudiante crearEstudiante(char nombre[21], int nivel, char carrera[41],
                           int n_materias, materia materia[7]);

profesor ingresarDatosProfesor();
estudiante ingresarDatosEstudiante();
void mostrar_estudiante(estudiante estudiante);
void mostrar_profesor(profesor prof);

estudiante eliminarMateriaEstudiante(estudiante estudiante);
profesor eliminarMateriaProfesor(profesor profesor);

estudiante cambiarNivelEstudiante(estudiante estudiante);

#endif