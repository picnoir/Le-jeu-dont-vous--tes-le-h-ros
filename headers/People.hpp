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
  People(const int & hp, const int & cp, const QList<Skill> & skills);
  int getHp(){return _hp;}
  int getCp(){return _cp;}
  ~People();
};
#endif
