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
  // TODO
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
  // TODO
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

   buffer = dataArray.at(REFERENCE / 2);
   
   cout << decorator << endl;
   cout << endl;
    
   this->compareObjectsWith(*buffer);

   cout << decorator << endl;
   cout << endl;
   cout << " Modifying objects..." << endl << endl;

   buffer = new StrangeObject("Strange Ref", 2.0f, 2.0f, 2.0f, 2.0f);
   cout << "Ref: " << buffer->toString() << endl << endl;

   for(int count = dataArray.size() - 1 ; count >= 0; --count)
   {
      
      (*dataArray[count]) = ((*dataArray[count]) + (*buffer));
      cout << "Modified: " << dataArray[count]->toString() << endl;
   }
   cout << decorator << endl;
   cout << endl;
   delete buffer;
 }
