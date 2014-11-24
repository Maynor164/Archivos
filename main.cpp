#include <iostream>
#include <fstream>

using namespace std;

void escribirNumeros(string nombre_archivo, int cant)
{
    //Convertir string en char apuntador
    ofstream out(nombre_archivo.c_str());
    for(int i=0; i < cant; i ++)
        {
         int num;
         cout<<"Ingrese un numero: ";
         cin>>num;
         out.write((char*)&num,4);
        }
}

int getMayor(string nombre_archivo)
{

    ifstream in(nombre_archivo.c_str());
    //seek para buscar el final y el principio.
    in.seekg(0,ios::end);
    //tellg para saber el espacio donde estamos del archivo(bits).
    int tamano = in.tellg();
    in.seekg(0,ios::beg);

    int mayor = -999;
    while(in.tellg()<tamano)
        {
         int num;
         in.read((char*)&num,4);

            if(mayor<num)
            mayor=num;
        }
        return mayor;

}
void imprimir(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int cant = in.tellg()/4;
    in.seekg(0);
    for(int i=0;i<cant;i++)
        {
            int num;
            in.read((char*)&num,4);
            cout<<num<<endl;
        }
        in.close();
}

void escribirNumero(string nombre_archivo, int num, int pos)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(pos*4);
    out.write((char*)&num,4);
    out.close();
}

int main()
{

    escribirNumeros("archivo",4);
    escribirNumero("archivo",10,2);
    imprimir("archivo");
    cout<<"Maestro el numero mayor es: "<<getMayor("archivo");
    return 0;
/*
//Creando archivos con caracteres binarios
    ofstream out("archivo");
    int *num = new int(100);
//Convertir de int a char apuntador.
    out.write((char*)num,4);
    *num = 200;
    out.write((char*)num,4);
    out.close();

    ifstream in("archivo");
    int *leido = new int(0);
    in.read((char*)leido,4);
    cout<<"He leido todo amo:  "<<*leido<<endl;
    in.read((char*)leido,4);
    cout<<"A disculpe faltaba esto amo:  "<<*leido<<endl;
    return 0;


/*
    ifstream mi_archivo("archivos");
//Lee en el programa todo lo que esta en el texto
    int num;
    while(mi_archivo>>num)
        {
            cout<<num<<endl;
        }

return 0;*/





/*
//Leer archivos
    ifstream in("archivos");
    string str;
//Leer las lineas del archivo
    getline(in,str);
    cout<<str<<endl;

    getline(in,str);
    cout<<str<<endl;

    getline(in,str);
    cout<<str<<endl;

    getline(in,str);
    cout<<str<<endl;

    getline(in,str);
    cout<<str<<endl;

    getline(in,str);
    cout<<str<<endl;
    return 0;*/

    /*
//Crear el archivo
    ofstream out("archivos");
//COn varios tipos de variables
    out<<10<<endl;
    out<<10.5<<endl;
    out<<'a'<<endl;
    out<<true<<endl;
    out<<"bitches"<<endl;
    out.close();

    ifstream in("archivos");
    int a;
    double b;
    char c;
    bool d;
    string e;
    in>>a;
    in>>b;
    in>>c;
    in>>d;
    in>>e;
    cout<<a<<endl;
    cout<<b*3<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
    return 0;*/

/*
//Escribir en el archivo
    out << "Hello world!" << endl;
    out << "Hola mundo!" << endl;
//Cerrar el archivo
    out.close();
//Leer el archivo en el programa
    ifstream in("archivo");
    string str;
    in>>str;
    cout<<"Lectura 1:"<<str<<endl;
    in>>str;
    cout<<"Lectura 2:"<<str<<endl;
    in>>str;
    cout<<"Lectura 3:"<<str<<endl;
    in>>str;
    cout<<"Lectura 4:"<<str<<endl;
    return 0;*/
}
