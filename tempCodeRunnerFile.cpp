arqRead.open("CMP-2.txt");
    if(arqRead.is_open()){
        alunos.open("alunos.txt");
        while(getline(arqRead, line)){
            if(line.size()>4 && line[8]=='.'){
                for(int i=3; i<18;i++){
                    number+=line[i];
                }
                for(int i=135; i<line.size(); i++){
                    if (i + 2 < line.size() && line[i+1] == ' ' && line[i+2] == ' ') {
                        // Se os próximos dois índices forem vazios, pula para a próxima linha
                        break;
                }
                    name += line[i];
                }
                }
                if(number!="" && name!="")
                    alunos<<number<<" "<<name<<endl;
                name="";
                number="";
            }
        arqRead.close();
        alunos.close();
        cout<<"Arquivo 'alunos' criado com sucesso!"<<endl;   
    }else{
        cout<<"Nao foi possivel abrir o arquivo."<<endl;
        return 0;
    }