#ifndef HTHPLUS_H
#define HTHPLUS_H
#include<vector>
#include<iostream>
#include "Pelicula.h"
#include<time.h>
using namespace std;

class HTHPlus
{
	private:
		vector <Pelicula*> peliculas;
		vector <int> auxiliar; //para ordenar de forma descendente 
		
	public:
		void addPelicula(Pelicula* pelicula);
		void imprimirPorGenero(string);
		void buscarPelicula(string);//buscar una pelicula por una palabra clave
		void ordenarPeliculas();//ordenar peliculas por valoracion, de mayor a menor
		vector<Pelicula*> getPeliculas();
		void listarPeliculas();
		void modificarVector(int,int,string);
		int random();
		HTHPlus();
		~HTHPlus();
	protected:
};

#endif