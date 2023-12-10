#include "lifelines.h"

void call_a_friend(string answers[],int &correct_answer,int &current_question){
    if(current_question==5){
        cout<<"Moim zdaniem odpowiedź to : "<<to_string(correct_answer)<<endl;
    }
    else{
       srand(time(NULL));
       int odp = rand()%4;
       cout<<"Moim zdaniem odpowiedź to : "<<answers[odp]<<endl;
    }
}

void fifty_fifty(string answers[],int &correct_answer){
   srand(time(NULL));
   int i=0;
   int pom=0;

   while(i<2){
        int odp = rand()%4;
        if(odp != correct_answer-1){
            if(odp != pom){
                answers[odp] = " ";
                pom=odp;
                i++;
            }
        }
    }
}

void ask_the_audience(string answers[],int &correct_answer){
    srand(time(NULL));
    int correct = rand()%51+50;
    int tab[4]={0};
    tab[correct_answer-1] = correct;
    int pom = 100 - correct;

    for(int i=0;i<4;i++){
        if(i != correct_answer-1){
                int n=0;
                n= rand()%pom;
                tab[i] = n;
                pom-=n;
        }
    }
    tab[rand()%4]+=pom;

    for(int i=0;i<4;i++){
        cout<<answers[i]<<" : "<<tab[i]<<"%"<<endl;
    }

}
