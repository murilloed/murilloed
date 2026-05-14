#include "raylib.h"

int main(void) {
  // Configurações da janela
  const int screenWidth = 960;
  const int screenHeight = 540;

  InitWindow(screenWidth, screenHeight, "Tennis For One");

  // Variáveis da Raquete (jogador único na esquerda)
  Rectangle paddle = {50, screenHeight / 2 - 50, 20, 100};

  // Variáveis da Bola
  Vector2 ballPosition = {screenWidth / 2, screenHeight / 2};
  Vector2 ballSpeed = {5, 5};
  int ballRadius = 10;

  int score = 0;
  bool gameOver = false;

  SetTargetFPS(60);

  while (!WindowShouldClose()) // Detecta se a janela foi fechada ou ESC foi
                               // pressionado
  {
    // ----------------------------------------------------------------------------------
    // Atualização da Lógica do Jogo
    // ----------------------------------------------------------------------------------
    if (!gameOver) {
      // Movimentação da Raquete seguindo o Mouse
      paddle.y = GetMouseY() - paddle.height / 2;

      // Limites da Raquete para não sair da tela
      if (paddle.y < 0) paddle.y = 0;
      if (paddle.y > screenHeight - paddle.height)
        paddle.y = screenHeight - paddle.height;


      // Movimentação da Bola
      ballPosition.x += ballSpeed.x;
      ballPosition.y += ballSpeed.y;

      // Colisão da Bola com o teto e o chão
      if (ballPosition.y >= (screenHeight - ballRadius) ||
          ballPosition.y <= ballRadius) {
        ballSpeed.y *= -1;
      }

      // Colisão da Bola com a parede direita (onde ela "rebate" sozinha)
      if (ballPosition.x >= (screenWidth - ballRadius)) {
        ballSpeed.x *= -1;
      }

      // Colisão da Bola com a Raquete
      if (CheckCollisionCircleRec(ballPosition, ballRadius, paddle)) {
        if (ballSpeed.x <
            0) // Rebate apenas se a bola estiver indo para a esquerda
        {
          ballSpeed.x *= -1; // Inverte a direção x (vai pra direita)

          // Aumenta a velocidade ligeiramente a cada rebatida para ficar mais
          // difícil
          ballSpeed.x += 0.5f;
          if (ballSpeed.y > 0)
            ballSpeed.y += 0.5f;
          else
            ballSpeed.y -= 0.5f;

          score++;
        }
      }

      // Condição de Game Over (Bola passou da raquete, ou seja, tocou na parede
      // esquerda)
      if (ballPosition.x <= 0) {
        gameOver = true;
      }
    } else {
      // Reiniciar o jogo apertando ENTER
      if (IsKeyPressed(KEY_ENTER)) {
        paddle.y = screenHeight / 2 - 50;
        ballPosition = (Vector2){screenWidth / 2, screenHeight / 2};
        ballSpeed = (Vector2){5, 5};
        score = 0;
        gameOver = false;
      }
    }

    // ----------------------------------------------------------------------------------
    // Desenho (Renderização)
    // ----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (!gameOver) {
      // Desenha a raquete e a bola
      DrawRectangleRec(paddle, BLACK);
      DrawCircleV(ballPosition, ballRadius, MAROON);

      // Desenha o placar
      DrawText(TextFormat("Pontos: %i", score), 350, 20, 30, LIGHTGRAY);
    } else {
      // Tela de Game Over
      DrawText("GAME OVER", 280, 150, 50, RED);
      DrawText(TextFormat("Pontuação Final: %i", score), 300, 220, 20,
               DARKGRAY);
      DrawText("Pressione ENTER para jogar novamente", 210, 260, 20, DARKGRAY);
    }

    EndDrawing();
  }

  // --------------------------------------------------------------------------------------
  // Finalização
  // --------------------------------------------------------------------------------------
  CloseWindow(); // Fecha a janela e o contexto OpenGL

  return 0;
}
