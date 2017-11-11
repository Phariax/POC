#include "raylib.h"
#include "public.h"

#define MAX_ASTEROIDS 15
// Variable declarations

static Background background;
static Player player;
static Asteroid asteroid[MAX_ASTEROIDS];




int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1920;
	int screenHeight = 1080;
	/*
	int screenWidth = 800;
	int screenHeight = 600;
	*/


	InitWindow(screenWidth, screenHeight, "Galactica");

	background.texture = LoadTexture("resources/galaxy.png");
	//gameOver = false;


	//Player
	player.texture = LoadTexture("resources/viperMarkIII.png");
	player.width = 128;
	player.height = 128;
	player.rec.x = 0;
	player.rec.y = 0;
	spawnPlayer();


	//Asteroids

	for (int i = 0; i <= MAX_ASTEROIDS; i++)
	{
		asteroid[i].rec.width = 64;
		asteroid[i].rec.height = 64;
		asteroid[i].rec.x = GetRandomValue(screenWidth-512, (screenWidth*4) );
		asteroid[i].rec.y = GetRandomValue(0, screenHeight - asteroid[i].rec.height);
		asteroid[i].speed.x = 5;
		asteroid[i].speed.x = 5;
		asteroid[i].texture = LoadTexture("resources/asteroid1.png");
	

	}

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

			if (asteroid[i].pos.x < -128)
			{
				asteroid[i].pos.x = GetRandomValue(screenWidth-512, screenWidth*3);
				asteroid[i].pos.y = GetRandomValue(0, screenHeight - asteroid[i].rec.height);
			}
		}
		

		//Player collision with asteroid
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (CheckCollisionRecs(player.rec, asteroid[i].rec)) {
				DrawText("We are colliding", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, WHITE);
			}

		}
		playerMovement();
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		HideCursor();

		
			DrawTextureV(background.texture, background.pos, WHITE);
			//DrawRectangleT(player.texturePos.x, player.texturePos.y, 128, 128, LIGHTGRAY);
			
			for (int i = 0; i < MAX_ASTEROIDS; i++)
			{
				DrawTextureV(asteroid[i].texture, asteroid[i].pos, WHITE);
			}
		
			DrawTextureV(player.texture, playerMovement(), WHITE);



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