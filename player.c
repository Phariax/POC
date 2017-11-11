#include "raylib.h"
#include "public.h"


static Player player;
static Asteroid asteroid;
static Rectangle rec;



Vector2 spawnPlayer()
{

	player.pos.x = (GetScreenWidth()-GetScreenWidth()+50);
	player.pos.y = (GetScreenHeight()/2);
	player.texturePos = player.pos;
	return player.pos;
}

Vector2 playerMovement()
{

	//Default movement
	if (IsKeyDown(KEY_D))player.pos.x += 2.6f;
	if (IsKeyDown(KEY_A))player.pos.x -= 2.9f;
	if (IsKeyDown(KEY_W))player.pos.y -= 2.6f;
	if (IsKeyDown(KEY_S))player.pos.y += 2.6f;

	
	//Preventing player from the boarders of the screen
	if (player.pos.x <= 0) 
		player.pos.x = 0;
	if (player.pos.x + player.texture.width >= GetScreenWidth())
		player.pos.x = GetScreenWidth() - player.texture.width*2;
	if (player.pos.y <= 0)
		player.pos.y = 0;
	if (player.pos.y + player.texture.height >= GetScreenHeight())
		player.pos.y = GetScreenHeight() - player.texture.height*2;
	

	return player.pos;
}

//Asteroid

/*Rectangle spawnAsteroid()
{

	asteroid.pos.x = GetRandomValue(GetScreenWidth() / 2, GetScreenWidth() + 1000);
	asteroid.pos.y = GetRandomValue(0, GetScreenHeight() - asteroid.height);
	asteroid.texturePos = asteroid.rec;
	return asteroid.rec;
}
*/
/*Vector2(*ptrSpawnAsteroid)(Vector2);

ptrSpawnAsteroid = &spawnAsteroid;

*/