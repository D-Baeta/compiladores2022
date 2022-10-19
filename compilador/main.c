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

    char token[] = "'&'";
    int i = 0;
    int aux;

    if(token[i] >= 'a' && token[i] <= 'z'){
        //chama a tabela
        printf("eita, deu");
    }else if((token[i] >= 0 && token[i] <= 9) || token[i] == '.'){
        //executar depois
    }else{
        switch("%c", token[i]){

        //literal
        case '\'':
            i++;
            if(token[i] != '\'' && token[i] != NULL){
                i++;
                if(token[i] == '\''){
                    i++;
                    if(token[i] == NULL){
                        printf("token: literal char");
                        break;
                    }
                }else if(token[i] >= 'a' && token[i] <= 'z'){
                    i++;
                    while(token[i] != NULL && token[i] != '\''){
                        i++;
                    }

                    if(token[i] == NULL){
                        printf("Erro: EOF dentro de string");
                        break;
                    }

                    if(token[i] == '\''){
                        i++;
                        if(token[i] == NULL){
                            printf("token: literal string");
                            break;
                        }
                    }
                }
            }

            printf("Erro, token invalido");
            break;

        //and
        case '&':
            i++;
            if(token[i] == '&'){
                i++;
                if(token[i] == NULL){
                    printf("token: and");
                    break;
                }
            }

            printf("Erro, token invalido");
            break;


        //or
        case '|':
            i++;
            if(token[i] == NULL){
                printf("token: or");
                break;
            }

            printf("Erro, token invalido");
            break;

        //rkey
        case '}':
            i++;
            if(token[i] == NULL){
                printf("token: rkey");
                break;
            }

            printf("Erro, token invalido");
            break;

        //lkey
        case '{':
            i++;
            if(token[i] == NULL){
                printf("token: lkey");
                break;
            }

            printf("Erro, token invalido");
            break;

        //rbrack
        case ']':
            i++;
            if(token[i] == NULL){
                printf("token: rbrack");
                break;
            }

            printf("Erro, token invalido");
            break;

        //lbrack
        case '[':
            i++;
            if(token[i] == NULL){
                printf("token: lbrack");
                break;
            }

            printf("Erro, token invalido");
            break;

        //rparen
        case ')':
            i++;
            if(token[i] == NULL){
                printf("token: rparen");
                break;
            }

            printf("Erro, token invalido");
            break;

        //lparen
        case '(':
            i++;
            if(token[i] == NULL){
                printf("token: lparen");
                break;
            }

            printf("Erro, token invalido");
            break;

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

        //colon e doublecolon
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

        //lesserOrEqual and lesser
        case '<':
            i++;

            //lesser
            if(token[i] == NULL){
                printf("token: lesser");
                break;

            //lesserOrEqual
            }else if(token[i] == '='){
                i++;
                if(token[i] == NULL){
                    printf("token: lesserOrEqual");
                    break;
                }
            }

        printf("Erro, token invalido");
        break;

        //greaterOrEqual and greater
        case '>':
            i++;

            //greater
            if(token[i] == NULL){
                printf("token: greater");
                break;

            //greaterOrEqual
            }else if(token[i] == '='){
                i++;
                if(token[i] == NULL){
                    printf("token: greaterOrEqual");
                    break;
                }
            }

        printf("Erro, token invalido");
        break;

        }
    }
}
