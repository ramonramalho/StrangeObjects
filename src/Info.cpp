/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Info.cpp
 * Author: andre
 * 
 * Created on May 22, 2016, 4:36 PM
 */

#include <iostream>
#include "Info.hpp"

using namespace std;

const string Info::institution = "Unicamp - Universidade Estadual de Campinas";
const string Info::dept = "FT - Faculdade de Tecnologia";
const string Info::author = "Prof. Dr. Andre F. de Angelis";
const string Info::date = "Mai/2016";

const string Info::decoration = "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

const string Info::getInstitution()
   {
   return (institution);
   };

const string Info::getDept()
   {
   return (dept);
   };

const string Info::getAuthor()
   {
   return (author);
   };

const string Info::getDate()
   {
   return (date);
   };

const void Info::wellcome(string message)
   {
   cout << decoration;
   cout << Info::getInstitution() << "\n" << Info::getDept() << endl;
   cout << Info::getAuthor() << "\n" << Info::getDate() << endl;
   cout << decoration;
   cout << message << endl;
   };

const void Info::goodbye()
   {
   cout << decoration;
   cout << "Mission accomplished! \n";
   cout << decoration;
   cout << "\n\n" << endl;
   };

