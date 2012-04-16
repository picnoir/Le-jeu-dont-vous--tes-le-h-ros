#include "FourChoicesLevel.hpp"
FourChoicesLevel::FourChoicesLevel(const QString & text,const QList<QString> & buttonsName,const QList<QString> & effectList,const QList<QString> & linkList,const LevelType levelType):Level(linkList,effectList,levelType),_buttonsName(buttonsName),_text(text)
{
}

FourChoicesLevel::~FourChoicesLevel()
{
}
