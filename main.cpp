
#include <iostream>
#include "ChessBoard.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc == 3) {
        
        int size = atoi(argv[1]);
        int method = atoi(argv[2]);
        
        ChessBoard c(size);
        
        if(method == 0) c.solve();
        else if(method == 1) c.solveAll();
        else cout<<"Wrong parameter";
    }
    
    else {
        cout<<"Wrong number of parameters";
    }

    return 0;
}

