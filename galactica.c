#include "raylib.h"
#include "public.h"

#define MAX_ASTEROIDS 15
// Variable declarations

static Background background;
static Player player;
static Asteroid asteroid[MAX_ASTEROIDS];
static Rectangle rec;
static bool collision;




int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1024;
	int screenHeight = 768;
	/*
	int screenWidth = 800;
	int screenHeight = 600;
	*/


	InitWindow(screenWidth, screenHeight, "Galactica");

	background.texture = LoadTexture("resources/galaxy.png");

	//Player
	player.texture = LoadTexture("resources/viperMarkIII.png");
	player.pos.x = (GetScreenWidth() - GetScreenWidth() + 50);
	player.pos.y = (GetScreenHeight() / 2);
	player.texturePos.x = player.pos.x;
	player.texturePos.y = player.pos.y;
	player.rec.width = 118;
	player.rec.height = 43;
	
	//Asteroids
	//activeAsteroids = MAX_ASTEROIDS;
	for (int i = 0; i <= MAX_ASTEROIDS; i++)
	{

		asteroid[i].active = true;
		asteroid[i].pos.x = GetRandomValue(screenWidth-512, (screenWidth*4) );
		asteroid[i].pos.y = GetRandomValue(0, screenHeight - asteroid[i].rec.height);
		asteroid[i].rec.x = asteroid[i].pos.x;
		asteroid[i].rec.y = asteroid[i].pos.y;
		asteroid[i].rec.y = asteroid[i].rec.y + 16;
		asteroid[i].rec.x = asteroid[i].rec.x + 16;
		asteroid[i].rec.height = 32;
		asteroid[i].rec.width = 32;
		asteroid[i].speed.x = 5;
		asteroid[i].speed.x = 5;
		asteroid[i].texture = LoadTexture("resources/asteroid1.png");
	

	}
	collision = false;
	//superfx = false;

	SetTargetFPS(60);

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here

		background.pos.x -= 1.1f;



		//Asteroid
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			(asteroid[i].pos.x -= asteroid[i].speed.x);
			(asteroid[i].rec.x -= asteroid[i].speed.x);
			if (asteroid[i].pos.x < -128)
			{
				asteroid[i].pos.x = GetRandomValue(screenWidth-512, screenWidth*3);
				asteroid[i].pos.y = GetRandomValue(0, screenHeight - asteroid[i].rec.height);
				asteroid[i].rec.x = asteroid[i].pos.x;
				asteroid[i].rec.y = asteroid[i].pos.y;
				asteroid[i].rec.y = asteroid[i].rec.y + 16;
				asteroid[i].rec.x = asteroid[i].rec.x + 16;
			}
		}


		if (IsKeyDown(KEY_D))(player.pos.x += 2.6f);
		if (IsKeyDown(KEY_A))(player.pos.x -= 2.9f);
		if (IsKeyDown(KEY_W))(player.pos.y -= 2.6f);
		if (IsKeyDown(KEY_S))(player.pos.y += 2.6f);

		if (player.pos.x <= 0)
			((player.pos.x = 0) && (player.rec.x = 0));
		if (player.pos.x + player.texture.width >= GetScreenWidth())
			((player.pos.x = GetScreenWidth() - player.texture.width) && (player.rec.x = GetScreenWidth() - player.texture.width));
		if (player.pos.y <= 0)
			((player.pos.y = 0) && (player.rec.y = 0));
		if (player.pos.y + player.texture.height >= GetScreenHeight())
			((player.pos.y = GetScreenHeight() - player.texture.height) && (player.rec.y = GetScreenHeight() - player.texture.height));

		player.texturePos.x = player.pos.x;
		player.texturePos.y = player.pos.y;
		player.rec.x = player.pos.x;
		player.rec.y = player.pos.y;
		

		//Player collision with asteroid
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (CheckCollisionRecs(player.rec, asteroid[i].rec)) {
				collision = true;
				
			}

		}		
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		HideCursor();

		
			DrawTextureV(background.texture, background.pos, WHITE);
			
			
			for (int i = 0; i < MAX_ASTEROIDS; i++)
			{
				DrawTextureV(asteroid[i].texture, asteroid[i].pos, WHITE);

				//Debug
				//DrawRectangleLines(asteroid[i].rec.x, asteroid[i].rec.y, 32, 32, YELLOW);
			}
		
			DrawTextureV(player.texture, player.pos, WHITE);
			

			//Collision and player pivots for debug
			//DrawRectangleLines(player.rec.x, player.rec.y, 118, 43, GRAY);
			//DrawRectangle(player.pos.x, player.pos.y, 10,10,ORANGE);
			//DrawRectangle(player.rec.x, player.rec.y, 5, 5, PINK);

			if (collision) {
				//DrawRectangle(screenWidth/2, screenHeight/2 , screenWidth, screenHeight	, WHITE);
			}
		


		//Debug
		DrawFPS(40, 40);
		

		EndDrawing();
		
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	UnloadTexture(background.texture);       // Texture unloading
	UnloadTexture(player.texture);
	UnloadTexture(asteroid[MAX_ASTEROIDS].texture);

	CloseWindow();                // Close window and OpenGL context
								  //--------------------------------------------------------------------------------------

	return 0;
}