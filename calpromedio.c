#include <stdio.h>

// Dejamos solo esta funcion que es la más común para iniciar
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
            
            // Guardar usando aritmetica de punteros como pide la guia
            *(*(calificaciones + i) + j) = nota_ingresada;
        }
    }
}

int main() {
    int total_estudiantes;
    int total_asignaturas = 3; // El total de asignaturas sera de 3 
    
    printf("SISTEMA DE GESTION DE CALIFICACIONES\n");
    printf("Cantidad de estudiantes a registrar: ");
    scanf("%d", &total_estudiantes);

    // Matriz de calificaciones
    float calificaciones[total_estudiantes][total_asignaturas];

    // Aqui usamos la unica funcion para llenar los datos
    cargarNotas(total_estudiantes, total_asignaturas, calificaciones);

   
    //PROMEDIO POR ESTUDIANTE 
   
    printf("\nPROMEDIO POR ESTUDIANTE\n");
    for (int i = 0; i < total_estudiantes; i++) {
        float suma = 0;
        for (int j = 0; j < total_asignaturas; j++) {
            suma += *(*(calificaciones + i) + j);
        }
        printf("Estudiante %d: %.2f\n", i + 1, suma / total_asignaturas);
    }

    //PROMEDIO POR ASIGNATURA 
   
    printf("\nPROMEDIO POR ASIGNATURA\n");
    for (int j = 0; j < total_asignaturas; j++) {
        float suma = 0;
        for (int i = 0; i < total_estudiantes; i++) {
            suma += *(*(calificaciones + i) + j);
        }
        printf("Asignatura %d: %.2f\n", j + 1, suma / total_estudiantes);
    }

    //NOTA ALTA Y BAJA POR ESTUDIANTE 

    printf("\nNOTA ALTA Y BAJA POR ESTUDIANTE\n");
    for (int i = 0; i < total_estudiantes; i++) {
        float alta = *(*(calificaciones + i) + 0);
        float baja = *(*(calificaciones + i) + 0);
        
        for (int j = 1; j < total_asignaturas; j++) {
            float actual = *(*(calificaciones + i) + j);
            if (actual > alta) alta = actual;
            if (actual < baja) baja = actual;
        }
        printf("Estudiante %d -> Nota Mas Alta: %.2f | Nota Mas Baja: %.2f\n", i + 1, alta, baja);
    }

    //NOTA ALTA Y BAJA POR ASIGNATURA 

    printf("\nNOTA ALTA Y BAJA POR ASIGNATURA\n");
    for (int j = 0; j < total_asignaturas; j++) {
        float alta = *(*(calificaciones + 0) + j);
        float baja = *(*(calificaciones + 0) + j);
        
        for (int i = 1; i < total_estudiantes; i++) {
            float actual = *(*(calificaciones + i) + j);
            if (actual > alta) alta = actual;
            if (actual < baja) baja = actual;
        }
        printf("Asignatura %d -> Nota Mas Alta: %.2f | Nota Mas Baja: %.2f\n", j + 1, alta, baja);
    }

    //ESTADISTICAS DE APROBACION 

    printf("\nESTADO DE RENDIMIENTO POR ASIGNATURA\n");
    for (int j = 0; j < total_asignaturas; j++) {
        int aprobados = 0;
        int reprobados = 0;
        
        for (int i = 0; i < total_estudiantes; i++) {
            if (*(*(calificaciones + i) + j) >= 6.0) { // Nota aprobatoria >= 6 [cite: 10]
                aprobados++;
            } else {
                reprobados++;
            }
        }
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n", j + 1, aprobados, reprobados);
    }
    return 0;
}