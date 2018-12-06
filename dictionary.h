#ifndef SOURSE_H
#define SOURSE_H

#include <map>
#include <iterator>
#include <QString>
using namespace std;

class dictionary
{
public:
    dictionary();
    ~dictionary();
    map<QString, QString> mp;
    void newDictionary();
    void addWord(QString key,QString value);
   // QString searchWord(QString key);
    void deleteWord();
};

#endif // SOURSE_H
