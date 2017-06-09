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
void Control::compareObjectsWith(StrangeObject& value){
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
void Control::addToObjects(StrangeObject& value){
  cout << " Modifying objects..." << endl << endl;
  cout << "Ref: " << value << endl << endl;
  
  for(int count = dataArray.size() - 1 ; count >= 0; --count)
  {
     (*dataArray[count]) = ((*dataArray[count]) + (value));
     cout << "Modified: " << dataArray[count]->toString() << endl;
  }
}

// Somar um objeto de todos os objetos na classe
void Control::subtractFromObjects(StrangeObject& value){
  // TODO
}

// Multiplicar os objetos por um outro objeto
void Control::multiplyObjectsBy(StrangeObject& value){
  // TODO
}

// Definir um determinado objeto como matriz identidade
void Control::setIdentityMatrix(int objectIndex){
  dataArray.at(objectIndex)->setIdentityMatrix();
}

// Mostrar menu com escolhas de ações
// @return int Número da opção escolhida
int Control::showMenu(){
  int option = 0;
  
  cout
  << " ========================================" << endl
  << "   Escolha uma opcao dentre as seguintes" << endl << endl
  << " 0. Sair" << endl
  << " 1. Comparar objetos" << endl
  << " 2. Somar os objetos" << endl
  << " 3. Subtrair dos objetos" << endl
  << " 4. Multiplicar os objetos" << endl
  << " 5. Definir matriz como matriz identidade" << endl
  << " > ";
  
  cin >> option;
  
  cout
  << " ========================================" << endl;
  
  return option;
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

   buffer = new StrangeObject("Strange Ref", 2.0f, 2.0f, 2.0f, 2.0f);
   
   int opcao = 0;
   do{
     opcao = this->showMenu();
     
     switch(opcao){
       case 1:
         this->compareObjectsWith(*buffer);
         break;
       case 2:
         this->addToObjects(*buffer);
         break;
       case 3:
         this->subtractFromObjects(*buffer);
         break;
       case 4:
         this->multiplyObjectsBy(*buffer);
         break;
       case 5:
         this->setIdentityMatrix(0);
         break;
     }
     
     cout << decorator << endl;
     cout << endl;
   }
   while(opcao != 0);
   
   
   delete buffer;
 }
