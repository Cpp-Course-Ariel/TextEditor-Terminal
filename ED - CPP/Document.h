#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#pragma once
using namespace std;

/**
 * 1)integer - move to the specific line
 * 2)+integer - move the number of lines forward
 * 3)-integer -  move back the number of lines
 * 4)$ - move to the last line.
 * 5)a - append add new line after the current one.
 * 6). - end adding lines
 * 7)i - add lines before the current line
 * 8)c - replace the current line with one line or more
 * 9)d - erase the current line
 * 10)/text/ - search forward the line that contains the text if not found move to the first line and search until current line, the first line that found became the current line
 * 11)s/old/new/ - replace the okd with the new
 * 12)j - join the current line with the one after it
 * 13) w filename - write the document to the file
 * 14) q - quit from the editor 
 */

class Document{
    private:
        vector<string> lines;
        int position;

    public:
        Document(){
            lines = {};
            position = 0;

        }
        Document(string path){
            position = 0;
            std::ifstream myfile(path);
            std::string line;
            std::vector<std::string> myLines;
            while (getline(myfile, line)){           
                lines.push_back(line);
            }
            for ( int i = 0; i <lines.size();i++)
                cout << lines.at(i) << endl;
        }
        void moveToLine(int);

        void moveForward(int);

        void moveBack(int);

        void moveToLast();//allways get $

        void addAfter(string);

        void addBefore(string);

        void reaplce(string);

        void del();

        void search(string);//get the string  and return the line number

        void searchAndReaplace(string,string);//get to strings replace the left with the right        

        void join();//join the current line with the one after

        void writeToFile(string);


        void printText();







};