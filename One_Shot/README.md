# Temporizador One Shot

# Descrição

Este projeto implementa um sistema de LEDs acionados a partir do clique de um botão (pushbutton). O comportamento dos LEDs segue uma sequência temporizada: inicialmente todos os LEDs acesos, depois dois LEDs e, por último, apenas um LED aceso. Esse processo ocorre com a utilização de um temporizador de um disparo (One Shot) a cada 3 segundos.

# Funcionalidades

**Acionamento com botão:** Quando o botão for pressionado, os três LEDs são acesos.

**Mudança de estado dos LEDs:** Após o primeiro temporizador de 3 segundos, os LEDs devem mudar de estado de forma sequencial (primeiro todos acesos, depois dois, e finalmente um).

**Temporizador de 3 segundos:** Cada mudança de estado dos LEDs deve ocorrer com um intervalo de 3 segundos.

**Função de Call-back:** A mudança de estado dos LEDs é realizada nas funções de call-back do temporizador (turn_off_callback()).

**Controle de Bouncing:** O sistema deve evitar que o botão gere múltiplos acionamentos acidentais, implementando uma técnica de software debounce.

# Estrutura do Código

**Função de inicialização do temporizador:** Configura o alarme de temporização para um atraso de 3 segundos.

**Função de call-back:** Controla o desligamento progressivo dos LEDs com base no temporizador.

**Controle de estado do botão:** Garante que o botão só ative a sequência de LEDs quando o último LED for desligado, evitando múltiplos acionamentos durante o ciclo de temporização.
