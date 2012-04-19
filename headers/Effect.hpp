/*
Cette classe permet d'encapsuler les différents effets des attaques/transitions
 */
#ifndef EFFECT
#define EFFECT
class Effect
{
protected:
  int _hp;
  int _cp;
public:
  Effect(int hp,int cp);
  int getHp(){return _hp;}
  int getCp(){return _cp;}
  ~Effect();
};
#endif
