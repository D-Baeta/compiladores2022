#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LENGTH 256

// Aqui, é verificado se o token é uma palavra reservada, se não encontrar, é id ou um token inválido
// Ainda não temos a hash no entanto para armazenar os ids, que seria o próximo passo.
// Logo, esta função serve apenas para constatar se a palavra é um comando/id válido, se não, um erro é emitido
void idOuErro(char *string){

    int i = 0;
    switch(string[i]){

    case 'r':
        if(string[i+1] == 'e' && string[i+2] == 'a' && string[i+3] == 'd' && (string[i+4] == NULL || string[i+4] == " " || string[i+4] == ";")){
            printf("READ");
            return;
        }else if(string[i+1] == 'e' && string[i+2] == 't' && string[i+3] == 'u' && string[i+4] == 'r' && string[i+5] == 'n' && (string[i+6] == NULL || string[i+6] == " " || string[i+6] == ";")){
            printf("RETURN");
            return;
        }

    case 's':
        if(string[i+1] == 't' && string[i+2] == 'r' && string[i+3] == 'u' && string[i+4] == 'c' && string[i+5] == 't' && (string[i+6] == NULL || string[i+6] == " " || string[i+6] == ";")){
            printf("STRUCT");
            return;
        }else if(string[i+1] == 'w' && string[i+2] == 'i' && string[i+3] == 't' && string[i+4] == 'c' && string[i+5] == 'h' && (string[i+6] == NULL || string[i+6] == " " || string[i+6] == ";")){
            printf("SWITCH");
            return;
        }

    case 'b':
        if(string[i+1] == 'r' && string[i+2] == 'e' && string[i+3] == 'a' && string[i+4] == 'k' && (string[i+5] == NULL || string[i+5] == " " || string[i+5] == ";")){
            printf("BREAK");
            return;
        }

    case 'p':
        if(string[i+1] == 'r' && string[i+2] == 'i' && string[i+3] == 'n' && string[i+4] == 't' && (string[i+5] == NULL || string[i+5] == " " || string[i+5] == ";")){
            printf("PRINT");
            return;
        }

    case 'w':
        if(string[i+1] == 'h' && string[i+2] == 'i' && string[i+3] == 'l' && string[i+4] == 'e' && (string[i+5] == NULL || string[i+5] == " " || string[i+5] == ";")){
            printf("PRINT");
            return;
        }

    case 'c':
        if(string[i+1] == 'a' && string[i+2] == 't' && string[i+3] == 'c' && string[i+4] == 'h' && (string[i+5] == NULL || string[i+5] == " " || string[i+5] == ";")){
            printf("CATCH");
            return;
        }

    case 'i':
        if(string[i+1] == 'f' && (string[i+2] == NULL || string[i+2] == " " || string[i+2] == ";")){
            printf("IF");
            return;
        }

    case 'e':
        if(string[i+1] == 'l' && string[i+2] == 's' && string[i+3] == 'e' && (string[i+4] == NULL || string[i+4] == " " || string[i+4] == ";")){
            printf("ELSE");
            return;
        }

    case 't':
        if(string[i+1] == 'r' && string[i+2] == 'y' && (string[i+3] == NULL || string[i+3] == " " || string[i+3] == ";")){
            printf("TRY");
            return;
        }
    }

    bool verificador;

    for (size_t i = 0; i < strlen(string); i++) {
        verificador = (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= '0' && string[i] <= '9');
        if(!verificador){
            printf("Erro, token invalido");
            return;
        }
    }

    printf("ID.");
    printf(string);
}

