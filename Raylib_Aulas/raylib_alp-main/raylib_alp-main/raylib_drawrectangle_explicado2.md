# Desenhando um Retângulo com Raylib (C)

Este é um exemplo básico usando a biblioteca raylib para criar uma janela gráfica e desenhar um retângulo azul na tela.



```c
#include "raylib.h"

int main()
{
    InitWindow(800, 450, "basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(100, 100, 100, 100, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que esse programa faz?

Esse programa:

- cria uma janela
- mantém ela aberta em um loop
- limpa a tela a cada frame
- desenha um retângulo azul
- atualiza a tela continuamente

---

# Explicação linha por linha

## Importando a raylib

```c
#include "raylib.h"
```

Importa a biblioteca raylib.

Ela fornece funções para:

- gráficos 2D
- áudio
- teclado
- mouse
- colisão
- jogos

---

# Função principal

```c
int main()
```

É o ponto de entrada do programa.

Todo programa em C começa pela função `main()`.

---

# Criando a janela

```c
InitWindow(800, 450, "basic window");
```

Cria a janela gráfica.

Parâmetros:

| Valor             | Significado      |
|--                -|--               -|
| `800`             | largura          |
| `450`             | altura           |
| `"basic window"`  | título da janela |

---

# Loop principal

```c
while (!WindowShouldClose())
```

Repete continuamente enquanto o usuário não fechar a janela.

Esse loop é chamado de:

- game loop
- render loop
- loop principal

Todo jogo funciona com esse conceito.

---

# Início do desenho

```c
BeginDrawing();
```

Informa à GPU que um novo frame será desenhado.

Tudo que estiver entre:

```c
BeginDrawing();
```

e

```c
EndDrawing();
```

será renderizado na tela.

---

# Limpando a tela

```c
ClearBackground(RAYWHITE);
```

Pinta o fundo da janela de branco.

Sem isso:
- os desenhos antigos ficam acumulados
- surgem rastros na tela

---

# Desenhando o retângulo

```c
DrawRectangle(100, 100, 100, 100, BLUE);
```

Desenha um retângulo azul.

Parâmetros:

| Parâmetro | Valor | Significado |
|--       -|--     -|-          --|
| x        | 100    | posição horizontal |
| y        | 100    | posição vertical |
| largura  | 100    | tamanho horizontal |
| altura   | 100    | tamanho vertical |
| cor      | BLUE   | cor do retângulo |

---

# Como funciona o sistema de coordenadas

A tela funciona como um plano cartesiano invertido.

O ponto `(0,0)` fica no canto superior esquerdo.

```text
(0,0) --------------------→ X
  |
  |
  |
  ↓
  Y
```

Então:

```c
DrawRectangle(100, 100, ...)
```

significa:
- 100 pixels para direita
- 100 pixels para baixo

---

# Finalizando o desenho

```c
EndDrawing();
```

Finaliza o frame e envia para a GPU exibir na tela.

É como dizer:

> “GPU, pode mostrar o frame pronto”.

---

# Fechando corretamente

```c
CloseWindow();
```

Fecha a janela e libera memória.

---

# Fluxo completo do programa

```text
InitWindow()

↓ LOOP

BeginDrawing()
    ↓
ClearBackground()
    ↓
DrawRectangle()
    ↓
EndDrawing()

↓
CloseWindow()
```

---

# O que acontece internamente?

Quando você chama:

```c
DrawRectangle(...)
```

acontece algo assim:

1. CPU envia comando gráfico
2. OpenGL processa
3. GPU desenha o retângulo
4. Monitor exibe o frame

---

# Resultado visual esperado

Você verá:

- uma janela branca
- um quadrado azul
- posicionado em `(100,100)`

---

# Como modificar o retângulo

## Mudar posição

```c
DrawRectangle(300, 200, 100, 100, BLUE);
```

---

## Mudar tamanho

```c
DrawRectangle(100, 100, 200, 50, BLUE);
```

---

## Mudar cor

```c
DrawRectangle(100, 100, 100, 100, RED);
```

---

# Cores disponíveis na raylib

Exemplos:

```c
RED
BLUE
GREEN
BLACK
WHITE
YELLOW
PURPLE
ORANGE
PINK
```

---

# Próximo passo natural

Depois disso normalmente vem:

## Movimento

```c
x += 5;
```

---

## Controle por teclado

```c
if (IsKeyDown(KEY_RIGHT))
{
    x += 5;
}
```

---

## Colisão

```c
CheckCollisionRecs();
```

---

## Sprites

```c
DrawTexture();
```

---

## Jogos 2D

- Pong
- Mario-like
- Plataforma
- Shooter
- RPG 2D

---

# Conceito importante

Esse código já é uma mini engine gráfica.

Você já possui:

- janela
- renderização
- loop de atualização
- desenho em tempo real
- comunicação com GPU

Isso é exatamente a base de praticamente todos os jogos 2D.
