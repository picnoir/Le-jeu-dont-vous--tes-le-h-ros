#include "FourChoicesLevel.hpp"
FourChoicesLevel::FourChoicesLevel(const QString & text,const QList<QString> & buttonsName,const QList<QString> & textEffectList,const QList<QString> & linkList,const LevelType levelType, const QList<Effect> & effectList):Level(linkList,textEffectList,levelType),_buttonsName(buttonsName),_text(text),_effectList(effectList)
{
}

FourChoicesLevel::~FourChoicesLevel()
{
}
