#include <stdio.h>
#include <raylib.h>
#include <SDL3/SDL.h>

int setup(void) {

};
int main(void)
{

    InitWindow(1440, 800, "Teste de Cu");
        SetTargetFPS(30);
        double x = 200;
        double y = 200;
        double velh = 0;
        double velv = 0;
        double accel = 0.1;
        double atrito = 1;
        double velmax = 5;

        while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, 0, 1440, 800, BLACK);
        DrawRectangle(x, y, 100, 100, RED);
        DrawText(TextFormat("Posição do Retangulo: VelH=%.4f Y=%.0d", velh, y), 0, 0, 20, RED);
        DrawFPS(0, 20);

        if (IsKeyDown(KEY_LEFT_SHIFT)) { 
            accel = 0.3;
            velmax = 8;
        }else{
            accel = 1;
            velmax = 5;
        };
        
        if (IsKeyDown(KEY_D) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
            velh += accel;
            
            if (velh >= velmax) {
                velh = velmax;
                
            };
           
        };
        
        

        if (IsKeyDown(KEY_A) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
            velh -= accel;
            
            if (velh <= -velmax) {
                velh = -velmax;
                
            };
            
        };
        
        if (IsKeyDown(KEY_S) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
            velv += accel;
            
            if (velv >= velmax) {
                velv = velmax;
                
            };
        
        };
        
        if (IsKeyDown(KEY_W) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) {
            velv -= accel;
            
            if (velv <= -velmax) {
                velv = -velmax;
                
            };
         
        };

        if (!IsKeyDown(KEY_D) && !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) && !IsKeyDown(KEY_A) && !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
            if (velh > 0) {
            velh -= atrito;
            };

            if (velh < 0) {
            velh += atrito;
            };
           
        };
        
        

        
        
        if (!IsKeyDown(KEY_W) && !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) && !IsKeyDown(KEY_S) && !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
            if (velv > 0) {
            velv -= atrito;
            };

            if (velv < 0) {
            velv += atrito;
            };
         
        };

        

        
        x += velh;
        y += velv;
        
        EndDrawing();

    };
    return 0;

}