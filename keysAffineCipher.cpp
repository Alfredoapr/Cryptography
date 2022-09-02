#include <bits/stdc++.h>
using namespace std;
//#define tam 21

//a es un elemento de Zn y b es el tamaño del alfabeto

vector<int> extendEuclides(int a, int b){
    vector<int> check_A;
    int u,v,q,r,x,y,d;
    int x1 = 1;
    int y1 = 0;
    int x2 = 0;
    int y2 = 1;

    while (u != 0)
    {
        q = v/u;
        r = v - (q * u);
        x = x2 - (q * x1);
        y = y2 - (q + y1);
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        d = v;
        x = x2;
        y = y2;
    }
    check_A.push_back(d);  // if d == 1, A es valida
    check_A.push_back(x);   // retorna a^-
    //check_A.push_back(d); // no  es un valor relevante para el programa.
}

vector<pair<int,int>> valid_keyA(int tamAlphabet){
    vector<pair<int,int>> keysA;
    pair<int,int> insertA;
    for(int i = 1; i < tamAlphabet; i++){
        auto aux = extendEuclides(i,tamAlphabet);
        if(aux[0] == 1){
            if(aux[1] < 0)
                aux[1] = tamAlphabet - ((-aux[1]) % tamAlphabet);
            insertA.first = i;
            insertA.second = aux[1];
            keysA.push_back(insertA);
        }
    }
    return keysA;
}

void validKeys(int tamano){
    int tamAlfabeto = tamano;
    auto keyA = valid_keyA(tamAlfabeto);
    vector<pair<pair<int,int>,int>> keys;
    pair<pair<int,int>,int> positions;

    for(int i = 1; i < tamAlfabeto; i++){
        positions.first = keyA[i];
        positions.second = i;
        keys.push_back(positions);
    }

    for(int j = 0; j < tamAlfabeto ; j++){
        cout << "Key A: " << keys[j].first.first << " Key B: " << keys[j].second << " A^-1: " << keys[j].first.second << endl;
    }
    //return ;
} 

int main(){

    int tamano;
    cout << "Ingresa el tamaño del alfabeto " << endl;
    cin >> tamano;
    validKeys(tamano);

    return 0;
}
