/*
Classe abstraite du niveau, elle sera dérivée pour être utilisée. Cette classe comporte les caractéristiques communes de tous les types de niveaux.
 */
#ifndef LEVEL
#define LEVEL
#include <QList>
#include <QString>
enum LevelType{FourChoices,Battle};
class Level
{
protected:
  QList<QString> _linkList;
  QList<QString> _effectList;
  LevelType _levelType;
public:
  Level(const QList<QString> & linkList,const QList<QString> & effectLists, const LevelType levelType);
  LevelType getLevelType(){return _levelType;}
  QString getLink(int number){return _linkList[number];}
  QString getEffectText(int number){return _effectList[number];}
  virtual QList<QString> getButtonsName()=0;
  virtual QString getText()=0;
  virtual ~Level();
};
#endif
