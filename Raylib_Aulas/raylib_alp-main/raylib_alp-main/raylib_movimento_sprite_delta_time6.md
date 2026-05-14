# Movimento de Sprite com Delta Time no Raylib

Este exemplo mostra como criar movimento suave e profissional usando:

- sprites
- texturas
- Delta Time
- velocidade baseada no tempo
- loop infinito de animação

Esse é um modelo muito próximo do que jogos reais utilizam.

---

# Código Completo

```c
#include "raylib.h"

int main()
{
    float posX = -100; // posição do sprite (começa fora da tela à esquerda)

    Texture2D sprite;

    InitWindow(800, 450, "basic window");

    sprite = LoadTexture("sprite.png");

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 300;

        if (posX > 800)
        {
            posX = -100;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(sprite, posX, 10, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que esse programa faz?

O programa:

- cria uma janela
- carrega uma imagem
- move essa imagem horizontalmente
- usa velocidade baseada no tempo
- reinicia o sprite quando sai da tela

---

# Conceito principal

Agora o movimento é:

```text
baseado no tempo
```

e não mais:

```text
baseado em frames
```

Esse é um conceito extremamente importante no desenvolvimento de jogos.

---

# Variável de posição

```c
float posX = -100;
```

Cria uma variável chamada:

```c
posX
```

Ela representa:
- a posição horizontal do sprite

---

# Por que float?

Usamos:

```c
float
```

porque:
- o movimento usa números decimais
- o Delta Time retorna valores quebrados

Exemplo:

```text
0.016
0.032
0.008
```

---

# O que significa -100?

O sprite começa:
- fora da tela
- à esquerda

---

# Coordenadas da tela

A tela funciona assim:

```text
(0,0) ----------------------→ X
  |
  |
  |
  ↓
  Y
```

---

# Coordenadas negativas

```text
X = -100
```

significa:
- 100 pixels fora da tela

---

# Variável da textura

```c
Texture2D sprite;
```

Cria uma variável do tipo:

```c
Texture2D
```

Ela representa:
- uma imagem carregada na GPU

---

# Criando a janela

```c
InitWindow(800, 450, "basic window");
```

Cria a janela gráfica.

---

# Carregando a imagem

```c
sprite = LoadTexture("sprite.png");
```

Carrega a imagem:

```text
sprite.png
```

para memória gráfica.

---

# O que acontece internamente?

Internamente:

```text
1. Arquivo PNG é aberto
2. Imagem é decodificada
3. GPU recebe textura
4. Texture2D é criado
```

---

# Loop principal

```c
while (!WindowShouldClose())
```

Loop do jogo.

Executa continuamente.

---

# O conceito mais importante

```c
GetFrameTime()
```

---

# O que é GetFrameTime()?

Retorna:

```text
quanto tempo o último frame demorou
```

em segundos.

---

# Outro nome importante

GetFrameTime() também é chamado de:

```text
Delta Time
```

---

# O que é Delta Time?

Delta Time significa:

```text
tempo entre frames
```

---

# Exemplo real

## 60 FPS

Cada frame dura aproximadamente:

```text
0.016 segundos
```

---

## 30 FPS

Cada frame dura:

```text
0.033 segundos
```

---

# Movimento profissional

```c
posX += GetFrameTime() * 300;
```

---

# O que significa 300?

```text
300 pixels por segundo
```

---

# Fórmula usada

genui{"math_block_widget_always_prefetch_v2":{"content":"x = x + v \\cdot \\Delta t"}}

---

# Onde:

| Símbolo | Significado |
|---|---|
| x | posição |
| v | velocidade |
| Δt | Delta Time |

---

# O que isso resolve?

Agora:
- o movimento fica igual em qualquer computador
- FPS não altera velocidade real
- animação fica suave

---

# Comparação importante

## Método antigo

```c
posX++;
```

Problema:
- depende do FPS

---

# Método profissional

```c
posX += GetFrameTime() * 300;
```

Resultado:
- velocidade constante

---

# Verificando saída da tela

```c
if (posX > 800)
```

Verifica:
- se o sprite saiu da tela.

---

# Reiniciando posição

```c
posX = -100;
```

Coloca novamente fora da tela.

---

# Resultado visual

O sprite:
- entra pela esquerda
- atravessa a tela
- sai pela direita
- reaparece novamente

---

# Início do frame

```c
BeginDrawing();
```

Começa renderização.

---

# Limpando tela

```c
ClearBackground(RAYWHITE);
```

Pinta fundo branco.

---

# Desenhando o sprite

```c
DrawTexture(sprite, posX, 10, WHITE);
```

Desenha a textura na tela.

---

# Parâmetros

| Parâmetro | Significado |
|---|---|
| sprite | imagem |
| posX | posição horizontal |
| 10 | posição vertical |
| WHITE | cor original |

---

# O que WHITE faz?

Mantém a textura:
- sem alteração de cor

---

# Finalizando frame

```c
EndDrawing();
```

Mostra frame na tela.

---

# Problema importante

A textura não está sendo liberada.

---

# O correto seria

Antes de:

```c
CloseWindow();
```

usar:

```c
UnloadTexture(sprite);
```

---

# Versão profissional correta

```c
UnloadTexture(sprite);

CloseWindow();
```

---

# Fluxo completo

```text
Criar janela
    ↓
Carregar sprite
    ↓
Entrar no loop
    ↓
Calcular Delta Time
    ↓
Atualizar posição
    ↓
Verificar saída da tela
    ↓
Desenhar sprite
    ↓
Mostrar frame
    ↓
Repetir
```

---

# Resultado esperado

Você verá:
- uma janela branca
- um sprite se movendo suavemente
- velocidade constante
- movimento infinito

---

# Conceitos aprendidos

Você aprendeu:

- sprites
- texturas
- movimento profissional
- Delta Time
- velocidade baseada no tempo
- loop infinito
- coordenadas negativas
- renderização contínua

---

# Conceito fundamental

Jogos modernos normalmente usam:

```text
posição += velocidade × Delta Time
```

Essa é uma das fórmulas mais importantes da programação de games.
