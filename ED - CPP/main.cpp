#include "Editor.h"
#include "Document.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char* argv[]){
    switch(argc){
        case 1:{
            Editor editor;
            editor.loop();
            break;
        }
        case 2:{
            Editor editor(argv[1]);
            editor.loop();
            break;
        }
    }
    //editor.loop();
    return 0;
    
}

