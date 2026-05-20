# Explicação Completa da Hierarquia do Código Raylib e Glossário

```c
#include <stdio.h>
#include "raylib.h"

int main()
{
    Texture2D sprite;
    Sound sound;
    Music music;
    
    InitWindow(800, 450, "basic window");
    
    InitAudioDevice();
    
    sprite = LoadTexture("feliz.png");
    sound = LoadSound("tiro.mp3");
    music = LoadMusicStream("fundo.ogg");
    
    float posX = -sprite.width;
    
    PlayMusicStream(music);
    
    while(!WindowShouldClose())
    {
        UpdateMusicStream(music);
        
        posX += GetFrameTime() * 300;
        
        if (posX > 800)
        {
            posX = -sprite.width;
        }
        
        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle spriteRect = {
                posX,
                10,
                sprite.width,
                sprite.height
            };
            
            if (CheckCollisionPointRec(GetMousePosition(), spriteRect))
            {
                PlaySound(sound);
            }
        }
        
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            DrawTexture(sprite, posX, 10, WHITE);
            
        EndDrawing();
    }
    
    StopMusicStream(music);
    
    UnloadTexture(sprite);
    UnloadSound(sound);
    UnloadMusicStream(music);
    
    CloseAudioDevice();
    
    CloseWindow();
    
    return 0;
}
```

---

# Estrutura Geral do Programa

A hierarquia do código existe porque algumas coisas precisam acontecer antes de outras.

O fluxo correto de um jogo normalmente é:

```text
1. Importar bibliotecas
2. Declarar variáveis
3. Criar janela
4. Iniciar áudio
5. Carregar arquivos
6. Iniciar música
7. Entrar no loop do jogo
8. Atualizar lógica
9. Desenhar na tela
10. Sair do loop
11. Liberar memória
12. Fechar sistemas
```

---

# 1. Bibliotecas

```c
#include <stdio.h>
#include "raylib.h"
```

## Para que serve?

### stdio.h

Biblioteca padrão do C.

Ela fornece:
- printf
- scanf
- entrada e saída

Nesse programa ela não está sendo usada diretamente.

---

### raylib.h

Importa a biblioteca Raylib.

Ela fornece funções como:

```c
InitWindow()
DrawTexture()
PlaySound()
```

---

## Por que vem primeiro?

Porque o compilador precisa conhecer as funções antes de compilar o restante do código.

---

# 2. Função main()

```c
int main()
```

## Para que serve?

É o ponto de entrada do programa.

Todo programa em C começa pela função:

```c
main()
```

---

## Por que vem depois dos includes?

Porque primeiro o compilador precisa conhecer as bibliotecas.

Depois o programa pode começar.

---

# 3. Declaração das variáveis

```c
Texture2D sprite;
Sound sound;
Music music;
```

## Para que serve?

Cria variáveis para armazenar:

| Variável | Guarda |
|---|---|
| sprite | imagem |
| sound | efeito sonoro |
| music | música de fundo |

---

## Por que vem antes do carregamento?

Porque antes de usar:

```c
sprite = LoadTexture(...)
```

a variável precisa existir.

---

# 4. Criar a janela

```c
InitWindow(800, 450, "basic window");
```

## Para que serve?

Cria a janela gráfica do jogo.

---

## Parâmetros

| Valor | Significado |
|---|---|
| 800 | largura |
| 450 | altura |
| basic window | título |

---

## Por que vem antes do desenho?

Porque não existe tela para desenhar antes da janela existir.

---

# 5. Iniciar áudio

```c
InitAudioDevice();
```

## Para que serve?

Inicializa o sistema de áudio.

---

## Por que vem antes de carregar sons?

Porque primeiro o sistema de áudio precisa estar funcionando.

Depois os sons podem ser carregados.

---

# 6. Carregar arquivos

```c
sprite = LoadTexture("feliz.png");
sound = LoadSound("tiro.mp3");
music = LoadMusicStream("fundo.ogg");
```

## Para que serve?

Carrega:

| Função | Tipo |
|---|---|
| LoadTexture | imagem |
| LoadSound | efeito sonoro |
| LoadMusicStream | música |

---

## Por que vem depois da janela e do áudio?

Porque:
- textura depende da GPU
- som depende do sistema de áudio

---

# 7. Posição inicial

```c
float posX = -sprite.width;
```

## Para que serve?

Define a posição inicial do sprite.

---

## Por que usar negativo?

Faz o sprite começar fora da tela.

---

## Por que vem depois de LoadTexture?

Porque:

```c
sprite.width
```

só existe depois que a imagem foi carregada.

---

# 8. Iniciar música

```c
PlayMusicStream(music);
```

## Para que serve?

Começa a tocar a música.

---

## Por que vem antes do loop?

Porque a música deve iniciar uma vez antes do jogo começar.

---

# 9. Loop principal

