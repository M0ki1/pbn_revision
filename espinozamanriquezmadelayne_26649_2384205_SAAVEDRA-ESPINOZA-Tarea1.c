#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//gcc main.c -o outputname -lm
// -lm es necesario para que se compile la libreria math.h
// flags:
//-Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
/*double distancia(double x1,double y1,double x2,double y2){
  double d;
  double a;
  a = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
  d = sqrt(a);
  return d;
}*/

int main() {
// En la siguiente sección se busca escalabilidad al funcionar con cualquier largo de archivo (para un int)
   FILE *arch_entr;
   int num_l=0;
   char f;

   arch_entr = fopen("a.txt", "r");

   if (arch_entr == NULL) {
      printf("Error al abrir el archivo.\n");
      return 1;
   }

   while ((f = fgetc(arch_entr)) != EOF) {
      if (f == '\n') {
         num_l++;
      }
   }
   

   

   fclose(arch_entr);


  FILE* arch_entrada; 
  FILE* arch_salida;
  char equipo[num_l];
  
  double x;
  double y;
  //double coord_x[num_l];
  //double coord_y[num_l];
  int j=0;
  //numero de lineas que tiene el archivo
  
  //Recuerda modificar el nombre del archivo de entrada : equipos.txt
  arch_entrada = fopen("a.txt", "r");
  char list_equipos[num_l][100];
 
  char L[num_l];
  if(arch_entrada == NULL){
  
	printf("No se puede abrir este archivo.\n");
	return 1;
	}
 // La función fgets leerá el archivo y guardará cada linea en el arreglo: L[10000]

  while(fgets(L, num_l, arch_entrada)!= NULL){		

//Mientras cada linea es leída, se separa usando la funcion sscanf (utiliza como parametros la linea que se leerá y caracter a usar para separar la linea), el nombre y sus respectivas coordenadas
//Se guarda cada nombre y sus coordenadas en su arreglo correspondiente
//"%[^,] esto aceptará cualquier caracter, exceptuando la coma (que es lo que separa los datos por linea)
	
	sscanf(L,"%[^,],%lf,%lf", equipo, &x, &y);
  	strcpy(list_equipos[j], equipo);
  	//coord_x[j]=x;
	//coord_y[j]=y;
	j++;
	
	}

fclose(arch_entrada);
 
//Desde ahora: crear partidos entre equipos.
  
  int made[num_l];
  for(int  i=0; i<num_l ; i++){
  	made[i]=i;
  	//printf("%d", made[i]);
  }
 
  //se generaran numeros aleatorios dentro de los parametros del largo del archivo
  // se guardaran en partes[] para crear los equipos que jugaran entre si
  
  int cantidad_partes=num_l/5;//cantidad de grupos que se formaran
  int tamano_parte=5; 
  int partes[cantidad_partes][tamano_parte]; 
 
 //Apoyo en internet para lograr obtener numeros aleatorios concordes a los parametros 
  srand(time(NULL));
  for (int i = 0; i < cantidad_partes; i++) {
        for (int j = 0; j < tamano_parte; j++) {
            int indice = rand() % num_l; 
            partes[i][j] = made[indice];
            made[indice] = made[num_l-1]; 
            num_l--;
        }
      //printf("\n");  
    }
 /*double dist_total[num_l][num_l];
  for(int i=0; i<num_l;i++){
  	for(int j =0; j<num_l;j++){
  		double x1=coord_x[i];
  		double x2=coord_x[j];
  		double y1=coord_y[i];
  		double y2=coord_y[j];
  		dist_total[i][j]=distancia(x1,y1,x2,y2);
  		printf("%lf\n",dist_total[i][j]);

  	}
  }*/
  
  
  
  
 
 //Se crea el archivo de salida que llevará por cada linea la forma:
 //NombreEquipo,rival1,rival2,rival3,rival4
 
 arch_salida = fopen("partidos.txt", "w");
 
 int ma=0; //iterador para lograr agregar todos los equipos y sus respectivos partidos
 
 while(ma<cantidad_partes){
 	fprintf(arch_salida, "%s, %s, %s, %s, %s\n", list_equipos[partes[ma][0]],list_equipos[partes[ma][1]],list_equipos[partes[ma][2]],list_equipos[partes[ma][3]],list_equipos[partes[ma][4]]);
 	
 	fprintf(arch_salida, "%s, %s, %s, %s, %s\n", list_equipos[partes[ma][1]],list_equipos[partes[ma][0]],list_equipos[partes[ma][2]],list_equipos[partes[ma][3]],list_equipos[partes[ma][4]]);
 	
 	fprintf(arch_salida, "%s, %s, %s, %s, %s\n", list_equipos[partes[ma][2]],list_equipos[partes[ma][0]],list_equipos[partes[ma][1]],list_equipos[partes[ma][3]],list_equipos[partes[ma][4]]);
 	
 	fprintf(arch_salida, "%s, %s, %s, %s, %s\n", list_equipos[partes[ma][3]],list_equipos[partes[ma][0]],list_equipos[partes[ma][1]],list_equipos[partes[ma][2]],list_equipos[partes[ma][4]]);
 	
 	fprintf(arch_salida, "%s, %s, %s, %s, %s\n", list_equipos[partes[ma][4]],list_equipos[partes[ma][0]],list_equipos[partes[ma][1]],list_equipos[partes[ma][2]],list_equipos[partes[ma][3]]);
 	
 	ma++;
 }

 
 
 fclose(arch_salida);
 /*for(int i=0;i<20;i++){
 	printf("%s\n", list_equipos[i]);
 }
 for(int i=0; i<4;i++){
 	printf("PARTE %d\n", i);
 	for(int j=0; j<5;j++){
 		printf("%d\n", partes[i][j]);
 		
 	}
 }*/
return 0;	
	
	

}

