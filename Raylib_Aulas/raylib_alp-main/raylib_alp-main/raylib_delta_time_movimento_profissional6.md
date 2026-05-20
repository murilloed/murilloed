# Movimento Profissional com Delta Time no Raylib (C)

Este exemplo mostra um conceito extremamente importante no desenvolvimento de jogos:

- movimento baseado no tempo
- Delta Time
- velocidade independente de FPS
- animação profissional

Agora você está saindo do movimento simples baseado em frames e entrando no modelo usado em jogos reais.

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

- carrega uma imagem
- move ela da esquerda para direita
- usa velocidade baseada no tempo
- faz o sprite voltar ao início
- cria movimento suave independente do FPS

---

# O grande conceito aqui

Antes você fazia:

```c
posX++;
```

Isso era:

```text
movimento baseado em frames
```

Agora você faz:

```c
posX += GetFrameTime() * 300;
```

Isso é:

```text
movimento baseado em tempo real
```

Esse é o padrão profissional usado em jogos modernos.

---

# Variável float

```c
float posX = -100;
```

Agora usamos:

```c
float
```

em vez de:

```c
int
```

---

# Por que usar float?

Porque agora o movimento pode ter valores decimais.

Exemplo:

```text
0.5
1.2
3.8
```

Isso cria:
- movimento suave
- precisão maior
- animações profissionais

---

# O que significa -100?

```c
float posX = -100;
```

O sprite começa:

```text
100 pixels fora da tela
```

à esquerda.

---

# Coordenadas negativas

A tela começa em:

```text
X = 0
```

Então:

```text
-100
```

fica fora da tela.

---

# Carregando a textura

```c
sprite = LoadTexture("sprite.png");
```

Carrega a imagem para GPU.

---

# O conceito mais importante do exemplo

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

# Exemplo real

## Se o jogo roda a 60 FPS

Cada frame dura aproximadamente:

```text
0.016 segundos
```

---

## Se roda a 30 FPS

Cada frame dura:

```text
0.033 segundos
```

---

# O que significa Delta Time?

Outro nome para:

```text
GetFrameTime()
```

é:

```text
Delta Time
```

---

# Delta Time significa

```text
tempo entre frames
```

Esse é um dos conceitos mais importantes da programação de jogos.

---

# A fórmula do movimento profissional

```c
posX += GetFrameTime() * 300;
```

---

# Vamos quebrar isso

## Parte 1

```c
GetFrameTime()
```

Tempo do frame.

---

## Parte 2

```c
300
```

Velocidade em:

```text
pixels por segundo
```

---

# Resultado final

```text
posição += tempo * velocidade
```

Essa é uma fórmula clássica da física.

---

# O que isso resolve?

Agora:
- o jogo roda igual em qualquer computador
- velocidade não depende do FPS
- animação fica consistente

---

# Comparação importante

## Método antigo

```c
posX++;
```

Problema:
- FPS alto = objeto muito rápido
- FPS baixo = objeto lento

---

# Método profissional

```c
posX += GetFrameTime() * velocidade;
```

Resultado:
- velocidade real constante

---

# Exemplo prático

## Computador 1

```text
60 FPS
```

## Computador 2

```text
144 FPS
```

Mesmo assim:
- o sprite se move na mesma velocidade real.

---

# Verificando saída da tela

```c
if (posX > 800)
{
    posX = -100;
}
```

---

# O que isso faz?

Se o sprite passar:
- da largura da janela

então:
- ele volta para esquerda.

---

# Resultado visual

O sprite:
- entra pela esquerda
- atravessa a tela
- sai pela direita
- reaparece novamente

---

# Sistema de loop infinito

Isso cria:
- movimento contínuo
- efeito cíclico
- animação infinita

---

# Início do frame

```c
BeginDrawing();
```

Começa renderização.

---

# Limpando a tela

```c
ClearBackground(RAYWHITE);
```

Pinta fundo branco.

---

# Desenhando o sprite

```c
DrawTexture(sprite, posX, 10, WHITE);
```

Agora a posição X:
- muda continuamente.

---

# O segredo da animação

Essa linha:

```c
posX += GetFrameTime() * 300;
```

é o coração da animação.

---

# Finalizando frame

```c
EndDrawing();
```

Mostra frame na tela.

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
Desenhar sprite
    ↓
Mostrar frame
    ↓
Repetir
```

---

# Conceito matemático

A fórmula usada é:

genui{"math_block_widget_always_prefetch_v2":{"content":"x = x + v \\cdot \\Delta t"}}

Onde:

| Símbolo | Significado |
|---|---|
| x | posição |
| v | velocidade |
| Δt | Delta Time |

---

# Isso vem da física

Essa fórmula é derivada de:

```text
posição = velocidade × tempo
```

---

# Jogos profissionais usam isso em:

- movimentação
- física
- câmera
- partículas
- gravidade
- IA
- animações

---

# Resultado visual esperado

Você verá:

- uma janela branca
- um sprite se movendo suavemente
- velocidade constante
- movimento infinito

---

# Problema no código atual

A textura não está sendo descarregada.

O ideal seria:

```c
UnloadTexture(sprite);
```

antes de:

```c
CloseWindow();
```

---

# Versão profissional correta

```c
UnloadTexture(sprite);

CloseWindow();
```

---

# Conceitos aprendidos

Você aprendeu:

- Delta Time
- GetFrameTime()
- movimento baseado em tempo
- velocidade independente de FPS
- loop infinito de animação
- coordenadas negativas
- física básica de jogos

---

# Conceito fundamental

A maioria dos jogos modernos funciona usando:

```text
posição += velocidade × Delta Time
```

Essa é uma das fórmulas mais importantes da programação de games.
