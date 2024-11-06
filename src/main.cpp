#include <raylib.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Set up the camera
    Camera3D camera = {};
    camera.position = (Vector3){ 8.0f, 8.0f, 8.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 55.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type


    InitWindow(screenWidth, screenHeight, "GHDraylib");

    SetTargetFPS(60);
    // DisableCursor();
    SetConfigFlags(FLAG_MSAA_4X_HINT);


    // Main loop (ESC to exit)
    bool firstFrame = true;
    while(!WindowShouldClose())
    {
        // Update
        UpdateCamera(&camera, CAMERA_ORBITAL);
        // Draw
        BeginDrawing();

        // bg
        ClearBackground(Color{25, 25, 25, 255});

        // 3D stuff
        BeginMode3D(camera);
        // cube
        DrawCube(Vector3{0, 1, 0}, 2.0f, 2.0f, 2.0f, RED);
        // light

        DrawGrid(10, 1.0f);
        EndMode3D();


        // text
        int textWidth = MeasureText("GHDraylib", 40);
        DrawText("GHDraylib", screenWidth/2-textWidth/2, 15, 40, RAYWHITE);

        // fps
        DrawFPS(10, 10);

        // sphere
        // DrawSphere(Vector3{0, 0, 2}, 1, Color{255, 255, 255, 255});
        // DrawSphereWires(Vector3{0, 0, 0}, 1, 8, 8, Color{255, 255, 255, 255});

        // DrawGrid(10, 1);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}