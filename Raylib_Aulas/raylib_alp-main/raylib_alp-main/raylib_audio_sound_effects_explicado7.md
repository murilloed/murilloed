# Trabalhando com Áudio no Raylib (Sound Effects)

Este exemplo mostra como adicionar som em um jogo usando a biblioteca raylib.

Agora você está entrando em outro pilar fundamental do desenvolvimento de jogos:

- áudio
- efeitos sonoros
- sound effects
- engine de áudio

---

# Código Completo

```c
#include "raylib.h"

int main()
{
    float posX = -100; // posição inicial (fora da tela)

    Texture2D sprite;

    Sound sound; // variável de som

    InitWindow(800, 450, "basic window");

    InitAudioDevice(); // inicia o sistema de áudio

    sprite = LoadTexture("sprite.png");

    sound = LoadSound("sound.ogg"); // carrega o som

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 300;

        // quando sair da tela, toca som
        if (posX > 800)
        {
            posX = -100;

            PlaySound(sound);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(sprite, posX, 10, WHITE);

        EndDrawing();
    }

    UnloadSound(sound);

    CloseAudioDevice();

    CloseWindow();

    return 0;
}
```

---

# O que esse programa faz?

O programa:

- cria uma janela
- carrega uma imagem
- carrega um efeito sonoro
- move o sprite pela tela
- toca um som quando o sprite sai da tela

---

# Conceito principal

Agora o jogo possui:

- gráficos
- movimento
- tempo
- áudio

Você já está criando uma mini game engine.

---

# Variável de som

```c
Sound sound;
```

Cria uma variável do tipo:

```c
Sound
```

Esse tipo representa:
- um efeito sonoro carregado na memória

---

# Diferença entre Sound e Music

No Raylib existem dois conceitos:

| Tipo | Uso |
|---|---|
| Sound | efeitos curtos |
| Music | músicas longas |

---

# Exemplos de Sound

- tiro
- explosão
- pulo
- clique
- moeda

---

# Exemplos de Music

- música de fundo
- trilha sonora
- ambientação

---

# Inicializando o sistema de áudio

```c
InitAudioDevice();
```

Essa linha é obrigatória.

Ela:
- inicia o sistema de áudio
- abre comunicação com o driver de som
- prepara buffers de áudio

---

# O que acontece internamente?

Internamente o Raylib:
- acessa a API de áudio do sistema
- cria buffers
- inicializa mixer de áudio

Dependendo do sistema operacional ele pode usar:
- WASAPI
- OpenAL
- ALSA
- PulseAudio
- CoreAudio

---

# Carregando o som

```c
sound = LoadSound("sound.ogg");
```

Essa linha:
- abre o arquivo .ogg
- decodifica o áudio
- envia para memória

---

# Formato OGG

```text
.ogg
```

é um formato:
- comprimido
- leve
- muito usado em jogos

---

# Outros formatos aceitos

Raylib também suporta:

- WAV
- MP3
- FLAC
- OGG

---

# Estrutura da pasta

O arquivo precisa existir:

```text
meu_jogo/
│
├── programa.exe
├── sprite.png
├── sound.ogg
```

---

# Movimento do sprite

```c
posX += GetFrameTime() * 300;
```

Move o sprite usando Delta Time.

---

# Verificando saída da tela

```c
if (posX > 800)
```

Verifica:
- se o sprite passou da largura da janela.

---

# Reiniciando posição

```c
posX = -100;
```

Coloca o sprite novamente fora da tela.

---

# Tocando o som

```c
PlaySound(sound);
```

Executa o efeito sonoro.

---

# O que acontece internamente?

Internamente:

```text
1. Sound buffer é enviado
2. Mixer processa áudio
3. Sistema operacional reproduz
4. Caixa de som toca
```

---

# Conceito importante: áudio assíncrono

Quando você chama:

```c
PlaySound(sound);
```

o programa:
- NÃO para
- NÃO trava
- continua rodando normalmente

O áudio roda em paralelo.

---

# Início da renderização

```c
BeginDrawing();
```

Começa novo frame.

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

Desenha a imagem.

---

# Finalizando frame

```c
EndDrawing();
```

Mostra o frame.

---

# Liberando som

```c
UnloadSound(sound);
```

Libera memória usada pelo áudio.

Isso é muito importante.

---

# Por que liberar memória?

O som ocupa:
- RAM
- buffers de áudio
- recursos do sistema

Jogos profissionais sempre liberam recursos.

---

# Fechando sistema de áudio

```c
CloseAudioDevice();
```

Fecha o sistema de áudio corretamente.

---

# Fluxo completo do programa

```text
Criar janela
    ↓
Inicializar áudio
    ↓
Carregar sprite
    ↓
Carregar som
    ↓
Entrar no loop
    ↓
Mover sprite
    ↓
Verificar colisão/limite
    ↓
Tocar som
    ↓
Renderizar frame
    ↓
Repetir
    ↓
Liberar som
    ↓
Fechar áudio
    ↓
Fechar janela
```

---

# Resultado visual esperado

Você verá:

- sprite se movendo
- quando sair da tela:
    - volta ao início
    - toca som

---

# Conceitos aprendidos

Você aprendeu:

- sistema de áudio
- efeitos sonoros
- LoadSound()
- PlaySound()
- buffers de áudio
- mixer de áudio
- áudio assíncrono
- gerenciamento de memória sonora

---

# Diferença importante

## Som curto

```c
Sound
```

Carregado totalmente na RAM.

Ideal para:
- efeitos rápidos

---

# Música longa

```c
Music
```

Transmitida em streaming.

Ideal para:
- músicas grandes
- trilhas sonoras

---

# Próximo passo natural

Depois disso normalmente vem:

## Música de fundo

```c
Music music;
```

---

## Atualização contínua

```c
UpdateMusicStream(music);
```

---

## Controle de volume

```c
SetSoundVolume(sound, 0.5f);
```

---

## Sons múltiplos

- explosões
- passos
- tiros
- interface

---

## Áudio espacial

- posição 3D
- distância
- direção

---

# Conceito fundamental

Áudio é uma das partes mais importantes da imersão em jogos.

Mesmo um jogo simples:
- sem áudio → parece vazio
- com áudio → ganha vida

O cérebro humano responde extremamente forte ao som em tempo real.
