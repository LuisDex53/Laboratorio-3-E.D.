//2019042851

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct estudiante{
	int carnet;
	char nombre[20];
	struct estudiante *next;
};

struct ListaDeEstudiantes{
	struct estudiante *start;
	struct estudiante *end;
};

struct ListaDeEstudiantes *list = NULL;

//Punteros para el nombre del estudiante y su carnet
struct estudiante* EstudianteNuevo(char nombre[20], int carnet){
        struct estudiante *CrearEstudiante;
	CrearEstudiante =  malloc(sizeof(struct estudiante));
        strcpy (CrearEstudiante->nombre, nombre);
        CrearEstudiante->carnet =  carnet;
        CrearEstudiante->next = NULL;
        return CrearEstudiante;
}

//Funcion para agregar un estudiante nuevo al inicio de la lista
void EstudianteNuevoStart(char nombre[20], int carnet){
	struct estudiante *EstudianteNew;
        EstudianteNew = EstudianteNuevo(nombre, carnet);
	if(list == NULL){
		list = malloc(sizeof(struct ListaDeEstudiantes));
		list->start = EstudianteNew;
		list->end = EstudianteNew;


	}else{
		EstudianteNew->next = list->start;
		list->start = EstudianteNew;
	}
}

//Funcion para agregar un estudiante nuevo al final de la lista
void EstudianteNuevoEnd(char nombre[20], int carnet){
	struct estudiante *EstudianteNew;
	EstudianteNew = EstudianteNuevo(nombre, carnet);
	 if(list == NULL){
        	 list = malloc(sizeof(struct ListaDeEstudiantes));
                 list->start = EstudianteNew;
                 list->end = EstudianteNew;

        }else{
		list->end->next = EstudianteNew;
                list->end = EstudianteNew;
        }

}

//Funcion para la busqueda de un estudiante
int  ConfirmarEstudiante(int CarnetIngresado, int indice){
	if(list == NULL){
		printf("No hay elementos en la lista\n");
		return 0;
	}else{
		struct estudiante *IndicePointer;
	        IndicePointer = list->start;
		int i = 0;
		while(i != indice){
			IndicePointer = IndicePointer->next;
			i++;
		}
		if(CarnetIngresado == IndicePointer->carnet){
			printf("El estudiante esta registrado\n");
                }else{
               		printf("El carnet no coresponde a ningun estudiante\n");
                }

	}
}

int EliminarEstudianteEnd(struct estudiante *Remove){
	struct estudiante *RemoveEstudiante = list->end;
	list->end = Remove;
	Remove->next = NULL;
	free(RemoveEstudiante);
	printf("El ultimo estudiante de la lista ha sido eliminado");
	return 0;
}

int EliminarEstudianteStart(){
	struct estudiante *RemoveStart = list->start;
	if(RemoveStart->next == NULL){
		list->start = NULL;
		list->end = NULL;
		free(RemoveStart);
		list = NULL;
		printf("Se elimino al primer estudiante de la lista");

	}else{
		list->start = RemoveStart->next;
		free(RemoveStart);
	}
	return 0;

}

int  EliminarEstudianteOtro(int indice){
	if(list == NULL){
		printf("La lista no tiene estudiantes\n");
		return 0;
	}
	if(indice == 0){
		EliminarEstudianteStart();
		return 0;
	}else{
		struct estudiante *IndicePointer;
                IndicePointer = list->start;
		int i = 0;
		while(i != indice-1){
                        IndicePointer = IndicePointer->next;
                        i++;
		}
		struct estudiante *RemovePointer = IndicePointer->next;
		if(RemovePointer->next == NULL){
			EliminarEstudianteEnd(IndicePointer);
			return 0;
		}else{
			IndicePointer->next = RemovePointer->next;
			RemovePointer->next = NULL;
			free(RemovePointer);
			printf("Se ha eliminado al estudiante\n");

		}
	}
}

int main(){
	int option;
	int CarnetIngresado;
	char nombre_digitado[20];
	int indice;
//El menu para la utilizacion del programa
	while(1){
    printf("---------------------------------------------\n");
    printf("Seleccione la opcion que desea utilizar\n");
	printf("1 Agregar un estudiante al final de la lista\n");
	printf("2 Agregar un estudiante al inicio de la lista\n");
	printf("3 Verificar carnet de estudiante\n");
	printf("4 Eliminar estudiante de la lista\n");
	printf("5 Salir\n");
    printf("---------------------------------------------\n");
	scanf("%d", &option);

	switch(option){

	case 1:
		printf("Ingrese el nombre del estudiante\n");
		scanf("%s", nombre_digitado);
		printf("Ingrese el carnet del estudiante\n");
		scanf("%d", &CarnetIngresado);
		EstudianteNuevoEnd(nombre_digitado, CarnetIngresado);
		break;
	case 2:
		printf("Ingrese el nombre del estudiante\n");
                scanf("%s", nombre_digitado);
                printf("Ingrese el carnet del estudiante\n");
                scanf("%d", &CarnetIngresado);
		EstudianteNuevoStart(nombre_digitado, CarnetIngresado);
		break;
	case 3:
		printf("Que posicion ocupa el estudiante en la lista?\n");
                scanf("%d", &indice);
                printf("Digite el numero del carnet del estudiante a confirmar \n");
                scanf("%d", &CarnetIngresado);
		ConfirmarEstudiante(CarnetIngresado, indice);
		break;
	case 4:
		printf("Que posicion ocupa el estudiante que desea eliminar?\n");
		scanf("%d", &indice);
		EliminarEstudianteOtro(indice);
		break;
	case 5:
		exit(1);
		break;
	}
	}
	return 0;
}
