
memoria = {}
positivo = []
negativo = []

def verificador(posicao, registros, somatorio, fluxo):
    global positivo
    global negativo
    global memoria

    if posicao >= len(registros):
        return True if somatorio == fluxo else False

    if (posicao,somatorio) in memoria.keys():
        return memoria[(posicao,somatorio)]

    veri_positivo = verificador(posicao+1, registros, somatorio + int(registros[posicao]), fluxo) 
    veri_negativo = verificador(posicao+1,registros,somatorio - int(registros[posicao]), fluxo)
    
    if veri_positivo == True and veri_negativo == True:
        positivo[posicao] = True
        negativo[posicao] = True

    elif veri_positivo == True and veri_negativo == False:
        positivo[posicao] = True

    elif veri_positivo == False and veri_negativo == True:
        negativo[posicao] = True

    memoria[(posicao, somatorio)] = True if veri_negativo == True or veri_positivo == True else False
    return True if veri_negativo or veri_positivo else False

def comparar(n):
   
    for _ in range(0,n):
        if positivo[_] != negativo[_]:
            return  False
    return False if all(positivo) else True

def main():
    
    while True:
        global positivo
        global negativo
        global memoria

        entrada = input()
        n,fluxo = entrada.split()
        
        if int(n)==0 and int(fluxo)==0:
            break
        registros = ()
        positivo.clear()
        negativo.clear()
        for _ in range(0,int(n)):
            ent = int(input())
            registros = registros +(str(ent),)
            positivo.append(False)
            negativo.append(False)
        
        memoria.clear()
        
        verificador(0,registros,0,int(fluxo))
        if comparar(int(n)) == True:
            print("*")
        else:
            resposta = ""
            for _ in range(0, int(n)):
                if positivo[_] == negativo[_]:
                    resposta = resposta + "?"
                elif positivo[_] == True:
                    resposta = resposta + "+"
                elif negativo[_] == True:
                    resposta = resposta + "-"
            print(resposta)
            
    
   

if __name__ == "__main__":
    main()

