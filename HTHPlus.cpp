#include "HTHPlus.h"

HTHPlus::HTHPlus()
{
}

HTHPlus::~HTHPlus()
{
	//delete peliculas;
}

void HTHPlus::addPelicula(Pelicula* peli){
	peliculas.push_back(peli);
}

void HTHPlus::imprimirPorGenero(string gend){
	int cont = 0;
	for(int i=0; i<peliculas.size(); i++){
		
		if(peliculas[i]->getGenero().find(gend)!=string::npos){
			//cout<<"Entre"<<endl;
			if(cont==0){
				cout<<gend<<": "<<endl;
				cont++;
			}
			cout<<"     "<<peliculas[i]->getTitulo()<<" - "<<peliculas[i]->getDirector()<<" - "<<peliculas[i]->getValoracion()<<endl;
			//break;
		}
	}
}

vector<Pelicula*> HTHPlus::getPeliculas(){//me retorna el arraylist, el vector que contiene las peliculas
	return peliculas;
}

void HTHPlus::listarPeliculas(){
	for(int i=0; i<peliculas.size(); i++){
		cout<<peliculas[i]->toString()<<endl;	
	}
}

void HTHPlus::buscarPelicula(string frase){
	int aux = 0, aux2=0;
	bool correct=false;
	string help="";
	for(int i=0; i<peliculas.size(); i++){
		if(frase[aux]==peliculas[aux2]->getTitulo()[aux2]){
			help+=peliculas[aux2]->getTitulo()[aux2];
			aux++;
			aux2=i+1;
		}
		else{
			aux2++;
		}
		
		if(frase.find(help)!=string::npos){
			cout<<peliculas[i]->toString()<<endl;
			correct=true;
		}
		
	}
	if(correct==false){
		cout<<"No se encontro nada "<<endl;
	}
}

void HTHPlus::ordenarPeliculas(){
	for(int i=0; i<peliculas.size(); i++){
		auxiliar.push_back(peliculas[i]->getValoracion());
	}
	
	int temp=0;
	for(int i=0; i<peliculas.size()-1; i++){
		for(int j=0; j<peliculas.size()-1; j++){
			if(auxiliar[j]<auxiliar[j+1]){
				temp = auxiliar[j];
				auxiliar[j]=auxiliar[j+1];
				auxiliar[j+1]=temp;
			}
		}
	}
	
	for(int i=0; i<peliculas.size(); i++){
		for(int j=0; j<peliculas.size(); j++){
			if(auxiliar[i]==peliculas[j]->getValoracion()){
				cout<<peliculas[j]->toString()<<endl;
			}
		}
	}
	auxiliar.clear();
}

void HTHPlus::modificarVector(int pos, int posarray, string nuevo){
	switch(pos){
		case 1:{
			peliculas[posarray]->setTitulo(nuevo);
			break;
		}
		case 2:{
			peliculas[posarray]->setDirector(nuevo);
			break;
		}
		case 3:{
			peliculas[posarray]->setGenero(nuevo);
			break;
		}
		case 4:{
			peliculas[posarray]->setValoracion(random());
			break;
		}	
	}

}

int HTHPlus::random(){
	srand(time(NULL));
	return 1+rand()%(5);
}