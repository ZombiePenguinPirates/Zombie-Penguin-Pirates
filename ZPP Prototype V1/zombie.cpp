#include "main.h"

ZOMBIE::ZOMBIE():OBJECT()					//initialise objects part of unit first
{
	team = 0;								//units team
	attackTimer = 0;						//frames until unit can attack
	attackDelay = 20;						//frames to wait after attacking before it can attack again
	health = 5;								//unit hp
	maxHealth = 5;							//unit max hp
	minDamage = 0;							//min unit dmg
	maxDamage = 5;							//max unit dmg
	moveOrder = pos;						//units movement order
	attack = false;							//unit attacking?
	selected = false;						//unit selected?
	collision.x = collision.y =	collision.width = collision.height = 0;								//used for collision detection only used internaly
	collisionside.bot = collisionside.left = collisionside.right = collisionside.top = false;		//used for collision detection only used internaly
	dead = false;
}

ZOMBIE::~ZOMBIE()
{
}

void ZOMBIE::SetCollision(SQUARE &col)
{
	collision.x = col.width;
	collision.y = col.height;
	collision.width = col.x;
	collision.height = col.y;
	CollisionSide();
}

bool ZOMBIE::CollisionCheck(OBJECT &object)
{
	bool temp = false;
	//figure out which type of collision to use
	switch(type)
	{
	case 0:
		switch(object.GetType())
		{
		case 0:
			if (BoxCollisionCheck(object))
			{
				collisionDetected = true;
				temp = true;
			}
			break;
		case 5:
			if (CirleVSSquareCollisionCheck(object.GetPos(), pos, size, object.GetRadius()))
			{
				//check how far into edge 1 the collision is
				collision.x = pos.x + size.x - object.GetPos().x;
				//check how far into edge 2 the collision is
				collision.width = object.GetPos().x + object.GetRadius() - pos.x;

				//check how far into edge 3 the collision is
				collision.y = pos.y + size.y - object.GetPos().y;
				//check how far into edge 4 the collision is
				collision.height = object.GetPos().y + object.GetRadius() - pos.y;

				collisionDetected = true;
				temp = true;
			}
			break;
		}
		break;
	case 5:
		switch(object.GetType())
		{
		case 0:
			if (CirleVSSquareCollisionCheck(pos, object.GetPos(), object.GetSize(), radius))
			{
				//check how far into edge 1 the collision is
				collision.x = pos.x + radius - object.GetPos().x;
				//check how far into edge 2 the collision is
				collision.width = object.GetPos().x + object.GetSize().x - pos.x - radius;

				//check how far into edge 3 the collision is
				collision.y = pos.y + radius - object.GetPos().y;
				//check how far into edge 4 the collision is
				collision.height = object.GetPos().y + object.GetSize().y - pos.y - radius;

				collisionDetected = true;
				temp = true;
			}
			break;
		case 5:
			if (CirleCollisionCheck(object))
			{
				collisionDetected = true;
				temp = true;
			}
			break;
		}
		break;
	}
	
	if (temp)
	{
		if (!collisionside.top || !collisionside.bot || !collisionside.left || !collisionside.right)
		{
			CollisionSide();
		}
	}
	return temp;
}

