#include "Pelicula.h"

Pelicula::Pelicula()
{
}

Pelicula::Pelicula(string _titulo, string _director, string _genero, int _valoracion){
	this->titulo = _titulo;
	this->director = _director;
	this->genero = _genero;
	this->valoracion = _valoracion;	
}

Pelicula::~Pelicula()
{
}

//Setters y getters
void Pelicula::setTitulo(string title){
	this->titulo = title;
}

string Pelicula::getTitulo(){
	return titulo;
}

void Pelicula::setDirector(string direc){
	this->director = direc;
}

string Pelicula::getDirector(){
	return director;
}

void Pelicula::setGenero(string gender){
	this->genero = gender;
}

string Pelicula::getGenero(){
	return genero;
}

void Pelicula::setValoracion(int val){
	this->valoracion = val;
}

int Pelicula::getValoracion(){
	return valoracion;
}

//toString() de peliculas
string Pelicula::toString(){
	ostringstream out;
	out<<valoracion;
	return titulo+" - "+director+" - "+genero+" - "+out.str();
}

