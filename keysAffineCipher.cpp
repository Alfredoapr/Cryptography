#include <bits/stdc++.h>
using namespace std;
//#define tam 21

//a es un elemento de Zn y b es el tamaño del alfabeto

vector<int> extendEuclides(int a, int b){
    vector<int> check_A;
    int u,v,q,r,x,y,d;
    u = a;
    v = b;
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
    return check_A;
}


vector<pair<int,int>> valid_keyA(int tamAlphabet){
    vector<pair<int,int>> keysA;
    pair<int,int> insertA;
    for(int i = 1; i < tamAlphabet; i++){
        auto aux = extendEuclides(i,tamAlphabet);
        //cout << aux[i] << " ";
        if(aux[0] == 1){
            if(aux[1] < 0){
                aux[1] = tamAlphabet - ((-aux[1]) % tamAlphabet);
            }
            insertA.first = i;      //inserta A
            insertA.second = aux[1];    //insert a^-1
            keysA.push_back(insertA);
        }
    }
    return keysA;
}

void validKeys(int tamano){
    ofstream MyFile("keysAffineCipher");
    int tamAlfabeto = tamano;
    auto keyA = valid_keyA(tamAlfabeto);
    vector<pair<pair<int,int>,int>> keys;
    pair<pair<int,int>,int> positions;

    for(int i = 0; i <keyA.size(); i++){       //Recorrer el tamaño del vector de A's 
        for(int k = 0; k < tamAlfabeto; k++){       //Recorro Zn para poder tomar el valor de Bb
            positions.first.first = keyA[i].first;      //insertar en el vector final A
            positions.first.second = keyA[i].second;    //insertar en el vector final A^-1
            positions.second = k;                       //insertar en el vector final b
            keys.push_back(positions);
        }
    }
    for(int j = 0; j < keys.size() ; j++){
        MyFile << "Key A: " << keys[j].first.first << ", Key B: " << keys[j].second << ", A^-1: " << keys[j].first.second << endl;
    }
    MyFile.close();
} 


int main(){
    int tamano;
    cout << "Ingresa el tamaño del alfabeto " << endl;
    cin >> tamano;
    validKeys(tamano);
    //extendEuclides(5,21);
    //valid_keyA(tamano);
    return 0;
}