bool ZOMBIE::CollisionCheck(ZOMBIE &object)
{
	bool temp = false;
	//figure out which type of collision to use
	switch(type)
	{
	case 0:
		switch(object.GetType())
		{
		case 0:
			if (BoxCollisionCheck(object))
			{
				collisionDetected = true;
				temp = true;
			}
			break;
		case 5:
			if (CirleVSSquareCollisionCheck(object.GetPos(), pos, size, object.GetRadius()))
			{
				//check how far into edge 1 the collision is
				collision.x = pos.x + size.x - object.GetPos().x;
				//check how far into edge 2 the collision is
				collision.width = object.GetPos().x + object.GetRadius() - pos.x;

				//check how far into edge 3 the collision is
				collision.y = pos.y + size.y - object.GetPos().y;
				//check how far into edge 4 the collision is
				collision.height = object.GetPos().y + object.GetRadius() - pos.y;

				collisionDetected = true;
				temp = true;
			}
			break;
		}
		break;
	case 5:
		switch(object.GetType())
		{
		case 0:
			if (CirleVSSquareCollisionCheck(pos, object.GetPos(), object.GetSize(), radius))
			{
				//check how far into edge 1 the collision is
				collision.x = pos.x + radius - object.GetPos().x;
				//check how far into edge 2 the collision is
				collision.width = object.GetPos().x + object.GetSize().x - pos.x - radius;

				//check how far into edge 3 the collision is
				collision.y = pos.y + radius - object.GetPos().y;
				//check how far into edge 4 the collision is
				collision.height = object.GetPos().y + object.GetSize().y - pos.y - radius;

				collisionDetected = true;
				temp = true;
			}
			break;
		case 5:
			if (CirleCollisionCheck(object))
			{
				collisionDetected = true;
				temp = true;
			}
			break;
		}
		break;
	}
	
	if (temp)
	{
		object.SetCollision(collision);
		if (!collisionside.top || !collisionside.bot || !collisionside.left || !collisionside.right)
		{
			CollisionSide();
		}
	}
	return temp;
}

void ZOMBIE::CollisionSide()
{
	//if more into left edge
	if(collision.width < collision.x)
		collisionside.left = true;
	
	//if more into right edge
	if(collision.x < collision.width)
		collisionside.right = true;	

	//if more into bot edge
	if(collision.height < collision.y)
		collisionside.bot = true;

	//if more into top edge
	if(collision.y < collision.height)
		collisionside.top = true;
}

bool ZOMBIE::BoxCollisionCheck(OBJECT &object)
{
	//if theres a collision return true (ask if you wanna know how this works)
	if ((pos.x + size.x >= object.GetPos().x) && (pos.x <= object.GetPos().x + object.GetSize().x)
		&& (pos.y + size.y >= object.GetPos().y) && (pos.y <= object.GetPos().y + object.GetSize().y)) 
	{
		//check how far into edge 1 the collision is
		collision.x = pos.x + size.x - object.GetPos().x;
		//check how far into edge 2 the collision is
		collision.width = object.GetPos().x + object.GetSize().x - pos.x;

		//check how far into edge 3 the collision is
		collision.y = pos.y + size.y - object.GetPos().y;
		//check how far into edge 4 the collision is
		collision.height = object.GetPos().y + object.GetSize().y - pos.y;
		
		return true;
	}
		
	return false;
}

bool ZOMBIE::CirleCollisionCheck(OBJECT &object)
{
	int x, y, r;
	x = (object.GetPos().x + object.GetSize().x/2) - (pos.x + size.x/2);
	y = (object.GetPos().y + object.GetSize().y/2) - (pos.y + size.y/2);
	r = object.GetRadius() + radius;

	//if theres a collision return true (ask if you wanna know how this works)
	if ((x * x) + (y * y) < (r * r))
	{
		//check how far into edge 1 the collision is
		collision.x = pos.x + size.x - object.GetPos().x;
		//check how far into edge 2 the collision is
		collision.width = object.GetPos().x + object.GetSize().x - pos.x;

		//check how far into edge 3 the collision is
		collision.y = pos.y + size.y - object.GetPos().y;
		//check how far into edge 4 the collision is
		collision.height = object.GetPos().y + object.GetSize().y - pos.y;

		return true;
	}

	return false;
}

