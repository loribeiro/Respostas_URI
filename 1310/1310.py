
def max_subsum(lista):
    if min(lista)>=0:
        return sum(lista)

    soma_maxima = 0
    soma_atual = 0
    for i in range(0,len(lista)-1):
        if soma_atual> soma_maxima:
            soma_maxima = soma_atual
        if lista[i] + soma_atual<0:
            soma_atual = 0
        else:
            soma_atual = soma_atual + lista[i]

    return soma_maxima


def main():
    while(True):
        try:
            n = int(input())
        except EOFError: 
            break
        custo = int(input())
        diarias = []
        for i in range(0,n):
            diarias.append(int(input())-custo)
        resposta = max_subsum(diarias)
        print(resposta)

if __name__ == "__main__":
    main()