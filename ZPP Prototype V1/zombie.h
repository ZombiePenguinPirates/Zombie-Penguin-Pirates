#ifndef _ZOMBIE_H				// If we haven't included this file							
#define _ZOMBIE_H				// Set a flag saying we included it

#define max_bullet_range 50
#include "main.h"

class BULLET
{
public:
	void moveBullet(BUFFER &pBuffer);
	BULLET(int positionX, int positionY, int targetX, int targetY);
	~BULLET();
	int getRange(){return range;}
	void increaseRange(){ ++range;}
protected:
	int velocityX, velocityY;
	int posX, posY;
	int range;
	HBITMAP display;
};

class ZOMBIE : public OBJECT
{
public:
	ZOMBIE();
	~ZOMBIE();

	BULLET *b;

	void SetTeam(int Team) {team = Team;};
	void SetHealth(int hp) {if (hp > maxHealth) health = maxHealth; else health = hp;};
	void SetMaxHealth(int hp) {maxHealth = hp;};
	void SetMinDamage(int dmg) {minDamage = dmg;};
	void SetMaxDamage(int dmg) {maxDamage = dmg;};
	void SetMoveOrder(int x, int y);
	void SetMoveOrder(POINT xy) {moveOrder = xy;};
	void SetAttackOrder(int numb) {unitNumb = numb; attack = true;};
	void StopAttack() {attack = false;};
	void Select(bool s) {selected = s;};
	void SetAttackTimer(int t) {attackTimer = t;};
	void SetAttackDelay(int d) {attackDelay = d;};
	void SetRanged(bool r) {ranged = r;};

	void LoseHealth(int dmg) {health -= dmg; if (health < 1) {dead = true; selected = false;}};

	void SetCollision(SQUARE &col);
	void ResetCollision() {collisionDetected = false;};

	bool CollisionCheck(OBJECT &object);
	bool CollisionCheck(ZOMBIE &object);
	bool GetRanged() {return ranged;};

	void Revive() {dead = false; health = maxHealth;};
	void Move();

	bool GetSelect() {return selected;};
	bool GetAttack() {return attack;};
	bool GetDead() { return dead;};
	int GetUnitNumb() {return unitNumb;};
	int GetTeam() {return team;};
	int GetHealth() {return health;};
	int GetDamage();
	SQUARE GetCollisions() {return collision;};

	void Render(BUFFER &pBuffer, POINT mappos);
	
protected:
	void CollisionSide();
	bool CirleCollisionCheck(OBJECT &object);
	bool BoxCollisionCheck(OBJECT &object);
	bool CirleVSSquareCollisionCheck(POINT circle, POINT square, POINT edges, int r);

	int team;
	int health;
	int maxHealth;
	int minDamage;
	int maxDamage;
	int attackTimer;
	int attackDelay;
	POINT moveOrder;
	SQUARE collision;
	BOOLSQUARE collisionside;
	bool collisionDetected;
	bool attack;
	int unitNumb;
	bool selected;
	bool dead;
	bool ranged;
	//bool extras[x];
	
};

#endif