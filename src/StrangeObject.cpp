/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   StrangeObject.cpp
 * Author: andre
 *
 * Created on May 22, 2016, 5:12 PM
 */

#include <sstream>
#include <iomanip>
#include "StrangeObject.hpp"
#include "Info.hpp"

using namespace std;

int StrangeObject::globalCount = 0;
int StrangeObject::globalPool = 0;

StrangeObject::StrangeObject() {
    // Incrementar o contador de instâncias estático, que é compartilhado por
    //  todas as instâncias de StrangeObject
    globalCount++;

    this->localID = globalPool++;
    this->text = Info::getInstitution();
    this->dataSet[0][0] = 0.0f;
    this->dataSet[0][1] = 0.0f;
    this->dataSet[1][0] = 0.0f;
    this->dataSet[1][1] = 0.0f;
}

/**
 *	Construtor de copia
 */
StrangeObject::StrangeObject(const StrangeObject& clone){
	 // Incrementar o contador de instâncias estático, que é compartilhado por
    //  todas as instâncias de StrangeObject
    globalCount++;

    this->localID = clone.localID;
    this->text = clone.text;
    this->dataSet[0][0] = clone.dataSet[0][0];
    this->dataSet[0][1] = clone.dataSet[0][1];
    this->dataSet[1][0] = clone.dataSet[1][0];
    this->dataSet[1][1] = clone.dataSet[1][1];
}

/**
 *	Construtor de movimentação (compila apenas com C++11) -std=c++11
 *
 *  A diferença para o construtor de cópia é que nesse caso o StrangeObject passado
 *  por referência é copiado para o atual e é alterado para os valores padrão
 */
StrangeObject::StrangeObject(StrangeObject&& move){

  	this->localID = move.localID;
  	this->text = move.text;
  	this->dataSet[0][0] = move.dataSet[0][0];
    this->dataSet[0][1] = move.dataSet[0][1];
    this->dataSet[1][0] = move.dataSet[1][0];
    this->dataSet[1][1] = move.dataSet[1][1];

    move.localID = 0;
    move.text = "";
    move.dataSet[0][0] = 0.0f;
    move.dataSet[0][1] = 0.0f;
    move.dataSet[1][0] = 0.0f;
    move.dataSet[1][1] = 0.0f;
}

StrangeObject::StrangeObject(string text, float e00, float e01, float e10, float e11) {
    // Incrementar o contador de instâncias estático, que é compartilhado por
    //  todas as instâncias de StrangeObject
    globalCount++;

    this->localID = globalPool++;
    this->text = text;
    this->dataSet[0][0] = e00;
    this->dataSet[0][1] = e01;
    this->dataSet[1][0] = e10;
    this->dataSet[1][1] = e11;
}

StrangeObject::~StrangeObject() {
    // Decrementar o contador de instâncias estático, que é compartilhado por
    //  todas as instâncias de StrangeObject
    globalCount--;

    this->localID = 0;
    this->text = "";
    this->dataSet[0][0] = 0.0f;
    this->dataSet[0][1] = 0.0f;
    this->dataSet[1][0] = 0.0f;
    this->dataSet[1][1] = 0.0f;
}

/**
 *Cria a matriz identidade em dataset
 *
 */
void StrangeObject::setIdentityMatrix(){
    this->dataSet[0][0] = 1.0f;
    this->dataSet[0][1] = 0.0f;
    this->dataSet[1][0] = 0.0f;
    this->dataSet[1][1] = 1.0f;
}

/**
 * Retornar o contador de instâncias estático, que é compartilhado por
 *  todas as instâncias de StrangeObject
 * @return int Número de instâncias de StrangeObject alocados na memória
 */
int StrangeObject::howManyInstances() {
    // Retornar o contador de instâncias que é compartilhado por todas as
    // instâncias
    return (globalCount);
}

int StrangeObject::getLocalID() {
    return (localID);
}

string StrangeObject::toString() {
    stringstream buffer;
    buffer << "Strange Object #" << this->localID << ". (" << globalCount << " instance(s)).";
    buffer << " { " << setprecision(3) << fixed << dataSet[0][0] << ", " << dataSet[0][1] << ", " << dataSet[1][0] << ", " << dataSet[1][1] << " } ";
    buffer << "[" << text << "]";
    return (buffer.str());
}

