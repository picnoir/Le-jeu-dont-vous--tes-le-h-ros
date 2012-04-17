#include "Level.hpp"
Level::Level(const QList<QString> & linkList,const QList<QString> & textEffectList, const LevelType levelType):_linkList(linkList),_textEffectList(textEffectList),_levelType(levelType)
{
}

Level::~Level()
{
}
