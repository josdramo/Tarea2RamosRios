#include "estructuras.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int numPersonas = atoi(argv[1]);
  if (numPersonas < 2) {
    printf("La cantidad a ingresar de personas debe ser mayor a 2\n");
    printf("Ingrese la cantidad nuevamente\n");
    exit(0);
  }
  int opt;
  while ((opt = getopt(argc, argv, "pea")) != -1) {

    switch (opt) {

    case 'p': {
      printf("Has ingresado a la opción profesor: %c\n", opt);
      profesor *arregloProfesores = malloc(numPersonas * sizeof(profesor));
      for (int i = 0; i < numPersonas; i++) {
        profesor p;
        p = ingresarDatosProfesor();
        p = eliminarMateriaProfesor(p);
        arregloProfesores[i] = p;
      }
      printf("Profesores ingresados:\n");
      for (int i = 0; i < numPersonas; i++) {
        mostrar_profesor(arregloProfesores[i]);
      }

      free(arregloProfesores);
      break;
    }

    case 'e': {
      printf("Has ingresado a la opción estudiante: %c\n", opt);
      estudiante *arregloEstudiantes = malloc(numPersonas * sizeof(estudiante));
      for (int i = 0; i < numPersonas; i++) {
        estudiante e;
        e = ingresarDatosEstudiante();
        e = eliminarMateriaEstudiante(e);
        e = cambiarNivelEstudiante(e);
        arregloEstudiantes[i] = e;
      }
      printf("Estudiantes ingresados:\n");
      for (int i = 0; i < numPersonas; i++) {
        mostrar_estudiante(arregloEstudiantes[i]);
      }
      free(arregloEstudiantes);
      break;
    }
    case 'a': {
      printf("Has ingresado a la opción ambas: %c\n", opt);
      // se va a ingresar solo un profesor
      // crear un arreglo de personas donde el primero es profesor y despues
      // estudiantes
      profesor *profesorIngresado = malloc(sizeof(profesor));
      *profesorIngresado = ingresarDatosProfesor();
      *profesorIngresado = eliminarMateriaProfesor(*profesorIngresado);
      // ingresar estudiantes
      estudiante *arregloEstudiantes = malloc(numPersonas * sizeof(estudiante));
      ;
      for (int i = 0; i < numPersonas - 1; i++) {
        estudiante e;
        e = ingresarDatosEstudiante();
        e = eliminarMateriaEstudiante(e);
        e = cambiarNivelEstudiante(e);
        arregloEstudiantes[i] = e; /// enviarlo al arreglo de personas
      }
      printf("Profesor ingresado:\n");
      mostrar_profesor(*profesorIngresado);
      printf("Estudiantes ingresados:\n");
      for (int i = 0; i < numPersonas - 1; i++) {
        mostrar_estudiante(arregloEstudiantes[i]);
      }

      free(profesorIngresado);
      free(arregloEstudiantes);
      break;
    }

    case '?': {
      printf("Opción no reconocida: %c\n", optopt);
      break;
    }
    }
  }

  return 0;
};
