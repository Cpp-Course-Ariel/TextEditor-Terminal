#include "Editor.h"
#include <stdio.h>
#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;

void Editor::loop(){
    string entry;
    getline(cin,entry);
    while (entry != "q")
    {
        if (entry != "\n" && !entry.empty()){
            if(isdigit(entry.at(0))){
                this->document.moveToLine(stoi(entry));
            }
            string newLine;
            switch (entry.at(0)){
                case 'a':
                    getline(cin,newLine);
                    while(newLine != "."){
                        this->document.Document::addAfter(newLine);
                        getline(cin,newLine);
                    }
                    this->document.printText();
                    break;
                
                case 'i':
                    getline(cin,newLine);
                    while(newLine != "."){
                        this->document.Document::addBefore(newLine);
                        getline(cin,newLine);
                    }
                    this->document.moveBack(1);//because enter before and the position moving forward
                    break;

                case 'c':
                    getline(cin,newLine);
                    if (newLine != "."){
                        this->document.reaplce(newLine);
                    }
                    getline(cin,newLine);
                    while(newLine != "."){
                        this->document.Document::addAfter(newLine);
                        getline(cin,newLine);
                    }
                    this->document.printText();
                    break;

                case '+':
                    if(isdigit(entry.at(1))){
                        entry.erase(entry.begin());
                        this->document.moveForward(stoi(entry));
                        break;
                    }
                case '-':
                    if(isdigit(entry.at(1))){
                        entry.erase(entry.begin());
                        this->document.moveBack(stoi(entry));
                        break;
                    }
                case '$':
                    this->document.moveToLast();
                    break;

                case 'd':
                    this->document.del();
                    break;
                
                case '/':
                {
                    string search = entry.substr(1,entry.size()-2);
                    this->document.search(search);
                
                }
                    break;
                
                case 's':{
                        int end = entry.size(); 
                        if(entry.at(end-1) == '/'){
                        entry.erase(entry.begin(),entry.begin()+2);
                        entry.erase(entry.end()-1);
                        this->document.searchAndReaplace(entry.substr(0,entry.find('/')),entry.substr(entry.find("/")+1));
                        break;
                    }else{
                        cout << "?" <<endl;
                        break;
                    }
                }
                case 'j':
                    this->document.join();
                    break;

                case 'w':
                {
                    if(entry.at(1) == ' '){
                    size_t found = entry.find(" ")+1;
                    this->document.writeToFile(entry.substr(found));
                    }else{
                        cout << "?" <<endl;
                    }
                }

                }
        }else{
        cout << "?" << endl;
        }
        
        getline(cin,entry);

    }
    
}