/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Info.hpp
 * Author: andre
 *
 * Created on May 22, 2016, 4:36 PM
 */

#ifndef INFO_HPP
#define INFO_HPP

#include <string>

using namespace std;

class Info {
private:
    static const string institution;
    static const string dept;
    static const string author;
    static const string date;
    static const string decoration;

public:
    static const string getInstitution();
    static const string getDept();
    static const string getAuthor();
    static const string getDate();

    static const void wellcome(string message);
    static const void goodbye(void);
};

#endif /* INFO_HPP */

