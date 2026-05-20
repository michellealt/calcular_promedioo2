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

// Calcular y mostrar el promedio por asignatura
void promedioMaterias(int n_estudiantes, int n_materias, float calificaciones[][n_materias]) {
    printf("\nPROMEDIO POR ASIGNATURA\n");
    for (int j = 0; j < n_materias; j++) {
        float suma = 0;
        for (int i = 0; i < n_estudiantes; i++) {
            suma += *(*(calificaciones + i) + j);
        }
        printf("Asignatura %d: %.2f\n", j + 1, suma / n_estudiantes);
    }
}

// Encontrar la calificacion mas alta y baja por estudiante
void notaAltaBajaEstudiante(int n_estudiantes, int n_materias, float calificaciones[][n_materias]) {
    printf("\nNOTA ALTA Y BAJA POR ESTUDIANTE\n");
    for (int i = 0; i < n_estudiantes; i++) {
        float alta = ((calificaciones + i) + 0);
        float baja = ((calificaciones + i) + 0);
        
        for (int j = 1; j < n_materias; j++) {
            float actual = ((calificaciones + i) + j);
            if (actual > alta) alta = actual;
            if (actual < baja) baja = actual;
        }
        printf("Estudiante %d -> Nota Mas Alta: %.2f | Nota Mas Baja: %.2f\n", i + 1, alta, baja);
    }
}
// Encontrar la calificacion mas alta y baja por asignatura
void notaAltaBajaAsignatura(int n_estudiantes, int n_materias, float calificaciones[][n_materias]) {
    printf("\nNOTA ALTA Y BAJA POR ASIGNATURA\n");
    for (int j = 0; j < n_materias; j++) {
        float alta = ((calificaciones + 0) + j);
        float baja = ((calificaciones + 0) + j);
        
        for (int i = 1; i < n_estudiantes; i++) {
            float actual = ((calificaciones + i) + j);
            if (actual > alta) alta = actual;
            if (actual < baja) baja = actual;
        }
        printf("Asignatura %d -> Nota Mas Alta: %.2f | Nota Mas Baja: %.2f\n", j + 1, alta, baja);
    }
}