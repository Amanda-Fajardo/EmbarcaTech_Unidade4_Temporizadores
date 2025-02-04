# Temporizadores com LEDs e Botões

Este repositório contém dois projetos desenvolvidos utilizando o Pico SDK para implementar sistemas de temporização com LEDs e botões. O objetivo principal de cada projeto é controlar o comportamento de LEDs em resposta a temporizações, utilizando os temporizadores fornecidos pela biblioteca do Pico SDK.

# Como Executar

**Pré-requisitos**

**Pico SDK:** Certifique-se de que o ambiente de desenvolvimento está configurado corretamente com o Pico SDK.

**Hardware:** Um microcontrolador Raspberry Pi Pico ou similar com suporte para LEDs e pushbuttons.
- 3 LEDs (vermelho, amarelo, verde).
- 1 pushbutton (botão).

# Compilação e Execução

1. Clone o repositório:

bash
Copiar
git clone <URL_DO_REPOSITORIO>
cd <diretorio_do_repositorio>

2. Compile o código utilizando o Pico SDK:

```bash
mkdir build
cd build
cmake ..
make
```
3. Carregue o firmware no seu microcontrolador Raspberry Pi Pico:

```bash
picotool load <caminho_do_firmware.uf2>
```
4. Execute o programa e observe a funcionalidade dos LEDs conforme descrito.
