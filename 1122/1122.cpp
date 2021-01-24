#include <iostream>
#include <map>
#include <utility>


using namespace std;

map< pair<int,int>, bool> memoria;

bool verificador(int posicao,int *registros,int n, int f, int somatorio, bool *positivo, bool *negativo) {
    if(posicao>=n){
        if(somatorio == f){
            return true;
        }else{
            return false;
        }
    }
    if(memoria.find(make_pair(posicao, somatorio))!= memoria.end()){
        return memoria[make_pair(posicao, somatorio)];
    }
    bool direita = verificador(posicao+1, registros, n, f, somatorio+registros[posicao], positivo, negativo);
    bool esquerda = verificador(posicao+1, registros, n, f, somatorio-registros[posicao], positivo, negativo);
    if(direita && esquerda){
        positivo[posicao] = true;
        negativo[posicao] = true;
    }else if(direita && !esquerda){
        positivo[posicao] = true;
    }else if(!direita && esquerda){
        negativo[posicao] = true;
    }
    return memoria[make_pair(posicao, somatorio)] = (direita || esquerda);
}

int main(){
    while(true){
        int N, F;
        cin>>N>>F;

        if(N == 0 && F == 0){
            break;
        }
        memoria.clear();
        int t;
        int registros[N+1];
        bool positivo[N+1], negativo[N+1];

        for(int i = 0; i<N; i++){
            cin>>registros[i];
            positivo[i] = false;
            negativo[i] = false; 
        }
        
        if(!verificador(0,registros,N, F, 0, positivo, negativo)){
            cout<<"*"<<endl;
        }else{
            for(int i = 0; i<N; i++){
                if(positivo[i]==negativo[i]){
                    cout<<"?";
                }else if(positivo[i]){
                    cout<<"+";
                }else if(negativo[i]){
                    cout<<"-";
                }
            }
            cout<<endl;
        }

    
    }
}