#include "operation_on_file.h"

void Create_path (string &path, const int question){
    path = "..\\";
    path += to_string(question);
    path += ".csv";
}

void Opening_file (fstream &tmp_file, string const path){
    tmp_file.open(path,ios::in);
    if(!tmp_file.is_open()){
        throw "Nie udało się otworzyć pliku z pytaniami";
    }
}

void Getting_data (fstream &file, string &question,  string anserws[], int &correct_answer){
    srand(time(NULL));
    string tmp_string;
    int id_of_question = rand()%10+1;
    int tmp_id = 0;

    while (tmp_id != id_of_question) {
        getline(file,tmp_string,'\n');
        tmp_string.clear();
        getline(file,tmp_string,';');
        tmp_id = stoi(tmp_string);
    }
    getline(file,question,';');
    getline(file,anserws[0],';');
    getline(file,anserws[1],';');
    getline(file,anserws[2],';');
    getline(file,anserws[3],';');
    getline(file,tmp_string,'\n');
    correct_answer = stoi(tmp_string);
}
