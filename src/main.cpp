#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct move_t{
    char fromFile;
    char fromRank;
    char toFile;
    char toRank;
    char prom;
};

int main(int argc, char* argv[]){
    std::string historyPath;
    std::string movePath;
    
    for(int i = 0; i+1 < argc; i++){
        const std::string_view arg = argv[i];
        if(arg == "-H"){
            historyPath = argv[++i];
        }
        if(arg == "-m"){
            movePath = argv[++i];
        }
    }
    if(historyPath.empty() || movePath.empty()){
        std::cout<<"usage: ./Alekhine-Engine -H <history-file> -m <move-file>\n";
    }

    std::vector<move_t> history;

    std::string token;
    std::ifstream fin(historyPath);
    std::ofstream fout(movePath);
    if(!fin)
        std::cout<<"Error: cannot open history file\n";
    if(!fout)
        std::cout<<"Error: cannot write to move file\n";
    
    while(fin>>token){
        history.push_back(move_t{
            .fromFile = token[0], 
            .fromRank = token[1], 
            .toFile = token[2], 
            .toRank = token[3], 
            .prom = (token.size() <= 4) ? '0' : token[4]
        });
    }

    //feed history to the engine and get a move
    //output the move below
    //feel free to move the move_t struct somewhere else and modify it

    if(history.size() % 2 == 0)
        fout<<"e2e4\n";
    else
        fout<<"e7e5\n";


    return 0;
}