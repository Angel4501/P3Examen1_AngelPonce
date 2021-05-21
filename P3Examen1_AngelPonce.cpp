#include <iostream>
#include<time.h>
#include "Pelicula.h"
#include "HTHPlus.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu();

int random();

int main(int argc, char** argv) {
	int opcion=0;
	int a = 0;
	HTHPlus* movies = NULL;
	Pelicula* peliculas = NULL;
	//Pelicula* peliculas = NULL;
	movies = new HTHPlus(); //Una instancia de la clase que contiene el "arraylist" de peliculas
	while(a!=8){
		switch(a = menu()){
			case 1:{
				string titulo,director,genero;
				cout<<"Ingrese titulo de la pelicula: ";
				cin.ignore();
				getline(cin,titulo);

				cout<<"Ingrese director de la pelicula: ";
				getline(cin,director);
				
				cout<<"Ingrese genero de la pelicula: ";
				getline(cin,genero);
				
				cout<<"La valoracion de esa pelicula es: "<<random()<<endl;
				
				
				peliculas = new Pelicula(titulo,director,genero,random());//generando la pelicula
				
				movies->addPelicula(peliculas);//agregando pelicula al vector 
				
				//NO hacer el delete peliculas;
				break;
			}	
			case 2:{
				cout<<"Peliculas agregadas: "<<endl;
				movies->listarPeliculas();	
				break;
			}	
			case 3:{
				//string choose;
				int eleccion,pos=0;
				cout<<"Que desea modificar?"<<endl;
				cout<<"1. Titulo"<<endl;
				cout<<"2. Director"<<endl;
				cout<<"3. Genero"<<endl;
				cout<<"4. Valoracion"<<endl
				<<"Opcion: ";
				cin>>eleccion;//para el switch
				
				cout<<"Las peliculas son estas: "<<endl;
				movies->listarPeliculas();
				cout<<"Ingrese posicion de la pelicula a modificar: ";
				cin>>pos;
				switch(eleccion){
					case 1: {
						string t="";
						cout<<"Ingrese nuevo titulo: ";
						cin.ignore();
						getline(cin,t);
						movies->modificarVector(eleccion,pos,t);
						break;
					}
					case 2: {
						string t="";
						cout<<"Ingrese nuevo director: ";
						cin.ignore();
						getline(cin,t);
						movies->modificarVector(eleccion,pos,t);
						break;
					}
					case 3: {
						string t="";
						cout<<"Ingrese nuevo genero: ";
						cin.ignore();
						getline(cin,t);
						movies->modificarVector(eleccion,pos,t);
						break;
					}
					case 4: {
						string t="";
						cout<<"Se modifico la valoracion de esa pelicula"<<endl;
						movies->modificarVector(eleccion,pos,t);
						break;
					}
				}
				cout<<"Se aplicaron los cambios!"<<endl;
				break;
			}	
			case 4:{
				int p=0;
				cout<<"ELIMINAR PELICULAS"<<endl;
				movies->listarPeliculas();
				cout<<"Ingrese la posicion de la pelicula que desea eliminar: ";
				cin>>p;
				//movies->
				
				break;			
			}
			case 5:{
				string gender;
				cout<<"Ingrese el genero: ";
				cin.ignore();
				getline(cin,gender);
				movies->imprimirPorGenero(gender);
				break;			
			}
			case 6:{
				string frase;
				cout<<"Ingrese palabra o frase clave para buscar pelicula: ";
				cin.ignore();
				getline(cin,frase);
				movies->buscarPelicula(frase);
				break;			
			}
			case 7:{
				cout<<"Peliculas por valoracion: "<<endl;
				movies->ordenarPeliculas();
				break;			
			}
			case 8:{
				break;			
			}
			default: 
				cout<<"Opcion no valida, ingresela nuevamente"<<endl;
	    }
   }//FIN DEL WHILE
   delete peliculas;//liberando memoria
   delete movies;//liberando memoria
	return 0;
}

int menu(){//funcion menu
	int opc=0;
	while(opc!=8){
		cout<<"MENU"<<endl
		<<"1. Agregar pelicula"<<endl //ya
		<<"2. Listar peliculas agregadas"<<endl //ya
		<<"3. Modificar pelicula"<<endl
		<<"4. Eliminar pelicula"<<endl
		<<"5. Imprimir peliculas por genero"<<endl //ya
		<<"6. Buscar pelicula"<<endl
		<<"7. Imprimir peliculas ordenadas por valoracion"<<endl
		<<"8. Salir"<<endl
		<<"Opcion: ";
		cin>>opc;
		if(opc>=1&&opc<=8){
			break;
		}
		else{
			cout<<"Opcion no valida, ingresela nuevamente"<<endl;
		}			
   }
   return opc;	
}//fin de la funcion menu

int random(){
	srand(time(NULL));
	return 1+rand()%(5);
}