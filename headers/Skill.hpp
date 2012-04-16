#ifndef SKILL
#define SKILL
#include <QString>
class Skill
{
protected:
  int _damage;
  int _cost;
  QString _name;
  QString _type;
public:
  Skill(const int & damage,const int & cost, const QString & name,const QString & type);
  ~Skill();
};
#endif
