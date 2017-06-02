/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on May 22, 2016, 4:11 PM
 */

#include <cstdlib>
#include "Info.hpp"
#include "Control.hpp"

using namespace std;

int main(int argc, char** argv) {
    // Creates an object that take care of all actions
    Control * program = new Control(argv[0]);
    // Puts a welcome message 
    Info::wellcome(argv[0]);
    // Transfers the control to OOP domain
    program->start();
    // Cleans up stuffs
    delete program;
    program = NULL;
    // Puts a goodbye message 
    Info::goodbye();
    // Finishes the program
    return 0;
}