StrangeObject StrangeObject::operator=(const StrangeObject value) {
    this->text = value.text;
    this->dataSet[0][0] = value.dataSet[0][0];
    this->dataSet[0][1] = value.dataSet[0][1];
    this->dataSet[1][0] = value.dataSet[1][0];
    this->dataSet[1][1] = value.dataSet[1][1];
    return (*this);
}

StrangeObject& StrangeObject::operator+=(const StrangeObject& value) {
    this->text += "; " + value.text;
    this->dataSet[0][0] += value.dataSet[0][0];
    this->dataSet[0][1] += value.dataSet[0][1];
    this->dataSet[1][0] += value.dataSet[1][0];
    this->dataSet[1][1] += value.dataSet[1][1];

    return (*this);
}

StrangeObject StrangeObject::operator+(StrangeObject value) {
    StrangeObject buffer;
    buffer.text = this->text + "; " + value.text;
    buffer.dataSet[0][0] = this->dataSet[0][0] + value.dataSet[0][0];
    buffer.dataSet[0][1] = this->dataSet[0][1] + value.dataSet[0][1];
    buffer.dataSet[1][0] = this->dataSet[1][0] + value.dataSet[1][0];
    buffer.dataSet[1][1] = this->dataSet[1][1] + value.dataSet[1][1];
    return (buffer);
}

bool StrangeObject::operator<(const StrangeObject& value) {
    return (this->localID < value.localID);
}

StrangeObject StrangeObject::operator-(StrangeObject value) {
    StrangeObject buffer;
    buffer.text = this->text + "; " + value.text;
    buffer.dataSet[0][0] = this->dataSet[0][0] - value.dataSet[0][0];
    buffer.dataSet[0][1] = this->dataSet[0][1] - value.dataSet[0][1];
    buffer.dataSet[1][0] = this->dataSet[1][0] - value.dataSet[1][0];
    buffer.dataSet[1][1] = this->dataSet[1][1] - value.dataSet[1][1];
    return (buffer);
}

StrangeObject StrangeObject::operator*(StrangeObject value) {
    StrangeObject buffer;
    buffer.text = this->text + "; " + value.text;
    buffer.dataSet[0][0] = this->dataSet[0][0]*value.dataSet[0][0] + this->dataSet[0][1]*value.dataSet[1][0];
    buffer.dataSet[0][1] = this->dataSet[0][0]*value.dataSet[0][1] + this->dataSet[0][1]*value.dataSet[1][1];
    buffer.dataSet[1][0] = this->dataSet[1][0]*value.dataSet[0][0] + this->dataSet[1][1]*value.dataSet[1][0];
    buffer.dataSet[1][1] = this->dataSet[1][0]*value.dataSet[0][1] + this->dataSet[1][1]*value.dataSet[1][1];
    return (buffer);
}

bool StrangeObject::operator==(const StrangeObject& value) {
    return (this->localID == value.localID);
}

bool StrangeObject::operator!=(const StrangeObject& value) {
    return (this->localID != value.localID);
}

bool StrangeObject::operator>(const StrangeObject& value) {
    return (this->localID > value.localID);
}

bool StrangeObject::operator>=(const StrangeObject& value) {
    return (this->localID >= value.localID);
}

bool StrangeObject::operator<=(const StrangeObject& value) {
    return (this->localID <= value.localID);
}

StrangeObject& StrangeObject::operator-=(const StrangeObject& value) {
    this->text += "; " + value.text;
    this->dataSet[0][0] -= value.dataSet[0][0];
    this->dataSet[0][1] -= value.dataSet[0][1];
    this->dataSet[1][0] -= value.dataSet[1][0];
    this->dataSet[1][1] -= value.dataSet[1][1];

    return (*this);
}

StrangeObject& StrangeObject::operator*=(const StrangeObject& value) {
    this->text += "; " + value.text;
    
    (*this) = (*this) * value;
    
    return (*this);
}


