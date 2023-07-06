#include "estructuras.c"
#include <stdio.h>
#include <string.h>

profesor crearProfesor(char nombre[20], char c[20], int n_materia,
                       materia materia[3]) {
  profesor p;
  strcpy(p.nombre, nombre);
  strcpy(p.carrera, c);
  p.n_materia = n_materia;
  for (int i = 0; i < n_materia; i++) {
    p.materia[i] = materia[i];
  }
  return p;
}

estudiante crearEstudiante(char nombre[21], int nivel, char carrera[41],
                           int n_materias, materia materia[7]) {
  estudiante e;
  strcpy(e.nombre, nombre);
  e.nivel = nivel;
  strcpy(e.carrera, carrera);
  e.n_materia = n_materias;
  for (int i = 0; i < n_materias; i++) {
    e.materia[i] = materia[i];
  }
  return e;
}

void mostrar_estudiante(estudiante e) {
  printf("Nombre: %s\n", e.nombre);
  printf("Nivel: %d\n", e.nivel);
  printf("Carrera: %s\n", e.carrera);
  printf("Materias:\n");
  for (int i = 0; i < e.n_materia; i++) {
    printf("Materia %d:\n", i + 1);
    printf("  Nombre: %s\n", e.materia[i].nombreMateria);
    printf("  Créditos: %d\n", e.materia[i].creditos);
  }
  printf("\n");
}

void mostrar_profesor(profesor prof) {
  printf("Nombre: %s\n", prof.nombre);
  printf("Carrera: %s\n", prof.carrera);
  printf("Materias:\n");
  for (int i = 0; i < prof.n_materia; i++) {
    printf("Materia %d:\n", i + 1);
    printf("  Nombre: %s\n", prof.materia[i].nombreMateria);
    printf("  Paralelo: %d\n", prof.materia[i].paralelo);
  }
  printf("\n");
}

estudiante eliminarMateriaEstudiante(estudiante estudiante) {
  int opcion;
  char nombreMateria[41];
  int indice = -1;
  printf("Desea eliminar una materia?:\n 1 = Si\n 2 = No\n");
  scanf("%i", &opcion);

  if (opcion == 1) {
    printf("Ingrese el nombre de la materia a eliminar\n");
    scanf("%s", nombreMateria);
    for (int i = 0; i < estudiante.n_materia; i++) {
      if (strcmp(estudiante.materia[i].nombreMateria, nombreMateria) == 0) {
        indice = i;
        break;
      }
    }
    // recorre el arreglo hacia atrás
    if (indice != -1) {
      for (int i = indice; i < estudiante.n_materia - 1; i++) {
        estudiante.materia[i] = estudiante.materia[i + 1];
      }
      estudiante.n_materia--;

      printf("La materia '%s' ha sido eliminada del estudiante '%s'.\n",
             nombreMateria, estudiante.nombre);
    } else {
      printf("La materia '%s' no se encuentra en el estudiante '%s'. No se "
             "pudo eliminar.\n",
             nombreMateria, estudiante.nombre);
    }
  }
  return estudiante;
}

profesor eliminarMateriaProfesor(profesor profesor) {
  int opcion;
  char nombreMateria[41];
  int indice = -1;
  printf("Desea eliminar una materia?:\n 1 = Si\n 2 = No\n");
  scanf("%i", &opcion);
  if (opcion == 1) {
    printf("Ingrese el nombre de la materia a eliminar\n");
    scanf("%s", nombreMateria);

    for (int i = 0; i < profesor.n_materia; i++) {
      if (strcmp(profesor.materia[i].nombreMateria, nombreMateria) == 0) {
        indice = i;
        break;
      }
    }
    // recorre el arreglo hacia atrás
    if (indice != -1) {
      for (int i = indice; i < profesor.n_materia - 1; i++) {
        profesor.materia[i] = profesor.materia[i + 1];
      }
      profesor.n_materia--;

      printf("La materia '%s' ha sido eliminada del estudiante '%s'.\n",
             nombreMateria, profesor.nombre);
    } else {
      printf("La materia '%s' no se encuentra en el estudiante '%s'. No se "
             "pudo eliminar.\n",
             nombreMateria, profesor.nombre);
    }
  }
  return profesor;
}

estudiante cambiarNivelEstudiante(estudiante estudiante) {
  int opcion;
  int nuevoNivel;
  printf("Desea cambiar su nivel?:\n 1 = Si\n 2 = No\n");
  scanf("%i", &opcion);
  if (opcion == 1) {
    printf("Ingrese el nuevo nivel:\n");
    scanf("%i", &nuevoNivel);
    estudiante.nivel = nuevoNivel;
  }
  return estudiante;
}