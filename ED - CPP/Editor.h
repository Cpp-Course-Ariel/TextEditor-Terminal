#include "Document.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Editor{
    private:
        Document document;
    
    public:

        Editor(): document(){};
        
        Editor(string path):document(path){};


        void loop();//wait for user input and call the right function from Document

};