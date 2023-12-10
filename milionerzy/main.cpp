#include "operation_on_file.h"
#include "lifelines.h"
#include <cmath>
#include <stdlib.h>

#define NUMBER_OF_ANSERWS 4

void game(int current_question,int &call_friend_counter,int &fifty_fifty_counter, int &ask_the_audience_counter, int money []){
    string path;
    string anserws [NUMBER_OF_ANSERWS];
    string question;
    int correct_answer;

    Create_path(path,current_question);

    fstream file;

    try{
        Opening_file(file, path);
    }
    catch (...){
        try {
            Opening_file(file, path);
        }
        catch (string txt) {
            cout << txt << endl;
        }
    }


    Getting_data(file,question,anserws,correct_answer);
    system("cls");

    string tmp_ans;
    int answer;

    do{
        cout << endl<< "PYTANIE " << current_question << ": " <<  question << endl;

        if (call_friend_counter>0){
            cout << " Telefon do przyjacieja -> 9"<<endl;
        }
        if (fifty_fifty_counter>0){
            cout << " 50/50 -> 8" << endl;
        }
        if (ask_the_audience_counter>0){
            cout << " Pytanie do publiczności -> 7\n";
        }
        cout << endl << "Zrezygnuj -> 5"<<endl;
        cout << "\n ODPOWIEDŹ 1: " << anserws[0] << endl;
        cout << " ODPOWIEDŹ 2: " << anserws[1] << endl;
        cout << " ODPOWIEDŹ 3: " << anserws[2] << endl;
        cout << " ODPOWIEDŹ 4: " << anserws[3] << endl;


        cout << "Wprowadź odpowiedź: ";
        cin >> tmp_ans;
        cin.sync();
        if(tmp_ans.find_first_not_of("0123456789")==string::npos){
            answer = stoi(tmp_ans);
        }
        else{
            answer = 0;
        }

        if(answer == 9 && call_friend_counter){
            call_a_friend(anserws,correct_answer,current_question);
            call_friend_counter--;

        }


        if(answer == 8 && fifty_fifty_counter){
            fifty_fifty(anserws,correct_answer);
            fifty_fifty_counter--;

        }


        if(answer == 7 && ask_the_audience_counter){
            ask_the_audience(anserws,correct_answer);
            ask_the_audience_counter--;

        }


    }while(answer < 1 || 5 < answer);


    if(answer == correct_answer&&current_question<15){
        current_question++;
        game(current_question,call_friend_counter,fifty_fifty_counter,ask_the_audience_counter,money);
    }
    else if(answer == correct_answer&&current_question==15) {
        cout << endl << "WYGRAŁEŚ MILION ZŁOTYCH!" << endl;
    }
    else if(answer == 5){
        cout << "Wyszedłeś z gry mając " << money[current_question-1] << endl;

    }
    else{

        cout << endl << "Przegrałeś!" << endl;

        if(current_question > 5){
            cout << "Twoja wygrana to " << money[5] << endl;
        }
        else if(current_question > 10){
            cout << "Twoja wygrana to " << money[10] << endl;
        }
    }

}

int main()
{
    int money [] = {100,200,300,500,1000,2000,4000,8000,16000,32000,64000,125000,250000,500000,1000000};

    SetConsoleOutputCP( 65001 );

    int current_question = 1;
    static int call_friend_counter = 1;
    static int fifty_fifty_counter = 1;
    static int ask_the_audience_counter = 1;

    game(current_question,call_friend_counter,fifty_fifty_counter,ask_the_audience_counter,money);



    return 0;
}