```c
while(!WindowShouldClose())
```

## Para que serve?

Mantém o jogo rodando.

---

## O que acontece dentro do loop?

```text
atualizar
↓
desenhar
↓
mostrar
↓
repetir
```

---

## Por que isso é importante?

Sem loop:
- o jogo abriria
- desenharia uma vez
- fecharia imediatamente

---

# 10. Atualizar música

```c
UpdateMusicStream(music);
```

## Para que serve?

Mantém a música tocando continuamente.

---

## Por que fica dentro do loop?

Porque a música precisa ser atualizada constantemente.

---

# 11. Movimento do sprite

```c
posX += GetFrameTime() * 300;
```

## Para que serve?

Move o sprite horizontalmente.

---

## O que significa?

```text
posição += velocidade × tempo
```

---

## Por que vem antes do desenho?

Porque primeiro atualizamos a posição.

Depois desenhamos.

---

# 12. Verificar saída da tela

```c
if (posX > 800)
{
    posX = -sprite.width;
}
```

## Para que serve?

Quando o sprite sai da tela:
- ele volta para esquerda.

---

## Por que vem depois do movimento?

Porque primeiro ele precisa andar.

Depois verificamos se saiu da tela.

---

# 13. Reiniciar música

```c
if (IsKeyPressed(KEY_SPACE))
```

## Para que serve?

Detecta quando o jogador aperta espaço.

---

## O que acontece?

```c
StopMusicStream(music);
PlayMusicStream(music);
```

A música reinicia.

---

## Por que fica dentro do loop?

Porque teclado precisa ser verificado continuamente.

---

# 14. Detectar clique do mouse

```c
if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
```

## Para que serve?

Detecta clique do mouse.

---

## Por que fica dentro do loop?

Porque o jogo precisa verificar mouse constantemente.

---

# 15. Criar área do sprite

```c
Rectangle spriteRect = {
    posX,
    10,
    sprite.width,
    sprite.height
};
```

## Para que serve?

Cria uma área invisível para colisão.

---

## O que representa?

| Valor | Significado |
|---|---|
| posX | posição X |
| 10 | posição Y |
| width | largura |
| height | altura |

---

# 16. Verificar colisão

```c
CheckCollisionPointRec(GetMousePosition(), spriteRect)
```

## Para que serve?

Verifica se o mouse clicou dentro do sprite.

---

## Se acertar

```c
PlaySound(sound);
```

toca o som.

---

# 17. BeginDrawing()

```c
BeginDrawing();
```

## Para que serve?

Inicia um novo frame gráfico.

---

## O que significa?

```text
“vou começar a desenhar”
```

---

## Por que vem antes do desenho?

Porque tudo precisa acontecer entre:

```c
BeginDrawing();
EndDrawing();
```

---

# 18. Limpar tela

```c
ClearBackground(RAYWHITE);
```

## Para que serve?

Apaga o frame anterior.

---

## Por que vem antes do DrawTexture?

Porque primeiro limpamos a tela.

Depois desenhamos.

---

# 19. DrawTexture()

```c
DrawTexture(sprite, posX, 10, WHITE);
```

## Para que serve?

Desenha o sprite na tela.

---

## Parâmetros

| Parâmetro | Significado |
|---|---|
| sprite | imagem |
| posX | posição horizontal |
| 10 | posição vertical |
| WHITE | cor original |

---

# 20. EndDrawing()

```c
EndDrawing();
```

## Para que serve?

Finaliza o frame.

---

## O que acontece?

O frame é enviado para GPU e mostrado no monitor.

---

# 21. StopMusicStream()

```c
StopMusicStream(music);
```

## Para que serve?

Para a música quando o jogo termina.

---

# 22. Liberar memória

```c
UnloadTexture(sprite);
UnloadSound(sound);
UnloadMusicStream(music);
```

## Para que serve?

Libera:
- VRAM
- RAM
- buffers de áudio

---

## Por que vem depois do loop?

Porque o jogo ainda precisava usar esses recursos.

---

# 23. Fechar áudio

```c
CloseAudioDevice();
```

## Para que serve?

Desliga o sistema de áudio.

---

# 24. Fechar janela

```c
CloseWindow();
```

## Para que serve?

Fecha a janela do jogo.

---

# 25. Finalizar programa

```c
return 0;
```

## Para que serve?

Informa ao sistema operacional:

```text
programa terminou corretamente
```

---

# Fluxo Completo do Programa

