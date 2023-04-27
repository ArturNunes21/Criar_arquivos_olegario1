#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    std::ifstream arqRead;
    std::ofstream alunos, disciplinas, matriculas;
    vector<string>vector{""};
    std::string line, matricula, name, codigoDisciplina, materia, turma;
    line=matricula=name=codigoDisciplina=materia=turma="";
    bool encontrado=false;

    arqRead.open("CMP-2.txt");
    if(arqRead.is_open()){
        alunos.open("alunos.txt");
        while(std::getline(arqRead, line)){
            if(line.size()>4 && line[8]=='.' && !line.empty()){
                for(int i=3; i<18;i++){
                    matricula+=line[i];
                }
                for(int i=25; i<line.size(); i++){
                    if (i + 2 < line.size() && line[i] == ' ' && line[i+1] == ' ') {
                        // Se os próximos dois índices forem vazios, pula para a próxima linha
                        break;
                    }
                    name += line[i];
                }
            }
                encontrado=false;
                for(int i=0;i<vector.size();i++){
                    if(vector[i]==matricula){
                        encontrado=true;
                        break;
                    }
                }
                if(matricula!="" && name!="" && !encontrado){
                    vector.push_back(matricula);  //adiciona matricula no vetor
                    alunos<<matricula<<" "<<name<<std::endl;   //Adiciona nome e matricula no arquivo
                }
            name="";
            matricula="";
            }
        arqRead.close();
        alunos.close();
        vector.clear();
        std::cout<<"Arquivo 'alunos' criado com sucesso!"<<std::endl;   
    }else{
        std::cout<<"Nao foi possivel abrir o arquivo."<<std::endl;
        return 0;
    }


    arqRead.open("CMP-2.txt");
    if(arqRead.is_open()){
        disciplinas.open("disciplinas.txt");
        while(std::getline(arqRead, line)){
            if(line[78]=='-'){
             for(int i=70; line[i]!=' '; i++){
                codigoDisciplina+=line[i];
             }
             for(int i=80; i<line.size(); i++){
                if (i + 2 < line.size() && line[i] == ' ' && line[i+1] == ' ')
                    break;
                materia+=line[i];
                }   
            }
            encontrado=false;
            for(int i=0;i<vector.size();i++){
                if(vector[i]==codigoDisciplina){
                    encontrado=true;
                    break;
                }
            }
            if(codigoDisciplina!="" && materia!="" && !encontrado){
                vector.push_back(codigoDisciplina); //codigo é adicionado ao vector
                disciplinas<<codigoDisciplina<<" "<<materia<<std::endl; //codigo e nome da materia são impressos no arquivo
            }
            codigoDisciplina="";
            materia="";
        }
        arqRead.close();
        disciplinas.close();
        vector.clear();
        std::cout<<"Arquivo 'disciplinas' criado com sucesso!"<<std::endl;
    }else{
        std::cout<<"Nao foi possivel abrir o arquivo."<<std::endl;
        return 0;
    }
    
    arqRead.open("CMP-2.txt");
    if(arqRead.is_open()){
        int espaco=-1;
        matriculas.open("matriculas.txt");
        while(std::getline(arqRead, line)){
            espaco++;
            if(line[78]=='-'){
             for(int i=70; i<77; i++){
                codigoDisciplina+=line[i];
             }
             for(int i=135; i<line.size(); i++){
                turma+=line[i];
                }
            }
            if(line.size()>4 && line[8]=='.'){
            for(int i=3; i<18;i++){
                    matricula+=line[i];
                }
            }   
            if(codigoDisciplina!="" && turma!="" &&espaco>1){
                matriculas<<"       *       "<<std::endl;
                matriculas<<"=="<<codigoDisciplina<<" "<<turma<<"=="<<std::endl;
            }
            if(matricula!="")
                matriculas<<matricula<<std::endl;
            codigoDisciplina="";
            turma="";
            matricula="";
            }
        arqRead.close();
        matriculas.close();
        std::cout<<"Arquivo 'matriculas' criado com sucesso!"<<std::endl;
    }else{
        std::cout<<"Nao foi possivel abrir o arquivo."<<std::endl;
        return 0;
    }
}
