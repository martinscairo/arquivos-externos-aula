#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include "Data.h"
#include <sstream> //manipula stringstream

void Programa (const Data&);

int main() {
        
   
//    Leitura do leitura.ini
    const std :: string FILENAME ("leitura.ini"); //variável filename, que origina arquivo "leitura", com dados tipo string
    std :: ifstream input (FILENAME);             //cria variável input, tipo ifstream (cópia), com valor de filename
    
//_________________________TESTE DE EXISTÊNCIA DO ARQUIVO_______________________
    
         if (!input){
             std :: cerr << "Arquivo" << FILENAME << " não encontrado" << std :: endl;
             std :: cerr << "Arquivo: " << __FILE__ << std :: endl;
             std :: cerr << "Linha: " << __LINE__  - 3 << std ::endl;
             std :: cerr << "Execução cancelada" << std :: endl;
             abort ();
         }

    
    Data data;                 //cria variável data do tipo Data
    std :: string linha;       //cria variável linha do tipo string
////    int contalinha (0);
    int contalinha (-1);       //cria variável inteira contalinha com valor inicial -1
    
    while (getline (input, linha))    //enquanto o programa possui linha com dados
    {
        std:: stringstream convert (linha);     //variável convert, tipo stringstream, valor inicial LINHA, CLASSE STREAM P OPERAR STRINGS
//        std :: cout << linha.size () << std :: endl;
        
        //A CONSTRUÇÃO NAO IGNORA AS INFORMAÇÕES REQUERIDAS ALÉM DO NOME DO ARQUIVO
        
        std :: cout << "Linha: " << linha << std :: endl;
        if (linha.size() >2) contalinha++; //se a memória ocupada pela variável linha exceder 2
        
        switch (contalinha)            //avalia CONTALINHA
        {
            case 0:  convert >> data.arq_dados;  // variável convert assimila arquivo de dados
                break;
            
            case 1: convert >> data.arq_sad; // variável convert assimila arquivo de saída
                break;
            
            default:                          //se nenhum caso for verdadeiro
                break;
                        
        }
        
////        if (linha.size() >2) contalinha++;
    }
    
//    input >> data.arq_dados >> data.arq_sad; //assimila as informações do arquivo nas variáveis da classe
    std :: cout << "Arquivo de dados: " << data.arq_dados << std :: endl;    //imprime variável de dados
    std :: cout << "Arquivo de saída: " << data.arq_sad << std :: endl;  //imprime variável de saída
//    
    
    input.close ();
    Programa (data);
    
    return 0;
    
}

void Programa (const Data& _data)
{
    std :: cout << "Estou no programa" << std::endl;
    std :: cout << "Arquivo de dados: " << _data.arq_dados << std :: endl; //exibe nome de arquivo de dados
    std :: cout << "Arquivo de saída: " << _data.arq_sad << std :: endl;  //exibe nome de arquivo de saída
    
//    ESCREVENDO ARQUIVO DE SAÍDA
    
    std:: ofstream output (_data.arq_sad);
    output << "Escrevendo no arquivo de saída\n";
    output << "Arquivo: " << _data.arq_sad << std :: endl;
    output.close();
    
//    LENDO ARQUIVO DE ENTRADA
     std :: ifstream input (_data.arq_dados);
         if (!input){
             std :: cerr << "Arquivo" << _data.arq_dados << " nao encontrado" << std :: endl;
             std :: cerr << "Arquivo: " << __FILE__ << std :: endl;
             std :: cerr << "Linha: " << __LINE__  - 3 << std ::endl;
             std :: cerr << "Execução cancelada" << std :: endl;
             abort ();
         }
}