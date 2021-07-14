#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
  char escolha;
  string nomelivro, autorlivro, obra;
  vector<string> livrovetor;

  cout << "____ *** Biblioteca Online *** ____" << endl;

  do{
    cout << "___________________________________" << endl;
    cout << "___________________________________" << endl;
    cout << "   a. Registrar livro!\n";
    cout << "   b. Limpar BD!\n";
    cout << "   c. Mostrar livros cadastrados\n";
    cout << "   d. Remover um livro\n";
    cout << "   e. Encerrar o programa\n";
    cout << "___________________________________" << endl;
    cout << "___________________________________\n" << endl;
    
    cout << "Navegue pelos índices do menu\n(a, b, c, d, e): ";
    cin >> escolha;

    if(escolha == 'e'){
        cout << "> Encerrando o programa!" << endl;
        cout << "*** Biblioteca Online Encerrada ***" << endl;
    }
    else{
        if(escolha == 'a'){
            std::cout << "Digite o nome do livro:" << endl;
            getline(cin >> ws, nomelivro);
            std::cout << "Digite o nome do autor:" << endl;
            getline(cin >> ws, autorlivro);
            obra = nomelivro + "/ " + autorlivro;
            livrovetor.push_back(obra);
            std::cout << "> Livro registrado com sucesso!" << endl;
        }
        else if(escolha == 'b'){
            livrovetor.clear();    
            std::cout << "> Banco de Dados limpo com sucesso!" << endl;
        }
        else if(escolha == 'c'){
            if(livrovetor.size() == 0){
              std::cout << "> Não existem livros cadastrados" << endl;
            }
            else{
              std::cout << "> A lista de obras cadastradas é:\n" << endl;
              for (int i = 0; i < livrovetor.size(); i++){
                std::cout << "Obra " << (i+1) << ": " << livrovetor[i] << endl;
              }
            }
        }
        else if (escolha == 'd'){
            string aux;
            cout << "> Insira o nome do livro a ser removido: " << endl;
            getline(cin >> ws, aux);

            vector<string>result;
            vector<string>same_author;
            stringstream ss;
            string item;

            for(int i=0; i<livrovetor.size(); i++){
              ss << livrovetor[i];

              while(getline(ss, item, '/')){
                result.push_back(item);
              }
              if(aux.compare(result[0]) == 0){
                same_author.push_back(livrovetor[i]);
              }
            }

            if(same_author.size() == 0) cout << "> Nenhum livro encontrado com esse título!" << endl;
            else{
                cout << "> Livros encontrados com esse título:" << endl;
                for(int i=0; i<same_author.size(); i++){
                  cout << i+1 << ". " << same_author[i] << endl;
                }
                cout << "> Insira o índice do livro a ser removido:" << endl;
                int subescolha;
                cin >> subescolha;
                livrovetor.erase(livrovetor.begin() + subescolha - 1);
                cout << "> Livro removido da Biblioteca Online!" << endl;
            }
        }
        else cout << "Entrada inválida!" << endl;
    }
  }while(escolha != 'e');
  return 0;
}