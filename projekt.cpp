// projekt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <iomanip>

using namespace std;


struct magazynier {
    int x;
    int y;
};

int tab[8][17] = {                              //sciana=1, wolne pole=0, skrzynka=2, pole zwycieskie=3, magazynier-4
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    { 1,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,1 },
    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
    { 1,2,0,2,0,2,0,0,0,0,0,0,0,0,0,0,1 },
    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
    { 1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
int liczbaruchow=0;


magazynier szukaj(int tab[8][17]) {             //funkcja szukajaca magazyniera w tablicy 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 17; j++) {
            if (tab[i][j] == 4) {           
                magazynier out;         //"wspolrzednie" magazyniera
                out.x = i;
                out.y = j;
                return out;
                
            }


        }
    }
}



int poruszanie(int tab[8][17]) {
    char ruch;
    cin >> ruch;
    
    system("cls");

    magazynier pozycja = szukaj(tab);




    if (ruch == 'a' && tab[pozycja.x][pozycja.y - 1] != 1 && tab[pozycja.x][pozycja.y-1]!=5 && tab[pozycja.x][pozycja.y - 1] != 3) {
        
        
        
        if (tab[pozycja.x][pozycja.y - 2] == 2 && tab[pozycja.x][pozycja.y - 1] == 2) {             //gdy skrzynka jest za skrzynka ktora chce przesunac
            tab[pozycja.x][pozycja.y - 1] = 2;
            tab[pozycja.x][pozycja.y] = 4;
            
           
        }
        else if (tab[pozycja.x][pozycja.y - 2] == 1 && tab[pozycja.x][pozycja.y - 1] == 2) {   //gdy sciana jest za skrzynka ktora chce przesunac
            tab[pozycja.x][pozycja.y - 1] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x][pozycja.y - 1] == 2) {                                  //gdy chce przesunac skrzynke bez spiny

            tab[pozycja.x][pozycja.y - 2] = 2;
            tab[pozycja.x][pozycja.y - 1] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;
        }
        
        else {                                                              //gdy chce sie ruszyc tak o na legalu
            tab[pozycja.x][pozycja.y - 1] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;

        }

    }
    if (ruch=='w' && tab[pozycja.x - 1][pozycja.y]!= 1 && tab[pozycja.x - 1][pozycja.y] != 5 && tab[pozycja.x - 1][pozycja.y]!=3) {

        if (tab[pozycja.x - 2][pozycja.y] == 2 && tab[pozycja.x - 1][pozycja.y] == 2) {
            tab[pozycja.x - 1][pozycja.y] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x - 2][pozycja.y] == 1 && tab[pozycja.x - 1][pozycja.y] == 2) {
            tab[pozycja.x - 1][pozycja.y] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x - 1][pozycja.y] == 2) {

            tab[pozycja.x - 2][pozycja.y] = 2;
            tab[pozycja.x - 1][pozycja.y] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;
        }

        else { 
            tab[pozycja.x - 1][pozycja.y] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;
        }

    }
    if (ruch=='d' && tab[pozycja.x][pozycja.y + 1]!= 1 && tab[pozycja.x][pozycja.y + 1] != 5 && tab[pozycja.x][pozycja.y+1]!=3) {

        if (tab[pozycja.x][pozycja.y + 2] == 2 && tab[pozycja.x][pozycja.y + 1] == 2) {
            tab[pozycja.x][pozycja.y + 1] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x][pozycja.y + 2] == 1 && tab[pozycja.x][pozycja.y + 1] == 2) {
            tab[pozycja.x][pozycja.y + 1] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x][pozycja.y + 1] == 2) {

            tab[pozycja.x][pozycja.y + 2] = 2;
            tab[pozycja.x][pozycja.y + 1] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;
        }

        else {
            tab[pozycja.x][pozycja.y + 1] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;
        }

    }
    if (ruch=='s' && tab[pozycja.x+1][pozycja.y] != 1 && tab[pozycja.x+1][pozycja.y] != 5 && tab[pozycja.x+1][pozycja.y]!=3) {

        if (tab[pozycja.x + 2][pozycja.y] == 2 && tab[pozycja.x + 1][pozycja.y] == 2) {
            tab[pozycja.x + 1][pozycja.y] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x + 2][pozycja.y] == 1 && tab[pozycja.x + 1][pozycja.y] == 2) {
            tab[pozycja.x + 1][pozycja.y] = 2;
            tab[pozycja.x][pozycja.y] = 4;

        }
        else if (tab[pozycja.x + 1][pozycja.y] == 2) {

            tab[pozycja.x + 2][pozycja.y] = 2;
            tab[pozycja.x + 1][pozycja.y] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;
        }

        else {
            tab[pozycja.x + 1][pozycja.y] = 4;
            tab[pozycja.x][pozycja.y] = 0;
            liczbaruchow = liczbaruchow + 1;

        }
        
    }
    
    
    return tab[pozycja.x][pozycja.y], liczbaruchow;
}




void mapa(int tab[8][17]){     //tzw. "tlumaczenie"
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 17; j++) {
            switch (tab[i][j]) {
            case 1:
                cout << "#";
                break;
            case 2:
                cout << "0";
                break;
            case 3:
                cout << "+";
                break;
            case 4:
                cout << "@";
                break;
            case 5:
                cout << "x";
                break;
            default:
                cout << " ";
            }
        }
        cout << "\n";
        

    }
    cout << "twoj ruch(w,s,a,d" << endl;
    cout << "Ilosc twoich ruchow: " << 35-liczbaruchow;
    
        
    }
    

void wygrana(int tab[8][17]) {       //zmiana piktogramu skrzyni
    
    if (tab[1][1] == 2) {
        tab[1][1] = 5;
    }
    if (tab[1][2] == 2) {
        tab[1][2] = 5;
    }
    if (tab[1][3] == 2) {
        tab[1][3] = 5;
    }
    if (tab[1][1] == 5 && tab[1][2] == 5 && tab[1][3] == 5) {
        cout << endl;
        
    }
    
    
}

void menu() {
    cout << "Kacper Kolassa EiT 193654" << endl;
    cout << "Witaj w grze Sokoban" << endl << "Wybierz opcje:" << endl;
    cout << "1.Rozpocznij gre" << endl;
   
    
    
    
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        
        while ((35-liczbaruchow)>0 && (tab[1][1] == 3 || tab[1][2] == 3 || tab[1][3] == 3)) {
            mapa(tab);
            wygrana(tab);
            poruszanie(tab);
            
            

            
            
            
        }
        if ((35 - liczbaruchow)<= 0) {
            cout << "przegrales" << endl;
            
        }
        else {
            cout << "wygrales" << endl;
            
            

        }
        
        
        break;
    
    default:
        void menu();



    }


}





int main()
{
    
    
        menu();
        
    
    
    
        return 0;

            





}

