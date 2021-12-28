#include <iostream>
#include <iomanip>
#include <conio.h>
#define clrscr() system("cls");

using namespace std;

class Result{
    private:
        int size,cho,mx,del;
        float *marks;
        float total, average;

    public:
        Result(){                //constructor
            cout<<"\n\n*******************************************************************";
            cout<< "\n\n\t\tHow many marks you want to insert : ";
            cin>>size;
            marks=new float[size];
            total = 0.0;
            average =0.0;
            cho=10;
            mx=0;
            del=size+4;
        }
        ~Result(){              //distructor

            cout<<"\n\n\n\t -----------------------------------------------";
            cout<<"\n\t|                                               |";
            cout<< "\n\t|\t           Program closed.          \t|";
            cout<<"\n\t|_______________________________________________|\n\n\n\n";
        }
        void input_result();    //Key in all marks
        void calc_total();     //Calculate the total mark
        void calc_average();   //Calculate the mark average
        void display();         //Display the list of marks, total and marks’ average.
        void insertion();       //Insertion algorithm
        void deletion();        //Deletion algorithm
        void menu();            //Menu for insert and delete

};

void Result::input_result(){
    cout<<"\n\t -----------------------------------------------";
    cout<<"\n\t|                                               |";
    cout<< "\n\t|\tPlease enter "<<size<<" marks respectively.\t|";
    cout<<"\n\t|_______________________________________________|\n";
    for(int i=0; i<size; i++){
        cout<<"\n\t\t\t> Mark " << i+1 <<": ";
        cin>> marks[i];
    }
    cout<<"\n\t\t\t-------x-------\n";
}

void Result::calc_total(){
    for(int i=0; i<size; i++){
        total+=marks[i];
    }
}

void Result::calc_average(){
    average= total/size;
}

void Result::display(){
    cout<<"\n\n\t\t -------------------------";
    cout<<"\n\t\t|           Marks         |";
    cout<<"\n\t\t|-------------------------|";

    for(int i=0; i<size; i++){
        cout<<"\n\t\t|             |\t          |";
        cout<<"\n\t\t|\t"<<i+1<<"     |\t"<< fixed << setprecision(2)<<marks[i]<<"\t  |";
    }
    cout<<"\n\t\t|-------------------------|";
    cout<<"\n\t\t|Total        |\t"<< fixed << setprecision(2)<< total <<"\t  |";
    cout<<"\n\t\t|-------------------------|";
    cout<<"\n\t\t|Average      |\t"<< fixed << setprecision(2)<< average <<"\t  |";
    cout<<"\n\t\t|_________________________|";
    cout<<endl;
}

void Result::insertion(){

    if(mx >= 3){
        cout<<"\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\t You have reached to maximum size. \t|";
        cout<<"\n\t|_______________________________________________|\n";
    }
    else{
        cout<<"\n\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\tEnter a number to add at the end. \t|";
        cout<<"\n\t|_______________________________________________|\n";

        size +=1; //increase the array size.
        mx+=1;  //count the limit size.

        cout<<"\n\t\t\t> Mark " << size <<": ";
        cin>> marks[size-1]; //input the value at the end of the array list.
        cout<<"\n\t\t\t-----x-----\n";
        cout<<"\n\t----- "<<marks[size-1]<<" added successfully to the list. -----";

        total=average=0;
        calc_total();
        calc_average();
    }
}

void Result::deletion(){
    if(size<=0){
        cout<<"\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\t There are no marks. Insert first. \t|";
        cout<<"\n\t|_______________________________________________|";
    }
    else{
        cout<<"\n\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\tEnter the index number to delete mark. \t|";
        cout<<"\n\t|_______________________________________________|\n";

        size -=1; //increase the array size.
        mx-=1;  //count the limit size.

        cout<<"\n\t\t\t> Index no : ";
        cin>> del; //input the index value to delete the mark.
        del-=1; //get the index number.
        cout<<"\n\t----- "<<marks[del]<<" deleted successfully from the list. -----";
        for(int i=del; i<size; i++){
            marks[del]=marks[del+1];
        }
        total=average=0;
        calc_total();
        calc_average();

    }
}

void Result::menu(){

//system("clear");
//clrscr();

    while (cho!=0)
    {
        display();

        cout<<"\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\t 1. Insert an additional marks.  \t|";
        cout<< "\n\t|\t 2. Delete a mark from list.     \t|";
        cout<< "\n\t|\t 0. Exit program.                \t|";
        cout<<"\n\t|_______________________________________________|\n";

        cout<<"\n\tChoose an option from menu : ";
        cin>>cho;

        switch (cho) {

        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 0:
            //system("clear");
            //clrscr();
            break;
        default:

            cout<<"\n\t -----------------------------------------------";
            cout<<"\n\t|                                               |";
            cout<< "\n\t|\tInvalid choice. Please try again.     \t|";
            cout<<"\n\t|_______________________________________________|\n";
            break;
            system("cls");
            //clrscr();
        }
    }



}

int main(){
    Result result;
    result.input_result();
    result.calc_total();
    result.calc_average();
    result.menu();



}
