# Código Básico em Raylib (C)


```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Meu Jogo");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello World", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que cada parte faz

## 1. Criar a janela

```c
InitWindow(800, 600, "Meu Jogo");
```

Cria uma janela:

- largura = 800
- altura = 600
- título = `"Meu Jogo"`

---

## 2. Loop principal do jogo

```c
while (!WindowShouldClose())
```

Isso significa:

> “repita tudo enquanto o jogador NÃO fechar a janela”.

Aqui acontece o famoso:

- game loop
- loop de renderização
- loop principal

Todo jogo funciona assim.

---

# Estrutura do loop gráfico

## Começar desenho

```c
BeginDrawing();
```

Informa para a GPU:

> “vou começar a desenhar a tela”.

---

## Limpar a tela

```c
ClearBackground(RAYWHITE);
```

Pinta o fundo inteiro de branco.

Sem isso:
- os frames antigos ficam acumulando
- gera “fantasmas” na tela

---

## Desenhar texto

```c
DrawText("Hello World", 10, 10, 20, BLACK);
```

Parâmetros:

| Valor           | Significado      |
|---              |---               |
| `"Hello World"` | texto            |
| `10`            | posição X        |
| `10`            | posição Y        |
| `20`            | tamanho da fonte |
| `BLACK`         | cor              |

---

## Finalizar desenho

```c
EndDrawing();
```

Entrega o frame pronto para a GPU mostrar na tela.

É como:

> “ok GPU, pode exibir”.

---

## Fechar janela

```c
CloseWindow();
```

Libera memória e encerra corretamente.

---

# Fluxo visual do programa

```text
InitWindow()

↓ LOOP INFINITO

BeginDrawing()
    ↓
ClearBackground()
    ↓
DrawText()
    ↓
EndDrawing()

↓
CloseWindow()
```

---

# O que esse programa é?

Esse é o equivalente ao:

```c
printf("Hello World");
```

só que no mundo gráfico/game.

Ele é:
- o menor programa gráfico funcional
- base de praticamente qualquer jogo em raylib
- início de engines 2D

---

# O que acontece internamente

A raylib usa APIs gráficas do sistema:

- OpenGL
- GLFW
- GPU Driver
- Double Buffering


Componente 	Onde encontrar?
# OpenGL	Embutido no Driver da GPU (opengl32.dll no Windows).
# GLFW	Na pasta que você definiu no seu projeto ou em /usr/include (Linux).
# GPU Driver	Pastas de sistema e software da fabricante (NVIDIA/AMD/Intel).
# Double Buffering	Espaço virtual na memória VRAM da placa de vídeo.




Então quando você faz:

```c
DrawText(...)
```

na verdade:
1. a CPU envia comandos
2. a GPU renderiza
3. o monitor mostra o frame

---

# Próximo passo natural

Depois disso normalmente vem:

## Movimento

```c
x += 1;
```

## Sprites

```c
DrawTexture();
```

## Som

```c
PlaySound();
```

## Input

```c
IsKeyPressed(KEY_SPACE)
```

## Física

colisão, gravidade, etc.

---

# Resultado esperado

Você verá:

- uma janela branca
- escrito “Hello World”
- texto preto no canto superior esquerdo
