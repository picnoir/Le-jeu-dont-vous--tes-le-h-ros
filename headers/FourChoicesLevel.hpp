/*
Classe dérivée de level. C'est une classe qui contient toutes les informations d'un niveau du type Four choices.
 */
#ifndef FOURCHOICESLEVEL
#define FOURCHOICESLEVEL
#include "Level.hpp"
#include "Effect.hpp"
#include <QString>
#include <QList>
class FourChoicesLevel: public Level
{
protected:
  QList<QString> _buttonsName;
  QString _text;
  QList<Effect> _effectList;
public:
  FourChoicesLevel(const QString & text,const QList<QString> & buttonsName,const QList<QString> & textEffectList,const QList<QString> & linkList, const LevelType levelType,const QList<Effect> & effectList);
  virtual QList<QString> getButtonsName(){return _buttonsName;}
  virtual QString getText(){return _text;}
  virtual Effect getEffect(int number){return _effectList[number];}
  virtual ~FourChoicesLevel();
};
#endif
