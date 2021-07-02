#include "Document.h"
#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::replace
#include <vector>       // std::vector
#include <fstream>  
using namespace std;


void Document::moveToLine(int newPosition){
    if(newPosition > 0 && newPosition <= this->lines.size()){
    this->position = newPosition-1;
    cout << this->lines.at(position) << endl;
    }else{
        cout << "?" << endl;
    }
};

void Document::moveForward(int forward){
    if(position + forward < this->lines.size()){
        this->position = this->position + forward;
        cout << this->lines.at(position)<< endl;
    }else{
        cout << "?" << endl;
    }
}

void Document::moveBack(int backwards){
    if(position - backwards >= 0){
        this->position = position - backwards;
        cout << this->lines.at(position)<< endl;
    }else{
        cout << "?" << endl;
    }
}

void Document::moveToLast(){
    this->position = this->lines.size();
    moveToLine(position);
}

void Document::addAfter(string newLine){
    auto place = this->lines.begin();
    if(this->lines.size() == 0){
        this->lines.insert( place , newLine);    
    }
    else if(this->position == this->lines.size()){
        this->lines.push_back(newLine);
    }
    else{
    this->lines.insert( place + position+1 , newLine);
    }
    this->position++;
}

void Document::addBefore(string newLine){
    auto place = this->lines.begin();
    if(this->lines.size() == 0){
        this->lines.insert( this->lines.begin() , newLine);
            
    }
    else if(this->position == this->lines.size()){
        this->lines.insert(this->lines.end()-1 , newLine);
    }
    else{
        this->lines.insert(place +position , newLine);
    }
    this->position++;
}

void Document::reaplce(string newLine){
 auto place = this->lines.begin();
    if(this->lines.size() == 0){
        this->lines.insert( place , newLine);    
    }
    else if(this->position == this->lines.size()){
        replace(place,this->lines.end(), this->lines.at(position-1) , newLine);;
    }
    else{
    replace(place,this->lines.end(), this->lines.at(position) , newLine);
    }
}   

void Document::del(){
    this->lines.erase(this->lines.begin()+position);
}

void Document::search(string word){
    
    int i = 1;
    while( i < this->lines.size()){

        if(this->position+1>this->lines.size()-1){
            this->position = (this->position+1)%(lines.size());
        }
        else{
            this->position = this->position + 1;
        }
        size_t found = this->lines.at(this->position).find(word);
        if(found!=std::string::npos){ 
            break;
        }
        i++;
    }
    cout<<position<<endl;
}//get the string  and return the line number

void Document::searchAndReaplace(string oldWord ,string newWord){
    size_t found = this->lines.at(this->position).find(oldWord);
    if(found!=std::string::npos){ 
            this->lines.at(position).replace(found, oldWord.size(), newWord);
            cout<<this->lines.at(position)<<endl;
        }
}//get to strings replace the left with the right        

void Document::join(){
    if(position != this->lines.size()-1){
        this->lines.at(position) += this->lines.at(position+1);
        this->lines.erase(this->lines.begin()+position+1);
    }else{
        cout << "?" << endl;
    }
}//join the current line with the one after

void Document::writeToFile(string text){
    ofstream outfile (text);
    for ( int i = 0 ; i < this->lines.size(); i++){
    outfile << this->lines.at(i) << std::endl;
    }
    outfile.close();
}


void Document::printText(){
    for(int i = 0 ; i < this->lines.size();i++)
        cout << this->lines.at(i) <<endl;
}