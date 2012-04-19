/**
Classe encapsulant les différents paramètres d'un personnage (joueur ou non joueur)
 */
#ifndef PEOPLE
#define PEOPLE
#include "Skill.hpp"
#include <QList>
class People
{
protected:
  int _hp;
  int _cp;
  QList<Skill> _skills;
public:
  People(int hp,int cp,const QList<Skill> & skills);
  int getHp(){return _hp;}
  int getCp(){return _cp;}
  void setHp(int hp){_hp=hp;}
  void setCp(int cp){_cp=cp;}
  ~People();
};
#endif
