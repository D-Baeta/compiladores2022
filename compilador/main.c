#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void idOuErro(char *string){

    bool verificador;

    for (size_t i = 0; i < strlen(string); i++) {
        verificador = (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= '0' && string[i] <= '9');
        if(!verificador){
            printf("Erro, token invalido");
            return;
        }
    }

    printf("token: id");
}

int main(){

    char token[] = "teste2";
    int i = 0;
    int aux;

    switch("%c", token[i]){

    //add
    case '+':
        i++;
        if(token[i] == NULL){
            printf("token: add");
            break;
        }

        printf("Erro, token invalido");
        break;

    //sub
    case '-':
        i++;
        if(token[i] == NULL){
            printf("token: sub");
            break;
        }

        printf("Erro, token invalido");
        break;

    //mult
    case '*':
        i++;
        if(token[i] == NULL){
            printf("token: mult");
            break;
        }

        printf("Erro, token invalido");
        break;

    //resto
    case '%':
        i++;
        if(token[i] == NULL){
            printf("token: resto");
            break;
        }

        printf("Erro, token invalido");
        break;

    //div e comment
    case '/':
        i++;

        //div
        if(token[i] == NULL){
            printf("token: div");
            break;

        //comment
        }else if(token[i] == '*'){
            i++;
            //limite de 1000 caracters por comentario, temporario
            while(i < 1000){
                if(token[i] == NULL){
                    printf("Erro: eof encontrado no meio do comentario.");
                    break;

                }else if(token[i] == '*'){
                    aux = i + 1;
                    if(token[aux] == '\\'){
                        printf("token: comment");
                        break;

                    }else if(token[aux] == NULL){
                        printf("Erro: eof encontrado no meio do comentario.");
                        break;
                    }
                }
                i++;
            }
            break;
        }

        printf("Erro, token invalido");
        break;

    //break;
    case 'b':
        i++;
        if(token[i] == 'r'){
            i++;
            if(token[i] == 'e'){
                i++;
                if(token[i] == 'a'){
                    i++;
                    if(token[i] == 'k'){
                        i++;
                            if(token[i] == NULL){
                                printf("token: break");
                                break;
                            }
                        }
                    }
                }
            }
    printf("chamando funcao de id ou erro");
    break;

    //print
    case 'p':
        i++;
        if(token[i] == 'r'){
            i++;
            if(token[i] == 'i'){
                i++;
                if(token[i] == 'n'){
                    i++;
                    if(token[i] == 't'){
                        i++;
                            if(token[i] == NULL){
                                printf("token: print");
                                break;
                            }
                        }
                    }
                }
            }

    idOuErro(token);
    break;

    //while
    case 'w':
        i++;
        if(token[i] == 'h'){
            i++;
            if(token[i] == 'i'){
                i++;
                if(token[i] == 'l'){
                    i++;
                    if(token[i] == 'e'){
                        i++;
                            if(token[i] == NULL){
                                printf("token: while");
                                break;
                            }
                        }
                    }
                }
            }

    idOuErro(token);
    break;

    //catch
    case 'c':
        i++;
        if(token[i] == 'a'){
            i++;
            if(token[i] == 't'){
                i++;
                if(token[i] == 'c'){
                    i++;
                    if(token[i] == 'h'){
                        i++;
                            if(token[i] == NULL){
                                printf("token: catch");
                                break;
                            }
                        }
                    }
                }
            }

    idOuErro(token);
    break;

    //if
    case 'i':
        i++;
        if(token[i] == 'f'){
            i++;
            if(token[i] == NULL){
                printf("token: if");
                break;
            }
        }

    idOuErro(token);
    break;

    //else
    case 'e':
        i++;
        if(token[i] == 'l'){
            i++;
            if(token[i] == 's'){
                i++;
                if(token[i] == 'e'){
                    i++;
                    if(token[i] == NULL){
                        printf("token: else");
                        break;
                    }
                }
            }
        }

    idOuErro(token);
    break;

    //try
    case 't':
        i++;
        if(token[i] == 'r'){
            i++;
            if(token[i] == 'y'){
                i++;
                if(token[i] == NULL){
                    printf("token: try");
                    break;
                }
            }
        }

    idOuErro(token);
    break;

    //switch e struct
    case 's':
        i++;

        //struct
        if(token[i] == 't'){
            i++;
            if(token[i] == 'r'){
                i++;
                if(token[i] == 'u'){
                    i++;
                    if(token[i] == 'c'){
                        i++;
                        if(token[i] == 't'){
                            i++;
                            if(token[i] == NULL){
                                printf("token: struct");
                                break;
                            }
                        }

                    }
                }
            }

        //switch
        }else if(token[i] == 'w'){
            i++;
            if(token[i] == 'i'){
                i++;
                if(token[i] == 't'){
                    i++;
                    if(token[i] == 'c'){
                        i++;
                        if(token[i] == 'h'){
                            i++;
                            if(token[i] == NULL){
                                printf("token: switch");
                                break;
                            }
                        }

                    }
                }
            }
        }

    idOuErro(token);
    break;

    //read e return
    case 'r':
        i++;

        if(token[i] == 'e'){
            i++;

            //read
            if(token[i] == 'a'){
                i++;
                if(token[i] == 'd'){
                    i++;
                    if(token[i] == NULL){
                        printf("token: read");
                        break;
                    }
                }

            //return
            }else if(token[i] == 't'){
                i++;
                if(token[i] == 'u'){
                    i++;
                    if(token[i] == 'r'){
                        i++;
                        if(token[i] == 'n'){
                            i++;
                            if(token[i] == NULL){
                                printf("token: return");
                                break;
                            }
                        }
                    }
                }
            }
        }

    idOuErro(token);
    break;

    //colon e semicolon
    case ':':
        i++;

        //colon
        if(token[i] == NULL){
            printf("token: colon");
            break;

        //doublecolon
        }else if(token[i] == ':'){
            i++;
            if(token[i] == NULL){
                printf("token: doublecolon");
                break;
            }
        }

    //semicolon
    case ';':
        i++;

        //semicolon
        if(token[i] == NULL){
            printf("token: semicolon");
            break;
        }

    printf("Erro, token invalido");
    break;

    //equal e equalto
    case '=':
        i++;

        //equal
        if(token[i] == NULL){
            printf("token: equal");
            break;

        //equalto
        }else if(token[i] == '='){
            i++;
            if(token[i] == NULL){
                printf("token: equalto");
                break;
            }
        }

    printf("Erro, token invalido");
    break;

    //negacao e dif
    case '!':
        i++;

        //negacao
        if(token[i] == NULL){
            printf("token: negacao");
            break;
        }

        //dif
        else if(token[i] == '='){
            i++;
            if(token[i] == NULL){
                printf("token: dif");
                break;
            }
        }

    printf("Erro, token invalido");
    break;

    }
}