```text
IMPORTAR BIBLIOTECAS
        ↓
CRIAR VARIÁVEIS
        ↓
CRIAR JANELA
        ↓
INICIAR ÁUDIO
        ↓
CARREGAR IMAGEM/SOM/MÚSICA
        ↓
INICIAR MÚSICA
        ↓
ENTRAR NO LOOP
        ↓
ATUALIZAR MÚSICA
        ↓
ATUALIZAR POSIÇÃO
        ↓
VERIFICAR TECLADO/MOUSE
        ↓
VERIFICAR COLISÃO
        ↓
COMEÇAR FRAME
        ↓
LIMPAR TELA
        ↓
DESENHAR SPRITE
        ↓
FINALIZAR FRAME
        ↓
REPETIR
        ↓
SAIR DO LOOP
        ↓
PARAR MÚSICA
        ↓
LIBERAR MEMÓRIA
        ↓
FECHAR ÁUDIO
        ↓
FECHAR JANELA
        ↓
FINALIZAR PROGRAMA
```

---

# Conceito Mais Importante

A ordem do código existe porque:

```text
não posso desenhar antes de criar janela
não posso tocar som antes de iniciar áudio
não posso usar imagem antes de carregar
não posso liberar memória antes de terminar o jogo
```

Toda engine de jogos segue uma hierarquia parecida.


# 📚 Glossário de Termos e Conceitos — Desenvolvimento de Jogos com Raylib

---

# API

API significa:

```text
Application Programming Interface
```

É um conjunto de funções prontas que um programador pode utilizar.

Exemplo no Raylib:

```c
DrawTexture()
PlaySound()
InitWindow()
```

A API funciona como uma ponte entre:
- seu código
- a engine/biblioteca

---

# Asset

Assets são os recursos do jogo.

Exemplos:
- imagens
- músicas
- sons
- fontes
- animações

Arquivos comuns:

```text
.png
.mp3
.ogg
.wav
```

---

# Áudio Assíncrono

Áudio assíncrono significa:
- o som toca em paralelo
- o jogo continua funcionando normalmente

Exemplo:

```c
PlaySound(sound);
```

O jogo não pausa enquanto o som toca.

---

# BackBuffer

O backbuffer é:
- uma área invisível da memória gráfica
- onde o próximo frame é desenhado

A GPU desenha tudo no backbuffer primeiro.

Depois:
- o frame completo é mostrado na tela.

Isso evita:
- flickering
- tremedeira
- imagens incompletas

---

# Biblioteca

Biblioteca é:
- um conjunto de funções prontas reutilizáveis

Exemplos:
- Raylib
- SDL
- OpenGL
- stdio.h

---

# Buffer

Buffer é:
- uma área temporária de memória

Usado para:
- armazenar dados temporariamente
- preparar informações antes do uso final

Exemplos:
- backbuffer
- audio buffer
- framebuffer

---

# C

Linguagem de programação criada em:
- 1972

Muito usada em:
- sistemas operacionais
- jogos
- drivers
- engines
- programação de baixo nível

---

# CheckCollisionPointRec

Função do Raylib que:
- verifica se um ponto está dentro de um retângulo

Exemplo:
- verificar se o mouse clicou no sprite

---

# Colisão

Colisão significa:
- detectar interação entre objetos

Exemplo:
- tiro acertou inimigo
- jogador bateu parede

---

# CPU

CPU significa:

```text
Central Processing Unit
```

É o “cérebro” do computador.

Responsável por:
- lógica
- decisões
- execução principal do programa

---

# Delta Time

Delta Time significa:

```text
tempo entre frames
```

Usado para:
- movimento profissional
- velocidade independente do FPS

Exemplo:

```c
GetFrameTime()
```

---

# Double Buffering

Técnica usada para:
- desenhar o frame escondido
- mostrar apenas quando estiver pronto

Usa:
- frontbuffer
- backbuffer

---

# DrawTexture()

Função do Raylib que:
- desenha imagens na tela

Exemplo:

```c
DrawTexture(sprite, x, y, WHITE);
```

---

# DrawRectangle()

Função usada para:
- desenhar retângulos

Muito usada em:
- protótipos
- HUD
- colisões
- jogos simples

---

# DrawText()

Função usada para:
- desenhar texto na tela

---

# Engine de Jogos

Engine é:
- conjunto de sistemas prontos para criação de jogos

Ela fornece:
- gráficos
- áudio
- física
- input
- renderização

Exemplos:
- Unity
- Unreal
- Godot
- Raylib

---

# EndDrawing()

Função que:
- finaliza o frame atual
- envia o frame para a tela

Tudo desenhado entre:

```c
BeginDrawing();
EndDrawing();
```

faz parte do frame.

---

# FPS

FPS significa:

```text
Frames Per Second
```

Ou seja:
- quantos frames o jogo mostra por segundo

Exemplos:
- 30 FPS
- 60 FPS
- 144 FPS

---

# Frame

Frame é:
- uma imagem do jogo

Jogos mostram:
- vários frames rapidamente

Criando ilusão de movimento.

---

# FrontBuffer

Buffer visível no monitor.

Enquanto:
- o backbuffer é desenhado escondido

o frontbuffer:
- é o frame atual sendo mostrado.

