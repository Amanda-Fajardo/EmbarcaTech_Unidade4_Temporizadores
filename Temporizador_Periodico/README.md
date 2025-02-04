# Descrição

Neste projeto, foi implementado um sistema de semáforo utilizando LEDs. A temporização de 3 segundos é utilizada para alternar entre os estados do semáforo (vermelho, amarelo e verde) de forma cíclica.

# Requisitos

**Início na cor vermelha:** O semáforo começa com o LED vermelho aceso.

**Temporização de 3 segundos:** Cada sinal do semáforo (vermelho, amarelo e verde) deve ficar aceso por 3 segundos antes de mudar.

**Temporização cíclica:** O temporizador utiliza a função `add_repeating_timer_ms()` do Pico SDK para alterar os LEDs a cada 3 segundos.

**Função de Call-back:** A mudança de estado dos LEDs deve ser realizada na função de call-back do temporizador (`repeating_timer_callback()`).

**Impressão de informações:** A rotina principal, dentro do loop while, imprime uma mensagem a cada segundo (1.000ms).

# Estrutura do Código

**Função de inicialização do temporizador:** Configura o temporizador com um intervalo de 3 segundos.

**Função de call-back:** Responsável por alternar o estado dos LEDs a cada 3 segundos.

**Loop principal:** Contém a lógica de impressão a cada 1 segundo e a verificação do estado do semáforo.