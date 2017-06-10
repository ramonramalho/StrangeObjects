/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Control.cpp
 * Author: andre
 *
 * Created on May 22, 2016, 4:23 PM
 */

#include <iostream>
#include <string>
#include <cstdio>
#include "Control.hpp"

#include <stdexcept>

using namespace std;

Control::Control(string progName)
   {
   this->progName = progName;
   }

Control::~Control()
   {
   vector<StrangeObject *>::iterator scam = dataArray.begin();
   while(scam != dataArray.end())
      {
      cout << "Cleaning dataArray. " << (*scam)->howManyInstances() << " instances left." <<endl;
      delete (*scam);
      (*scam) = NULL;
      scam++;
      }

   dataArray.clear();
   }


// Comparar os objetos com um outro objeto
void Control::compareObjectsWith(StrangeObject value){
   cout << " Comparing all objects against " << value << endl << endl;

    for(int count = 0; count < dataArray.size(); count++)
    {
        if(value < *dataArray[count])
        {
        cout << "              " << value << endl
             << " is less than " << (*dataArray[count]) << endl;
        }
        else if(value > *dataArray[count]){
        cout << "                 " << value << endl
             << " is greater than " << (*dataArray[count]) << endl;
        }
        else if(value == *dataArray[count]){
        cout << "             " << value << endl
             << " is equal to " << (*dataArray[count]) << endl;
        }
    }
}

// Somar um objeto de todos os objetos na classe
void Control::addToObjects(StrangeObject value){
  cout << " Modifying objects..." << endl << endl;
  cout << "Ref: " << value << endl << endl;
  
  for(int count = dataArray.size() - 1 ; count >= 0; --count)
  {
     (*dataArray[count]) += (value);
     cout << "Modified: " << *dataArray[count] << endl;
  }
}

// Somar um objeto de todos os objetos na classe
void Control::subtractFromObjects(StrangeObject value){
  cout << " Modifying objects..." << endl << endl;
  cout << "Ref: " << value << endl << endl;
  
  for(int count = dataArray.size() - 1 ; count >= 0; --count)
  {
     (*dataArray[count]) -= value;
     cout << "Modified: " << *dataArray[count] << endl;
  }
}

// Multiplicar os objetos por um outro objeto
void Control::multiplyObjectsBy(StrangeObject value){
  cout << " Modifying objects..." << endl << endl;
  cout << "Ref: " << value << endl << endl;
  
  for(int count = dataArray.size() - 1 ; count >= 0; --count)
  {
     (*dataArray[count]) *= value;
     cout << "Modified: " << *dataArray[count] << endl;
  }
}

// Definir um determinado objeto como matriz identidade
void Control::setIdentityMatrix(){
  int objectIndex = 0;
  cout << "  Escolha o indice do objeto a ser definido como matriz identidade: ";
  cin >> objectIndex;
  try{
    dataArray.at(objectIndex)->setIdentityMatrix();
    
    cout << endl << "Modified: " << *dataArray.at(objectIndex) << endl;
  }
  catch(out_of_range e){
    cout << endl << "  Indice invalido" << endl;
  }
}

void Control::printAllObjects(){
   cout << endl;
   for(int i = 0; i < dataArray.size(); i++)
   {
      cout << " " << *dataArray.at(i)<< endl;
   }
}

// Mostrar menu com escolhas de ações
// @return int Número da opção escolhida
int Control::showMenu(){
  int option = 0;
  
  cout
  << " =============================================" << endl
  << "    Escolha uma opcao dentre as seguintes" << endl << endl
  << " 0. Sair" << endl
  << " 1. Comparar todos os objetos com outro" << endl
  << " 2. Somar todos os objetos com outro" << endl
  << " 3. Subtrair um objeto de todos objetos" << endl
  << " 4. Multiplicar todos os objetos por um outro" << endl
  << " 5. Definir um objeto com a matriz identidade" << endl
  << " 6. Somar dois objetos" << endl
  << " 7. Subtrair dois objetos" << endl
  << " 8. Multiplicar dois objetos" << endl
  << " 9. Comparar dois objetos" << endl
  << " 10. Imprimir todos os objetos" << endl
  << " > ";
  
  cin >> option;
  
  cout
  << " =============================================" << endl;
  
  return option;
}

StrangeObject Control::askForStrangeObjectData(string mensagem){
	string text;
	int a=0, b=0, c=0, d=0;
	
	cout
	<< endl << "  " << mensagem << endl << endl
	<< "   Texto: ";
	cin >> text;
	
	cout << "   Valor 00: ";
	cin >> a;
	
	cout << "   Valor 01: ";
	cin >> b;
	
	cout << "   Valor 10: ";
	cin >> c;
	
	cout << "   Valor 11: ";
	cin >> d;
	cout << endl;
	
	return StrangeObject(text, a, b, c, d);
}

