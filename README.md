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
```
git clone <https://github.com/Amanda-Fajardo/EmbarcaTech_Unidade4_Temporizadores>
```

2. Tenha o VSCode instalado e configurado.
   
3. Tenha a extensão do Raspberry Pi Pico instalada e configurada.
   
2. Compile o programa utilizando o CMake:

```
mkdir build
cd build
cmake ..
make
```
3. Carregue o firmware no seu microcontrolador Raspberry Pi Pico.
   
4. Caso não possua a placa para testar, é possível simular o programa com a extensão `Wokwi Simulator` no VSCode. Basta compilar e clicar no arquivo `diagram.json`.
