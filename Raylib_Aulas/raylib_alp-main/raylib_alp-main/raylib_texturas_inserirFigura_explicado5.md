# Trabalhando com Imagens (Textures/Sprites) no Raylib

Este exemplo mostra como carregar e desenhar uma imagem usando a biblioteca raylib.

Agora você está entrando em um dos conceitos mais importantes do desenvolvimento de jogos:

- sprites
- texturas
- renderização de imagens
- assets gráficos

---

# Código Completo

```c
#include "raylib.h"

int main()
{
    Texture2D sprite;   // Vou ter uma imagem chamada sprite

    InitWindow(800, 450, "basic window");

    sprite = LoadTexture("sprite.png");   // Carregue a imagem sprite.png para usar no jogo

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(sprite, 10, 10, WHITE);

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
- carrega uma imagem chamada `sprite.png`
- desenha essa imagem na tela
- atualiza continuamente

---

# Conceito principal

Antes você desenhava:

```c
DrawRectangle()
```

que cria formas geométricas.

Agora você está usando:

```c
DrawTexture()
```

que desenha imagens reais.

---

# O que é uma Texture?

Uma texture (textura) é:

> uma imagem carregada na memória da GPU.

Pode ser:
- personagem
- inimigo
- cenário
- item
- botão
- efeito visual

---

# O que é um Sprite?

Sprite é:
- uma imagem usada em jogos
- normalmente 2D
- desenhada na tela

Exemplos:
- Mario
- Sonic
- inimigos
- moedas
- tiros

---

# Importando a raylib

```c
#include "raylib.h"
```

Importa a biblioteca raylib.

---

# Função principal

```c
int main()
```

Ponto de entrada do programa.

---

# Criando a variável da textura

```c
Texture2D sprite;
```

Cria uma variável do tipo:

```c
Texture2D
```

Esse tipo representa:
- uma imagem carregada
- armazenada na GPU

---

# O que existe dentro de Texture2D?

Internamente ela possui:
- largura
- altura
- ponteiro para memória gráfica
- identificador OpenGL
- formato da imagem

É uma estrutura complexa.

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

Essa linha:

- abre o arquivo PNG
- decodifica a imagem
- envia para GPU
- cria a textura

---

# O que LoadTexture faz internamente?

Internamente ocorre algo parecido com:

```text
1. Abrir arquivo PNG
2. Ler bytes da imagem
3. Descompactar PNG
4. Criar textura OpenGL
5. Enviar para VRAM da GPU
6. Retornar Texture2D
```

---

# Muito importante

O arquivo:

```text
sprite.png
```

precisa estar:
- na mesma pasta do executável
OU
- no caminho correto

---

# Estrutura típica

```text
meu_jogo/
│
├── programa.exe
├── sprite.png
```

---

# Loop principal

```c
while (!WindowShouldClose())
```

Loop do jogo.

Executa continuamente.

---

# Início da renderização

```c
BeginDrawing();
```

Começa um novo frame.

---

# Limpando a tela

```c
ClearBackground(RAYWHITE);
```

Pinta o fundo de branco.

---

# Desenhando a textura

```c
DrawTexture(sprite, 10, 10, WHITE);
```

Desenha a imagem carregada.

---

# Parâmetros do DrawTexture

| Parâmetro | Significado |
|---|---|
| sprite | textura carregada |
| 10 | posição X |
| 10 | posição Y |
| WHITE | cor/tintura |

---

# O que significa WHITE aqui?

Essa parte:

```c
WHITE
```

funciona como um filtro de cor.

---

# Exemplo

## Branco

```c
DrawTexture(sprite, 10, 10, WHITE);
```

Mostra a imagem original.

---

## Vermelho

```c
DrawTexture(sprite, 10, 10, RED);
```

Tinge a imagem de vermelho.

---

## Azul

```c
DrawTexture(sprite, 10, 10, BLUE);
```

Aplica tom azul.

---

# Coordenadas da textura

```c
10, 10
```

Significa:
- 10 pixels da esquerda
- 10 pixels do topo

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

Fecha a janela.

---

# Problema importante no código

O código funciona.

Mas existe um detalhe importante:

A textura não está sendo descarregada da memória.

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

# Versão profissional

```c
UnloadTexture(sprite);
CloseWindow();
```

---

# Por que isso importa?

Porque:
- a textura ocupa VRAM
- memória gráfica precisa ser liberada
- jogos profissionais evitam vazamento de memória

---

# Fluxo completo do programa

```text
Criar janela
    ↓
Carregar imagem
    ↓
Entrar no loop
    ↓
Limpar tela
    ↓
Desenhar textura
    ↓
Mostrar frame
    ↓
Repetir
    ↓
Liberar textura
    ↓
Fechar janela
```

---

# Resultado visual esperado

Você verá:
- uma janela branca
- a imagem sprite.png desenhada no canto superior esquerdo

---

# Conceitos aprendidos

Você aprendeu:

- o que é uma textura
- o que é um sprite
- como carregar imagens
- como desenhar imagens
- como GPU armazena texturas
- como renderizar assets gráficos

---

# Próximo passo natural

Depois disso normalmente vem:

## Movimento da sprite

```c
DrawTexture(sprite, posX, posY, WHITE);
```

---

## Animação

Spritesheets:

```text
corrida
pulo
ataque
idle
```

---

## Rotação

```c
DrawTextureEx();
```

---

## Escala

```c
DrawTexturePro();
```

---

## Jogos reais

Agora você já possui base para criar:

- personagem
- inimigos
- cenários
- HUD
- efeitos visuais

---

# Conceito fundamental

Sprites são o coração dos jogos 2D.

Quase tudo em um jogo 2D é:
- uma textura
- desenhada em posições diferentes
- atualizada frame a frame
