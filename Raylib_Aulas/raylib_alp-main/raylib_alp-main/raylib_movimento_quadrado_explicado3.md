# Movimento de Quadrado com Raylib (C)

Este exemplo mostra como mover um quadrado horizontalmente usando a biblioteca raylib.

O programa cria uma janela e faz um quadrado azul se mover automaticamente da esquerda para a direita.

---

# Código Completo

```c
#include "raylib.h"

int main()
{
    int posX = 0;  // Onde o quadrado está no eixo horizontal

    InitWindow(800, 450, "basic window");

    while (!WindowShouldClose())
    {
        posX++;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(posX, 100, 100, 100, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que esse programa faz?

Esse código:

- cria uma janela gráfica
- cria uma variável chamada `posX`
- aumenta essa variável continuamente
- usa essa variável para mover um quadrado
- cria uma animação simples

---

# Conceito mais importante aqui

Esse é um dos conceitos fundamentais dos jogos:

> alterar variáveis a cada frame para criar movimento.

Basicamente:

```text
posição atual + velocidade = nova posição
```

---

# Explicação linha por linha

---

# Importando a raylib

```c
#include "raylib.h"
```

Importa a biblioteca gráfica raylib.

Ela fornece funções para:

- gráficos
- teclado
- áudio
- mouse
- renderização

---

# Função principal

```c
int main()
```

Ponto de entrada do programa.

Todo programa em C começa pela função `main()`.

---

# Variável de posição

```c
int posX = 0;
```

Cria uma variável inteira chamada `posX`.

Ela representa:

> a posição horizontal do quadrado.

---

# O que significa eixo X?

Em computação gráfica:

```text
X → horizontal
Y → vertical
```

Então:

```text
(0,0)
```

fica no canto superior esquerdo da tela.

---

# Sistema de coordenadas

```text
(0,0) ----------------------→ X
  |
  |
  |
  ↓
  Y
```

---

# Criando a janela

```c
InitWindow(800, 450, "basic window");
```

Cria a janela gráfica.

Parâmetros:

| Valor | Significado |
|---|---|
| 800 | largura |
| 450 | altura |
| "basic window" | título |

---

# Loop principal

```c
while (!WindowShouldClose())
```

Repete infinitamente enquanto o usuário não fechar a janela.

Esse loop é chamado de:

- game loop
- render loop
- loop principal

---

# Movimento do quadrado

```c
posX++;
```

Essa é a linha mais importante do programa.

Ela significa:

```text
posX = posX + 1
```

Ou seja:
- pega o valor atual
- soma 1
- salva novamente

---

# O que acontece frame por frame?

```text
Frame 1 → posX = 0
Frame 2 → posX = 1
Frame 3 → posX = 2
Frame 4 → posX = 3
```

Então o quadrado se move continuamente para direita.

---

# Conceito de animação

Jogos funcionam exatamente assim.

A cada frame:

```text
posição = posição + velocidade
```

Esse é o princípio básico de:

- movimento
- física
- animação
- câmeras
- partículas

---

# Início da renderização

```c
BeginDrawing();
```

Começa um novo frame gráfico.

---

# Limpando a tela

```c
ClearBackground(RAYWHITE);
```

Pinta a tela inteira de branco.

Sem isso:
- os frames anteriores acumulam
- surgem rastros

---

# Desenhando o quadrado

```c
DrawRectangle(posX, 100, 100, 100, BLUE);
```

Desenha o quadrado azul.

---

# Parâmetros do DrawRectangle

| Parâmetro | Valor | Significado |
|---|---|---|
| x | posX | posição horizontal |
| y | 100 | posição vertical |
| largura | 100 | tamanho horizontal |
| altura | 100 | tamanho vertical |
| cor | BLUE | cor |

---

# O segredo do movimento

Antes:

```c
DrawRectangle(100, 100, 100, 100, BLUE);
```

o quadrado ficava parado.

Agora:

```c
DrawRectangle(posX, 100, 100, 100, BLUE);
```

o valor muda constantemente.

Resultado:
- o quadrado se move.

---

# Finalizando o frame

```c
EndDrawing();
```

Envia o frame para GPU exibir.

---

# Fechando corretamente

```c
CloseWindow();
```

Libera memória e fecha a janela.

---

# Fluxo do programa

```text
Criar janela
    ↓
Entrar no loop
    ↓
Aumentar posX
    ↓
Limpar tela
    ↓
Desenhar quadrado
    ↓
Mostrar frame
    ↓
Repetir
```

---

# Resultado visual esperado

Você verá:

- um quadrado azul
- movendo da esquerda para direita
- continuamente

---

# Problema atual do código

O quadrado nunca para.

Ele continuará indo para direita até sair da tela.

---

# Como fazer voltar para início

Você pode fazer:

```c
if (posX > 800)
{
    posX = 0;
}
```

---

# Como controlar velocidade

Atualmente:

```c
posX++;
```

move 1 pixel por frame.

Mais rápido:

```c
posX += 5;
```

Mais lento:

```c
posX += 1;
```

---

# Conceito importante: FPS

O movimento depende dos frames por segundo.

Se o jogo rodar:
- 60 FPS → movimento suave
- 30 FPS → mais lento
- 144 FPS → muito rápido

Por isso jogos profissionais usam:

```c
GetFrameTime()
```

---

# Movimento profissional

Exemplo moderno:

```c
posX += 300 * GetFrameTime();
```

Isso cria:
- velocidade consistente
- independente do FPS

---

# Próximo passo natural

Depois disso normalmente vem:

## Movimento por teclado

```c
if (IsKeyDown(KEY_RIGHT))
{
    posX += 5;
}
```

---

## Movimento vertical

```c
int posY;
```

---

## Física

- gravidade
- colisão
- aceleração

---

## Sprites

```c
DrawTexture();
```

---

# Conceito fundamental aprendido

Você acabou de criar:

- animação
- movimento em tempo real
- atualização frame a frame
- base da lógica de jogos

Esse é um dos pilares do desenvolvimento de games.