void analyser(char *token){
    int i = 0;
    int aux;

    //caso começe com uma letra minuscula, ele analisa se é um id, uma palavra conhecida ou se é uma entrada inválida
    if(token[i] >= 'a' && token[i] <= 'z'){
        idOuErro(token);

    //caso comece com um número, ele verifica se é um número válido
    }else if((token[i] >= '0' && token[i] <= '9') || token[i] == '.'){

        if(token[i] >= '0' && token[i] <= '9'){
            while(token[i] >= '0' && token[i] <= '9'){
                i++;
            }
            if(token[i] == NULL){
                printf("NUMBER.");
                printf(token);
                return 0;
            }
            if(token[i] != '.'){
                printf("Error: invalid number");
                return 0;
            }else{
                if(token[i+1] == NULL){
                    printf("NUMBER.");
                    printf(token);
                    return 0;
                }
            }
        }

        i++;

        while(token[i] >= '0' && token[i] <= '9'){
            i++;
        }

        if(token[i] == NULL){
            printf("NUMBER.");
            printf(token);
            return 0;
        }

        if(token[i] == 'e'){
            i++;
            if(token[i] == '-'){
                i++;
            }

            while(token[i] >= '0' && token[i] <= '9'){
                i++;
            }

            if(token[i] != NULL){
                printf("Error: invalid number");
                return 0;
            }else{
                printf("NUMBER.");
                printf(token);
                return 0;
            }
        }

    }else{
        //caso não seja nem um numero, id ou uma palavra conhecida, ele verifica se é um dos simbolos conhecidos
        //se não se tratar de um token válido, ele retorna um erro
        switch("%c", token[i]){

        //literal
        case '\'':
            i++;
            if(token[i] != '\'' && token[i] != NULL){
                i++;
                if(token[i] == '\''){
                    i++;
                    if(token[i] == NULL){
                        printf("LITERAL_CHAR");
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
                            printf("LITERAL_STRING");
                            break;
                        }
                    }
                }
            }

            printf("Erro, token invalido");
            break;

        //and / address
        case '&':
            //and
            if(token[i+1] == '&'){
                printf("AND");
            //address
            }else{
                printf("ADDRESS");
            }
            break;

        //or
        case '|':
            printf("OR");
            break;

        //rkey
        case '}':
            printf("RKEY");
            break;

        //lkey
        case '{':
            printf("LKEY");
            break;

        //rbrack
        case ']':
            printf("RBRACK");
            break;

        //lbrack
        case '[':
            printf("LBRACK");
            break;

        //rparen
        case ')':
            printf("RPAREN");
            break;

        //lparen
        case '(':
            printf("LPAREN");
            break;

        //add
        case '+':
            printf("ADD");
            break;

        //sub
        case '-':
            printf("SUB");
            break;

        //mult
        case '*':
            printf("MULT");
            break;

        //resto
        case '%':
            printf("REST");
            break;

        //div e comment
        case '/':

            if(token[i+1] != '*'){
                printf("DIV");
                break;
            }else{
                i++;
                //limite de 1000 caracters por comentario, temporario
                while(i < 1000){

                    if(token[i] == NULL){
                        printf("Erro: eof encontrado no meio do comentario.");
                        break;

                    }else if(token[i] == '*'){
                        aux = i + 1;
                        if(token[aux] == '\/'){
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

        //colon e doublecolon
        case ':':
            //doublecolon
            if(token[i+1] == ':'){
                printf("DBCOLON");
            //colon
            }else{
                printf("COLON");
            }
            break;

        //semicolon
        case ';':
            printf("SEMICOLON");
            break;

        //equal e equalto
        case '=':
            //equalTo
            if(token[i+1] == '='){
                printf("EQUALTO");
            //equal
            }else{
                printf("EQUAL");
            }
            break;

        printf("Erro, token invalido");
        break;

        //negacao e dif
        case '!':
            //greaterOrEqual
            if(token[i+1] == '='){
                printf("DIF");
            //greater
            }else{
                printf("NEG");
            }
            break;

        //lesserOrEqual
        case '<':
            //lesserOrEqual
            if(token[i+1] == '='){
                printf("LESSEROREQUAL");
            //greater
            }else{
                printf("LESSER");
            }
            break;

        //greaterOrEqual and greater
        case '>':
            //greaterOrEqual
            if(token[i+1] == '='){
                printf("GREATEROREQUAL");
            //greater
            }else{
                printf("GREATER");
            }
            break;
        }
    }
}

int main(){

    printf("ANALISE LEXICA - TOKENS\n");
    printf("----------------------------------------\n");
    printf("LEXEMA\n");
    printf("----------------------------------------\n");

    FILE* file = fopen("test.txt", "r"); /*abre o arquivo "test.txt" */
    char line[256];
    char *ptr;
    while (fgets(line, sizeof(line), file)) {
        /* analisa as linhas */
        ptr = strtok(line, " "); //divide pelo espaço
        while(ptr != NULL)  // enquanto ainda há algo na string
        {
            analyser(ptr);
            printf("\n");
            ptr = strtok(NULL, " "); // continua dividindo
        }
    }
    fclose(file);

    return 0;

    printf("\n");
}
