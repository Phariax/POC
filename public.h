#ifndef PUBLIC_H
#define PUBLIC_H

///////////////////////////////////////
///PLAYER AND AI///////////////////////
///////////////////////////////////////


//Player
typedef struct Player {
	Vector2 pos;
	Vector2 texturePos;
	Texture2D texture;
	Rectangle rec;
	int width;
	int height;
	int health;
	int armor;
}Player;

///////////////////////////////////////
///ENVIRONMENT/////////////////////////
///////////////////////////////////////

//Background

typedef struct Background {
	Vector2 pos;
	Texture2D texture;
}Background;


//Asteroid

typedef struct Asteroid {
	Rectangle rec;
	Vector2 pos;
	Vector2 texturePos;
	Texture2D texture;
	bool active;
	int radius;
	int width;
	int height;
	int health;
	Vector2 speed;
}Asteroid;



///////////////////////////////////////
///POWERUPS////////////////////////////
///////////////////////////////////////



//
#endif // !PUBLIC_H

