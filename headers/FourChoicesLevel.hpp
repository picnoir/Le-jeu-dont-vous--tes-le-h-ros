/*
Classe dérivée de level. C'est une classe qui contient toutes les informations d'un niveau du type Four choices.
 */
#ifndef FOURCHOICESLEVEL
#define FOURCHOICESLEVEL
#include "Level.hpp"
#include <QString>
#include <QList>
class FourChoicesLevel: public Level
{
protected:
  QList<QString> _buttonsName;
  QString _text;
public:
  FourChoicesLevel(const QString & text,const QList<QString> & buttonsName,const QList<QString> & effectList,const QList<QString> & linkList, const LevelType levelType);
  virtual QList<QString> getButtonsName(){return _buttonsName;}
  virtual QString getText(){return _text;}
  virtual ~FourChoicesLevel();
};
#endif