---

# Game Loop

Game Loop é:
- o loop principal do jogo

Exemplo:

```c
while (!WindowShouldClose())
```

Todo jogo funciona assim:

```text
atualizar
↓
desenhar
↓
mostrar
↓
repetir
```

---

# Game Engine

Outro nome para:
- engine de jogos

---

# GetFrameTime()

Função do Raylib que retorna:
- tempo entre frames

Usada para:
- Delta Time

---

# GPU

GPU significa:

```text
Graphics Processing Unit
```

É responsável por:
- gráficos
- pixels
- renderização
- shaders

Possui milhares de núcleos paralelos.

---

# Hierarquia do Código

Ordem lógica que o programa precisa seguir.

Exemplo:

```text
criar janela
↓
carregar textura
↓
desenhar
```

A hierarquia existe porque:
- algumas coisas dependem de outras.

---

# HUD

HUD significa:

```text
Heads-Up Display
```

É a interface do jogador.

Exemplos:
- vida
- munição
- pontuação
- minimapa

---

# Input

Input significa:
- entrada de dados do jogador

Exemplos:
- teclado
- mouse
- joystick

---

# InitAudioDevice()

Inicializa o sistema de áudio.

Necessário antes de:
- carregar sons
- tocar músicas

---

# InitWindow()

Cria a janela do jogo.

Também inicializa:
- OpenGL
- sistema gráfico
- comunicação com GPU

---

# Loop

Loop significa:
- repetição contínua

Exemplo:

```c
while()
```

---

# LoadSound()

Carrega:
- efeitos sonoros curtos

---

# LoadTexture()

Carrega:
- imagens/texturas

---

# LoadMusicStream()

Carrega:
- música longa em streaming

---

# Memória RAM

Memória usada pelo programa durante execução.

Armazena:
- variáveis
- sons
- dados do jogo

---

# OpenGL

API gráfica usada para:
- comunicação com GPU

Raylib usa OpenGL internamente.

---

# Paralelismo

Capacidade de executar:
- várias tarefas ao mesmo tempo

GPU é especializada nisso.

---

# Pixel

Menor ponto de uma imagem digital.

A tela é formada por milhões de pixels.

---

# PlaySound()

Executa:
- efeito sonoro curto

---

# PlayMusicStream()

Inicia:
- música de fundo

---

# PNG

Formato de imagem muito usado em jogos.

Características:
- compressão
- transparência
- qualidade alta

---

# Programação Procedural

Modelo de programação baseado em:
- funções
- sequência lógica
- fluxo procedural

Muito comum em C.

---

# Raylib

Biblioteca gráfica escrita em C.

Voltada para:
- aprendizado
- jogos 2D
- jogos simples
- ensino de computação gráfica

---

# Rectangle

Estrutura usada para:
- representar retângulos

Muito usada em:
- colisão
- HUD
- áreas clicáveis

---

# Renderização

Processo de:
- desenhar imagens na tela

A GPU faz renderização.

---

# Shader

Programa executado na GPU.

Usado para:
- iluminação
- sombras
- efeitos gráficos

---

# Sound

Tipo usado para:
- efeitos sonoros curtos

Carregado totalmente na RAM.

---

# Sprite

Imagem usada como objeto do jogo.

Exemplos:
- personagem
- inimigo
- item

---

# Streaming de Música

Técnica onde:
- música é carregada aos poucos

Usada para:
- arquivos grandes

---

# Texture

Imagem carregada na GPU.

---

# Texture2D

Tipo usado no Raylib para:
- armazenar texturas 2D

---

# UpdateMusicStream()

Atualiza continuamente a música em streaming.

Deve ser chamada:
- dentro do loop do jogo

---

# VRAM

Memória da placa de vídeo.

Usada para:
- texturas
- buffers
- renderização

---

# while (!WindowShouldClose())

Loop principal do jogo.

Mantém o programa funcionando enquanto:
- a janela não for fechada

---

# WindowShouldClose()

Função que verifica:
- se o usuário quer fechar o jogo

Exemplos:
- apertar ESC
- clicar no X da janela

---

# WHITE

Constante de cor da Raylib.

Representa:
- cor branca

Também usada para:
- desenhar textura sem alterar sua cor original

---

# X e Y

Coordenadas usadas para posicionamento.

| Coordenada | Direção |
|---|---|
| X | horizontal |
| Y | vertical |

---

# Sistema de Coordenadas 2D

No Raylib:

```text
(0,0)
```

fica no canto superior esquerdo.

```text
X → direita
Y ↓ baixo
```

---

# Conceito Mais Importante

Todo jogo basicamente funciona assim:

```text
ATUALIZAR
    ↓
DESENHAR
    ↓
MOSTRAR
    ↓
REPETIR
```

Esse é o coração de praticamente toda engine de jogos.
