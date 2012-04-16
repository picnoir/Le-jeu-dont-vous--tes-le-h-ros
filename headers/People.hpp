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
  ~People();
};
#endif
