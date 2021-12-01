#include "Shashki.h"                    //0 spitak  1 sev
Shashki::Shashki():figur(' '),at_index1(0),at_index2(0),to_index1(0),to_index2(0), count(0){
    
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if((i+j)%2!=0){
                state = false;
            }
            else{
                state = true;
            }
            if((i+j)%2!=0 && i<3){
                figur = 'X';
                vandak[i][j] = figur;
            }
            else if((i+j)%2!=0 && i>4){
                figur = 'O';
                vandak[i][j]= figur;
            }
            else {
                figur = ' ';
                vandak[i][j] = figur;
            }
        }
    }
    start();

}

void Shashki::start(){
    system("clear");
    std::cout<<"  _A____B____C____D____E____F____G____H__\n";
    for(int i=0;i<8;++i){
      for(int j=0;j<8;++j){
            if(j==0){ 
                std::cout<<i<<"| "<<vandak[i][j]<<" |";    
            }
            else{
                std::cout<<"| "<<vandak[i][j]<<" |";  
            }  
        }
      std::cout<<"\n"<<"  _______________________________________\n";
    }
        
    check_win();
    enter_index();
}

void Shashki::enter_index(){
    if(count == 0){
        std::cout<<"Your turn O ";
    }
    else if(count == 1){
        std::cout<<"Your turn X ";

    }
    std::cout<<"\n"<<"Enter at index1 : ";
    std::cin>>at_index1;
    std::cout<<"\n"<<"Enter at index2 : ";
    std::cin>>at_index2;
    if(check_at(at_index1,at_index2)){
        vandak[at_index1][at_index2] = ' ';
    }
    std::cout<<"\n"<<"Enter to index1 : ";
    std::cin>>to_index1;
    std::cout<<"\n"<<"Enter to index2 : ";
    std::cin>>to_index2;
    if(check_to(to_index1,to_index2)){
        if(count == 0 && (at_index1-to_index1 == 1) && (at_index2!=to_index2 && (at_index2-to_index2 == 1 || at_index2-to_index2==-1))){
        vandak[to_index1][to_index2] = 'O';
        count = 1;
        }
        else if(count == 1 && (at_index1-to_index1 == -1) && (at_index2!=to_index2 && (at_index2-to_index2 == 1 || at_index2-to_index2==-1))){
        vandak[to_index1][to_index2] = 'X';
        count = 0;
        }
        else if(count == 0 && (at_index1-to_index1 == 2)){
            if(vandak[at_index1-1][at_index2-1] == 'X') {
                vandak[at_index1-1][at_index2-1] = ' ';
                vandak[to_index1][to_index2] = 'O';
                if(vandak[to_index1-1][to_index2-1]=='X' && (vandak[to_index1-2][to_index2-2]==' ') || (vandak[to_index1-1][to_index2+1]=='X' && (vandak[to_index1-2][to_index2+2]==' '))){
                    count=0;
                }
                else
                count=1;
            }
            else if(vandak[at_index1-1][at_index2+1] == 'X'){
                vandak[to_index1][to_index2] = 'O';
                vandak[at_index1-1][at_index2+1] = ' ';
                if(vandak[to_index1-1][to_index2-1]=='X' && (vandak[to_index1-2][to_index2-2]==' ') || (vandak[to_index1-1][to_index2+1]=='X' && (vandak[to_index1-2][to_index2+2]==' '))){
                    count = 0;
                }
                else
                count=1;
            }
        }
        else if(count == 1 && (at_index1-to_index1 == -2)){
            if(vandak[at_index1+1][at_index2-1] == 'O') {
                vandak[at_index1+1][at_index2-1] = ' ';
                vandak[to_index1][to_index2] = 'X';
                if(vandak[to_index1+1][to_index2-1]=='O' && (vandak[to_index1+2][to_index2-2]==' ') || (vandak[to_index1+1][to_index2+1]=='O' && (vandak[to_index1+2][to_index2+2]==' '))){
                    count=1;
                }
                else
                count=0;
            }
            else if(vandak[at_index1+1][at_index2+1] == 'O'){
                vandak[at_index1+1][at_index2+1] = ' ';
                vandak[to_index1][to_index2] = 'X';
                if(vandak[to_index1+1][to_index2+1]=='O' && (vandak[to_index1+2][to_index2+2]==' ') || (vandak[to_index1+1][to_index2-1]=='O' && (vandak[to_index1+2][to_index2-2]==' '))){
                    count = 1;
                }
                else
                count=0;
            }
        }
        else{
            std::cout<<"Wrong input try again !";
            enter_index();
        }
        start();
    }

}

bool Shashki::check_at(int i1,int i2){
    if((i1<0 && i1>7)||(i2<0 && i2>7)){
        return false;
    }
    else if(count == 0  && vandak[i1][i2] == 'O'){

        return true;
    }
    else if(count == 1  && vandak[i1][i2] == 'X'){
        return true;
    }
    else{
        return false;
    }
}

bool Shashki::check_to(int i1,int i2){
    if((i1<0 && i1>7)||(i2<0 && i2>7)){
        return false;
    }
    else if(count == 0  && vandak[i1][i2] == ' '){
        return true;
    }
    else if(count == 1  && vandak[i1][i2] == ' '){
        return true;
    }
    else{
        return false;
    }
}

void Shashki::check_win(){
    int x_count{};
    int o_count{};
    for(int i=0;i<8;++i){
      for(int j=0;j<8;++j){
          if(vandak[i][j] == 'O'){
            o_count++;
          }
          else if(vandak[i][j]== 'X'){
           x_count++;
          }
      }
    }
    if(o_count == 0){
        system("clear");
        std::cout<<"The winner is X ";
    }
    else if(x_count == 0){
        system("clear");
        std::cout<<"The winner is O ";        
    }
}