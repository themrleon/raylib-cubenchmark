#include "raylib.h"
#include "rlgl.h"

int main(void)
{
    InitWindow(320, 240, "Cubenchmark");

    Camera3D camera = { 0 };
    camera.position   = (Vector3){ 5.0f, 5.0f, 5.0f };
    camera.target     = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up         = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy       = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float angle = 0.0f;
    float s = 1.0f;  // half-size of cube

    while (!WindowShouldClose())
    {
        angle += 1.5f;
        if (angle >= 360.0f) angle -= 360.0f;

	if (IsKeyPressed(KEY_Q)) break;                // Q to quit

        BeginDrawing();
        ClearBackground((Color){ 10, 10, 15, 255 });  // Very dark gray

        BeginMode3D(camera);

        rlPushMatrix();
        rlTranslatef(0.0f, 0.0f, 0.0f);
        rlRotatef(angle, 0.7f, 1.0f, 0.3f);

        // === 6 Faces with different colors (raylib 4.5 safe) ===

        // +Z (Front) - RED
        DrawTriangle3D((Vector3){-s,-s, s}, (Vector3){ s,-s, s}, (Vector3){ s, s, s}, RED);
        DrawTriangle3D((Vector3){-s,-s, s}, (Vector3){ s, s, s}, (Vector3){-s, s, s}, RED);

        // -Z (Back) - GREEN
        DrawTriangle3D((Vector3){-s,-s,-s}, (Vector3){-s, s,-s}, (Vector3){ s, s,-s}, GREEN);
        DrawTriangle3D((Vector3){-s,-s,-s}, (Vector3){ s, s,-s}, (Vector3){ s,-s,-s}, GREEN);

        // +Y (Top) - BLUE
        DrawTriangle3D((Vector3){-s, s,-s}, (Vector3){-s, s, s}, (Vector3){ s, s, s}, BLUE);
        DrawTriangle3D((Vector3){-s, s,-s}, (Vector3){ s, s, s}, (Vector3){ s, s,-s}, BLUE);

        // -Y (Bottom) - YELLOW
        DrawTriangle3D((Vector3){-s,-s,-s}, (Vector3){ s,-s,-s}, (Vector3){ s,-s, s}, YELLOW);
        DrawTriangle3D((Vector3){-s,-s,-s}, (Vector3){ s,-s, s}, (Vector3){-s,-s, s}, YELLOW);

        // +X (Right) - MAGENTA
        DrawTriangle3D((Vector3){ s,-s,-s}, (Vector3){ s, s,-s}, (Vector3){ s, s, s}, MAGENTA);
        DrawTriangle3D((Vector3){ s,-s,-s}, (Vector3){ s, s, s}, (Vector3){ s,-s, s}, MAGENTA);

        // -X (Left) - CYAN (manual color since CYAN not in 4.5)
        Color cyan = { 0, 255, 255, 255 };
        DrawTriangle3D((Vector3){-s,-s,-s}, (Vector3){-s,-s, s}, (Vector3){-s, s, s}, cyan);
        DrawTriangle3D((Vector3){-s,-s,-s}, (Vector3){-s, s, s}, (Vector3){-s, s,-s}, cyan);

        // White wireframe
        DrawCubeWires((Vector3){0,0,0}, 2.0f, 2.0f, 2.0f, WHITE);

        rlPopMatrix();
        EndMode3D();

        // White FPS
        DrawText(TextFormat("FPS: %02d", GetFPS()), 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

