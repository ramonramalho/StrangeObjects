/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Control.hpp
 * Author: andre
 *
 * Created on May 22, 2016, 4:23 PM
 */

#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <string>
#include <vector>

#include "StrangeObject.hpp"

using namespace std;

class Control {
private:
    static const int REFERENCE = 8;
    string progName;
    vector<StrangeObject *> dataArray;
    
	StrangeObject askForStrangeObjectData();
    
    void compareObjectsWith(StrangeObject value);
    
    void addToObjects(StrangeObject value);
    
    void subtractFromObjects(StrangeObject value);
    
    void multiplyObjectsBy(StrangeObject value);
    
    void setIdentityMatrix();
    
    int showMenu();
   
public:
    Control(string);
    virtual ~Control();
    void start(); 

};

#endif /* CONTROL_HPP */

