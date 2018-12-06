#include "dictionary.h"
#include <iterator>

dictionary::dictionary()
{

}

void dictionary::addWord(QString key, QString value){
    mp[key] = value;
}

void dictionary::newDictionary(){
    mp.clear();
}
/*
QString dictionary::searchWord(QString key){
    map<QString,QString> :: iterator iter;


}*/

void dictionary::deleteWord(){

}
