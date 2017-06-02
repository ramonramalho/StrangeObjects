/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrangeObject.hpp
 * Author: andre
 *
 * Created on May 22, 2016, 5:12 PM
 */

#ifndef STRANGEOBJECT_HPP
#define STRANGEOBJECT_HPP

#include <string>

using namespace std;

class StrangeObject {
private:
    /**
     * Contador do número de instâncias de StrangeObject existem
     * Este atributo é estático, portanto é compartilhado por todas as
     *  instâncias, pois está ligado à classe StrangeObject
     * Os construtores deverão incrementar 1 a esta variável e o destrutor
     *  deverá decrementar 1
     */
    static int   globalCount;
    
    static int   globalPool;
    int          localID;
    double       dataSet[2][2];
    string       text;
    
public:
    StrangeObject();
    StrangeObject(string, float, float, float, float);
    virtual ~StrangeObject();
    
    int howManyInstances();
    int getLocalID();
    string toString();
    StrangeObject operator=(StrangeObject);
    StrangeObject operator+(StrangeObject);
    StrangeObject& operator+=(const StrangeObject &);
    bool operator <(const StrangeObject&);
    
};

#endif /* STRANGEOBJECT_HPP */

