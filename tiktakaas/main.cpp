#include <iostream>
#include <stdlib.h>
using namespace std;


char lenta[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int pasirinkimas;
int e,s;
char eile = 'X';
char rerun;
bool lygiosios = false;


void print_board(){


    cout<<"\033[1;44m\t ŽAIDĖJAS - 1 [X] \t ŽAIDĖJAS - 2 [O] \033[0m"<<endl;;
    cout<<"\033[1;36m\t     |     |     \n";
    cout<<"\t  "<<lenta[0][0]<<"  | \t"<<lenta[0][1]<<"  |  "<<lenta[0][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<lenta[1][0]<<"  | \t"<<lenta[1][1]<<"  |  "<<lenta[1][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<lenta[2][0]<<"  | \t"<<lenta[2][1]<<"  |  "<<lenta[2][2]<<" \n";
    cout<<"\t     |     |     \n\033[0m";
}


void ejimo_tvarka(){
    if(eile == 'X'){
        cout<<"\n\tŽAIDĖJO - 1 [X] eile : ";
    }
    else if(eile == 'O'){
        cout<<"\n\tŽAIDĖJO - 2 [O] eile : ";
    }

    cin>> pasirinkimas;


    switch(pasirinkimas){
        case 1: e=0; s=0; break;
        case 2: e=0; s=1; break;
        case 3: e=0; s=2; break;
        case 4: e=1; s=0; break;
        case 5: e=1; s=1; break;
        case 6: e=1; s=2; break;
        case 7: e=2; s=0; break;
        case 8: e=2; s=1; break;
        case 9: e=2; s=2; break;
        default:
            cout<<"\033[1;31m\n\tRinkis Normaliai!\n\n\033[0m";
    }

    if(eile == 'X' && lenta[e][s] != 'X' && lenta[e][s] != 'O'){
        lenta[e][s] = 'X';
        eile = 'O';
    }else if(eile == 'O' && lenta[e][s] != 'X' && lenta[e][s] != 'O'){
        lenta[e][s] = 'O';
        eile = 'X';
    }else {
        cout<<"\033[1;31m\n\tLangelis jau užpildytas!\n\n\033[0m";
        ejimo_tvarka();
    }
    
}


bool gameover(){
    for(int i=0; i<3; i++)
    if(lenta[i][0] == lenta[i][1] && lenta[i][0] == lenta[i][2] || lenta[0][i] == lenta[1][i] && lenta[0][i] == lenta[2][i])
    return false;


    if(lenta[0][0] == lenta[1][1] && lenta[0][0] == lenta[2][2] || lenta[0][2] == lenta[1][1] && lenta[0][2] == lenta[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(lenta[i][j] != 'X' && lenta[i][j] != 'O')
    return true;

    lygiosios = true;
    return false;
}




int main()
{
    cout<<"\n\n\t\033[1;31mT I C K    T A C    T O E\033[0m\n\n\n";
    print_board();
    while(gameover()){
        ejimo_tvarka();
        gameover();
        print_board();
    }
    if(eile == 'X' && lygiosios == false){
        cout<<"\033[1;32m\tLaimėjo Žaidėjas 2 'O'!\033[0m";
    
    }
    else if(eile == 'O' && lygiosios == false){
        cout<<"\033[1;32m\tLaimėjo Žaidėjas 1 'X'!\033[0m";
        
    }
    else
    cout<<"LYGIOSIOS!";
}