bool ZOMBIE::CirleVSSquareCollisionCheck(POINT circle, POINT square, POINT edges, int r)
{
	POINT Distance;
	float cornerDistance;
	
	//distance from center of square to center of circle
	Distance.x = abs(circle.x + radius - square.x - edges.x/2);
    Distance.y = abs(circle.y + radius - square.y - edges.y/2);

	//too far
    if (Distance.x > (edges.x/2 + r)) { return false; }
    if (Distance.y > (edges.y/2 + r)) { return false; }

	//edges of square
    if (Distance.x <= (edges.x/2)) { return true; } 
    if (Distance.y <= (edges.y/2)) { return true; }

	//corners
    cornerDistance = ((Distance.x - edges.x/2) * (Distance.x - edges.x/2)) +
                         ((Distance.y - edges.y/2) * (Distance.y - edges.y/2));

    return (cornerDistance <= (r * r));
}

void ZOMBIE::SetMoveOrder(int x, int y)
{
	moveOrder.x = x;
	moveOrder.y = y;

	//check collision with map edge if none move
	if (moveOrder.x < 0) moveOrder.x = 0;
	else if (moveOrder.x > (TilesSize * xtiles) - size.x) moveOrder.x = (TilesSize * xtiles) - size.x;
	if (moveOrder.y < 0) moveOrder.y = 0;
	else if (moveOrder.y > (TilesSize * ytiles) - size.y) moveOrder.y = (TilesSize * ytiles) - size.y;
}

void ZOMBIE::Move()
{
	//if theres a collision
	if (collisionDetected)
	{
		//check if unit can move on x
		if (pos.x < moveOrder.x && !collisionside.right) pos.x++;
		else if (pos.x > moveOrder.x && !collisionside.left) pos.x--;
		//check if unit can move on y
		if (pos.y < moveOrder.y && !collisionside.top) pos.y++;
		else if (pos.y > moveOrder.y && !collisionside.bot) pos.y--;
	}
	//otherwise
	else
	{
		//move x
		if (pos.x < moveOrder.x) pos.x++;
		else if (pos.x > moveOrder.x) pos.x--;

		//move y
		if (pos.y < moveOrder.y) pos.y++;
		else if (pos.y > moveOrder.y) pos.y--;
	}

	collisionside.bot = collisionside.left = collisionside.right = collisionside.top = false;
}

int ZOMBIE::GetDamage()
{
	
	int dmg = 0;
	if(attackTimer == 0)
	{
		attackTimer = attackDelay;
		//get random number within range (max - min + 1 = dmg range, ask for better explenation if needed)
		dmg = rand() % (maxDamage - minDamage + 1);
		//add min dmg
		dmg += minDamage;
	}
	else attackTimer--;
	return dmg;
}

void ZOMBIE::Render(BUFFER &pBuffer, POINT mappos)
{
	if (!dead)
	{
		//if unit on screen draw unit
		if ((pos.x + size.x > mappos.x)
			&& (pos.x < mappos.x + WIDTH)
			&& (pos.y + size.y > mappos.y)
			&& (pos.y < mappos.y + HEIGHT))
		{
			//draw unit
			TransparentStretchBitmap(pBuffer, pic, pos.x - mappos.x, pos.y - mappos.y, size.x, size.y, 0, 0,  imagesize.x, imagesize.y);
			//if unit selected
			if (selected)
			{
				//draw area around unit (works in the same way as mouse drag area)
				StretchBitmap(pBuffer, 3, pos.x - mappos.x, pos.y - mappos.y, size.x, 1, 0, 0, 1, 1);
				StretchBitmap(pBuffer, 3, pos.x - mappos.x, pos.y + size.y - mappos.y - 1, size.x, 1, 0, 0, 1, 1);
				StretchBitmap(pBuffer, 3, pos.x - mappos.x, pos.y - mappos.y, 1, size.y, 0, 0, 1, 1);
				StretchBitmap(pBuffer, 3, pos.x + size.x - mappos.x - 1, pos.y - mappos.y, 1, size.y, 0, 0, 1, 1);

				StretchBitmap(pBuffer, 0, pos.x - mappos.x + 1, pos.y + size.y - mappos.y - 3, (size.x - 2) * ((float)health/(float)maxHealth), 3, 0, 0, 1, 1);
			}
		}
	}
}