#ifndef OPERATION_ON_FILE_H
#define OPERATION_ON_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>


using namespace std;

void Create_path (string &, const int );

void Opening_file (fstream &, string const);

void Getting_data (fstream &, string &,  string [], int &);



#endif // OPERATION_ON_FILE_H