void Control::sumTwoObjects(){
	int indiceA = 0, indiceB = 0;
	cout << "  Indice do primeiro objeto: ";
	cin >> indiceA;
	cout << "  Indice do segundo objeto: ";
	cin >> indiceB;
	
	StrangeObject a, b;
	
	try{
		a = *dataArray.at(indiceA);
		b = *dataArray.at(indiceB);
	}
	catch(out_of_range e){
		cout << endl << "  Algum dos objetos nao foi encontrado" << endl;
	}
	
	StrangeObject sum = a+b;
	
	cout << "   Soma: " << endl << "  " << sum << endl;
}

void Control::subtractTwoObjects(){
	int indiceA = 0, indiceB = 0;
	cout << "  Indice do primeiro objeto: ";
	cin >> indiceA;
	cout << "  Indice do segundo objeto: ";
	cin >> indiceB;
	
	StrangeObject a, b;
	
	try{
		a = *dataArray.at(indiceA);
		b = *dataArray.at(indiceB);
	}
	catch(out_of_range e){
		cout << endl << "  Algum dos objetos nao foi encontrado" << endl;
	}
	
	StrangeObject diff = a-b;
	
	cout << "   Diferenca: " << "  " << diff << endl;
}

void Control::multiplyTwoObjects(){
	int indiceA = 0, indiceB = 0;
	cout << "  Indice do primeiro objeto: ";
	cin >> indiceA;
	cout << "  Indice do segundo objeto: ";
	cin >> indiceB;
	
	StrangeObject a, b;
	
	try{
		a = *dataArray.at(indiceA);
		b = *dataArray.at(indiceB);
	}
	catch(out_of_range e){
		cout << endl << "  Algum dos objetos nao foi encontrado" << endl;
	}
	
	StrangeObject mul = a-b;
	
	cout << "   Produto: " << "  " << mul << endl;
}


void Control::compareTwoObjects(){
	int indiceA = 0, indiceB = 0;
	cout << "  Indice do primeiro objeto: ";
	cin >> indiceA;
	cout << "  Indice do segundo objeto: ";
	cin >> indiceB;
	
	StrangeObject a, b;
	
	try{
		a = *dataArray.at(indiceA);
		b = *dataArray.at(indiceB);
	}
	catch(out_of_range e){
		cout << endl << "  Algum dos objetos nao foi encontrado" << endl;
	}
	
	if(a < b)
	{
	cout << "              " << a << endl
		 << " is less than " << b << endl;
	}
	else if(a > b){
	cout << "                 " << a << endl
		 << " is greater than " << b << endl;
	}
	else if(a == b){
	cout << "             " << a << endl
		 << " is equal to " << b << endl;
	}
	else if(a <= b){
	cout << "                     " << a << endl
		 << " is less or equal to " << b << endl;
	}
	else if(a >= b){
	cout << "                       " << a << endl
		 << " is bigger or equal to " << b << endl;
	}
}

void Control::start()
   {
   StrangeObject * buffer;
   string decorator = "________________________________________________________________________________";
   char uniqueId[12];

   cout << decorator << endl << endl;
   cout << "  Starting program \""<< progName << "\"" << endl;
   cout << decorator << endl;
   cout << endl;
   cout << " Creating objects..." << endl << endl;

   for(int count = 0; count < REFERENCE; count++)
   {
      sprintf(uniqueId, "%i", count);
      buffer = new StrangeObject("StrangeObj " + string(uniqueId), count, count*2, count*3, count*4);
      dataArray.push_back(buffer);
      cout << "Created: " << buffer->toString() << endl;
   }
   
   int opcao = 0;
   do{
     opcao = this->showMenu();
     
     switch(opcao){
       case 1:
		 cout << "  Comparar todos os objetos com outro" << endl;
         this->compareObjectsWith(
			this->askForStrangeObjectData("Digite os dados de um StrangeObject para comparar com os outros")
		 );
         break;
       case 2:
		 cout << "  Somar todos os objetos com outro" << endl;
         this->addToObjects(
			this->askForStrangeObjectData("Digite os dados de um StrangeObject para somar aos outros")
		 );
         break;
       case 3:
		 cout << "  Subtrair um objeto de todos os objetos" << endl;
         this->subtractFromObjects(
			this->askForStrangeObjectData("Digite os dados de um StrangeObject para subtrair dos outros")
		 );
         break;
       case 4:
		 cout << "  Multiplicar todos os objetos por outro" << endl;
         this->multiplyObjectsBy(
			this->askForStrangeObjectData("Digite os dados de um StrangeObject para multiplicar os outros")
		 );
         break;
       case 5:
		 cout << "  Definir um objeto com matriz identidade" << endl;
         this->setIdentityMatrix();
         break;
	   case 6:
		 cout << "  Somar dois objetos" << endl;
		 this->sumTwoObjects();;
         break;
	   case 7:
		 cout << "  Subtrair dois objetos" << endl;
		 this->subtractTwoObjects();
         break;
	   case 8:
		 cout << "  Multiplicar dois objetos" << endl;
		 this->multiplyTwoObjects();
         break;
	   case 9:
		 cout << "  Comparar dois objetos" << endl;
		 this->compareTwoObjects();
         break;
	   case 10:
		 cout << "  Imprimir todos os objetos" << endl;
		 this->printAllObjects();
         break;
     }
     
     cout << decorator << endl;
     cout << endl;
   }
   while(opcao != 0);
   
 }
