#include "raylib.h"

#define MAX_COLUMNS 20

typedef struct Player{
	Vector3 position;

} Player;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    Player player;
    player.position = (Vector3){0,0,0};

    
    // Define the camera to look into our 3d world (position, target, up vector)
    Camera camera = {0};
    camera.position = (Vector3){-4.0f, -1.6f, 0};
    camera.target = (Vector3){0.0f, 1.8f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float mapSizeX = 100.f;
    float mapSizeZ = 100.f;

    // Generates some random columns
    //float heights[MAX_COLUMNS] = {0};
    //Vector3 positions[MAX_COLUMNS] = {0};
    //Color colors[MAX_COLUMNS] = {0};

    //for (int i = 0; i < MAX_COLUMNS; i++)
    //{
    //    heights[i] = (float)GetRandomValue(1, 12);
    //    positions[i] = (Vector3){(float)GetRandomValue(-15, 15), heights[i] / 2.0f, (float)GetRandomValue(-15, 15)};
    //    colors[i] = (Color){GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255};
    //}

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground((Color){0, 0, 0, 255});

        BeginMode3D(camera);

        DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){mapSizeX, mapSizeZ}, (Color){0, 0, 0, 255}); // Draw ground

        for (int z = -100; z < 100; z+=5){
            for (int x = -100; x < 100; x+=5)
            {
                DrawLine3D((Vector3){x, 0.05f, z}, (Vector3){x * -1, 0.05f, z}, (Color){100, 140, 255, 255});
                DrawLine3D((Vector3){x, 0.05f, z}, (Vector3){x, 0.05f, z * -1}, (Color){100, 140, 255, 255});
            }
        }

        DrawCylinder(player.position, 0.3f, 0.3f, 1.8f, 10, (Color){200,200,255, 255});

        //DrawSphereWires((Vector3){0,1,0},1, 6, 10, (Color){140, 140, 255, 255});



        //DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
        //DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
        //DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

    // Draw some cubes around
        //for (int i = 0; i < MAX_COLUMNS; i++)
        //{
        //    DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
        //    DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
        //}

        EndMode3D();

        DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 220, 70, BLUE);

        DrawText("First person camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}