/*
#include <stdio.h>
#include <string.h>
#include <math.h>

//gcc main.c -o outputname -lm
// -lm es necesario para que se compile la libreria math.h

double distancia(double x1,double y1,double x2,double y2){
  double d;
  double a;
  a = ((x2-x1)(x2-x1))+((y2-y1)(y2-y1));
  d = sqrt(a);
  return d;
}

double comparar_dist(double d0,double d1,double d2,double d3){
  if (d0>d1){
    if (d0>d2){
    if (d0>d3){
    return d0;
    }
    }
  }
  if (d1>d0){
    if (d1>d2){
    if (d1>d3){
    return d1;
    }
    }
  }
  if (d2>d0){
    if (d2>d1){
    if (d2>d3){
    return d2;
    }
    }
  }
  if (d3>d0){
    if (d3>d1){
    if (d3>d2){
    return d3;
    }
    }
  }
}

long int factorial(int a){
  int b;
  long int res = 1;
  for (b=1; b<=a; b++){
    res = res * b;
  }
  return res;
}

long int combinatoria(int n){
  long int up;
  //long int down1;
  //long int down2;
  long int down;
  long int resp;
  up = factorial(n);
  printf("%ld\n", up);
  down = factorial(n-2)*2;
  printf("%ld\n", down);
  resp = up/down;
  return resp;
}

int main() {
  FILE* arch_entrada; 
  FILE* arch_salida;
  char equipo[10000];
  char list_equipos[5000][100];
  double x;
  double y;
  double coord_x[10000];
  double coord_y[10000];
  int j=0;
 
  
  //Recuerda modificar el nombre del archivo de entrada : equipos.txt
  arch_entrada = fopen("equipos_corto.txt", "r");
  arch_salida = fopen("partidos.txt", "w");
  
  char L[10000];
  if(arch_entrada == NULL){
  
	printf("No se puede abrir este archivo.\n");
	return 1;
	}
	
// La función fgets leerá el archivo y guardará cada linea en el arreglo: L[10000]
  
  while(fgets(L, 10000, arch_entrada)!= NULL){		

//Mientras cada linea es leída, se separa usando la funcion sscanf (utiliza como parametros la linea que se leerá y caracter a usar para separar la linea), el nombre y sus respectivas coordenadas
//Se guarda cada nombre y sus coordenadas en su arreglo correspondiente
//"%[^,] esto aceptará cualquier caracter, exceptuando la coma (que es lo que separa los datos por linea)
	sscanf(L,"%[^,],%lf,%lf", equipo, &x, &y);

//LOGRE SEPARAR LAS COORDENADAS X e Y EN ARREGLOS PERO LOS NOMBRES DE LOS EQUIPOS NO :( AIUDAAAAA
	//printf("%s", equipo);
  strcpy(list_equipos[j], equipo);
  coord_x[j]=x;
	coord_y[j]=y;
	j++;
	}

  int i=0;
  while(i<j){
  printf("%s\n", list_equipos[i]);
	printf("%.3f\n", coord_x[i]);
	printf("%.3f\n", coord_y[i]);
	i++;
	} 

  fclose(arch_entrada);
  fclose(arch_salida);
  //int fact = 4;
  //printf("Factorial of %d is: %ld\n", fact, factorial(fact));
  printf("%d sobre 2 es: %ld\n", j, combinatoria(j));
  printf("el largo del archivo es: %d\n", j);

  //ACA EMPIZA EL WEBEO

  // lista[a][b]: a es el num de una de las listas, b es el num del elmento de la lista interna, ambos parten de 0
  
  int it = 0;
  double it1;
  double it2;
  double x1;
  double y1;
  double x2;
  double y2;
  double d;
  long int num_comb_pos;
  num_comb_pos = combinatoria(j);
  double possible_matches [num_comb_pos][3];
  for (it1=0; it1<j; it1++){
    it2=it1+1;
    for (it2=it1+1; it2<j; it2++){
      possible_matches[it][0] = it1;
      possible_matches[it][1] = it2;
      //ahora iria la distancia que voy a dejar 0 por ahora
      x1 = coord_x[(int)it1];
      y1 = coord_y[(int)it1];
      x2 = coord_x[(int)it2];
      y2 = coord_y[(int)it2];
      d = distancia(x1,y1,x2,y2);

      possible_matches[it][2] = d;
      it=it+1;
    }
  }

  

  
  printf("comb pos: %ld\n", num_comb_pos);
  

  int len_tot;
  len_tot = j*4;
  double all_final_matches[len_tot][3];
  // elem 0-3 del equipo 0, luego 4-7 del 1, luego 8-11 del 2, y asi etc...
  // podemos entonces 0*4+0=0, 0*4+1=1, 0*4+2=2 y 0*4+3=3
  // podemos entonces 1*4+0=4, 1*4+1=5, 1*4+2=6 y 1*4+3=7
  // podemos entonces 2*4+0=8, 2*4+1=9, 2*4+2=10 y 2*4+3=11
  // y así

  int temp_team, temp_team2;
  int u, v, w, z, k, h;
  u=0;
  k=0;
  
  for (w=0; w<len_tot; w++){
    all_final_matches[w][2]=(double)0;
  }

  for (temp_team=0; temp_team<j; temp_team++){

    k=0;
    printf("For num 1");
    for (u=0; u<num_comb_pos; u++){
      v=0;
      printf("For num 2");
      if (((int)possible_matches[u][0])==temp_team){
        //encontro el equipo en 0
        double num_lock[3];
        h=0;
        for (h=0; h<3; h++){
          num_lock[h] = -1;
        }
        for (v=0; v<4; v++){
          printf("For num 3 A");
          printf(" %lf ", all_final_matches[(temp_team*4)+v][2]);
          if (all_final_matches[(temp_team*4)+v][2]==(double)0){
            
            
            //ahora, escribamos para k el equipo con el que juega tmbn añada el partido a sus lineas de la lista
            
            temp_team2 = possible_matches[u][1];
            //printf("%d\n", temp_team2);
            //printf("%d\n", (temp_team2*4)+v);

            for (z=0; z<4; z++){
              if (all_final_matches[(temp_team2*4)+z][2]==(double)0){
                //revisar si la k esta intentando agregar ya existe
                
                if (possible_matches[u][1]==num_lock[0]){break;}
                if (possible_matches[u][1]==num_lock[1]){break;}
                if (possible_matches[u][1]==num_lock[2]){break;}

                all_final_matches[(temp_team*4)+v][0]=possible_matches[u][0];
                all_final_matches[(temp_team*4)+v][1]=possible_matches[u][1];
                all_final_matches[(temp_team*4)+v][2]=possible_matches[u][2];
                
                all_final_matches[(temp_team2*4)+z][0]=possible_matches[u][1];
                all_final_matches[(temp_team2*4)+z][1]=possible_matches[u][0];
                all_final_matches[(temp_team2*4)+z][2]=possible_matches[u][2];
                break;
              }
            }
            
            break;
          }
          else if (all_final_matches[(temp_team*4)+v][2]!=(double)0){
            //quien guarda las comb ya presentes:
            num_lock[k] = all_final_matches[(temp_team*4)+v][1];
            k++;
          }
          printf("%d\n",v);
        }
        
        if (v>=4){
          //llamar una f conparadora y pasarle las 4 distancias que ya hay
          double d0,d1,d2,d3, mayor_d, p0, p1, p2, p3;
          d0 = all_final_matches[(temp_team*4)][2];
          d1 = all_final_matches[(temp_team*4)+1][2];
          d2 = all_final_matches[(temp_team*4)+2][2];
          d3 = all_final_matches[(temp_team*4)+3][2];
          p0 = all_final_matches[(temp_team*4)][1];
          p1 = all_final_matches[(temp_team*4)+1][1];
          p2 = all_final_matches[(temp_team*4)+2][1];
          p3 = all_final_matches[(temp_team*4)+3][1];
          if(possible_matches[u][1]==p0){break;}
          if(possible_matches[u][1]==p1){break;}
          if(possible_matches[u][1]==p2){break;}
          if(possible_matches[u][1]==p3){break;}
          mayor_d = comparar_dist(d0,d1,d2,d3);
          if (possible_matches[u][2]<mayor_d){
            if (d0==mayor_d){
              all_final_matches[(temp_team*4)][0]=possible_matches[u][0];
              all_final_matches[(temp_team*4)][1]=possible_matches[u][1];
              all_final_matches[(temp_team*4)][2]=possible_matches[u][2];
            }
            else if (d1==mayor_d){
              all_final_matches[(temp_team*4)+1][0]=possible_matches[u][0];
              all_final_matches[(temp_team*4)+1][1]=possible_matches[u][1];
              all_final_matches[(temp_team*4)+1][2]=possible_matches[u][2];
            }
            else if (d2==mayor_d){
              all_final_matches[(temp_team*4)+2][0]=possible_matches[u][0];
              all_final_matches[(temp_team*4)+2][1]=possible_matches[u][1];
              all_final_matches[(temp_team*4)+2][2]=possible_matches[u][2];
            }
            else if (d3==mayor_d){
              all_final_matches[(temp_team*4)+3][0]=possible_matches[u][0];
              all_final_matches[(temp_team*4)+3][1]=possible_matches[u][1];
              all_final_matches[(temp_team*4)+3][2]=possible_matches[u][2];
            }
          }
        }
      }
      else if (((int)possible_matches[u][1])==temp_team){
        //encontro el equipo en 1
        double num_lock[3];
        h=0;
        for (h=0; h<3; h++){
          num_lock[h] = -1;
        }
        for (v=0; v<4; v++){
          printf("For num 3 B");
          printf(" %lf ", all_final_matches[(temp_team*4)+v][2]);
          if (all_final_matches[(temp_team*4)+v][2]==(double)0){
            
            //ahora, escribamos para k el equipo con el que juega tmbn añada el partido a sus lineas de la lista
            
            temp_team2 = possible_matches[u][0];
            //printf("%d\n", temp_team2);
            //printf("%d\n", (temp_team2*4)+v);

            for (z=0; z<4; z++){
              if (all_final_matches[(temp_team2*4)+z][2]==(double)0){

                if (possible_matches[u][0]==num_lock[0]){break;}
                if (possible_matches[u][0]==num_lock[1]){break;}
                if (possible_matches[u][0]==num_lock[2]){break;}

                all_final_matches[(temp_team*4)+v][0]=possible_matches[u][1];
                all_final_matches[(temp_team*4)+v][1]=possible_matches[u][0];
                all_final_matches[(temp_team*4)+v][2]=possible_matches[u][2];

                all_final_matches[(temp_team2*4)+z][0]=possible_matches[u][0];
                all_final_matches[(temp_team2*4)+z][1]=possible_matches[u][1];
                all_final_matches[(temp_team2*4)+z][2]=possible_matches[u][2];
                break;
              }
            }
            
            break;
          }
          else if (all_final_matches[(temp_team*4)+v][2]!=(double)0){
            //quien guarda las comb ya presentes:
            num_lock[k] = all_final_matches[(temp_team*4)+v][0];
            k++;
          }
          printf("%d\n",v);
        }

        if (v>=4){
          //llamar una f conparadora y pasarle las 4 distancias que ya hay
          double d0,d1,d2,d3, mayor_d, p0, p1, p2, p3;
          d0 = all_final_matches[(temp_team*4)][2];
          d1 = all_final_matches[(temp_team*4)+1][2];
          d2 = all_final_matches[(temp_team*4)+2][2];
          d3 = all_final_matches[(temp_team*4)+3][2];
          p0 = all_final_matches[(temp_team*4)][1];
          p1 = all_final_matches[(temp_team*4)+1][1];
          p2 = all_final_matches[(temp_team*4)+2][1];
          p3 = all_final_matches[(temp_team*4)+3][1];
          if(possible_matches[u][0]==p0){break;}
          if(possible_matches[u][0]==p1){break;}
          if(possible_matches[u][0]==p2){break;}
          if(possible_matches[u][0]==p3){break;}
          mayor_d = comparar_dist(d0,d1,d2,d3);
          if (possible_matches[u][2]<mayor_d){
            if (d0==mayor_d){
              all_final_matches[(temp_team*4)][0]=possible_matches[u][1];
              all_final_matches[(temp_team*4)][1]=possible_matches[u][0];
              all_final_matches[(temp_team*4)][2]=possible_matches[u][2];
            }
            else if (d1==mayor_d){
              all_final_matches[(temp_team*4)+1][0]=possible_matches[u][1];
              all_final_matches[(temp_team*4)+1][1]=possible_matches[u][0];
              all_final_matches[(temp_team*4)+1][2]=possible_matches[u][2];
            }
            else if (d2==mayor_d){
              all_final_matches[(temp_team*4)+2][0]=possible_matches[u][1];
              all_final_matches[(temp_team*4)+2][1]=possible_matches[u][0];
              all_final_matches[(temp_team*4)+2][2]=possible_matches[u][2];
            }
            else if (d3==mayor_d){
              all_final_matches[(temp_team*4)+3][0]=possible_matches[u][1];
              all_final_matches[(temp_team*4)+3][1]=possible_matches[u][0];
              all_final_matches[(temp_team*4)+3][2]=possible_matches[u][2];
            }
          }
        }

      }
    }


  }

  u=0;
  v=0;
  w=0;
  //double all_final_matches[len_tot][3];
  
  for (u=0; u<len_tot; u++){
    for (v=0; v<3; v++){
      printf("all_final_matches[%d][%d] = %lf\n", u, v, all_final_matches[u][v]);
    }
  }
  

  return 0;
}

*/	
	
