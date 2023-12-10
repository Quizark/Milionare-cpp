#include "lifelines.h"

void call_a_friend(string answers[],int &correct_answer,int &current_question){

    if(current_question<=5){
        cout<<"Moim zdaniem odpowiedź to : "<<to_string(correct_answer)<<endl;
    }
    else{
       srand(time(NULL));
       int ans = rand()%4;
       cout<<"Moim zdaniem odpowiedź to : "<<answers[ans]<<endl;
    }
}

void fifty_fifty(string answers[],int &correct_answer){
   srand(time(NULL));
   int counter = 0;
   int auxiliary = 0;

   while(counter<2){
        int ans = rand()%4;
        if(ans != correct_answer-1){
            if(ans != auxiliary){
                answers[ans] = " ";
                auxiliary = ans;
                counter++;
            }
        }
    }

   for(int counter=0;counter<4;counter++){
       cout << "ODPOWIEDZ "<<counter+1<<": " << answers[counter] << endl;
   }
}

void ask_the_audience(string answers[],int &correct_answer){
    srand(time(NULL));
    int correct = rand()%51+50;
    int tab[4] = {0};
    tab[correct_answer-1] = correct;
    int auxiliary = 100 - correct;

    for(int i=0;i<4;i++){

        if(answers[i] == " "){
            tab[i] = 0;
        }
        else{
            if(i != correct_answer-1 ){
                int n=0;
                n = rand()%auxiliary;
                tab[i] = n;
                auxiliary -= n;
             }
        }
    }
    tab[correct_answer-1] += auxiliary;

    for(int i=0;i<4;i++){
        cout<<answers[i]<<" : "<<tab[i]<<"%"<<endl;
    }
}
