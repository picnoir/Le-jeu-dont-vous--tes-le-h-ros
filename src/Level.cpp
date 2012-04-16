#include "Level.hpp"
Level::Level(const QList<QString> & linkList,const QList<QString> & effectList, const LevelType levelType):_linkList(linkList),_effectList(effectList),_levelType(levelType)
{
}

Level::~Level()
{
}
