Projeto de Semáforo com Raspberry Pi Pico W
Este projeto implementa um semáforo com temporização de 3 segundos para cada estado (vermelho, amarelo e verde), 
utilizando o microcontrolador Raspberry Pi Pico W e o Pico SDK. O código foi desenvolvido para ser testado no simulador Wokwi e na placa de desenvolvimento BitDogLab.

Funcionalidades
Temporização de 3 segundos:

Cada estado do semáforo (vermelho, amarelo e verde) dura 3 segundos.

A mudança de estado é controlada por um temporizador repetitivo usando a função add_repeating_timer_ms().

Feedback Serial:

A cada segundo, o estado atual do semáforo é enviado pela porta serial para depuração.

Simulação no Wokwi:

O projeto pode ser simulado no Wokwi usando LEDs externos (vermelho, amarelo e verde) conectados aos pinos GPIO do Raspberry Pi Pico W.

Teste no BitDogLab:

O código pode ser adaptado para usar o LED RGB integrado da placa BitDogLab, substituindo os LEDs externos.

Componentes Necessários
Simulação no Wokwi
Raspberry Pi Pico W.

3 LEDs (vermelho, amarelo e verde).

3 resistores de 330 Ω.

Teste no BitDogLab
Placa BitDogLab com LED RGB integrado (GPIOs 11, 12 e 13).

Estrutura do Código
O código está organizado da seguinte forma:

Inicialização dos LEDs:

Configura os pinos dos LEDs como saída e os desliga no início.

Temporizador Repetitivo:

Usa a função add_repeating_timer_ms() para chamar uma função de callback a cada 3 segundos.

Função de Callback:

Altera o estado do semáforo e liga o LED correspondente.

Loop Principal:

Envia mensagens pela porta serial a cada segundo para depuração.

Instruções de Uso
Simulação no Wokwi
Abra o simulador Wokwi.

Conecte os componentes conforme a configuração sugerida:

LED vermelho → GPIO 11.

LED amarelo → GPIO 12.

LED verde → GPIO 13.

Resistores de 330 Ω em série com cada LED.

Carregue o código no Raspberry Pi Pico W.

Execute a simulação e observe o funcionamento do semáforo.

Teste no BitDogLab
Conecte a placa BitDogLab ao computador.

Substitua os pinos dos LEDs no código pelos pinos do LED RGB:

GPIO 11: Vermelho.

GPIO 12: Verde.

GPIO 13: Azul.

Carregue o código na placa BitDogLab.

Observe o LED RGB simulando o semáforo.

