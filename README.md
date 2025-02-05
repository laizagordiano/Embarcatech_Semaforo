# Temporizador Periódico para Controle de Semáforo

Este projeto foi desenvolvido para o microcontrolador **Raspberry Pi Pico W** e tem como objetivo simular um semáforo com LEDs (vermelho, amarelo e verde) controlados por um temporizador periódico. O semáforo altera sua cor a cada 3 segundos, utilizando a função `add_repeating_timer_ms()` do Pico SDK.


## Descrição do Funcionamento

Este sistema simula o funcionamento de um semáforo, alterando os LEDs entre as cores vermelha, amarela e verde a cada 3 segundos. O sistema também imprime mensagens na porta serial a cada segundo, como forma de monitoramento.

### 1. Estado Inicial
- O LED vermelho é aceso, representando a luz vermelha do semáforo.

### 2. Ciclo de Sinalização
- **1º Ciclo**: O LED vermelho acende, e após **3 segundos**, o LED vermelho é apagado e o LED amarelo é aceso.
- **2º Ciclo**: O LED amarelo acende, e após **3 segundos**, o LED amarelo é apagado e o LED verde é aceso.
- **3º Ciclo**: O LED verde acende, e após **3 segundos**, o LED verde é apagado e o LED vermelho é aceso novamente.

Este ciclo de alternância se repete continuamente.

### 3. Temporizador
- O temporizador é configurado utilizando a função `add_repeating_timer_ms()` do Pico SDK, que chama a função de callback a cada **3 segundos** para alternar o estado dos LEDs.

### 4. Mensagem Serial
- A rotina principal, no loop `while`, imprime uma mensagem a cada **1 segundo**. 

## Fluxo de Operação

1. **LED Vermelho** aceso inicialmente.
2. Após **3 segundos**, o **LED Vermelho** apaga e o **LED Amarelo** acende.
3. Após **3 segundos**, o **LED Amarelo** apaga e o **LED Verde** acende.
4. Após **3 segundos**, o **LED Verde** apaga e o **LED Vermelho** acende novamente.
5. O ciclo se repete continuamente.

