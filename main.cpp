#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream arqRead;
    ofstream alunos;
    string line="";
    string number="";
    string name="";

    arqRead.open("CMP-2.txt");
    if(arqRead.is_open()){
        alunos.open("alunos.txt");
        while(getline(arqRead, line)){
            if(!line.empty()){
                for(int i=3; i<18;i++){
                    number+=line[i];
                }

                for(int i=25; i<line.size();i++){
                    name+=line[i];
                }
                alunos<<number<<" "<<name<<endl;
                name="";
                number="";
            }
        }
        arqRead.close();
        alunos.close();
        cout<<"Concluido";
    }else{
        cout<<"Nao foi possivel abrir o arquivo."<<endl;
    }
}
