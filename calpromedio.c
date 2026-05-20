#include <stdio.h>

// Funcion para pedir las calificaciones y validar el rango de 0 a 10
void cargarNotas(int n_estudiantes, int n_materias, float calificaciones[][n_materias]) {
    for (int i = 0; i < n_estudiantes; i++) {
        printf("\nNotas del Estudiante %d\n", i + 1);
        for (int j = 0; j < n_materias; j++) {
            float nota_ingresada;
            do {
                printf("Asignatura %d (0-10): ", j + 1);
                scanf("%f", &nota_ingresada);
                if (nota_ingresada < 0 || nota_ingresada > 10) {
                    printf("Error: La nota debe estar entre 0 y 10. Intenta otra vez.\n");
                }
            } while (nota_ingresada < 0 || nota_ingresada > 10);
            
            // Guardar usando aritmetica de punteros
            *(*(calificaciones + i) + j) = nota_ingresada;
        }
    }
}


// Calcular y mostrar el promedio de calificaciones para cada estudiante
void promedioEstudiantes(int n_estudiantes, int n_materias, float calificaciones[][n_materias]) {
    printf("\nPROMEDIO POR ESTUDIANTE\n");
    for (int i = 0; i < n_estudiantes; i++) {
        float suma = 0;
        for (int j = 0; j < n_materias; j++) {
            suma += *(*(calificaciones + i) + j);
        }
        printf("Estudiante %d: %.2f\n", i + 1, suma / n_materias);
    }
}