#include <iostream>
using namespace std;

int max_subsum(int *lista,int n){
   int maxima_soma = 0;
   int soma_atual = 0;

    for (int i = 0; i<n; i++){
        if(lista[i]+soma_atual<0){
            soma_atual = 0;
        }else if(lista[i]+soma_atual>maxima_soma){
            maxima_soma = lista[i]+soma_atual;
            soma_atual = lista[i]+soma_atual;
        }else{
            soma_atual = lista[i]+soma_atual;
        }      
    }
    return maxima_soma;
}
int main(){
    int n;
    while(cin>>n){
        int custo,receita[n+1];
        cin>>custo;
        for (int i = 0; i<n ; i++){
            int aux;
            cin>>aux;
            receita[i] = aux - custo;
        }
        cout<<max_subsum(receita,n)<<endl;
    }
}