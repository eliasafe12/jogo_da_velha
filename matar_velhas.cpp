#include <iostream>
#include <cstdlib>
using namespace std;
// JOGO DA VELHA - Eliasafe Matheus Kelczeski Mendes
// 20/08/2025
int lin, col; // usar pra posição que o usuário quer
char  mat_velha[3][3], vazio = '-', xis = 'X', bola = 'O';   // declarar a tabela do jogo
void tabu(){ // imprimir tabuleiro
    cout << "Tabuleiro:" << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mat_velha[i][j] << " ";
        }
            cout << endl;
    }
}
void victory(){ // checa se alguém venceu
    for(int i=0; i<3; i++){ 
        if(mat_velha[i][0] == mat_velha[i][1] && mat_velha[i][1] == mat_velha[i][2]){ // checar linhas
            if(mat_velha[i][0] != vazio){
                cout << mat_velha[i][0] << " venceu" << endl;
                exit(0);
            }
        }
        if(mat_velha[0][i] == mat_velha[1][i] && mat_velha[1][i] == mat_velha[2][i]){ // checar colunas
            if(mat_velha[0][i] != vazio){
                cout << mat_velha[0][i] << " venceu" << endl;
                exit(0);
            }
        }
    }
    if(mat_velha[0][0] == mat_velha[1][1] && mat_velha[1][1] == mat_velha[2][2]){ // checar diagonal decrescente
        if(mat_velha[0][0] != vazio){
            cout << mat_velha[0][0] << " venceu" << endl;
            exit(0);
        }
    }
    if(mat_velha[0][2] == mat_velha[1][1] && mat_velha[1][1] == mat_velha[2][0]){ // checar diagonal crescente
        if(mat_velha[0][2] != vazio){
            cout << mat_velha[0][2] << " venceu" << endl;
            exit(0);
        }
    }    
}
int main(){
    // preencher a matriz pra n�o dar erro
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mat_velha[i][j]= vazio;
        }
    }
    tabu(); // mostra o tabuleiro inicial
    for(int l=0; l<9; l++){
        if(l%2==0){ // imprimir de quem é a vez
            cout << "Vez do " << bola << endl;
        }else{
            cout << "Vez do " << xis << endl;
        }
        cout << "Insira uma posic�o:" << endl; // pedir pro usuário a posição da peça
        cin >> lin >> col;
        if(mat_velha[lin][col] == bola || mat_velha[lin][col] == xis || lin < 0 || lin > 2 || col < 0 || col > 2){ // checar se a jogada é válida
            cout << "Jogada inv�lida" << endl;
            l--;
        }else{
            if(l%2==0){
                mat_velha[lin][col] = bola;
            }else{
                mat_velha[lin][col] = xis;
            }
        }
        tabu();
        victory();
    }
    cout << "Deu velha!" << endl;
}

