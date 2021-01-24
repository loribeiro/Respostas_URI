#include <iostream>
#include <map>

using namespace std;

bool resposta(map <int,int> bancos, int b){
    for (int i = 0; i < b; i++)
        {         
           if(bancos[i+1]<0){
               return false;
           } 
        }
        return true;
}

int main(){
    while(true){
        int b, n;
        cin>>b>>n;
        if (b == 0 && n == 0){
            break;
        }
        int d, c,v;
        map <int, int> bancos;
        for (int i = 0; i < b; i++)
        {
            int saldo;
            cin>>saldo;
            bancos[i+1] = saldo; 
        }
        
        for (int i=0; i<n;i++){
            cin>>d>>c>>v;
            bancos[d] -= v;
            bancos[c] += v; 
        }
        
       cout<<( resposta(bancos, b) ? "S" : "N")<<endl; 
    }
}