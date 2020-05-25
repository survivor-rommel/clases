#include<iostream>
#include<sstream> 
#include<string.h>
using namespace std;



class Curso{
	private:
		int nroAlumnos;
		string nombre;
		string codigo;
		
	public:
		Curso();
		Curso(string , string , int);
		string getCodigo();
		string getNombre();
		int getNroAlumnos();
		void setNombre(string);
		void setCodigo(string );
		void setNroAlumnos(int);
		string toString();
};

 
 

Curso::Curso(){
	nombre = "o";
	codigo = "o";
	nroAlumnos = 0;
}
Curso::Curso(string _nombre , string _codigo ,int _nroalumnos){
	nombre = _nombre;
	codigo = _codigo;
	nroAlumnos = _nroalumnos;
	
}
void Curso::setCodigo(string _codigo){
	codigo = _codigo;
}
void Curso::setNombre(string _nombre){
	nombre = _nombre;
}
void Curso::setNroAlumnos(int _nroAlumnos){
	nroAlumnos = _nroAlumnos;
}
string Curso::getNombre(){
	return nombre;
}
string Curso::getCodigo(){
	return codigo;
}
int Curso::getNroAlumnos(){
	return nroAlumnos;
}
string Curso::toString(){
	stringstream s;
	s<<"nombre : "<<nombre<<endl;
	s<<"codigo : "<<codigo<<endl;
	s<<"nroalumnos : "<<nroAlumnos<<endl;
	return s.str();
}



class ArregloDeCursos{
	private:
	Curso *cursos = NULL;
	int tam;
	public:
		int cantidad ;
		ArregloDeCursos();
		ArregloDeCursos(Curso *,int);
		~ArregloDeCursos();
		ArregloDeCursos(ArregloDeCursos &); 
		void redimensionar(int n);
		void push_back(Curso &);
		void insert(int ,Curso &);
		void remove(int pos);
		int getSize();
		void clear();
		string mostrar();
};
// un constructor simple
ArregloDeCursos::ArregloDeCursos(){
	cantidad = 0;
}
// constructor con parametros 
ArregloDeCursos::ArregloDeCursos(Curso *cursitos , int tama){
	tam = tama;
	cursitos = new Curso[tam];
	cursos  = cursitos;
}


ArregloDeCursos::ArregloDeCursos(ArregloDeCursos &C){
	tam = C.tam;  
	cursos = C.cursos; //cursos (puntero)es la variable private ;
	cursos = new Curso[tam];
}
// DESTRUCTOR
ArregloDeCursos::~ArregloDeCursos(){
}

// metodo pushback - > PARA EL INGRESO DE ELEMENTOS 
void ArregloDeCursos::push_back(Curso &p){
		
	if(cantidad < tam){
		cursos[cantidad++] = p;
	}
	
}
// metodos para mostrar el contenido del arreglo 
string ArregloDeCursos::mostrar(){
	stringstream s;   
	for(int i = 0 ; i < cantidad; i ++){
		s<<cursos[i].toString()<<endl;
	}
	return s.str();
}



// metodo para redimimensionar el arreglo
void ArregloDeCursos::redimensionar(int num ){
	Curso*aux=new Curso[tam];
	for(int i=0;i<tam;i++)
		*(aux++)=*(cursos++);
	delete [] cursos;
	tam=tam+num;
	cursos=new Curso[tam];
	for(int i=0;i<tam;i++)
		*(cursos++)=*(aux++);
	delete [] aux;
}
// metodo para eliminar los elementos del arreglo 
void ArregloDeCursos::clear(){
	
	delete[] cursos;
	cout<<"\n\nSe eliminaron los elementos del arreglo\n";
}
// obtener el tamaño del arreglo
int ArregloDeCursos::getSize(){
	return  cantidad;
}

// insertar elemento en una posicion determinada
void ArregloDeCursos::insert( int pos, Curso &p){
	this->redimensionar(1);
	for(int i=tam-1;i>pos;i--)
		*(cursos+i)=*(cursos+i-1);
	*(cursos+pos)=p;
}
// eliminar elemento en una posicion determinada
void ArregloDeCursos::remove(const int pos){
	for(int i=pos;i<tam-1;i++)
		*(cursos+i)=*(cursos+i+1);
	this->redimensionar(-1);
}
int main(){
	Curso *punt;
	ArregloDeCursos a1(punt,6);
	Curso a("percio","4542",3);
	Curso b("grecia","4585",4);
	Curso c("geremy","15616",5);

	a1.push_back(a);
	a1.push_back(a);
	a1.push_back(b);
	a1.push_back(c);
	a1.push_back(b);

	cout<<a1.mostrar()<<endl;
	
	cout<<a1.getSize()<<endl;
	a1.push_back(a);
	
	cout<<a1.getSize();
	a1.push_back(a);
	
	//a1.clear();
	
	
	
	
	/*
	Curso a;
	cout<<a.getNroAlumnos()<<endl;
	cout<<a.getCodigo()<<endl;
	cout<<a.getNombre()<<endl;
	cout<<"\n\n";
	Curso b("Pedro","457895",2);
	cout<<b.getNroAlumnos()<<endl;
	cout<<b.getCodigo()<<endl;
	cout<<b.getNombre()<<endl;
	cout<<"\n\n";
	Curso c;
	c.setCodigo("564652");
	c.setNombre("Calvito");
	c.setNroAlumnos(2);
	cout<<c.getNroAlumnos()<<endl;
	cout<<c.getCodigo()<<endl;
	cout<<c.getNombre()<<endl;
	*/
	
	return 0;
}
