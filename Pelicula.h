#ifndef PELICULA_H
#define PELICULA_H
#include<string>
#include<iostream>
#include<sstream> 
using namespace std;
using std::string;

class Pelicula
{
	private:
		string titulo,director,genero;
		int valoracion;
		//string peli;
	
	public:
		Pelicula();
		Pelicula(string,string,string,int);
		
		//setters y getters
		void setTitulo(string);
		string getTitulo();
		void setDirector(string);
		string getDirector();
		void setGenero(string);
		string getGenero();
		void setValoracion(int);
		int getValoracion();
		//toString()
		string toString();
		~Pelicula();
	protected:
};

#endif