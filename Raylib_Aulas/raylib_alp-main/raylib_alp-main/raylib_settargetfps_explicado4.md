# Controle de FPS com Raylib (C)

Este exemplo mostra como controlar a velocidade do loop do jogo usando a função:

```c
SetTargetFPS();
```

Esse é um dos conceitos mais importantes no desenvolvimento de jogos.

---

# Código Completo

```c
#include "raylib.h"

int main()
{
    int posX = 0;

    InitWindow(800, 450, "basic window");

    SetTargetFPS(24);  // Diz ao Raylib quantas vezes por segundo o loop do jogo deve rodar

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

O programa:

- cria uma janela
- cria um quadrado azul
- move o quadrado horizontalmente
- controla quantas vezes por segundo o jogo atualiza

---

# Conceito principal: FPS

FPS significa:

```text
Frames Per Second
```

Ou seja:

> quantos frames o jogo desenha por segundo.

---

# O que é um frame?

Um frame é:

- uma imagem da tela
- um instante do jogo
- uma atualização visual

Jogos são várias imagens mostradas rapidamente.

---

# Exemplo visual

```text
Frame 1
Frame 2
Frame 3
Frame 4
Frame 5
...
```

Quando isso acontece muito rápido:
- o cérebro interpreta como movimento.

Exatamente como um filme.

---

# Importando a raylib

```c
#include "raylib.h"
```

Importa a biblioteca gráfica raylib.

---

# Variável de posição

```c
int posX = 0;
```

Guarda a posição horizontal do quadrado.

---

# Criando a janela

```c
InitWindow(800, 450, "basic window");
```

Cria a janela gráfica.

---

# A linha mais importante desse exemplo

```c
SetTargetFPS(24);
```

Essa função diz:

> “quero que o loop rode 24 vezes por segundo”.

---

# O que significa 24 FPS?

Significa:

```text
24 frames por segundo
```

Então:
- o jogo desenhará 24 imagens por segundo
- o movimento ficará limitado a essa taxa

---

# Por que isso é importante?

Sem controle de FPS:

- o jogo pode rodar rápido demais
- depende da potência do computador
- animações ficam inconsistentes

---

# Sem SetTargetFPS()

Imagine:

```text
PC fraco → 60 FPS
PC gamer → 500 FPS
```

Nesse caso:

```c
posX++;
```

aconteceria:
- 60 vezes por segundo num PC
- 500 vezes por segundo em outro

Resultado:
- velocidades diferentes
- jogo quebrado

---

# Com SetTargetFPS(24)

Agora todos tentam rodar:

```text
24 atualizações por segundo
```

Isso estabiliza:
- animação
- física
- movimentação

---

# Relação entre FPS e movimento

Observe:

```c
posX++;
```

Isso acontece:
- uma vez por frame

Então:

## Em 24 FPS

```text
24 incrementos por segundo
```

## Em 60 FPS

```text
60 incrementos por segundo
```

---

# Como o Raylib controla isso?

Internamente o Raylib:

- mede o tempo
- espera o frame correto
- sincroniza o loop

É parecido com:

```text
"espere até o próximo frame"
```

---

# Loop principal

```c
while (!WindowShouldClose())
```

Loop do jogo.

Repete continuamente.

---

# Atualização da posição

```c
posX++;
```

Move o quadrado.

Equivale a:

```c
posX = posX + 1;
```

---

# Início do frame

```c
BeginDrawing();
```

Começa a renderização.

---

# Limpando a tela

```c
ClearBackground(RAYWHITE);
```

Pinta o fundo de branco.

---

# Desenhando o quadrado

```c
DrawRectangle(posX, 100, 100, 100, BLUE);
```

Desenha o quadrado azul.

---

# Parâmetros do DrawRectangle

| Parâmetro | Significado |
|---|---|
| posX | posição horizontal |
| 100 | posição vertical |
| 100 | largura |
| 100 | altura |
| BLUE | cor |

---

# Finalizando o frame

```c
EndDrawing();
```

Mostra o frame na tela.

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
Definir FPS
    ↓
Entrar no loop
    ↓
Atualizar posição
    ↓
Desenhar frame
    ↓
Mostrar frame
    ↓
Repetir
```

---

# Comparação de FPS

| FPS | Sensação |
|---|---|
| 24 | estilo cinema |
| 30 | aceitável |
| 60 | fluido |
| 120 | muito suave |
| 240 | ultra suave |

---

# Curiosidade

Filmes normalmente usam:

```text
24 FPS
```

Por isso esse valor é muito famoso.

---

# Jogos modernos normalmente usam

| Tipo | FPS |
|---|---|
| Jogos antigos | 30 |
| Jogos modernos | 60 |
| Competitivo | 120+ |

---

# Problema importante

Mesmo com:

```c
SetTargetFPS(24);
```

o movimento ainda depende do FPS.

Isso porque:

```c
posX++;
```

continua ligado ao frame.

---

# Movimento profissional

Jogos modernos usam:

```c
GetFrameTime()
```

Exemplo:

```c
posX += 300 * GetFrameTime();
```

Isso cria:
- velocidade consistente
- independente do FPS

---

# O que é Delta Time?

```text
Delta Time = tempo entre frames
```

É um dos conceitos mais importantes da programação de jogos.

---

# Resultado visual esperado

Você verá:

- uma janela branca
- um quadrado azul
- movendo suavemente para direita
- com velocidade controlada

---

# Conceitos aprendidos

Você aprendeu:

- o que é FPS
- o que é frame
- como jogos controlam velocidade
- como sincronizar renderização
- por que FPS importa
- diferença entre FPS e velocidade real

---

# Conceito fundamental

FPS não é velocidade do objeto.

FPS é:

> quantas vezes o jogo atualiza por segundo.

Isso muda completamente como jogos funcionam internamente.
