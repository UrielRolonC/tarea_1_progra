#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define alumnos 8
#define materias 6
int m[alumnos][materias];
int generarcalificación();
void mostrar();
void llenar();
int promediomateria();
int promedioalumnos();
int mjr_prom_alm();
int mjr_prom_mat();
int peor_prom_mat();
int peor_prom_alm();

void main(){
    srand(time(NULL));
    llenar();
    mostrar();
    char *Alumnos [alumnos] = {"Juan alberto", "paola macias", "luis perez", "sofia vergara", "alfredo contreras", "carla jimenez", "alondra ruvalcaba", "pancrasio filomeno"};
    char *Materias2 [materias] = {"Fundamentos de programación", "programación orientada a objetos", "fundamentos de redes", "matematicas discretas", "inglés", "electrónica básica"};
    promediomateria();
    promedioalumnos();
    mjr_prom_alm();
    mjr_prom_mat();
    peor_prom_mat();
    peor_prom_alm();
} 

int generarcalificación(){
    return 5.0 + (rand() %51) / 10.0;
}

void llenar(){
    for(int i=0; i < alumnos; i++){
        for(int j=0; j < materias; j++){
            m[i][j] = generarcalificación();
        }
    }
}

void mostrar(){
    for(int i=0; i < alumnos; i++){
        for(int j=0; j < materias; j++){
            printf("%d ", m[i][j] = generarcalificación());
        }
        printf("\n");
    }
}

int promediomateria(){
    char *Materias2 [materias] = {"Fundamentos de programación", "programación orientada a objetos", "fundamentos de redes", "matematicas discretas", "inglés", "electrónica básica"};
    printf("El promedio de cada materia es:\n");
    for (int j = 0; j < materias; j++){
        int suma = 0;
        for (int i = 0; i < alumnos; i++){
            suma += m[i][j];
        }
        printf("Materia: %s, Promedio: %.2f\n", Materias2[j], (float)suma / alumnos);
    }
}

int promedioalumnos(){
    char *Alumnos [alumnos] = {"Juan alberto", "paola macias", "luis perez", "sofia vergara", "alfredo contreras", "carla jimenez", "alondra ruvalcaba", "pancrasio filomeno"};
    printf("El promedio de cada alumno es:\n");
    for (int i = 0; i < alumnos; i++){
        int suma = 0;
        for (int j = 0; j < materias; j++){
            suma += m[i][j];
        }
        printf("Alumno; %s, promedio: %.2f\n", Alumnos[i], (float)suma / materias);
    }
}

int mjr_prom_alm(){
    int prom1 = 0;
    float prom = 0;
    char *Alumnos [alumnos] = {"Juan alberto", "paola macias", "luis perez", "sofia vergara", "alfredo contreras", "carla jimenez", "alondra ruvalcaba", "pancrasio filomeno"};
    for (int i = 0; i < alumnos; i++){
        int suma = 0;
        for (int j = 0; j < materias; j++){
            suma += m[i][j];
        }
     float prom_est = (float)suma / materias;
     if ( prom_est > prom){
        prom = prom_est;
        prom1 = i;
        }
    }
    printf("Estudiante con mejor promedio: %s, Promedio: %.2f\n", Alumnos[prom1], prom);
}

int mjr_prom_mat(){
    int prom1 = 0;
    float prom = 0;
    char *Materias2 [materias] = {"Fundamentos de programación", "programación orientada a objetos", "fundamentos de redes", "matematicas discretas", "inglés", "electrónica básica"};
    for (int j = 0; j < materias; j++){
        int suma = 0;
        for (int i = 0; i < alumnos; i++){
            suma += m[i][j];
        }
        float prom_mat= (float) suma / alumnos;
     if ( prom_mat > prom){
        prom = prom_mat;
        prom1 = j;
        }
    }
    printf("Materia con mejor promedio: %s, Promedio: %.2f\n", Materias2[prom1], prom);
}

int peor_prom_mat(){
    char *Materias2 [materias] = {"Fundamentos de programación", "programación orientada a objetos", "fundamentos de redes", "matematicas discretas", "inglés", "electrónica básica"};   
    for (int j = 0; j < materias; j++){
        int suma = 0;
        for (int i = 0; i < alumnos; i++){
            suma += m[i][j];
        }
        float prom_mat= (float) suma / alumnos;
        if (prom_mat < 6){
            printf("Materia: %s, Promedio: %.2f\n", Materias2[j], prom_mat);
        }
    }
}    

int peor_prom_alm(){
    char *Alumnos [alumnos] = {"Juan alberto", "paola macias", "luis perez", "sofia vergara", "alfredo contreras", "carla jimenez", "alondra ruvalcaba", "pancrasio filomeno"};
    for (int i = 0; i < alumnos; i++){
        int suma = 0;
        for (int j = 0; j < materias; j++){
            suma += m[i][j];
        }
     float prom_est = (float)suma / materias;
     if (prom_est < 6){
        printf("El alumno %s está reprobado por sacar este promedio: %.2f\n", Alumnos[i], prom_est);
     }
    }
}    