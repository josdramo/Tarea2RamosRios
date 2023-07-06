#include "estructuras.c"
#include <stdio.h>
#include <string.h>

profesor ingresarDatosProfesor() {
  char nombre[20];
  char carrera[20];
  int n_materia;

  printf("Ingrese el nombre del profesor:\n");
  scanf("%s", nombre);
  printf("Ingrese la carrera:\n");
  scanf("%s", carrera);

  printf("Cuantas materias va a ingresar:\n");

  scanf("%i", &n_materia);
  while (n_materia < 2 || n_materia > 3) {
    printf("ERROR, el profesor solo puede contener de 2 a 3 materias\n");
    printf("Cuantas materias va a ingresar:\n");
    scanf("%i", &n_materia);
  }

  materia arregloMateria[n_materia];
  for (int i = 0; i < n_materia; i++) {
    char nombre_materia[41];
    int materia_paralelo;
    materia m;
    printf("Ingrese el nombre de la materia:\n");
    scanf("%s", nombre_materia);
    strcpy(m.nombreMateria, nombre_materia);
    printf("Ingrese el paralelo de la materia:\n");
    scanf("%i", &materia_paralelo);
    m.creditos = materia_paralelo;

    arregloMateria[i] = m;
  }

  profesor profesorIngresado =
      crearProfesor(nombre, carrera, n_materia, arregloMateria);
  return profesorIngresado;
};

estudiante ingresarDatosEstudiante() {
  char nombre[20];
  char carrera[20];
  int nivel;
  int materia_creditos;
  int n_materia;
  char nombreMateria[41];
  materia m;
  printf("Ingrese el nombre del estudiante:\n");
  scanf("%s", nombre);
  printf("Ingrese el nivel del estudiante:\n");
  scanf("%i", &nivel);
  printf("Ingrese la carrera del estudiante:\n");
  scanf("%s", carrera);
  // materia
  printf("Cuantas materias va a ingresar:\n");
  scanf("%i", &n_materia);
  while (n_materia < 3 || n_materia > 7) {
    printf("ERROR, el profesor solo puede contener de 3 a 7 materias\n");
    printf("Cuantas materias va a ingresar:\n");
    scanf("%i", &n_materia);
  }

  materia arregloMateria[n_materia];
  for (int i = 0; i < n_materia; i++) {
    printf("Ingrese el nombre de la materia:\n");
    scanf("%s", nombreMateria);
    strcpy(m.nombreMateria, nombreMateria);
    printf("Ingrese los creditos de la materia:\n");
    scanf("%i", &materia_creditos);
    m.creditos = materia_creditos;

    arregloMateria[i] = m;
  }
  estudiante estudianteIngresado =
      crearEstudiante(nombre, nivel, carrera, n_materia, arregloMateria);
  return estudianteIngresado;
};